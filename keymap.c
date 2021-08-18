/* Copyright 2019
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

enum layers {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   |  |Enter |  
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  /   |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |RShift| 
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |Raise |Lower |    Space    | RAlt |   ;  | Down | Down |Right | 
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_mit( \
  KC_ESC,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_TAB,         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_BSLS, KC_ENT, \
  RSFT_T(KC_DEL), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   RSFT_T(KC_SLSH), \
  KC_LCTL,        KC_LGUI, KC_LALT, LOWER,   RAISE,   KC_SPC,           KC_RALT, KC_SCLN, KC_LEFT, KC_DOWN, KC_RGHT \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  ~   |  !   |  @   |  #   |  $   |  %   |  ^   |  &   |  *   |  (   |  )   |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |LShift|  /   |  \   |  "   |  ?   |  -   |  _   |  +   |  =   |  {   |  }   |RShift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LCTRL| LGUI | LAlt |      |      |             |AltGrp| RGUI |  [   |  ]   |RCTRL |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_mit( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_ENT, \
  KC_LSFT, KC_SLSH, KC_BSLS, KC_QUOT, KC_QUES, KC_MINS, KC_UNDS, KC_PLUS, KC_EQL,  KC_LCBR, KC_RCBR, KC_RSFT, \
  KC_LCTL, KC_LGUI, KC_LALT, _______, _______, KC_SPC,           KC_RALT, KC_RGUI, KC_LBRC, KC_RBRC, KC_RCTL \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Ins  | Home | PgUp |      |      |      |   -  |   =  |   [  |   ]  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |LShift| Del  | End  |PgDown|      |      |      |PrtScr|      |Pause |      |RShift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |LCTRL | LGUI | LAlt |      |      |             |AltGrp| RGUI | App  |      |RCTRL |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_mit( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, KC_INS,  KC_HOME, KC_PGUP, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_ENT, \
  KC_LSFT, KC_DEL,  KC_END,  KC_PGDN, _______, _______, _______, KC_PSCR, _______, KC_PAUS, _______, KC_RSFT, \
  KC_LCTL, KC_LGUI, KC_LALT, _______, _______, KC_SPC,           KC_RALT, KC_RGUI, KC_APP,  _______, KC_RCTL \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      | BRI+ |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Led SW|Led + |      |      |      | BRI- |      |      | Mute | Play |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |RGB SW|RGBmod|      |      |      |      |      | FBck | Vol+ | FFwd |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      | Next | Vol- | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  _______, RESET,   _______, _______, _______, _______, _______, KC_BRIU, _______, _______, _______, _______, \
  _______, _______, BL_TOGG, BL_STEP, _______, _______, _______, KC_BRID, _______, _______, KC_MUTE, KC_MPLY, \
  _______, _______, RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______, KC_MRWD, KC_VOLU, KC_MFFD, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT \
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
