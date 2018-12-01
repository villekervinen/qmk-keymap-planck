#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _DEFAULT,
  _LOWER,
  _RAISE,
  _ADJUST
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------------------.
 * |  Tab  |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   |  Bksp |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  Esc  |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   Ö   |   Ä   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | Shift |   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   -   | Shift |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |  Ctrl |  Alt  |  GUI  | Lower | Enter | Space | Raise |       |       |       |       |
 * `-----------------------------------------------------------------------------------------------'
 */
[_DEFAULT] = LAYOUT_planck_grid(
    KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BSPC,
    KC_ESC, KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,KC_H   ,KC_J   ,KC_K   ,KC_L   ,NO_OSLH,NO_AE  ,
    KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,KC_N   ,KC_M   ,KC_COMM,KC_DOT ,NO_MINS,KC_RSFT,
    _______,KC_LCTL,KC_LALT,KC_LGUI,LOWER  ,KC_ENT ,KC_SPC ,RAISE  ,_______,_______,_______,_______
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
    _______,NO_CIRC,NO_AT  ,KC_HASH,KC_PERC,NO_TILD,NO_BSLS,NO_SLSH,NO_RPRN,NO_RCBR,NO_RBRC,KC_DEL ,
    _______,KC_EXLM,NO_QUO2,KC_BSLS,NO_DLR ,NO_PIPE,NO_AMPR,NO_EQL ,NO_LPRN,NO_LCBR,NO_LBRC,NO_ASTR,
    _______,_______,_______,_______,_______,_______,NO_GRV ,NO_QUES,NO_LESS,NO_GRTR,NO_PLUS,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______
),

/* Raise
 * ,-----------------------------------------------------------------------------------------------.
 * |       |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |  F1   |  F2   |  F3   |  F4   |  F5   |  F6   | Left  | Down  |  Up   | Right |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |  F7   |  F8   |  F9   |  F10  |  F11  |  F12  | Home  | PgDn  | PgUp  |  End  |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * `-----------------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    _______,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,_______,
    _______,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,_______,
    _______,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_HOME,KC_PGDN,KC_PGUP,KC_END ,_______,
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
)


};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
