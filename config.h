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


// Use the standard LEDs for custom needs.
#define LED_1_PIN LED_NUM_LOCK_PIN
#define LED_2_PIN LED_CAPS_LOCK_PIN
#define LED_3_PIN LED_SCROLL_LOCK_PIN
#define LED_4_PIN LED_COMPOSE_PIN
// Bind the standard LEDs to unused pin.
#undef LED_NUM_LOCK_PIN
#define LED_NUM_LOCK_PIN LINE_PIN33
#undef LED_CAPS_LOCK_PIN
#define LED_CAPS_LOCK_PIN LINE_PIN33
#undef LED_SCROLL_LOCK_PIN
#define LED_SCROLL_LOCK_PIN LINE_PIN33
#undef LED_COMPOSE_PIN
#define LED_COMPOSE_PIN LINE_PIN33
