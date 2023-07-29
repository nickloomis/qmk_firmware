/* Copyright 2021 Yiancar-Designs
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

// qmk compile -kb yiancardesigns/seigaiha -km loomsci
// qmk flash -kb yiancardesigns/seigaiha -km loomsci 

// make yiancardesigns/seigaiha:loomsci
// make yiancardesigns/seigaiha:loomsci:flash
// hold down top-left ("escape") key to enter flash mode on keyboard

#include QMK_KEYBOARD_H

#define BASE 0  // default layer
#define EXTEND 1
#define SPACE 2

// https://www.reddit.com/r/olkb/comments/ghjkvl/anyone_know_how_to_make_a_screenshot_key_for_mac/
// Props to TheMadTinker
#define KC_CAPP LGUI(LSFT(KC_4))        // Capture portion of screen (save to file)
#define KC_CPYP LGUI(LSFT(LCTL(KC_4)))  // Copy portion of screen

enum custom_keycodes {
    MAC_LOGIN = SAFE_RANGE,
    MAC_LOGIN_ANTICOLEMAK,
    VPN,
    LINUX_LOGIN
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LINUX_LOGIN:
            if (record->event.pressed) {
                SEND_STRING("spegpm\n");
            }
            break;
        case MAC_LOGIN:
            if (record->event.pressed) {
                // when keycode MAC_LOGIN is pressed
                SEND_STRING("Iamgroot_3\n");
            } else {
                // when keycode MAC_LOGIN is released
            }
            break;
        case MAC_LOGIN_ANTICOLEMAK:
            if (record->event.pressed) {
                SEND_STRING("Lamts;;f_3\n");
            }
            break;
        case VPN:
            if (record->event.pressed) {
                SEND_STRING("kingofrock");
            }
            break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_alice_split_bs(
    LINUX_LOGIN,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,             KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_TRNS,  KC_BSPACE,
    VPN,        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,    KC_LBRC, KC_RBRC, KC_BSLS,
    KC_CPYP, LT(EXTEND, KC_ESC), KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,          KC_ENT,
                KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                      KC_ESC,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_TRNS,
                KC_LCTL,          KC_LOPT,     KC_LGUI,    LCTL_T(KC_BSPACE),       LT(SPACE, KC_SPC),           KC_LGUI,                            LT(EXTEND, KC_ENT)
    ),

[EXTEND] = LAYOUT_alice_split_bs(
    MAC_LOGIN_ANTICOLEMAK, KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,          KC_F7,   KC_F8,   KC_F9,   KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS, KC_TRNS,
    KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,
    KC_CAPP,               KC_TRNS, KC_TRNS, KC_TRNS, KC_LSFT, KC_TRNS, KC_TRNS,                 KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS,          KC_TRNS,
                           KC_TRNS, KC_TRNS, LCTL(KC_X), LCTL(KC_C), KC_TRNS, LCTL(KC_V),        KC_TRNS, LCTL(KC_K), KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
                           KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS,                 KC_TRNS,          KC_TRNS,                            KC_TRNS
    /*),*/
    ),


// TODO: cmd-shift-p, cmd-opt-i, other shortcuts that aren't on the EXTEND layer, etc
[SPACE] = LAYOUT_alice_split_bs(
    KC_TRNS, KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,          KC_F7,   KC_F8,   KC_F9,   KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS, KC_TRNS,
    KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS, KC_MS_U,   KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,
    KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                 KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN2, KC_TRNS,          KC_TRNS,
                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
                           KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS,                 KC_TRNS,          KC_TRNS,                            KC_TRNS
    /*),*/
    )
};

/*
    // triggered from caps lock
    [EXTEND] = LAYOUT_buzzsaw(
        KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,      KC_F7, KC_F8, KC_F9, KC_F10, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS,                                            MAC_LOGIN_ANTICOLEMAK,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, LSFT(KC_LEFT), KC_UP,  LSFT(KC_RIGHT), KC_BRID, LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), LCMD(KC_T),      VPN, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   LCMD(LOPT(KC_LEFT)), KC_LEFT, KC_DOWN, KC_RIGHT, LCMD(LOPT(KC_RIGHT)), KC_BRIU, KC_TRNS,                  KC_CAPP,
        KC_TRNS, KC_TRNS, LCTL(KC_X), LCTL(KC_C), KC_TRNS, KC_TRNS,       LCTL(KC_K), KC_TRNS, KC_TRNS, LCMD(LCTL(LSFT(KC_4))), LCMD(LSFT(KC_4)), KC_TRNS,           KC_TRNS, 
        LCMD(LOPT(KC_I)), KC_TRNS, KC_TRNS, KC_TRNS,                     KC_SPC, KC_TRNS,                                       KC_TRNS, KC_TRNS, KC_TRNS
    ),
*/
/*

[COMMAND] = LAYOUT_alice_split_bs(
    KC_TRNS, KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,          KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PAUS, KC_UP,   KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_LEFT, KC_RGHT,          KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_END,  KC_DOWN, KC_TRNS, KC_TRNS,
             KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS,                 KC_TRNS,          KC_TRNS,                            KC_TRNS)
};
*/


