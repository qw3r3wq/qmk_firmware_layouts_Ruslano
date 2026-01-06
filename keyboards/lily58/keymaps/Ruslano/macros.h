#pragma once

enum custom_keycodes {
        MAC_LOK = SAFE_RANGE,   // For Win + L -> Cmd + Ctrl + Q
        MAC_APP, // For Alt + Tab -> Cmd + Tab
        MAC_LWR, // For Ctrl + Left -> Option + Left
        MAC_RWR  // For Ctrl + Right -> Option + Right
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MAC_LOK:
            if (record->event.pressed) {
                // macOS Lock Screen: Cmd + Ctrl + Q
                // Press Cmd, Ctrl, Q
                register_code(KC_LGUI);
                register_code(KC_LCTL);
                register_code(KC_Q);
                register_code(KC_Q);
            } else {
                // Release Cmd, Ctrl, Q
                unregister_code(KC_Q);
                unregister_code(KC_LCTL);
                unregister_code(KC_LGUI);
            }
            return false; // Return false to indicate that QMK should not process this keycode further
        case MAC_APP:
            if (record->event.pressed) {
                // macOS App Switcher: Cmd + Tab
                // Press Cmd, then Tab
                register_code(KC_LGUI);
                tap_code(KC_TAB);
            } else {
                // Release Cmd (Tab is already released by tap_code)
                unregister_code(KC_LGUI);
            }
            return false;
        case MAC_LWR:
            if (record->event.pressed) {
                // macOS Move Left Whole Word: Option + Left Arrow
                // Press Option, then Left Arrow
                register_code(KC_LALT); // Option key
                register_code(KC_LEFT);
            } else {
                // Release Option, Left Arrow
                unregister_code(KC_LEFT);
                unregister_code(KC_LALT);
            }
            return false;
        case MAC_RWR:
            if (record->event.pressed) {
                // macOS Move Right Whole Word: Option + Right Arrow
                // Press Option, then Right Arrow
                register_code(KC_LALT); // Option key
                register_code(KC_RIGHT);
            } else {
                // Release Option, Right Arrow
                unregister_code(KC_RIGHT);
                unregister_code(KC_LALT);
            }
            return false;
    }
/*
	if (record->event.pressed) {
		#ifdef OLED_ENABLE
		set_keylog(keycode, record);
		#endif
		// set_timelog();
	}
*/
    return true; // Process all other keycodes as usual
}


//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE
