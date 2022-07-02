#include QMK_KEYBOARD_H


#define QWERTY 0 // Base qwerty

// MacOS Home and End (Modify iTerm Key: LCMD + LEFT -> Hex Code 001 and LCMD + RIGHT -> Hex Code 005)
#define MAC_HOME LCMD(KC_LEFT)
#define MAC_END  LCMD(KC_RGHT)

// Shift keys send parentheses on tap and act as Shift on hold.
// Note that these match the definition from the built-in Space Caded, which we have disabled here.
// #define KC_LSPO LSFT_T(KC_LPRN)  //  LSFT on hold, KC_LPRN on tap
// #define KC_RSPC RSFT_T(KC_RPRN)  //  RSFT on hold, KC_RPRN on tap

// Command keys send curly braces on tap and act as Command on hold.
#define KC_LCBO LCMD_T(KC_LCBR)  //  LCMD on hold, KC_LCBR on tap
#define KC_RCBC RCMD_T(KC_RCBR)  //  RCMD on hold, KC_RCBR on tap

/****************************************************************************************************
*
* Keymap: Default Layer in Qwerty
*
* ,-------------------------------------------------------------------------------------------------------------------.
* | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F12 | PSCR | SLCK | PAUS |  FN0 |  BOOT  |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* | =+     |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8*  |  9(  |  0)  | -_     |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* | Tab    |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  | \|     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | CAPSWRD|   A  |   S  |   D  |   F  |   G  |                           |   H  |   J  |   K  |   L  |  ;:  | '"     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Shift (|   Z  |   X  |   C  |   V  |   B  |                           |   N  |   M  |  ,.  |  .>  |  /?  | Shift )|
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          | `~   | INS  | Left | Right|                                         | Up   | Down |  [{  |  ]}  |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | Cmd {| Alt  |         | Ctrl | Cmd }|
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | Home |         | PgUp |      |      |
*                                 | BkSp | Del  |------|         |------|Return| Space|
*                                 |      |      | End  |         | PgDn |      |      |
*                                 `--------------------'         `--------------------'
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [QWERTY] = LAYOUT_pretty(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,         KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_SLCK,  KC_PAUS,  KC_NO,    QK_BOOT,
    KC_EQL,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                                                                      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                                                                      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
    CAPSWRD,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                                                                      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSPO,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                                                                      KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSPC,
              KC_GRV,   KC_INS,   KC_LEFT,  KC_RGHT,                                                                                       KC_UP,    KC_DOWN,  KC_LBRC,  KC_RBRC,
                                                      KC_LCBO,  KC_LALT,                                               KC_RCTL,  KC_RCBC,
                                                                MAC_HOME,                                              KC_PGUP,
                                            KC_BSPC,  KC_DEL,   MAC_END,                                               KC_PGDN,  KC_ENTER, KC_SPC
  )

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
    case KC_LCBO:  // LCMD on hold, KC_LCBR on tap.
      if (record->tap.count && record->event.pressed) {
        tap_code16(KC_LCBR);
        return false;
      }
      break;
    case KC_RCBC:  //  RCMD on hold, KC_RCBR on tap.
      if (record->tap.count && record->event.pressed) {
        tap_code16(KC_RCBR);
        return false;
      }
      break;
    // case KC_LSPO: //  LSFT on hold, KC_LPRN on tap
    //   if (record->tap.count && record->event.pressed) {
    //     tap_code16(KC_LPRN);
    //     return false;
    //   }
    //   break;
    // case KC_RSPC: //  LSFT on hold, KC_RPRN on tap
    //   if (record->tap.count && record->event.pressed) {
    //     tap_code16(KC_RPRN);
    //     return false;
    //   }
    //   break;
	}

	return true;  // Return true to allow further processing of key.
}

// Returns per key term.
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_LCBO:
    case KC_RCBC:
    case KC_LSPO:
    case KC_RSPC:
      return 125;  // The default is 200ms.
    default:
      return TAPPING_TERM;
  }
}

void set_led(int pin, bool active) {
  // Write LED_PIN_ON_STATE or inverse of it.
  writePin(pin, active ? LED_PIN_ON_STATE : !LED_PIN_ON_STATE);
}

void set_led_1(bool active) {
  set_led(LED_1_PIN, active);
}

void set_led_2(bool active) {
  set_led(LED_2_PIN, active);
}

void set_led_3(bool active) {
  set_led(LED_3_PIN, active);
}

void set_led_4(bool active) {
  set_led(LED_4_PIN, active);
}

// User callback for Caps Word mode.
void caps_word_set_user(bool active) {
  set_led_1(active);
}

// Callback for keyboard initialization.
void keyboard_pre_init_user() {
  setPinOutput(LED_1_PIN);
  set_led(LED_1_PIN, false);
  setPinOutput(LED_2_PIN);
  set_led(LED_2_PIN, false);
  setPinOutput(LED_3_PIN);
  set_led(LED_3_PIN, false);
  setPinOutput(LED_4_PIN);
  set_led(LED_4_PIN, false);
}

