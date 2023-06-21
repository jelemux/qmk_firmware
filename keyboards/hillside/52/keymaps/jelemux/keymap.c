// Copyright 2022 Jeremias Weber (@jelemux)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// https://docs.qmk.fm/#/feature_caps_word?id=representing-caps-word-state
void caps_word_set_user(bool active) {
    if (active) {
        // TODO: Light LEDs when Caps Word activates.
    } else {
        // TODO: Turn LEDs off when Caps Word deactivates.
    }
}

enum layers {
    _BASE = 0,
    _MEDIA,
    _GAMING,
    _ADJUST,
};

#define LY_BASE TO(_BASE)
#define LY_MED OSL(_MEDIA)
#define LY_GAM OSL(_GAMING)
#define LY_ADJ OSL(_ADJUST)
#define ALT_GR OSM(MOD_RALT)
#define OSM_LSFT OSM(MOD_LSFT)
#define OSM_RSFT OSM(MOD_RSFT)
#define OSM_LCT OSM(MOD_LCTL)
#define OSM_RCT OSM(MOD_RCTL)

#define UNDO LCTL(KC_Y)
#define CUT  LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define REDO LCTL(KC_Z)
// (For OS X, you'll want to change these editing keys to LGUI(KC_Z) etc.)


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
     KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ENT,
     KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
     OSM_LCT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_DEL,                       KC_BSPC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OSM_RCT,
     LY_MED,  KC_LGUI, KC_LALT,          ALT_GR,  KC_CAPS, KC_SPC, OSM_LSFT,   OSM_RSFT, KC_SPC , KC_CAPS, ALT_GR,           KC_MINS, LY_GAM,  LY_ADJ
    ),
    [_MEDIA] = LAYOUT(
     KC_VOLU, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                                        KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_HOME,
     KC_VOLD, KC_F11 , KC_F12 , KC_MPLY, KC_MSTP, KC_MPRV,                                        KC_MNXT, KC_LEFT, KC_UP  , KC_DOWN, KC_RGHT, KC_END,
     _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , UNDO   ,                      REDO   , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______,
     _______, LY_BASE, _______,          KC_MUTE, CUT    , COPY   , _______,    _______, PASTE  , KC_PGUP, KC_PGDN,          XXXXXXX, _______, _______
    ),
    [_GAMING] = LAYOUT(
     KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
     KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_3,                         KC_4,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_RSFT,
     KC_LCTL, LY_BASE, KC_ESC,           KC_LGUI, KC_LALT, KC_SPC,  KC_1,         KC_2,  KC_SPC,  KC_RALT, KC_RGUI,          KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_ADJUST] = LAYOUT(
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, AG_SWAP, CG_SWAP,                                        XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, KC_BRIU, XXXXXXX, AG_NORM, CG_NORM,                                        RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, XXXXXXX, XXXXXXX,
     QK_BOOT, XXXXXXX, KC_BRID, XXXXXXX, XXXXXXX, XXXXXXX, EE_CLR,                      RGB_TOG, RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, XXXXXXX, XXXXXXX,
     XXXXXXX, LY_BASE, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, _______,    _______, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX
    ),
};

//  Template:
//    [_INDEX] = LAYOUT(
//     _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______,
//     _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______,
//     _______, _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, _______,
//     _______, _______, _______,          _______, _______, _______, _______,    _______, _______, _______, _______,          _______, _______, _______
//    ),
