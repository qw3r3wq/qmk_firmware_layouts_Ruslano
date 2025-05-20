#pragma once

// Include the main QMK header. This provides necessary types like qk_tap_dance_state_t
// and the ACTION_TAP_DANCE_FN_ADVANCED macro.
#include "quantum.h"

// Define an enum for your tap dance keys.
// This makes your keymap.c more readable and robust.
enum {
	TD_DCOM // A descriptive name for our tap dance key
};

enum custom_keycodes {
	MAC_LOK = SAFE_RANGE,   // For Win + L -> Cmd + Ctrl + Q
	MAC_APP, // For Alt + Tab -> Cmd + Tab
	MAC_LWR, // For Ctrl + Left -> Option + Left
	MAC_RWR  // For Ctrl + Right -> Option + Right
};

// Function called when a tap dance key is tapped/released.
// Use this to determine what action to perform based on state->count.
void dot_commas_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        // Single tap: Send KC_DOT
        tap_code(KC_DOT);
    } else if (state->count == 2) {
        // Double tap: Send KC_COMM
        tap_code(KC_COMM);
    } else if (state->count == 3) {
        // Triple tap: Send KC_DOT three times
        tap_code(KC_DOT);
        tap_code(KC_DOT);
        tap_code(KC_DOT);
    }
    // For more than 3 taps, you could define another action, or have it do nothing.
    // As per your request, we stop at 3.
}

// Function called when the tap dance sequence is reset (e.g., after a short delay
// or when another key is pressed). This is useful for clearing internal states
// if your tap dance was more complex (e.g., involving toggles).
void dot_commas_reset(tap_dance_state_t *state, void *user_data) {
    // In this simple case, no specific cleanup is needed, so it can be empty.
    // If you had a state variable that changed on tap, you'd reset it here.
}

// Define the array of tap dance actions.
// The index of each entry in this array corresponds to the enum value.
tap_dance_action_t tap_dance_actions[] = {
    // Use ACTION_TAP_DANCE_FN_ADVANCED for custom functions
    // The first argument (NULL) is for on_each_tap_fn, which we don't need here.
    [TD_DCOM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dot_commas_finished, dot_commas_reset)
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
    return true; // Process all other keycodes as usual
}


