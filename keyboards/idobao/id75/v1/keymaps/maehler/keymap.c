/* Copyright 2024 maehler
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

enum layers {
    _QWERTY,
    _COLEMAK,
    _FUNCTION,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FUNCT MO(_FUNCTION)
#define LOWER MO(_LOWER)

#define FN_ESC  LT(_FUNCTION, KC_ESC)
#define SFT_ENT MT(MOD_RSFT, KC_ENT)

// Colemak home row mods, left side
#define MOD_A MT(MOD_LSFT, KC_A)
#define MOD_R MT(MOD_LALT, KC_R)
#define MOD_S MT(MOD_LGUI, KC_S)
#define MOD_T MT(MOD_LCTL, KC_T)

// Colemak home row mods, right side
#define MOD_N MT(MOD_LCTL, KC_N)
#define MOD_E MT(MOD_LGUI, KC_E)
#define MOD_I MT(MOD_LALT, KC_I)
#define MOD_O MT(MOD_LSFT, KC_O)

// Colemak home row mods, raise, right side
#define MOD_MINS MT(MOD_RCTL, KC_MINS)
#define MOD_EQL  MT(MOD_RGUI, KC_EQL)
#define MOD_LBRC MT(MOD_RALT, KC_LBRC)
#define MOD_RBRC MT(MOD_RSFT, KC_RBRC)

// Colemak home row mods, raise/lower, left side
#define MOD_F1 MT(MOD_LSFT, KC_F1)
#define MOD_F2 MT(MOD_LALT, KC_F2)
#define MOD_F3 MT(MOD_LGUI, KC_F3)
#define MOD_F4 MT(MOD_LCTL, KC_F4)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTY
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * |        | 1      | 2      | 3      | 4      | 5      |        |        |        | 6      | 7      | 8      | 9      | 0      |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | TAB    | Q      | W      | E      | R      | T      | [      | \      | ]      | Y      | U      | I      | O      | P      | [      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | FN_ESC | A      | S      | D      | F      | G      | HOME   | DEL    | PG UP  | H      | J      | K      | L      | ;      | '      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      | END    | UP     | PG DN  | N      | M      | ,      | .      | /      | ENTER  |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
     * | MUTE   | LCTL   | LALT   | LGUI   | LOWER  | BACKSP | LEFT   | DOWN   | RIGHT  | SPACE  | RAISE  | RGUI   | RALT   | RCTL   |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_ortho_5x15(
        _______, KC_1,    KC_2,    KC_3,    KC_4,  KC_5,    _______, _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,    KC_LBRC, KC_SLSH, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
        FN_ESC,  KC_A,    KC_S,    KC_D,    KC_F,  KC_G,    KC_HOME, KC_DEL,  KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,    KC_END,  KC_UP,   KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT,
        KC_MUTE, KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_SPC,  RAISE,   KC_RGUI, KC_RALT, KC_RCTL, _______
    ),

    /* COLEMAK
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * |        | Q      | W      | F      | P      | G      |        |        |        | J      | L      | U      | Y      | ;      |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * |        | A      | R      | S      | T      | D      |        |        |        | H      | N      | E      | I      | O      |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * |        | Z      | X      | C      | V      | B      |        |        |        | K      | M      | ,      | .      | /      |        |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_COLEMAK] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    _______, _______, _______, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______,
        _______, MOD_A,   MOD_R,   MOD_S,   MOD_T,   KC_D,    _______, _______, _______, KC_H,    MOD_N,   MOD_E,   MOD_I,   MOD_O,   _______,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, _______, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_LOWER] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
        _______, MOD_F1,  MOD_F2,  MOD_F3,  MOD_F4,  KC_F5,   _______, _______, _______, KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, _______, _______, KC_F12,  KC_TILD, KC_LT,   KC_GT,   KC_HOME, KC_END,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY
    ),

    [_RAISE] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,  _______,  _______,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, _______, KC_6,    KC_7,     KC_8,    KC_9,     KC_0,     _______,
        _______, MOD_F1,  MOD_F2,  MOD_F3,  MOD_F4,  KC_F5,   _______, _______, _______, KC_F6,   MOD_MINS, MOD_EQL, MOD_LBRC, MOD_RBRC, KC_BSLS,
        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, _______, _______, KC_F12,  _______,  _______, _______,  KC_PGDN,  KC_PGDN,
        _______, _______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______, _______,  _______, _______,  _______,  KC_MPLY
    ),

    [_FUNCTION] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY
    ),

    [_ADJUST] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_VAI, RGB_TOG,
        _______, QK_BOOT, _______, KC_VOLD, _______, _______, _______, _______, _______, _______, _______, KC_VOLU, _______, RGB_VAD, RGB_MOD,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QWERTY,  COLEMAK, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
            break;
    }
    return true;
}
