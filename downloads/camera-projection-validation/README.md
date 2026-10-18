# Offline projection verification gate

This standalone Python 3 checker compares supplied world landmarks against independently measured top-left screen pixels. It does not read BlueStacks memory, discover matrices, invoke game functions or produce aim output. The example is synthetic and does not establish Free Fire camera compatibility.

Run on Windows with Python 3:

```powershell
py -3 .\check_projection.py .\synthetic-example.json .\result.json
py -3 -m unittest discover -s . -v
```

Matrices are explicitly four row arrays multiplying column vectors: clip = projection * view * [world,1]. Viewport is [left,top,width,height] in the same image pixel coordinates as measurements. Specify ZERO_TO_ONE or MINUS_ONE_TO_ONE clip depth; never silently transpose a matrix, flip an axis, or infer a convention. All landmarks must be inside the declared clip volume with positive clip w. Exit code 0 means every supplied landmark fits the declared tolerance; 2 means mismatch. Invalid input raises an error before writing a report; do not reuse old output after a failed command.

The four test methods cover exact match, a measurable mismatch, view translation, and nine malformed/ambiguous input cases. Run them with Python 3; no external dependencies are required.

## Live source prerequisites still pending

The V4 user log reported matching player/main/controller native links, with getter initialization unavailable. Its pointer inventory does not provide view/projection matrices, FOV or render-frame identity. The pinned static audit establishes method registrations and names only. No live projection reader is added here.

Before substituting real data, independently establish the matrix data source and layout for the exact build, axis/handedness and depth convention, viewport including emulator scaling/cropping, and the same camera/pose/frame for both matrices and pixel measurements. Use multiple spatially spread static landmarks and multiple poses; values derived from the same projection formula are not independent measurements. A single supplied-data match neither proves render authority nor validates LOS, shot direction, aim integration, server hit classification or future frames.

Do not enter guessed matrices or guessed FOV into the example and label the result live verification. Existing camera probes remain unchanged. No additional READY/turn experiment is requested by this package.
