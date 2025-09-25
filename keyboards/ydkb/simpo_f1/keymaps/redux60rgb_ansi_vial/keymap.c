#include "config.h"
#include QMK_KEYBOARD_H

enum layer_names {
  _BASE,
  _RAISE,
  _LOWER
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* _BASE Layer: Standard typing
 * ,---------------------------------------------------------------------------------.
 * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |Del|Bsp|
 * |---------------------------------------------------------------------------------|
 * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |  \  |
 * |---------------------------------------------------------------------------------|
 * | Caps   |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  | Enter   |
 * |---------------------------------------------------------------------------------|
 * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | Shift     |
 * |---------------------------------------------------------------------------------|
 * | Lower | Win | Alt |          Space          | Raise | Win | Fn  | Ctl |
 * `---------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_60_ansi(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
  KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
  KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
  MO(_LOWER), KC_LGUI, KC_LALT,          KC_SPC,                           MO(_RAISE), KC_RGUI, KC_APP,  KC_RCTL
),

/* _RAISE Layer: Navigation, F-keys, Symbols
 * ,---------------------------------------------------------------------------------.
 * |  `  | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |TRNS|TRNS|
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
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
  _______, KC_NO,   KC_NO,   KC_LPRN, KC_RPRN, KC_NO,   KC_NO,   KC_PGUP, KC_UP,   KC_PGDN, KC_NO,   KC_NO,   KC_NO,   _______,
  _______, KC_HOME, KC_END,  KC_LCBR, KC_RCBR, KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,   KC_NO,            _______,
  _______,          KC_NO,   KC_NO,   KC_LBRC, KC_RBRC, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            _______,
  _______, _______, _______,          _______,                          _______, _______, _______, _______
),

/* _LOWER Layer: System, Media, RGB Control
 * ,---------------------------------------------------------------------------------.
 * |RESET|TRNS |TRNS |TRNS |TRNS |TRNS |TRNS |TRNS |TRNS |TRNS |TRNS |TRNS |TRNS |TRNS|TRNS|
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
  RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLU, KC_VOLD, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______,          _______,
  _______,          RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______,          _______,
  _______, _______, _______,          _______,                          _______, _______, _______, _______

)
};

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
    // Key Matrix to LED Index
  { 0,       1,      2,      3,      4,      5,      6,      7,      8,      9,     10,     11,     12,     13 },
  { 27,     26,     25,     24,     23,     22,     21,     20,     19,     18,     17,     16,     15,     14 },
  { 28,     29,     30,     31,     32,     33,     34,     35,     36,     37,     38,     39, NO_LED,     40 },
  { 52,     51,     50,     49,     48,     47,     46,     45,     44,     43,     42,     41, NO_LED, NO_LED },
  { 53,     54,     55, NO_LED, NO_LED,     56, NO_LED, NO_LED, NO_LED,     57,     58,     59, NO_LED,     60 }
}, {
    // LED Index to Physical Position
    // x = 224 / (NUMBER_OF_COLS - 1) * COL_POSITION
    // y =  64 / (NUMBER_OF_ROWS - 1) * ROW_POSITION
    {   0,  12 }, {  13,  12 }, {  26,  12 }, {  39,  12 }, {  52,  12 }, {  65,  12 }, { 78,  12 }, { 91,  12 }, { 104,  12 }, { 117,  12 }, { 130,  12 }, { 143,  12 }, { 156,  12 }, { 169,  12 }, 
    { 169,  24 }, { 156,  24 }, { 143,  24 }, { 130,  24 }, { 117,  24 }, { 104,  24 }, { 91,  24 }, { 78,  24 }, {  65,  24 }, {  52,  24 }, {  39,  24 }, {  26,  24 }, {  13,  24 }, {   0,  24 }, 
    {   0,  36 }, {  13,  36 }, {  26,  36 }, {  39,  36 }, {  52,  36 }, {  65,  36 }, { 78,  36 }, { 91,  36 }, { 104,  36 }, { 117,  36 }, { 130,  36 }, { 143,  36 },               { 169,  36 },
    { 169,  48 }, { 130,  48 }, { 117,  48 }, { 104,  48 }, {  91,  48 }, {  78,  48 }, { 65,  48 }, { 52,  48 }, {  39,  48 }, {  26,  48 }, {  13,  48 }, {   0,  48 },                            
    {   0,  64 }, {  13,  64 }, {  26,  64 },                             {  78,  64 },                                         { 130,  64 }, { 143,  64 }, { 156,  64 },               { 169,  64 }, 

    { 169,  48 }, { 143,  48 }, { 117,  48 }, {  91,  48 }, { 65,  48 }, {  39,  48 },  {  13,  48 },  {  0,  48 }, {   0,  36 }, 
    {   0,  12 }, {  26,  12 }, {  52,  12 }, {  78,  12 }, { 104,  12 },{ 130,  12 },  { 156,  12 }, { 169,  12 }, { 169,  36 }
}, {
    // LED Index to Flag
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,     
    4, 4, 4,       4,          4, 4, 4,    4,
    
    2, 2, 2, 2, 2, 2, 2,  2, 
    2,                      2, 
    2, 2, 2, 2, 2, 2, 2, 2, 
} };

extern LED_TYPE indicator_color[3];
extern uint8_t indicator_color_config[];
__attribute__ ((weak))
void rgb_matrix_indicators_user(void) {
    if (indicator_color_config[1] & 0b10) { //Swithes Only
        for (uint8_t i=0; i<61; i++) {
            rgb_matrix_set_color(i, 0, 0, 0); 
        }
    }
    if (indicator_color_config[1] & 0b1) { //Underglow Only
        for (uint8_t i=61; i<(61+18); i++) {
            rgb_matrix_set_color(i, 0, 0, 0); 
        }
    }
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(28, indicator_color[0].r, indicator_color[0].g, indicator_color[0].b);
    }
    if (rgb_matrix_config.enable == 0) {
        if (host_keyboard_led_state().caps_lock == 0) {
            rgb_matrix_set_color(28, 0, 0, 0);
        }
        rgb_matrix_update_pwm_buffers();
    }
}
#endif
