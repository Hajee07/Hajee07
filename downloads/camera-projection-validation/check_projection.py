"""Offline landmark reprojection; no process access or game control."""
import argparse
import json
import math


def vector(value, size):
    if not isinstance(value, list) or len(value) != size:
        raise ValueError(f'Expected vector of length {size}')
    if any(isinstance(x, bool) or not isinstance(x, (int, float)) or not math.isfinite(x) for x in value):
        raise ValueError('Non-finite or non-numeric value')
    return value


def matrix(value):
    if not isinstance(value, list) or len(value) != 4:
        raise ValueError('Expected four matrix rows')
    return [vector(row, 4) for row in value]


def mul(m, v):
    return [sum(a*b for a, b in zip(row, v)) for row in m]


def assess(data):
    if data.get('convention') != 'ROW_ARRAYS_COLUMN_VECTORS_TOP_LEFT_PIXELS':
        raise ValueError('Explicit supported convention required')
    view, projection = matrix(data['view']), matrix(data['projection'])
    x, y, width, height = vector(data['viewport'], 4)
    if width <= 0 or height <= 0:
        raise ValueError('Positive viewport dimensions required')
    tolerance = data['tolerance_pixels']
    vector([tolerance], 1)
    if tolerance <= 0 or tolerance > 20:
        raise ValueError('Tolerance must be >0 and <=20 pixels')
    depth = data.get('depth_range')
    if depth not in ('ZERO_TO_ONE', 'MINUS_ONE_TO_ONE'):
        raise ValueError('Explicit depth range required')
    landmarks = data['landmarks']
    if not isinstance(landmarks, list) or len(landmarks) < 4:
        raise ValueError('At least four independently measured landmarks required')
    results = []
    points = []
    for item in landmarks:
        world = vector(item['world'], 3)
        measured = vector(item['pixel'], 2)
        points.append(tuple(world))
        clip = mul(projection, mul(view, world + [1]))
        if any(not math.isfinite(v) for v in clip) or clip[3] <= 1e-8:
            raise ValueError('Invalid or behind-camera clip coordinate')
        ndc = [c / clip[3] for c in clip[:3]]
        low = 0 if depth == 'ZERO_TO_ONE' else -1
        if not (-1 <= ndc[0] <= 1 and -1 <= ndc[1] <= 1 and low <= ndc[2] <= 1):
            raise ValueError('Landmark outside declared clip volume')
        if not (x <= measured[0] <= x+width and y <= measured[1] <= y+height):
            raise ValueError('Measured pixel outside viewport')
        predicted = [x+(ndc[0]+1)*width/2, y+(1-ndc[1])*height/2]
        error = math.dist(predicted, measured)
        results.append({'predicted_pixel': predicted, 'error_pixels': error})
    if len(set(points)) < 4:
        raise ValueError('Distinct landmarks required')
    errors = [r['error_pixels'] for r in results]
    return {'status': 'REPROJECTION_MATCH' if max(errors) <= tolerance else 'REPROJECTION_MISMATCH',
            'scope': 'SUPPLIED_DATA_ONLY', 'actual_rendered_camera': 'UNVERIFIED',
            'frame_synchronization': 'UNVERIFIED', 'aim_writes': 'NONE',
            'rms_pixels': math.sqrt(sum(e*e for e in errors)/len(errors)),
            'maximum_error_pixels': max(errors), 'landmarks': results}


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('input')
    parser.add_argument('output')
    args = parser.parse_args()
    with open(args.input, encoding='utf-8-sig') as f:
        report = assess(json.load(f))
    with open(args.output, 'w', encoding='utf-8') as f:
        json.dump(report, f, indent=2, allow_nan=False)
    print(report['status'])
    raise SystemExit(0 if report['status'] == 'REPROJECTION_MATCH' else 2)
