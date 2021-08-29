

[_QWERTY] = LAYOUT( \
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, \
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \
          KC_LGUI, LT(_LOWER, KC_TAB),   CTL_T(KC_SPC),    SFT_T(KC_BSPC), LT(_RAISE, KC_DEL), KC_RALT         \
),

 

[_RAISE] = LAYOUT( \
  KC_EXLM,    KC_AT,    KC_HASH, KC_DLR,  KC_PERC,      KC_PLUS, KC_7,     KC_8,   KC_9, KC_0,    \
  KC_CIRC,    KC_AMPR,  KC_TILD, KC_PIPE, KC_BSLS,      KC_MINUS,  KC_4,     KC_5,   KC_6, KC_EQL, \
  KC_DQT,     KC_QUOT,  KC_UNDS, KC_GRV,  _______,      KC_ASTR,  KC_1,     KC_2,   KC_3, KC_SLSH, \
                        _______, MO(_ADJUST), _______,      _______,  _______,  _______                    \
),

 


[_LOWER] = LAYOUT( \
  KC_ESC,   KC_HOME, KC_UP,   KC_END,   KC_LALT,     KC_LPRN, KC_RPRN, KC_WH_U, KC_MS_U, KC_WH_D,\
  KC_VOLU,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGUP,     KC_LBRC, KC_RBRC, KC_MS_L, KC_MS_D, KC_MS_R, \
  KC_VOLD,  KC_MPRV, KC_MPLY, KC_MNXT,  KC_PGDN,     KC_LCBR, KC_RCBR, KC_BTN1, KC_BTN3,  KC_BTN2, \
                    _______, _______, _______,      KC_ENT,  MO(_ADJUST), _______                    \
),

 


[_ADJUST] =  LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,    KC_F8,   KC_F9,    KC_F10, \
  _______, _______, RGB_RMOD, RGB_SAI,  RGB_SAD,      _______,  _______,  _______, KC_F11,   KC_F12, \
  RESET,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD,      RGB_VAI, RGB_VAD,  RGB_M_P, RGB_M_B,  RGB_M_X, \
                    _______, _______, _______,      _______, _______,  _______                    \
)
};
 




