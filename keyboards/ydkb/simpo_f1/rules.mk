# project specific files
SRC ?=	matrix.c led.c

# MCU name
MCU = STM32F103

# Bootloader selection
MCU_LDSCRIPT = STM32F103CBT6_uf2_bootloader
BOOTLOADER = custom

# Build Options
#   change yes to no to disable
#
CUSTOM_MATRIX           = yes # Custom matrix file
#CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
SLEEP_LED_ENABLE = no


# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
OPT_DEFS += -DCORTEX_VTOR_INIT=0x4000

VPATH += keyboards/ydkb/00common
