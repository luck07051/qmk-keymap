
// $ qmk flash -kb ferris/sweep -km uima -e CONVERT_TO=promicro_rp2040

#include QMK_KEYBOARD_H

enum layers_names {
    _DEF_,
    _COLEMAK_,
    _NERPS_,

    _NAV_,
    _NUM_,
    _FUN_,
    _WM_,
};

enum custom_keycodes {
    KEYCODE = SAFE_RANGE,

    // String
    ST_HMD,
    ST_UPD,
};

enum custom_keycodes_shortcut {
    NAV_SPC = LT(_NAV_, KC_SPC),
    NUM_ENT = LT(_NUM_, KC_ENT),

    // Move one word
    CK_LW = C(KC_LEFT),
    CK_RW = C(KC_RIGHT),

    // Move focus on browser tabs
    CK_LTAB = C(S(KC_TAB)),
    CK_RTAB = C(KC_TAB),

    // Set different layout
    TO_DEF = TO(_DEF_),
    TO_COL = TO(_COLEMAK_),
    TO_NER = TO(_NERPS_),

    // Home Row Mod
    HM_A = LGUI_T(KC_A), HM_S = LALT_T(KC_S), HM_D = LCTL_T(KC_D), HM_F = LSFT_T(KC_F),
    HM_J = RSFT_T(KC_J), HM_K = RCTL_T(KC_K), HM_L = RALT_T(KC_L), HM_P = RGUI_T(KC_P),

    // HRM for Nerps
    CM_A = LGUI_T(KC_A), CM_R = LALT_T(KC_R), CM_S = LCTL_T(KC_S), CM_T = LSFT_T(KC_T),
    CM_N = RSFT_T(KC_N), CM_E = RCTL_T(KC_E), CM_I = RALT_T(KC_I), CM_O = RGUI_T(KC_O),

    // HRM for Nerps
    NE_N = LGUI_T(KC_N), NE_R = LALT_T(KC_R), NE_T = LCTL_T(KC_T), NE_S = LSFT_T(KC_S),
    NE_H = RSFT_T(KC_H), NE_E = RCTL_T(KC_E), NE_I = RALT_T(KC_I), NE_A = RGUI_T(KC_A),

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEF_] = LAYOUT(
        XXXXXXX, KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    XXXXXXX,
        HM_A,    HM_S,    HM_D,    HM_F,    KC_G,         KC_H,    HM_J,    HM_K,    HM_L,    HM_P,
        KC_UNDS, KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_QUOT, KC_COMM, KC_DOT,
                                   NAV_SPC, NAV_SPC,      NUM_ENT, NUM_ENT
    ),

    [_COLEMAK_] = LAYOUT(
        XXXXXXX, KC_W,    KC_F,    KC_P,    KC_B,         KC_J,    KC_L,    KC_U,    KC_Y,    XXXXXXX,
        CM_A,    CM_R,    CM_S,    CM_T,    KC_G,         KC_M,    CM_N,    CM_E,    CM_I,    CM_O,
        KC_UNDS, KC_X,    KC_C,    KC_D,    KC_V,         KC_K,    KC_H,    KC_QUOT, KC_COMM, KC_DOT,
                                   NAV_SPC, NAV_SPC,      NUM_ENT, NUM_ENT
    ),

    [_NERPS_] = LAYOUT(
        XXXXXXX, KC_L,    KC_D,    KC_P,    KC_V,         KC_X,    KC_K,    KC_O,    KC_U,    XXXXXXX,
        NE_N,    NE_R,    NE_T,    NE_S,    KC_G,         KC_Y,    NE_H,    NE_E,    NE_I,    NE_A,
        KC_UNDS, KC_J,    KC_M,    KC_C,    KC_W,         KC_B,    KC_F,    KC_QUOT, KC_COMM, KC_DOT,
                                   NAV_SPC, NAV_SPC,      NUM_ENT, NUM_ENT
    ),

    [_NAV_] = LAYOUT(
        XXXXXXX, _______, CK_LTAB, CK_RTAB, _______,      CK_LW,   _______, _______, CK_RW,   XXXXXXX,
        C(KC_A), _______, KC_PGDN, KC_PGUP, _______,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
        C(KC_Z), KC_CUT,  KC_COPY, KC_PSTE, _______,      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
                                   _______, _______,      _______, _______
    ),

    [_NUM_] = LAYOUT(
        XXXXXXX, KC_7,    KC_8,    KC_9,    KC_MINS,      KC_TILD, KC_LCBR, KC_RCBR, KC_DLR,  XXXXXXX,
        KC_ASTR, KC_4,    KC_5,    KC_6,    KC_PLUS,      KC_GRV,  KC_LPRN, KC_RPRN, KC_CIRC, KC_PERC,
        KC_SLSH, KC_1,    KC_2,    KC_3,    KC_EQL,       KC_AT,   KC_LBRC, KC_RBRC, KC_COMM, KC_DOT,
                                   _______, KC_0,         _______, _______
    ),

    [_FUN_] = LAYOUT(
        XXXXXXX, KC_PSCR, _______, _______, QK_BOOT,      _______, TO_DEF,  TO_COL,  TO_NER,  XXXXXXX,
        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,       KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,
        _______, _______, _______, KC_F6,   _______,      _______, KC_F5,   _______, _______, _______,
                                   XXXXXXX, _______,      _______, XXXXXXX
    ),

    [_WM_] = LAYOUT(
        XXXXXXX, _______, _______, _______, _______,      _______, _______, _______, _______, XXXXXXX,
        _______, G(KC_1), G(KC_K), G(KC_J), _______,      _______, G(KC_1), G(KC_2), G(KC_3), G(KC_4),
        _______, _______, _______, _______, _______,      _______, G(KC_5), G(KC_6), G(KC_7), G(KC_8),
                                   XXXXXXX, _______,      _______, XXXXXXX
    ),

};

