#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_PGDN,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                              KC_RALT, MO(_FN), KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_FN] = LAYOUT(
        QK_BOOT,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RM_TOGG,
        _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RM_NEXT,
        _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RM_PREV,
        _______,  _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______, _______, RM_VALU, RM_SPDU,
        _______,  _______, _______,                   _______,                            _______, _______, RM_HUED, RM_VALD, RM_HUEU
    ),
};

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    oled_write_ln_P(PSTR("FREEBOARD"), false);
    oled_write_P(PSTR("Layer: "), false);
    oled_write_ln(get_highest_layer(layer_state) == _FN ? PSTR("FN") : PSTR("BASE"), false);

    led_t leds = host_keyboard_led_state();
    oled_write_P(PSTR("Caps:  "), false);
    oled_write_ln_P(leds.caps_lock ? PSTR("ON") : PSTR("OFF"), false);
    return false;
}
#endif
