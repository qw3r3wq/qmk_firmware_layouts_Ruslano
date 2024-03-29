/* Copyright 2017 Wunder
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
/*
#include "send_string.h"
#include "keymap_lithuanian_qwerty.h"
 */

#define DEFAULT TO(_QWERTY)
#define FUNCT MO(_FUNCT)
#define TOP MO(_TOP)
#define BOT MO(_BOT)
#define NUMPAD TG(_FUNCT)

enum layer_names {
	_QWERTY,
	_TOP,
	_BOT,
	_FUNCT
};

enum custom_keycodes {
	IBAN = SAFE_RANGE,
	QMKURL,
	LCTL_AC,
	LWIN_L,
	UPDATE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case IBAN:
        if (record->event.pressed) {
            // when keycode IBAN is pressed
            SEND_STRING("LT907044000713615550");
        } else {
            // when keycode QMKBEST is released
        }
        break;

    case QMKURL:
        if (record->event.pressed) {
            // when keycode QMKURL is pressed
            SEND_STRING("https://qmk.fm/\n");
        } else {
            // when keycode QMKURL is released
        }
        break;

    case LCTL_AC:
        if (record->event.pressed) {
           SEND_STRING(SS_LCTL("ac")); // selects all and copies
        }
        break;
    case LWIN_L:
        if (record->event.pressed) {
           SEND_STRING(SS_LWIN("l")); // WIN+L
        }
        break;
    case UPDATE:
        if (record->event.pressed) {
           SEND_STRING("apt-update && apt-full"); // WIN+L
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | `      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | TAB    | Q      | W      | E      | R      | T      | [      | \      | ]      | Y      | U      | I      | O      | P      | '      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | CAP LK | A      | S      | D      | F      | G      | HOME   | DEL    | PG UP  | H      | J      | K      | L      | ;      | ENTER  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      | END    | UP     | PG DN  | N      | M      | ,      | .      | /      | RSHIFT |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
     * | LCTRL  | LGUI   | LALT   | FN     | SPACE  | SPACE  | LEFT   | DOWN   | RIGHT  | SPACE  | SPACE  | NUMPAD | RALT   | RGUI   | RCTRL  |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_ortho_5x15( /* QWERTY */
        KC_ESC,		KC_1,	KC_2,		KC_3,	KC_4,	KC_5,	KC_HOME,KC_INS,	KC_PGUP,KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	KC_BSPC,
        KC_ESC,		KC_Q,	KC_W,		KC_E,	KC_R,	KC_T,	KC_END, LCTL_AC,KC_PGDN,KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,	KC_BSPC,
        KC_TAB,		KC_A,	KC_S,		KC_D,	KC_F,	KC_G,	XXXXXXX,LWIN_L,	XXXXXXX,KC_H,	KC_J,	KC_K,	KC_L,	KC_SCLN,KC_QUOT,
        LSFT_T(KC_DEL),	KC_Z,	KC_X,		KC_C,	KC_V,	KC_B,	XXXXXXX,IBAN,	XXXXXXX,KC_N,	KC_M,	KC_COMM,KC_DOT,	KC_UP	,RSFT_T(KC_SLSH),
	KC_LCTL,	KC_LGUI,LALT_T(KC_MINS),BOT,	TOP,	KC_SPC,	XXXXXXX,UPDATE,	XXXXXXX,KC_ENT,	NUMPAD,	KC_BSLS,KC_LEFT,KC_DOWN,KC_RGHT
    ),
    [_TOP] = LAYOUT_ortho_5x15( /* TOP NUMBER AND MISSING CHAR */
        /*KC_ESC,		LT_AOGO,LT_CCAR,	LT_EOGO,LT_EDOT,LT_IOGO,KC_MINS,KC_GRV,	KC_EQL,	LT_SCAR,LT_UOGO,LT_UMAC,KC_9,	LT_ZCAR,KC_BSPC,*/
        KC_ESC,		KC_1,	KC_2,		KC_3,	KC_4,	KC_5,	KC_MINS,KC_GRV,	KC_EQL,	KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	KC_BSPC,
        KC_GRV,		KC_1,	KC_2,		KC_3,	KC_4,	KC_5,	KC_MINS,KC_GRV,	KC_EQL,	KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	KC_BSPC,
        KC_TILD,	KC_EXLM,KC_AT,		KC_HASH,KC_DLR,	KC_PERC,KC_HOME,KC_INS,	KC_PGUP,KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_QUOT,
        LSFT_T(KC_DEL),	KC_SLSH,KC_BSLS,	KC_QUOT,KC_QUES,KC_MINS,KC_END,	KC_UP,	KC_PGDN,KC_UNDS,KC_PLUS,KC_EQL,	KC_LCBR,KC_RCBR	,RSFT_T(KC_SLSH),
	KC_LCTL,	KC_LGUI,LALT_T(KC_MINS),KC_PSCR,BOT,	KC_SPC,	KC_LEFT,KC_DOWN,KC_RGHT,KC_ENT,	KC_RALT,KC_RGUI,KC_LBRC,KC_RBRC,KC_RCTL
    ),
    [_BOT] = LAYOUT_ortho_5x15( /* TOP NUMBER AND MISSING CHAR */
        KC_ESC,		KC_1,	KC_2,		KC_3,	KC_4,	KC_5,	KC_MINS,KC_GRV,	KC_EQL,	KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	KC_BSPC,
        KC_F12,		KC_F1,	KC_F2,		KC_F3,	KC_F4,	KC_F5,	KC_MINS,KC_GRV,	KC_EQL,	KC_F6,	KC_F7,	KC_F8,	KC_F9,	KC_F10,	KC_F11,
        KC_CAPS,	KC_INS,	KC_HOME,	KC_PGUP,_______,_______,KC_HOME,KC_INS,	KC_PGUP,KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_QUOT,
        LSFT_T(KC_DEL),	KC_DEL,	KC_END,		KC_PGDN,KC_QUES,KC_MINS,KC_END,	KC_UP,	KC_PGDN,KC_UNDS,KC_PLUS,KC_EQL,	KC_LCBR,KC_RCBR,RSFT_T(KC_SLSH),
	KC_LCTL,	KC_LGUI,LALT_T(KC_MINS),KC_PSCR,BOT,	KC_SPC,	KC_LEFT,KC_DOWN,KC_RGHT,KC_ENT,	KC_RALT,KC_RGUI,KC_APP,	KC_APP,	KC_RCTL
    ),

    /* FUNCTION
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | SELECT | CALC   | MYCOMP | MAIL   | RGB HD | RGB HI | P7     | P8     | P9     | -      |        |        | PR SCR | SCR LK | PAUSE  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | PREV   | PLAY   | NEXT   | STOP   | RGB SD | RGB SI | P4     | P5     | P6     | +      |        | RESET  |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | VOL-   | MUTE   | VOL+   | APP    | RGB VD | RGB VI | P1     | P2     | P3     | PENT   |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        | RGB TG | FN     | RGB RMD| RGB MD | P0     |        | P.     | PENT   | PENT   | DEFAULT|        |        |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_FUNCT] = LAYOUT_ortho_5x15( /* FUNCTION */
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_NUM,  KC_SLSH, KC_ASTR, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_MSEL, KC_CALC, KC_MYCM, KC_MAIL, RGB_HUD, RGB_HUI, KC_P7,   KC_P8,   KC_P9,   KC_MINS, _______, _______, KC_PSCR, KC_LSCR, KC_PAUS,
        KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, RGB_SAD, RGB_SAI, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, LWIN_L,  QK_BOOT, _______, _______, _______,
        KC_VOLD, KC_MUTE, KC_VOLU, KC_APP,  RGB_VAD, RGB_VAI, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, QK_RBT,  _______, _______, KC_RSFT,
        _______, _______, RGB_TOG, _______, RGB_RMOD,RGB_MOD, KC_P0,   _______, KC_PDOT, KC_PENT, DEFAULT, DEFAULT, _______, QK_MAKE, KC_RCTL
    )
};

