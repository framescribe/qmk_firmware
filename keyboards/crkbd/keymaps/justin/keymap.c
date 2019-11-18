#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _NAV 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  NAV,
  BACKLIT,
  RGBRST
};

// JR Custon Key Define Block - start here
#define MDASH LSFT(LALT(KC_MINS))
#define TRIG LSFT(LALT(LGUI(KC_ENTER)))
#define ARRCLN LT(3, KC_SCLN)
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
  [_QWERTY] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
     KC_TAB, KC_Q, 	KC_W,  KC_E,  KC_R,  KC_T,             		 KC_Y,  KC_U,  	KC_I,  KC_O, KC_P, 	KC_MINS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    KC_LEAD, KC_A,  KC_S,  KC_D,  KC_F,  KC_G,             		 KC_H,  KC_J,  	KC_K,  KC_L,ARRCLN, KC_QUOT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    KC_LSPO, KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,             		 KC_N,  KC_M,KC_COMM,KC_DOT,KC_SLSH,KC_RSPC,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                            	  OPT, 	 CMD,  BSPC,   	   SPC,  ENTL2, MO(1) \
                              //`--------------------'  `--------------------'
  ),

  [_LOWER] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
     KC_ESC,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,                   KC_6,  KC_7,  KC_8,  KC_9,  KC_0, MDASH,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
   KC_CAPS, KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC,         KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN, KC_EQUAL,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    RGB_TOG,RGB_MOD,RGB_HUI,RGB_HUD,RGB_SAI, RGB_SAD,       RGB_VAI, RGB_VAD, RGB_SPI, RGB_SPD, RGB_MODE_PLAIN, TRIG,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                               		LWORD, RWORD,  BSPC,   	   SPC,  ENT, MO(1) \
                              //`--------------------'  `--------------------'
  ),

  [_RAISE] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
     RESET,KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC,              KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_PLUS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    KC_LCTL, KC_NO, KC_NO, KC_NO, LWORD, RWORD,                KC_MINS,KC_EQL,KC_LCBR,KC_RCBR,KC_PIPE,KC_GRV,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    KC_LSFT, REDO, 	CUT,   COPY,  PASTE, BOLD,                NEW,KC_PLUS,KC_LBRC,KC_RBRC,KC_BSLS,KC_TILD,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                   KC_MEDIA_REWIND,KC_MEDIA_FAST_FORWARD,  KC_MEDIA_PLAY_PAUSE,   SPC,  ENT, MO(1) \
                              //`--------------------'  `--------------------'
  ),


  [_NAV] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
   RESET, KC_TRNS, KC_TRNS, KC_MS_UP, MWD, MWD,                  KC_PGUP, KC_PGUP, KC_UP, KC_NO, KC_NO, KC_NO,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
   KC_TRNS, MO(4), KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_TRNS, KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO, KC_NO,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
   KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, MWU, MWU,                 KC_PGDOWN, KC_PGDOWN, KC_NO, KC_NO, KC_NO, KC_RSFT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                KC_LALT, KC_MS_BTN2,KC_MS_BTN1,   KC_MEDIA_PLAY_PAUSE, KC_MEDIA_REWIND,KC_MEDIA_FAST_FORWARD\
                              //`--------------------'  `--------------------'
  )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);




void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _NAV);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _NAV);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _NAV);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _NAV);
      }
      return false;
    case NAV:
        if (record->event.pressed) {
          layer_on(_NAV);
        } else {
          layer_off(_NAV);
        }
        return false;
    
  
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}




