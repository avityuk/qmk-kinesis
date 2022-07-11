#include QMK_KEYBOARD_H


#define BASE  0  // Base qwerty layer
#define NAV   1  // Navigation layer
#define BLANK 2  // Just a blank layer for easier copy-paste

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

// Z/slash send LCTRL/RCTRL on hold.
#define KC_ZCTL LCTL_T(KC_Z)      //  LCTL on hold, KC_Z on tap
#define KC_SLCTL RCTL_T(KC_SLSH)  // RCTL on hold, KC_SLSH on tap

// Text editing shortcuts.
#define KC_CMDX LT(0, KC_X)  // Cmd+X on hold, X on tap.
#define KC_CMDC LT(0, KC_C)  // Cmd+C on hold, C on tap.
#define KC_CMDV LT(0, KC_V)  // Cmd+V on hold, V on tap.
#define KC_CMDF LT(0, KC_F)  // Cmd+F on hold, F on tap.
#define KC_CMDS LT(0, KC_S)  // Cmd+S on hold, S on tap.

enum custom_keycodes {
  COMMAND = SAFE_RANGE,  // Command keycode.
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /****************************************************************************************************
  *
  * Keymap 0: Base layer (qwerty)
  *
  * ,-------------------------------------------------------------------------------------------------------------------.
  * | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F12 | PSCR | SLCK | PAUS |  FN0 | COMMAND|
  * |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
  * | =+     |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8*  |  9(  |  0)  | -_     |
  * |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
  * | Tab    |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  | \|     |
  * |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
  * |Toggle 1|   A  |(Cmd)S|   D  |(Cmd)F|   G  |                           |   H  |   J  |   K  |   L  |  ;:  | '"     |
  * |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
  * | Shift  |Z Ctrl|(Cmd)X|(Cmd)C|(Cmd)V|   B  |                           |   N  |   M  |  ,.  |  .>  |/?Ctrl| Shift  |
  * `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
  *          | `~   | INS  | Left | Right|                                         |  Up  | Down |  [{  |  ]}  |
  *          `---------------------------'                                         `---------------------------'
  *                                        ,-------------.         ,-------------.
  *                                        | Cmd  | Alt  |         | Ctrl | Cmd  |
  *                                 ,------|------|------|         |------+------+------.
  *                                 |      |      | Home |         | PgUp |      |      |
  *                                 | BkSp | Del  |------|         |------|Return| Space|
  *                                 |      |      | End  |         | PgDn |      |      |
  *                                 `--------------------'         `--------------------'
  */
  [BASE] = LAYOUT_pretty(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,         KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_SLCK,  KC_PAUS,  KC_NO,    COMMAND,
    KC_EQL,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                                                                      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                                                                      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
    TG(NAV),  KC_A,     KC_CMDS,  KC_D,     KC_CMDF,  KC_G,                                                                      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,  KC_ZCTL,  KC_CMDX,  KC_CMDC,  KC_CMDV,  KC_B,                                                                      KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLCTL, KC_RSFT,
              KC_GRV,   KC_INS,   KC_LEFT,  KC_RGHT,                                                                                       KC_UP,    KC_DOWN,  KC_LBRC,  KC_RBRC,
                                                      KC_LCMD,  KC_LALT,                                               KC_RCTL,  KC_RCMD,
                                                                MAC_HOME,                                              KC_PGUP,
                                            KC_BSPC,  KC_DEL,   MAC_END,                                               KC_PGDN,  KC_ENTER, KC_SPC
  ),
  /****************************************************************************************************
  *
  * Keymap 1: Navigation layer
  * Note: Scroll down and up are inverted because of MacOS.
  *
  * ,-------------------------------------------------------------------------------------------------------------------.
  * |        |      |      |      |      |      |      |      |      |      |      |      |      |      |      |        |
  * |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
  * | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |                           |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
  * |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
  * | Tab    |      |      | M Up |      |      |                           | SC D | SC L |  Up  | SC R |      |   F12  |
  * |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
  * |Toggle 1|      |M Left|M Down|M Rght|      |                           | SC U | Left | Down | Right|      |        |
  * |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
  * |        |      |      |      |      |      |                           |      |      |      |      |      |        |
  * `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
  *          |      |      |      |      |                                         |      |      |      |      |
  *          `---------------------------'                                         `---------------------------'
  *                                        ,-------------.         ,-------------.
  *                                        | L CK |      |         |      | R CK |
  *                                 ,------|------|------|         |------+------+------.
  *                                 |      |      | Home |         | PgUp |      |      |
  *                                 | BkSp | Del  |------|         |------|Return| Space|
  *                                 |      |      | End  |         | PgDn |      |      |
  *                                 `--------------------'         `--------------------'
  */
  [NAV] = LAYOUT_pretty(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,       _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                                                                     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
    _______,  XXXXXXX,  XXXXXXX,  KC_MS_U,  XXXXXXX,  XXXXXXX,                                                                   KC_WH_D,  KC_WH_L,  KC_UP,    KC_WH_R,  XXXXXXX,  KC_F12,
    TG(NAV),  XXXXXXX,  KC_MS_L,  KC_MS_D,  KC_MS_R,  XXXXXXX,                                                                   KC_WH_U,  KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                                                                   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,
              XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                                                                                       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                                      KC_BTN1,  XXXXXXX,                                               XXXXXXX,  KC_BTN2,
                                                                _______,                                               _______,
                                            _______,  _______,  _______,                                               _______,  _______,  _______
  ),
  /****************************************************************************************************
  *
  * Keymap 2: Blank layer
  *
  * ,-------------------------------------------------------------------------------------------------------------------.
  * |        |      |      |      |      |      |      |      |      |      |      |      |      |      |      |        |
  * |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
  * |        |      |      |      |      |      |                           |      |      |      |      |      |        |
  * |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
  * |        |      |      |      |      |      |                           |      |      |      |      |      |        |
  * |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
  * |        |      |      |      |      |      |                           |      |      |      |      |      |        |
  * |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
  * |        |      |      |      |      |      |                           |      |      |      |      |      |        |
  * `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
  *          |      |      |      |      |                                         |      |      |      |      |
  *          `---------------------------'                                         `---------------------------'
  *                                        ,-------------.         ,-------------.
  *                                        |      |      |         |      |      |
  *                                 ,------|------|------|         |------+------+------.
  *                                 |      |      |      |         |      |      |      |
  *                                 |      |      |------|         |------|      |      |
  *                                 |      |      |      |         |      |      |      |
  *                                 `--------------------'         `--------------------'
  */
  [BLANK] = LAYOUT_pretty(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,       _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,                                                                   _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,                                                                   _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,                                                                   _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,                                                                   _______,  _______,  _______,  _______,  _______,  _______,
              _______,  _______,  _______,  _______,                                                                                       _______,  _______,  _______,  _______,
                                                      _______,  _______,                                               _______,  _______,
                                                                _______,                                               _______,
                                            _______,  _______,  _______,                                               _______,  _______,  _______
  ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
    case KC_LCBO:  // LCMD on hold, KC_LCBR on tap.
      if (record->tap.count && record->event.pressed) {
        tap_code16(KC_LCBR);
        return false;
      }
      return true;
    case KC_RCBC:  //  RCMD on hold, KC_RCBR on tap.
      if (record->tap.count && record->event.pressed) {
        tap_code16(KC_RCBR);
        return false;
      }
      return true;
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
    case COMMAND:
      if (record->event.pressed) {
        register_code(KC_LCMD);
        register_code(KC_RCMD);
      } else {
        unregister_code(KC_LCMD);
        unregister_code(KC_RCMD);
      }
      return true;
    case KC_CMDX:  // Cmd+X on hold, X on tap.
      if (!record->tap.count && record->event.pressed) {
        tap_code16(LCMD(KC_X));
        return false;
      }
      return true;
    case KC_CMDC:  // Cmd+C on hold, C on tap.
      if (!record->tap.count && record->event.pressed) {
        tap_code16(LCMD(KC_C));
        return false;
      }
      return true;
    case KC_CMDV:  // Cmd+V on hold, V on tap.
      if (!record->tap.count && record->event.pressed) {
        tap_code16(LCMD(KC_V));
        return false;
      }
      return true;
    case KC_CMDF:  // Cmd+F on hold, F on tap.
      if (!record->tap.count && record->event.pressed) {
        tap_code16(LCMD(KC_F));
        return false;
      }
      return true;
    case KC_CMDS:  // Cmd+S on hold, S on tap.
      if (!record->tap.count && record->event.pressed) {
        tap_code16(LCMD(KC_S));
        return false;
      }
      return true;
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
      return 125;
    case KC_CMDX:
    case KC_CMDC:
    case KC_CMDV:
    case KC_CMDF:
    case KC_CMDS:
      return 500;
    default:
      return TAPPING_TERM;  // The default is 200ms.
  }
}

// Returns per key mod tap interrupt.
bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_ZCTL:
    case KC_SLCTL:
      return true;
    default:
#ifdef IGNORE_MOD_TAP_INTERRUPT
      return true;
#else
      return false;
#endif
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

layer_state_t layer_state_set_user(layer_state_t state) {
  set_led_3(layer_state_cmp(state, NAV));
  return state;
}

