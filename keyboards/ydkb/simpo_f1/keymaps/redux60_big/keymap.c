#include "config.h"
#include QMK_KEYBOARD_H
#include "matrix_led.c"

enum layer_names {
  _BASE,
  _RAISE,
  _LOWER
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* _BASE Layer: Standard typing
 * ,---------------------------------------------------------------------------------.
 * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |BSPC|
 * |---------------------------------------------------------------------------------|
 * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |  \  |
 * |---------------------------------------------------------------------------------|
 * | Caps   |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  | Enter   |
 * |---------------------------------------------------------------------------------|
 * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | Shift     |
 * |---------------------------------------------------------------------------------|
 * | LCTL | Win | Alt |          Space          | Raise | Win | Fn  | Ctl |
 * `---------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_60_ansi(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
  KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
  KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
  KC_LCTL, KC_LGUI, KC_LALT,          KC_SPC,                          MO(_LOWER), MO(_RAISE), KC_APP,  KC_RCTL
),
     
/* _RAISE Layer: Navigation, F-keys, Symbols
 * ,---------------------------------------------------------------------------------.
 * |  `  | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |TRNS|
 * |---------------------------------------------------------------------------------|
 * | TRNS   |TRNS |TRNS |  (  |  )  |TRNS |TRNS | PgUp| Up  | PgDn|TRNS |TRNS |TRNS |TRNS |
 * |---------------------------------------------------------------------------------|
 * | TRNS   | Home| End |  {  |  }  |TRNS |TRNS | Left|Down |Right|TRNS |TRNS | Enter   |
 * |---------------------------------------------------------------------------------|
 * | TRNS      |TRNS |TRNS |  [  |  ]  |TRNS |TRNS |TRNS |TRNS |TRNS |TRNS | Shift     |
 * |---------------------------------------------------------------------------------|
 * | TRNS  |TRNS |TRNS |          TRNS           | TRNS  |TRNS |TRNS |TRNS |
 * `---------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_60_ansi(
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
  _______, KC_NO,   KC_NO,   KC_LPRN, KC_RPRN, KC_NO,   KC_NO,   KC_PGUP, KC_UP,   KC_PGDN, KC_NO,   KC_NO,   KC_NO,   _______,
  _______, KC_HOME, KC_END,  KC_LCBR, KC_RCBR, KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,   KC_NO,            _______,
  _______,          KC_NO,   KC_NO,   KC_LBRC, KC_RBRC, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            _______,
  _______, _______, _______,          _______,                          _______, _______, _______, _______
),

/* _LOWER Layer: System, Media, RGB Control
 * ,---------------------------------------------------------------------------------.
 * |RESET|TRNS |TRNS |TRNS |TRNS |TRNS |TRNS |TRNS |TRNS |TRNS |TRNS |TRNS |TRNS |TRNS
 * |---------------------------------------------------------------------------------|
 * | TRNS   |TRNS |TRNS |TRNS |TRNS |TRNS |TRNS | Mute|VolU |VolD |TRNS |TRNS |TRNS |TRNS |
 * |---------------------------------------------------------------------------------|
 * | TRNS   |TRNS |TRNS |TRNS |TRNS |TRNS | Prev|Play/Pause|Next|TRNS |TRNS | Enter   |
 * |---------------------------------------------------------------------------------|
 * | TRNS      |RGB T|RGB M|RGB H|RGB S|RGB V|TRNS |TRNS |TRNS |TRNS |TRNS | Shift     |
 * |---------------------------------------------------------------------------------|
 * | TRNS  |TRNS |TRNS |          TRNS           | TRNS  |TRNS |TRNS |TRNS |
 * `---------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_60_ansi(
  RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
  _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLU, KC_VOLD, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______,          _______,
  _______,          RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______,          _______,
  _______, _______, _______,          _______,                          _______, _______, _______, _______

)
};