/* Create Combos */
#undef COMB
#define COMB(name, key, ...) name,
enum combos {
#include "combos.def"
};

#undef COMB
#define COMB(name, key, ...) const uint16_t PROGMEM cmb_##name[] = {__VA_ARGS__, COMBO_END};
#include "combos.def"

#undef COMB
#define COMB(name, key, ...) [name] = COMBO(cmb_##name, key),
combo_t key_combos[] = {
#include "combos.def"
};

uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(*key_combos);

uint8_t combo_ref_from_layer(uint8_t layer){
    switch (get_highest_layer(layer_state)){
        case _COLEMAK_:
        case _NERPS_:
            return _DEF_;
    }
    return layer;  // important if default is not in case.
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        /* Enable def combo if def layer is enable */
        case DEFAULT_COMBO_START ... DEFAULT_COMBO_END:
            if (layer_state_is(_DEF_)) return true;
    }

    return false;
}


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        // HMR for Qwerty
        case HM_A: case HM_S: case HM_D: case HM_F:
        case HM_J: case HM_K: case HM_L: case HM_P:
        // // HMR for Colemak
        // case CM_A: case CM_R: case CM_S: case CM_T:
        // case CM_N: case CM_E: case CM_I: case CM_O:
        // // HMR for Nerps
        // case NE_N: case NE_R: case NE_T: case NE_S:
        // case NE_H: case NE_E: case NE_I: case NE_A:
            return TAPPING_TERM + 30;

        default:
            return TAPPING_TERM;
    }
}


bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_MINS:
        case KC_UNDS:
        case KC_BSPC:
        case KC_DEL:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        // Tri Layer Implementation
        case NAV_SPC:
            if (record->event.pressed) layer_on(_NAV_);
            else layer_off(_NAV_);
            update_tri_layer(_NAV_, _NUM_, _FUN_);
            // return false;
            return true;
        case NUM_ENT:
            if (record->event.pressed) layer_on(_NUM_);
            else layer_off(_NUM_);
            update_tri_layer(_NAV_, _NUM_, _FUN_);
            // return false;
            return true;
    }

    if (record->event.pressed) {
        switch (keycode) {
            // String
            case ST_HMD: SEND_STRING("~/"); return false; break;
            case ST_UPD: SEND_STRING("../"); return false; break;
        }
    }

    return true;
}
