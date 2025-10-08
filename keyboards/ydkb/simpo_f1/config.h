
#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define FW_VER_DATE DP3F
#define CONTACT(x, y) x##y
#define CONTACT2(x, y) CONTACT(x, y)
#define FW_VER CONTACT2(VIAL_, FW_VER_DATE)
#if CONSOLE_ENABLE
#    define PRODUCT Simpo_F1 Uni Debug(FW_VER)
#else
#    define PRODUCT Simpo_F1 Uni(FW_VER)
#endif

#define WAIT_FOR_USB
#define RGBLED_NUM 79
/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 15
// #define FORCE_NKRO //When FORCE_NKRO, Enable NKRO in QMK Settings will not be saved

#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_TWINKLE
#define RGBLIGHT_DEFAULT_MODE 7 // defaut: RAINBOW_MOOD

#define RGBLIGHT_SLEEP
#define RGB_DI_PIN A7

#define DRIVER_LED_TOTAL must_redefine

// #define SUSPEND_ACTION
