#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _DEFAULT,
  _LOWER,
  _RAISE,
  _ADJUST,
  _GAMING
};

enum custom_keycodes {
  CIRC = SAFE_RANGE,
  TILD,
};

#define DEFAULT DF(_DEFAULT)
#define GAMING DF(_GAMING)

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define ESC LCTL_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------------------.
 * |  Tab  |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   |  Bksp |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  Esc  |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   Ö   |   Ä   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | Shift |   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   -   | Shift |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |  Ctrl |  Alt  |  GUI  | Lower | Enter | Space | Raise |       |       |       | Gaming|
 * `-----------------------------------------------------------------------------------------------'
 */
[_DEFAULT] = LAYOUT_planck_grid(
    KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BSPC,
    ESC    ,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,KC_H   ,KC_J   ,KC_K   ,KC_L   ,SE_OSLH,SE_AE  ,
    KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,KC_N   ,KC_M   ,KC_COMM,KC_DOT ,SE_MINS,KC_RSFT,
    _______,KC_LCTL,KC_LALT,KC_LGUI,LOWER  ,KC_ENT ,KC_SPC ,RAISE  ,_______,_______,_______,GAMING
),

/* Lower
 * ,-----------------------------------------------------------------------------------------------.
 * |       |   ^   |   @   |   #   |   %   |   ~   |   \   |   /   |   )   |   ]   |   }   |  Del  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |   !   |   "   |   '   |   $   |   |   |   &   |   =   |   (   |   [   |   {   |   *   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |   `   |   ?   |   <   |   >   |   +   |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * `-----------------------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    _______,CIRC   ,SE_AT  ,KC_HASH,KC_PERC,TILD   ,SE_BSLS,SE_SLSH,SE_RPRN,SE_RCBR,SE_RBRC,KC_DEL ,
    _______,KC_EXLM,SE_QUO2,KC_BSLS,SE_DLR ,SE_PIPE,SE_AMPR,SE_EQL ,SE_LPRN,SE_LCBR,SE_LBRC,SE_ASTR,
    _______,_______,_______,_______,_______,_______,SE_GRV ,SE_QUES,SE_LESS,SE_GRTR,SE_PLUS,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______
),

/* Raise
 * ,-----------------------------------------------------------------------------------------------.
 * |       |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |  F1   |  F2   |  F3   |  F4   |  F5   |  Left |  Down |  Up   | Right |  Home |  PgUp |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |  F6   |  F7   |  F8   |  F9   |  F10  |  F11  |  F12  |       |       |  End  |  PgDn |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * `-----------------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    _______,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,_______,
    _______,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_HOME,KC_PGUP,
    _______,KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,_______,_______,KC_END ,KC_PGDN,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------------------.
 * | Reset |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       | Play  | Vol+  | Mute  |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       | Prev  | Vol-  | Next  |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * `-----------------------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    RESET  ,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,KC_MPLY,KC_VOLU,KC_MUTE,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,KC_MPRV,KC_VOLD,KC_MNXT,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______
),

/* Gaming
 * ,-----------------------------------------------------------------------------------------------.
 * |  Esc  |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |  Bksp |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  Tab  |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   |   -   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  Ctrl |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   ,   |   .   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | Shift |   Z   |   X   |   C   |   V   | Space |   B   |   N   |   M   |   Alt |  GUI  |Default|
 * `-----------------------------------------------------------------------------------------------'
 */
[_GAMING] = LAYOUT_planck_grid(
    KC_ESC ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_BSPC,
    KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,SE_MINS,
    KC_LCTL,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_COMM,KC_DOT ,
    KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_SPC ,KC_B   ,KC_N   ,KC_M   ,KC_RALT,KC_RGUI,DEFAULT
),

};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CIRC:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT("]")" ");
      }
      break;
    case TILD:
      if (record->event.pressed) {
        SEND_STRING(SS_ALGR("]")" ");
      }
      break;
  }
  return true;
};