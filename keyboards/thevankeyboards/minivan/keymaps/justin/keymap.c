#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _QW 0
#define _DV 1
#define _CM 2
#define _L1 3
#define _L2 4
#define _L3 5

// Curly braces have their own keys. These are defined to make them not mess up
// the grid in layer 2.
#define L_CURBR LSFT(KC_LBRC)
#define R_CURBR LSFT(KC_RBRC)

 // JR Custon Key Define Block - start here
#define MDASH LSFT(LALT(KC_MINS))
#define TRIG LSFT(LALT(LGUI(KC_ENTER)))
#define ARRCLN LT(4, KC_SCLN)
#define ENTL1 LT(1, KC_ENT)
#define BSPC3 LT(3, KC_BSPC)
#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)
#define UNDO LGUI(KC_Z)
#define REDO LGUI(LSFT(KC_V))
#define SELALL LGUI(KC_A)
#define LWORD LALT(KC_LEFT)
#define RWORD LALT(KC_RIGHT)
#define BOLD LGUI(KC_B)
#define ITAL LGUI(KC_I)
#define UNDER LGUI(KC_U)
#define FIND LGUI(KC_F)
#define NEW LGUI(KC_N)
#define SAVE LGUI(KC_S)
#define SAVEAS LALT(LSFT(LGUI(KC_S)))
#define RELOAD LGUI(KC_R)
#define NTAB LGUI(KC_T)
#define QUIT LGUI(KC_Q)
#define CMD KC_LGUI
#define OPT KC_LALT
#define BSPC KC_BSPC
#define ENT KC_ENTER
#define SPC KC_SPC
#define MWD KC_MS_WH_DOWN
#define MWU KC_MS_WH_UP
#define CONTESC MT(MOD_LCTL, KC_ESC)
#define ADJESC LT(3, KC_ESC)







enum macro_keycodes {
  KC_SAMPLEMACRO,
};


LEADER_EXTERNS();
void matrix_scan_user(void) {
  
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();
   
    SEQ_ONE_KEY(KC_C) {
      SEND_STRING("(CONT'D)");
    }

      SEQ_ONE_KEY(KC_V) {
      SEND_STRING("(V.O.)");
    }

      SEQ_ONE_KEY(KC_P) {
      SEND_STRING("PRE-LAP");
    }

     SEQ_ONE_KEY(KC_T) {
      SEND_STRING("CUT TO:");
    }

     SEQ_ONE_KEY(KC_O) {
      SEND_STRING("(O.S.)");
    }

     SEQ_ONE_KEY(KC_B) {
      SEND_STRING("(V.O., CONT'D)");
    }
  
   
  }
}


// END JR CUSTOM BLOCK. STOP PASTE HERE.

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  QWERTY,
  COLEMAK
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( /* Qwerty */
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
    KC_LEAD, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    LT(4, KC_SCLN), KC_QUOT,
    KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
    KC_LCTL, KC_LALT, KC_LGUI,                   KC_BSPC,  KC_SPC,                    KC_ENT, MO(1),  MO(2)
  ),
  [_DV] = LAYOUT( /* Dvorak */
    KC_ESC,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,   KC_6,    KC_7,    KC_8,     KC_9,  KC_0, MDASH,
    KC_CAPS, MO(4), KC_NO, KC_NO, KC_NO, KC_NO,                KC_LEFT,KC_DOWN,KC_UP, KC_RIGHT,KC_PLUS, KC_EQUAL,
    KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_RSFT,
    KC_LCTL, LWORD, RWORD,                   KC_ENT,  KC_SPC,                    KC_RALT, KC_NO,  KC_NO
  ),
  [_CM] = LAYOUT( /* Colemak */
    RESET,KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC,              KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_PLUS,
    KC_LCTL, MO(4), KC_NO, KC_NO, KC_NO, KC_NO,                KC_MINS,KC_EQL,KC_LCBR,KC_RCBR,KC_PIPE,KC_GRV,
    KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                KC_UNDS,KC_PLUS,KC_LBRC,KC_RBRC,KC_BSLS,KC_TILD,
    KC_LCTL, KC_LALT, KC_LGUI,                   KC_BSPC,  KC_SPC,                    KC_ENT, MO(1),  MO(2)
  ),
  [_L1] = LAYOUT( /* LAYER 1 */
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    _______, KC_BSLS, KC_QUOT, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_DOWN, KC_UP,   KC_LEFT, KC_RGHT, _______,
    _______, KC_ESC,  _______, KC_PSCR, _______, _______, _______, KC_MSTP, KC_MPLY, KC_MPRV, KC_MNXT, KC_RSFT,
    _______, KC_LGUI, _______,                   _______, _______,                   _______, _______, _______
  ),
  [_L2] = LAYOUT( /* LAYER 2 */
  RESET, KC_TRNS, KC_TRNS, KC_MS_UP, KC_MS_WH_DOWN, KC_MS_WH_DOWN,                  KC_PGUP, KC_PGUP, KC_UP, KC_NO, KC_NO, KC_NO,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
   KC_TRNS, MO(4), KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_TRNS,                 KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO, KC_NO,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
   KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_WH_UP, KC_MS_WH_UP,                 KC_PGDOWN, KC_PGDOWN, KC_NO, KC_NO, KC_NO, KC_RSFT,
   KC_LCTL, KC_LALT, KC_LGUI,                   KC_BSPC,  KC_SPC,                    KC_ENT, MO(1),  MO(2)
  ),
  [_L3] = LAYOUT( /* LAYER 3 */
    _______, _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,
    KC_ESC,  _______, _______, _______, _______, _______, _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,
    KC_LSFT, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
    _______, KC_LSFT, KC_B,                      KC_SPC,  KC_C,                      _______, _______, _______
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
      switch(keycode) {
        case DVORAK:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_DV);
          }
          return false;
        case QWERTY:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_QW);
          }
          return false;
        case COLEMAK:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_CM);
          }
          return false;
        default:
          return true;
      }
    return true;
};
