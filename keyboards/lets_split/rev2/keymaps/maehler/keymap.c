#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
    _FUNCTION
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define FUNCTION MO(_FUNCTION)

#define SFT_ENT MT(MOD_RSFT, KC_ENT)
#define FN_ESC LT(FUNCTION, KC_ESC)

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

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Mute | Ctrl | Alt  | GUI  |Lower | Bksp |Space |Raise | GUI  | Alt  | Ctrl |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    FN_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT,
    KC_MUTE, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_BSPC, KC_SPC,  RAISE,   KC_RGUI, KC_LALT, KC_RCTL, _______
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower | Bksp |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_4x12(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    FN_ESC,  MOD_A,   MOD_R,   MOD_S,   MOD_T,   KC_D,    KC_H,    MOD_N,   MOD_E,   MOD_I,   MOD_O,   KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT,
    KC_MUTE, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_BSPC, KC_SPC,  RAISE,   KC_RGUI, KC_LALT, KC_RCTL, _______
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |   <  |   >  | Home | End  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    _______, MOD_F1,  MOD_F2,  MOD_F3,  MOD_F4,  KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TILD, KC_LT,   KC_GT,   KC_HOME, KC_END,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |ISO / |      |Pg Up |Pg Dn |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | Del  |      |      |      |      |      | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,    KC_7,     KC_8,    KC_9,     KC_0,     _______,
    _______, MOD_F1,  MOD_F2,  MOD_F3,  MOD_F4,  KC_F5,  KC_F6,   MOD_MINS, MOD_EQL, MOD_LBRC, MOD_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12,  _______,  KC_NUBS, _______,  KC_PGUP,  KC_PGDN,
    _______, _______, _______, _______, _______, KC_DEL, _______, _______,  _______, _______,  _______,  KC_MPLY
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      | Vol+ |      |      |      |      | Vol- | Mute |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|      |      |Qwerty|Colemk|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |Mus on|Musoff|MIDIon|MIDIof|             |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12(
    _______, QK_BOOT, _______, KC_VOLD, _______, _______, _______, _______, KC_VOLU, KC_MUTE, _______, _______,
    _______, _______, _______, AU_ON,   AU_OFF,  _______, _______, QWERTY,  COLEMAK, _______, _______, _______,
    _______, _______, _______, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Function
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |  Up  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Left | Down |Right |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTION] = LAYOUT_ortho_4x12(
    _______, _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY
),

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
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
  }
  return true;
}
