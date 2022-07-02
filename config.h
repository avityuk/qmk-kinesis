#pragma once

// Activate Command with Left Cmd + Right Cmd.
#define IS_COMMAND() (get_mods() == MOD_MASK_GUI)

// Activate Caps Word on Left Shift + Right Shift.
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// Enable per key tapping term configuration.
#define TAPPING_TERM_PER_KEY

// Disable Auto Shift for alpha keys.
#define NO_AUTO_SHIFT_ALPHA

// Enable Mod Tap Interrupt
#undef IGNORE_MOD_TAP_INTERRUPT


// // Use the standard LEDs for custom needs.
#define LED_1_PIN LINE_PIN12
#define LED_2_PIN LINE_PIN24
#define LED_3_PIN LINE_PIN25
#define LED_4_PIN LINE_PIN26
// Bind the standard LEDs to unused pin.
#undef LED_NUM_LOCK_PIN
#undef LED_CAPS_LOCK_PIN
#undef LED_SCROLL_LOCK_PIN
#undef LED_COMPOSE_PIN
#undef LED_KANA_PIN
