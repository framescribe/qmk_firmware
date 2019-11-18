/*
Copyright 2017 Balz Guenat

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H


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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
        KC_GESC,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,     COPY,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_MINS,    KC_EQL,     KC_BSLS,     PASTE,
        KC_LEAD,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       LT(1, KC_SCLN),KC_QUOT, KC_ENT,
        KC_LSPO,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSPC,    KC_UP,
        KC_LCTL,    KC_LALT,    KC_LGUI,                            KC_SPC,                             KC_RGUI,    KC_RALT,    MO(1),      KC_LEFT,    KC_DOWN,    KC_RGHT
    ),
  [1] = LAYOUT(
        RESET,      KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     MDASH,      KC_F12,     _______,     _______,
        _______,    _______,    _______,    KC_MS_UP,   KC_WH_U,    _______,    _______,    KC_PGUP,    KC_UP,      _______,    _______,    _______,    _______,    _______,     _______,
        _______,    _______,    KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT,_______,    _______,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   _______,    _______,    _______,
        _______,    _______,    _______,    _______,    KC_WH_D,    _______,    _______,    KC_PGDOWN,  _______,    _______,    _______,    _______,    _______,
        _______,    _______,    KC_MS_BTN2,                         KC_MS_BTN1,                         _______,_______,MO(1),              _______,    _______,    _______
    )       
};
