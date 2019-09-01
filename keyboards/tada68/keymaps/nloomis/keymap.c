#include QMK_KEYBOARD_H

/* helpful shortcuts to know
KC_CAPS - caps lock
KC_PSCR - print screen
KC_BRMD - brightness down (mac)
KC_BRMU - brightness up (mac)
KC_UP - up arrow
KC_CUT, KC_COPY, KC_PASTE -- do these work?
KC__MUTE, KC__VOLUP, KC_VOLDOWN - mute, volume up, mac
KC_LCTL - left control
KC_LSHIFT, KC_LSFT - left shift
KC_LGUI - left gui (KC_LCMD alias)
DEBUG - toggler debug mode
KC_GESC - escape/grave
KC_LSPO, KC_RSPC - space cadet (?)
BL_TOGG - toggle keyboard backlight
BL_INC, BL_DEC - increase, decrease keyboard backlight
MO(layer) - momentarily switch layer when pressed
OSL(layer) - one-shot layer switching, until another key is pressed
LM(layer, mod) - momentary layer switch with MOD_* active
LT(layer, kc) - layer when held, kc when tapped
LCTL(kc), LSFT(kc), LATL(kc), LGUI(kc) - modifiers
MT(mod, kc) - mod when held, kc when tapped
LSFT_T(kc) - left shift when held, kc when tapped
OSM(mod) - one shot, apply MOD to next keypress
*/


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0  // base layer
#define _FL 1  // fn layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * Left shift: space cadet
   * Right shift: space cadet
   * Caps: ctrl-up when tapped (show all windows)
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |~ ` |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
   * |----------------------------------------------------------------|
   * |Shift/( |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space          |Alt| FN|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_BL] = LAYOUT_ansi(
  KC_ESC,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,  KC_EQL, KC_BSPC,  KC_GRV,  \
  KC_TAB,    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS, KC_DEL,  \
  LCTL(KC_UP), KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN, KC_QUOT,     KC_ENT,   KC_PGUP, \
  KC_LSPO,       KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH,   KC_RSPC,  KC_UP,  KC_PGDN, \
  KC_LCTL, KC_LGUI,KC_LALT,                KC_SPC,                        KC_RALT,MO(_FL), KC_RCTRL, KC_LEFT, KC_DOWN, KC_RGHT),

  /* Keymap _FL: Function Layer
   * M: Mute
   * <: volume down
   * >: volume up
   * Del: keyboard backlight toggle
   * PgUp: keyboard backlight up
   * PgDn: keyboard backlight down
   * up: brightness up
   * dn: brightness down
   * WASD: more arrows
   * Caps: Control-down (show all windows for current app)
   * ,----------------------------------------------------------------.
   * |   | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Ins |
   * |----------------------------------------------------------------|
   * |     |   |Up |   |   |   |   |   |   |   |   |   |   |     |Hme |
   * |----------------------------------------------------------------|
   * |      |<- |Dn | ->|   |   |   |   |   |   |   |   |        |End |
   * |----------------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |   McL|MsU|McR |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |MsL|MsD|MsR |
   * `----------------------------------------------------------------'
   */
[_FL] = LAYOUT_ansi(
  _______,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,    KC_INS ,  \
  _______,_______, KC_UP,_______,_______, _______,_______,_______,_______,_______,_______,_______,_______, _______,BL_TOGG, \
  LCTL(KC_DOWN), KC_LEFT,KC_DOWN,KC_RIGHT,_______,_______,_______,_______,_______,_______,_______,_______,        _______,BL_INC, \
  _______,_______,_______,_______, _______,_______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______,_______, KC_BRIU, BL_DEC, \
  _______,_______,_______,                 _______,                _______,_______,_______,_______, KC_BRID, _______),
};

/*KC_VOLD
KC_VOLU
KC_MUTE
KC_BRIU - screen brightness up
KC_BRID
*/