"""All 51 recovered controls, in the supplied menu order."""
from buttons.button_01_enable_all import button_01_enable_all
from buttons.button_02_aimkill_multitarget import button_02_aimkill_multitarget
from buttons.button_03_speed_timer import button_03_speed_timer
from buttons.button_04_speed_slow_v2 import button_04_speed_slow_v2
from buttons.button_05_speed_run import button_05_speed_run
from buttons.button_06_auto_target import button_06_auto_target
from buttons.button_07_auto_revive import button_07_auto_revive
from buttons.button_08_esp_line import button_08_esp_line
from buttons.button_09_esp_box import button_09_esp_box
from buttons.button_10_esp_health import button_10_esp_health
from buttons.button_11_esp_weapon_icon import button_11_esp_weapon_icon
from buttons.button_12_esp_distance import button_12_esp_distance
from buttons.button_13_esp_grenade import button_13_esp_grenade
from buttons.button_14_draw_fov import button_14_draw_fov
from buttons.button_15_enable_look_changer import button_15_enable_look_changer
from buttons.button_16_show_for_others_os import button_16_show_for_others_os
from buttons.button_17_look_1_rampage import button_17_look_1_rampage
from buttons.button_18_look_2_cobra import button_18_look_2_cobra
from buttons.button_19_look_3_criminal_red import button_19_look_3_criminal_red
from buttons.button_20_look_4_sakura import button_20_look_4_sakura
from buttons.button_21_look_5_venom import button_21_look_5_venom
from buttons.button_22_look_6_titan import button_22_look_6_titan
from buttons.button_23_look_7_hip_hop import button_23_look_7_hip_hop
from buttons.button_24_look_8_bunny_warrior import button_24_look_8_bunny_warrior
from buttons.button_25_look_9_breakdancer import button_25_look_9_breakdancer
from buttons.button_26_look_10_arctic_blue import button_26_look_10_arctic_blue
from buttons.button_27_look_11_naruto import button_27_look_11_naruto
from buttons.button_28_look_12_sasuke import button_28_look_12_sasuke
from buttons.button_29_look_13_kakashi import button_29_look_13_kakashi
from buttons.button_30_look_14_saitama import button_30_look_14_saitama
from buttons.button_31_look_15_dino import button_31_look_15_dino
from buttons.button_32_look_16_old_man import button_32_look_16_old_man
from buttons.button_33_look_17_criminal_blue import button_33_look_17_criminal_blue
from buttons.button_34_look_18_criminal_green import button_34_look_18_criminal_green
from buttons.button_35_look_19_angelic_set import button_35_look_19_angelic_set
from buttons.button_36_look_20_galaxy_set import button_36_look_20_galaxy_set
from buttons.button_37_fly_lock import button_37_fly_lock
from buttons.button_38_rise_up import button_38_rise_up
from buttons.button_39_rise_up_new_height import button_39_rise_up_new_height
from buttons.button_40_tp_anywhere import button_40_tp_anywhere
from buttons.button_41_telespot_manual import button_41_telespot_manual
from buttons.button_42_telespot_auto import button_42_telespot_auto
from buttons.button_43_wide_camera import button_43_wide_camera
from buttons.button_44_invisible_kill import button_44_invisible_kill
from buttons.button_45_black_sky import button_45_black_sky
from buttons.button_46_downkill import button_46_downkill
from buttons.button_47_joystick_speed import button_47_joystick_speed
from buttons.button_48_show_keybinds import button_48_show_keybinds
from buttons.button_49_enable_keybind_system import button_49_enable_keybind_system
from buttons.button_50_show_match_timer import button_50_show_match_timer
from buttons.button_51_clear_all_keybinds import button_51_clear_all_keybinds

BY_ID = {
    102: button_01_enable_all,
    110: button_02_aimkill_multitarget,
    517: button_03_speed_timer,
    1099: button_04_speed_slow_v2,
    507: button_05_speed_run,
    34834: button_06_auto_target,
    7896: button_07_auto_revive,
    1: button_08_esp_line,
    2: button_09_esp_box,
    3: button_10_esp_health,
    32: button_11_esp_weapon_icon,
    4: button_12_esp_distance,
    33: button_13_esp_grenade,
    16: button_14_draw_fov,
    7100: button_15_enable_look_changer,
    7101: button_16_show_for_others_os,
    7102: button_17_look_1_rampage,
    7103: button_18_look_2_cobra,
    7104: button_19_look_3_criminal_red,
    7105: button_20_look_4_sakura,
    7106: button_21_look_5_venom,
    7107: button_22_look_6_titan,
    7108: button_23_look_7_hip_hop,
    7109: button_24_look_8_bunny_warrior,
    7110: button_25_look_9_breakdancer,
    7111: button_26_look_10_arctic_blue,
    7112: button_27_look_11_naruto,
    7113: button_28_look_12_sasuke,
    7114: button_29_look_13_kakashi,
    7115: button_30_look_14_saitama,
    7116: button_31_look_15_dino,
    7117: button_32_look_16_old_man,
    7118: button_33_look_17_criminal_blue,
    7119: button_34_look_18_criminal_green,
    7120: button_35_look_19_angelic_set,
    7121: button_36_look_20_galaxy_set,
    5194: button_37_fly_lock,
    111: button_38_rise_up,
    5660: button_39_rise_up_new_height,
    5198: button_40_tp_anywhere,
    59910: button_41_telespot_manual,
    59912: button_42_telespot_auto,
    7003: button_43_wide_camera,
    532: button_44_invisible_kill,
    7001: button_45_black_sky,
    5658: button_46_downkill,
    114: button_47_joystick_speed,
    6002: button_48_show_keybinds,
    6000: button_49_enable_keybind_system,
    6003: button_50_show_match_timer,
    6001: button_51_clear_all_keybinds,
}
