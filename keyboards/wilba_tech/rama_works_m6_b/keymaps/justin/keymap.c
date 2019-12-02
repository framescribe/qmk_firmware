#include QMK_KEYBOARD_H

// JR Custon Key Define Block
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
#define NEXT KC_MEDIA_FAST_FORWARD
#define PREV KC_MEDIA_REWIND
#define PLAY KC_MEDIA_PLAY_PAUSE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    LAYOUT(
        KC_1, LGUI(KC_C), LGUI(KC_V), BOLD, ITAL, UNDER),

    LAYOUT(
        UNDO, REDO, KC_NO, PREV, PLAY, NEXT),

    LAYOUT(
        RGB_TOG,  KC_NO, KC_NO, RGB_HUI, RGB_HUD, RGB_VAI),

    LAYOUT(
        KC_NO,  KC_NO, KC_NO, KC__VOLDOWN, KC__MUTE, KC__VOLUP) };

