/* Copyright 2019 gtips
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
#define ARRCLN LT(4, KC_SCLN)
#define ENTL2 LT(2, KC_ENT)
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



void dance_cln_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_RSFT);
    register_code (KC_SCLN);
  } else {
    register_code (KC_SCLN);
  }
}

void dance_cln_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_RSFT);
    unregister_code (KC_SCLN);
  } else {
    unregister_code (KC_SCLN);
  }
}


enum {
  TD_ESC_CAPS = 0, 
  TD_Q_TAB,
  TD_SQUES
};



void dance_ques_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_RSFT);
    register_code (KC_SLSH);
  } else {
    register_code (KC_SLSH);
  }
}

void dance_ques_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_RSFT);
    unregister_code (KC_SLSH);
  } else {
    unregister_code (KC_SLSH);
  }
}


//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
  [TD_Q_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_TAB),
  [TD_SQUES] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_ques_finished, dance_ques_reset)
// Other declarations would go here, separated by commas, if you have them
};



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
      SEND_STRING("(PRE-LAP)");
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

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
    _ARROWS
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung39(
    MT(MOD_LALT, KC_TAB),   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_MINS,
    KC_LEAD,  KC_A,     KC_S,     KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     ARRCLN,  KC_QUOT,
    KC_LSPO,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSPC,
                                                       MT(MOD_LGUI, KC_BSPC), KC_SPC , LT(RAISE, KC_ENT)
  ),
  
  [_LOWER] = LAYOUT_reviung39(
    _______,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,    KC_PERC,            KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  MDASH,
    _______,  KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,   KC_PIPE,            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_PLUS,   KC_EQUAL,
    _______,  KC_ESC,   KC_LGUI,  KC_LALT,  KC_CAPS,   KC_DQUO,            KC_HOME,  KC_END,   KC_PGUP,  KC_PGDN,  KC_PSCR,  RSFT_T(KC_SPC),
                                                       _______,  KC_BSPC,   _______
  ),
  
  [_RAISE] = LAYOUT_reviung39(
    KC_ESC,  KC_1,     KC_2,     KC_3,     KC_4,      KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,   MDASH,
    _______,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,    KC_PERC,           KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_EQUAL,
    KC_LSFT,  KC_ESC,   KC_RGUI,  XXXXXXX, XXXXXXX, XXXXXXX,              KC_MEDIA_REWIND, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_FAST_FORWARD,  KC_VOLD,   KC_VOLU,   KC_RSFT,
                                                       _______,  KC_ENT,  _______
  ),
  
  [_ADJUST] = LAYOUT_reviung39(
    RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,  XXXXXXX,   RGB_TOG,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, XXXXXXX,   XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            RESET,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                                       _______,  XXXXXXX,  _______
  ),

  [_ARROWS] = LAYOUT_reviung39(
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            KC_PGUP,  KC_PGUP,  KC_UP,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RIGHT,  XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            KC_PGDOWN,  KC_PGDOWN,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                                       _______,  XXXXXXX,  _______
  ),
};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
