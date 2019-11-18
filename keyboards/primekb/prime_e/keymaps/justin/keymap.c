/* Copyright 2018 Holten Campbell
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

 // JR Custon Key Define Block - start here
#define MDASH LSFT(LALT(KC_MINS))
#define TRIG LSFT(LALT(LGUI(KC_ENTER)))
#define ARRCLN LT(3, KC_SCLN)
#define ENTL2 LT(2, KC_ENT)
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(
		KC_TAB,     KC_Q,     KC_W,       KC_E,     KC_R,       KC_T,             KC_Y,       KC_U,     KC_I,     KC_O,       KC_P,       KC_MINS, KC_EQUAL,
		KC_LEAD,    KC_A,     KC_S,       KC_D,     KC_F,       KC_G,             KC_H,       KC_J,     KC_K,     KC_L,       ARRCLN,     KC_QUOT,
		KC_LSPO,    KC_Z,     KC_X,       KC_C,     KC_V,       KC_B,             MO(1),      KC_N,     KC_M,     KC_COMM,    KC_DOT,     KC_SLSH, KC_RSPC,
		KC_LCTL,    KC_LALT,                        CMD,        BSPC,	            SPC,        ENTL2,                                      LWORD,   RWORD
    ),

    LAYOUT(
		RESET,     KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,     KC_PERC,          KC_CIRC,   KC_AMPR,    KC_ASTR,   KC_LPRN,   KC_RPRN,   KC_VOLD,   KC_VOLU,
		KC_CAPS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,          KC_TRNS,   KC_LEFT,    KC_DOWN,   KC_RIGHT,  KC_SCLN,   KC_MUTE,
		KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,          KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_MPLY,
		MWD,   MWU,                         KC_TRNS,    KC_TRNS,	        KC_TRNS,   KC_TRNS,                                     KC_MPRV,   KC_MNXT
    ),

    LAYOUT(
		KC_ESC,   KC_1,      KC_2,      KC_3,      KC_4,       KC_5,             KC_6,      KC_7,     KC_8,    KC_9,    KC_0,      MDASH,  TRIG,
		KC_CAPS,  KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,     KC_PERC,          KC_CIRC,   KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN,   KC_PLUS,
		KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,          KC_TRNS,   KC_P1,    KC_P2,   KC_P3,   KC_TRNS,   KC_TRNS,  KC_TRNS,
		KC_TRNS,  KC_TRNS,                         KC_TRNS,    KC_TRNS,	         KC_PENT,   KC_PDOT,                               KC_TRNS,  KC_TRNS
    ),

    LAYOUT(
		KC_TRNS,  KC_F1,     KC_F2,     KC_F3,     KC_F4,      KC_F5,            KC_PGUP,   KC_PGUP,  KC_UP,   KC_NO,   KC_F10,    KC_F11,   KC_F12,
		KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,          KC_NO,     KC_LEFT,  KC_DOWN, KC_RIGHT, KC_TRNS,   KC_TRNS,
		KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,          KC_PGDOWN, KC_PGDOWN,  KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,
		KC_TRNS,  KC_TRNS,                         KC_TRNS,    KC_TRNS,	         KC_TRNS,   KC_TRNS,                               KC_TRNS,  KC_TRNS
    )
};

void matrix_init_user(void) {
  // set CapsLock LED to output and low
  setPinOutput(B1);
  writePinLow(B1);
  // set NumLock LED to output and low
  setPinOutput(B2);
  writePinLow(B2);
  // set ScrollLock LED to output and low
  setPinOutput(B3);
  writePinLow(B3);
}






layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case 1:
    writePinHigh(B2);
        break;
    case 2:
         writePinHigh(B3);
        break;
    case 3:
         writePinHigh(B1);
        break;
    default: //  for any other layers, or the default layer
        writePinLow(B1);
        writePinLow(B2);
        writePinLow(B3);
        break;
    }
  return state;
}


