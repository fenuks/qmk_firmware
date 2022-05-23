/*
Copyright 2016 Daniel Svensson <dsvensson@gmail.com>

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

/* Qwerty layout
* ┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐     ┌───────────┐
* │ESC│   │F1 │F2 │F3 │F4 │ │F5 │F6 │F7 │F8 │ │F9 │F10│F11│F12│ │PRT│SCR│PAU│     │Ghost Squid│
* └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘     └───────────┘
* ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
* │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│ │INS│HOM│PgU│ │NUM│ / │ * │ - │
* ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
* │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │     │ │DEL│END│PgD│ │ 7 │ 8 │ 9 │   │
* ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐  ↲ │ └───┴───┴───┘ ├───┼───┼───┤ + │
* │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ \ │    │               │ 7 │ 8 │ 9 │   │
* ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤     ┌───┐     ├───┼───┼───┼───┤
* │Shif│ # │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │    Shift │     │ ↑ │     │ 1 │ 2 │ 3 │   │
* ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐ ├───┴───┼───┤ ↲ │
* │Ctrl│GUI │Alt │                        │ Alt│ GUI│Fn  │Ctrl│ │ ← │ ↓ │ → │ │   0   │ , │   │
* └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘ └───────┴───┴───┘
*/

/* Dvorak layout (modified)
* ┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐     ┌───────────┐
* │ESC│   │F1 │F2 │F3 │F4 │ │F5 │F6 │F7 │F8 │ │F9 │F10│F11│F12│ │PRT│SCR│PAU│     │Ghost Squid│
* └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘     └───────────┘
* ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
* │ ` │ - │ 7 │ 5 │ 3 │ 1 │ 9 │ 0 │ 2 │ 4 │ 6 │ 8 │ = │ Backsp│ │INS│HOM│PgU│ │NUM│ / │ * │ - │
* ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
* │ Tab │ ' │ , │ . │ P │ Y │ F │ G │ C │ R │ L │ [ │ ] │     │ │DEL│END│PgD│ │ 7 │ 8 │ 9 │   │
* ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐  ↲ │ └───┴───┴───┘ ├───┼───┼───┤ + │
* │ Caps │ A │ O │ E │ U │ I │ D │ H │ T │ N │ S │ / │ \ │    │               │ 7 │ 8 │ 9 │   │
* ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤     ┌───┐     ├───┼───┼───┼───┤
* │Shif│ < │ ; │ Q │ J │ K │ X │ B │ M │ W │ V │ Z │    Shift │     │ ↑ │     │ 1 │ 2 │ 3 │   │
* ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐ ├───┴───┼───┤ ↲ │
* │Ctrl│GUI │Alt │                        │ Alt│ GUI│Fn  │Ctrl│ │ ← │ ↓ │ → │ │   0   │ , │   │
* └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘ └───────┴───┴───┘
*/

/* tap dance */
enum {
    TAP_DANCE_LCBR,
    TAP_DANCE_RCBR,
    TAP_DANCE_A,
    TAP_DANCE_M,
    TAP_DANCE_U,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TAP_DANCE_LCBR] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
    [TAP_DANCE_RCBR] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),
    [TAP_DANCE_A]    = ACTION_TAP_DANCE_DOUBLE(KC_A,    RALT(KC_A)),
    [TAP_DANCE_M]    = ACTION_TAP_DANCE_DOUBLE(KC_M,    KC_ENT),
    [TAP_DANCE_U]    = ACTION_TAP_DANCE_DOUBLE(KC_U,    KC_MYCM),
};

/* layers */
enum layer_names {
    KM_QWERTY,
    KM_QWERTY_MEDIA,
    KM_QWERTY_VIM,

    KM_DVORAK,
    KM_DVORAK_MEDIA,
    KM_DVORAK_NUM,
    KM_DVORAK_VIM,
};

// key defines
#define MO_DM MO(KM_DVORAK_MEDIA)
#define TG_DV TG(KM_DVORAK_VIM)
#define TG_DN TG(KM_DVORAK_NUM)

#define MO_QM MO(KM_QWERTY_MEDIA)
#define TG_QV TG(KM_QWERTY_VIM)

#define DF_Q DF(KM_QWERTY)
#define DF_D DF(KM_DVORAK)

#define RC_ESC LCTL_T(KC_ESC)
#define RA_RB RALT_T(KC_RBRC)
#define LA_LB LALT_T(KC_LBRC)
#define RC_BL RCTL_T(KC_BSLS)

#define NNN KC_TRNS

// tap dance keys
#define TD_A TD(TAP_DANCE_A)
#define TD_LB TD(TAP_DANCE_LCBR)
#define TD_RB TD(TAP_DANCE_RCBR)
#define TD_M TD(TAP_DANCE_M)
#define TD_U TD(TAP_DANCE_U)

// home dvorak keys
#define HD_A LGUI_T(KC_A)
#define HD_O LALT_T(KC_O)
#define HD_E LSFT_T(KC_E)
#define HD_U LCTL_T(KC_U)
#define HD_H RCTL_T(KC_H)
#define HD_T RSFT_T(KC_T)
#define HD_N LALT_T(KC_N)
#define HD_S RGUI_T(KC_S)

#define MOD_MASK_RCTRL MOD_BIT(KC_RCTL)
#define MOD_MASK_LCTRL MOD_BIT(KC_LCTL)
#define MOD_MASK_RSHIFT MOD_BIT(KC_RSFT)
#define MOD_MASK_LSHIFT MOD_BIT(KC_LSFT)
#define VIM_LAYER_MASK (1 << KM_QWERTY_VIM)
#define DEF_LAYER_MASK (1 << KM_QWERTY)

/* |`KC_WWW_STOP`           |`KC_WSTP`                      |Browser Stop       */  
/* |`KC_WWW_REFRESH`        |`KC_WREF`                      |Browser Refresh    */  
/* |`KC_WWW_FAVORITES`      |`KC_WFAV`                      |Browser Favorites  */  
/* |`KC_MAIL`               |                               |Launch Mail        */  
/* |`KC_WWW_HOME`           |`KC_WHOM`                      |Browser Home       */  
/* |`KC_WWW_BACK`           |`KC_WBAK`                      |Browser Back       */  
/* |`KC_WWW_FORWARD`        |`KC_WFWD`                      |Browser Forward    */  


/* |`KC_MY_COMPUTER`        |`KC_MYCM`                      |Launch My Computer */  
/* |`KC_WWW_SEARCH`         |`KC_WSCH`                      |Browser Search     */  
/* |`KC_CALCULATOR`         |`KC_CALC`                      |Launch Calculator  */  
/* |`KC_F13`                |                               |F13 */
/* |`KC_F14`                |                               |F14 */
/* |`KC_F15`                |                               |F15 */
/* |`KC_F16`                |                               |F16 */
/* |`KC_F17`                |                               |F17 */
/* |`KC_F18`                |                               |F18 */
/* |`KC_F19`                |                               |F19 */
/* |`KC_F20`                |                               |F20 */
/* |`KC_F21`                |                               |F21 */
/* |`KC_F22`                |                               |F22 */
/* |`KC_F23`                |                               |F23 */
/* |`KC_F24`                |                               |F24 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [KM_QWERTY] = LAYOUT(
KC_ESC,          KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,   KC_PSCR,DF_D,   KC_PAUS,
KC_GRV,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,  TG_QV,  KC_HOME,KC_PGUP,    KC_NLCK,KC_PSLS,KC_PAST,KC_PMNS,
KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   TD_U,   KC_I,   KC_O,   KC_P,   TD_LB, TD_RB, RC_BL,  KC_DEL, KC_END, KC_PGDN,    KC_P7,  KC_P8,  KC_P9,  KC_PPLS,
RC_ESC, TD_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,        KC_ENT,                               KC_P4,  KC_P5,  KC_P6,
KC_LSPO, KC_NUBS,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,  KC_M,   KC_COMM,KC_DOT, KC_SLSH,        KC_RSPC,          KC_UP,              KC_P1,  KC_P2,  KC_P3,  KC_PENT,
KC_LCTL, KC_LGUI,LA_LB,                       KC_SPC,                          KC_RALT,  KC_RGUI,MO_QM,KC_RCTL,   KC_LEFT,KC_DOWN,KC_RGHT,    KC_P0,          KC_PDOT),
        [KM_QWERTY_MEDIA] = LAYOUT(
KC_SLEP,  KC_MYCM,KC_WSCH,KC_CALC,KC_MSEL,  KC_MEDIA_PLAY_PAUSE, KC_MEDIA_STOP, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK,  TG_QV,KC_MUTE, KC_VOLD, KC_VOLU,KC_PWR,KC_SLCK, RESET,
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
_______,DT_PRNT,DT_DOWN,DT_UP  ,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
_______,_______,_______,_______,_______,TG_QV,  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,  _______,_______,
_______,_______,_______,KC_LOCK,_______,_______,_______,_______,_______,_______,_______,_______,_______),
       [KM_QWERTY_VIM] = LAYOUT(
_______,          _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______,   _______,KC_SLCK,_______,
KC_GRV,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,  TG_QV, KC_HOME,KC_PGUP,    KC_NLCK,KC_PSLS,KC_PAST,KC_PMNS,
KC_TAB,  KC_Q,   C(KC_RGHT),   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   TG_QV,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,  KC_DEL, KC_END, KC_PGDN,    KC_P7,  KC_P8,  KC_P9,  KC_PPLS,
KC_CLCK, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,KC_SCLN,KC_QUOT,        KC_ENT,                               KC_P4,  KC_P5,  KC_P6,
KC_LSPO, KC_NUBS,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,        KC_RSPC,          KC_UP,              KC_P1,  KC_P2,  KC_P3,  KC_PENT,
KC_LCTL, KC_LGUI,KC_LALT,                       KC_SPC,                          KC_RALT,KC_RGUI,MO_QM,  KC_RCTL,   KC_LEFT,KC_DOWN,KC_RGHT,    KC_P0,          KC_PDOT),

        /* [KM_DVORAK] = LAYOUT( */
/* KC_ESC,       KC_F1, KC_F2, KC_F3, KC_F4,  KC_F5,KC_F6,KC_F7,KC_F8,  KC_F9, KC_F10,  KC_F11, KC_F12,     KC_PSCR, DF_Q,    KC_PAUS, */
/* KC_GRV, KC_1,   KC_2,   KC_3,  KC_4, KC_5, KC_6,   KC_7, KC_8, KC_9,   KC_0,   KC_LBRC, KC_RBRC,KC_BSPC, KC_INS,  KC_HOME, KC_PGUP,  KC_NLCK,KC_PSLS,KC_PAST,KC_PMNS, */
/* KC_TAB, KC_QUOT,KC_COMM,KC_DOT,KC_P, KC_Y, KC_F,   KC_G, KC_C, KC_R,   KC_L,   KC_SLSH, KC_EQL, KC_BSLS, KC_DEL,  KC_END,  KC_PGDN,  KC_P7,  KC_P8,  KC_P9,  KC_PPLS, */
/* RC_ESC, HD_A,   HD_O,   HD_E,  HD_U, KC_I, KC_D,   HD_H, HD_T, HD_N,   HD_S,   KC_MINS,         KC_ENT,                              KC_P4,  KC_P5,  KC_P6, */
/* KC_LSPO,KC_NUBS,KC_SCLN,KC_Q,  KC_J, KC_K, KC_X,   KC_B, KC_M, KC_W,   KC_V,   KC_Z,            KC_RSPC,          KC_UP,             KC_P1,  KC_P2,  KC_P3,  KC_PENT, */
/* KC_LCTL,KC_LGUI,LA_LB,                          KC_SPC,            RA_RB,   KC_RGUI, MO_DM,  KC_RCTL,    KC_LEFT,KC_DOWN,  KC_RGHT,  KC_P0,          KC_PDOT), */
        [KM_DVORAK] = LAYOUT(
KC_ESC,       KC_F1, KC_F2, KC_F3, KC_F4,  KC_F5,KC_F6,KC_F7,KC_F8,  KC_F9, KC_F10,  KC_F11, KC_F12,     KC_PSCR, DF_Q,    KC_PAUS,
KC_GRV, KC_MINS,   KC_7,   KC_5,  KC_3, KC_1, KC_9,   KC_0, KC_2, KC_4,   KC_6,   KC_8, KC_EQL, KC_BSPC, KC_INS,  KC_HOME, KC_PGUP,  KC_NLCK,KC_PSLS,KC_PAST,KC_PMNS,
KC_TAB, KC_QUOT,KC_COMM,KC_DOT,KC_P, KC_Y, KC_F,   KC_G, KC_C, KC_R,   KC_L,   KC_LBRC, KC_RBRC,KC_BSLS, KC_DEL,  KC_END,  KC_PGDN,  KC_P7,  KC_P8,  KC_P9,  KC_PPLS,
RC_ESC, HD_A,   HD_O,   HD_E,  HD_U, KC_I, KC_D,   HD_H, HD_T, HD_N,   HD_S,   KC_SLSH,         KC_ENT,                              KC_P4,  KC_P5,  KC_P6,
KC_LSPO,KC_NUBS,KC_SCLN,KC_Q,  KC_J, KC_K, KC_X,   KC_B, KC_M, KC_W,   KC_V,   KC_Z,            KC_RSPC,          KC_UP,             KC_P1,  KC_P2,  KC_P3,  KC_PENT,
KC_LCTL,KC_LGUI,LA_LB,                          KC_SPC,            RA_RB,   KC_RGUI, MO_DM,  KC_RCTL,    KC_LEFT,KC_DOWN,  KC_RGHT,  KC_P0,          KC_PDOT),
        [KM_DVORAK_NUM] = LAYOUT(
_______,    _______,_______,_______,_______,  _______,_______,_______,_______,  _______,_______,_______,_______,    _______,_______,_______,
_______,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, _______,    _______,_______,_______,   NNN,NNN,NNN,NNN,
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,    _______,_______,_______,   NNN,NNN,NNN,NNN,
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,  _______,_______,_______,                                     NNN,NNN,NNN,
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,                    _______,           NNN,NNN,NNN,NNN,
_______,_______,_______,                        _______,                        _______,_______,_______,_______,    _______,_______,_______,   NNN,    NNN),
        [KM_DVORAK_MEDIA] = LAYOUT(
KC_SLEP,    KC_MYCM,KC_WSCH,KC_CALC,KC_MSEL,  KC_MPLY,KC_MSTP,KC_MPRV,KC_MNXT,  TG_DV,  KC_MUTE,KC_VOLD,KC_VOLU,     KC_PWR, KC_SLCK,RESET,
KC_ASTG,KC_ASRP,KC_ASDN,KC_ASUP,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______,_______,_______,   TG_DN,NNN,NNN,NNN,
_______,DT_PRNT,DT_DOWN,DT_UP  , KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19,_______,_______,_______,     _______,_______,_______,   NNN,NNN,NNN,NNN,
_______, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24,KC_MAIL,KC_WHOM,KC_WBAK,KC_WFWD,KC_WSTP,_______,_______,                                        NNN,NNN,NNN,
_______,KC_WREF,KC_WFAV,_______,_______,TG_DV  ,_______,_______,_______,_______,_______,_______,_______,                     _______,           NNN,NNN,NNN,NNN,
_______,_______,_______,                  KC_LOCK,                      _______,_______,_______,_______,             _______,_______,_______,   NNN,    NNN),
        [KM_DVORAK_VIM] = LAYOUT(
_______,    _______,_______,_______,_______,  _______,_______,_______,_______,  _______,_______,_______,_______,    _______,KC_SLCK,_______,
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,    _______,_______,_______,   NNN,NNN,NNN,NNN,
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,    _______,_______,_______,   NNN,NNN,NNN,NNN,
_______,_______,_______,_______,_______,_______,_______,_______,_______,TG_DV,  _______,_______,_______,                                       NNN,NNN,NNN,
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,                    _______,           NNN,NNN,NNN,NNN,
_______,_______,_______,                        _______,                        _______,_______,MO_DM,  _______,    _______,_______,_______,   NNN,    NNN),

};

layer_state_t layer_state_set_user(layer_state_t state) {
    if (IS_LAYER_ON_STATE(state, KM_QWERTY_VIM) || IS_LAYER_ON_STATE(state, KM_DVORAK_VIM)) {
        fn_led_on();
    } else {
        fn_led_off();
    }

    return state;
}

enum layer_names CURRENT_LAYER = KM_QWERTY;

layer_state_t default_layer_state_set_user(layer_state_t state) {
    if (IS_LAYER_ON_STATE(state, KM_DVORAK)) {
        writePinLow(LED_CAPS_LOCK_PIN);
        writePinHigh(LED_SCROLL_LOCK_PIN);
        CURRENT_LAYER = KM_DVORAK;
    } else {
        writePinHigh(LED_SCROLL_LOCK_PIN);
        writePinHigh(LED_CAPS_LOCK_PIN);
        CURRENT_LAYER = KM_QWERTY;
    }

    return state;
}

bool led_update_user(led_t led_state) {
#if LED_PIN_ON_STATE == 0
    // invert the whole thing to avoid having to conditionally !led_state.x later
    led_state.raw = ~led_state.raw;
#endif

    writePin(LED_NUM_LOCK_PIN, led_state.num_lock);
    return false;
}

void suspend_wakeup_init_user() {
    if (CURRENT_LAYER == KM_DVORAK) {
        writePinLow(LED_CAPS_LOCK_PIN);
    }
}

bool get_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_SCLN:
            return true;
        default:
            return false;
    }
}

const key_override_t shift_space = ko_make_basic(MOD_MASK_RSHIFT, KC_SPC, KC_ENT);
const key_override_t gui_space = ko_make_basic(MOD_MASK_GUI, KC_SPC, KC_ENT);
const key_override_t ctrl_f_vim = ko_make_with_layers(MOD_MASK_RCTRL, KC_F, KC_PGDN, VIM_LAYER_MASK);
const key_override_t b_vim = ko_make_with_layers(0, KC_B, C(KC_LEFT), VIM_LAYER_MASK);
const key_override_t ctrl_b_vim = ko_make_with_layers(MOD_MASK_RCTRL, KC_B, KC_PGUP, VIM_LAYER_MASK);
const key_override_t end_vim = ko_make_with_layers(MOD_MASK_RSHIFT, KC_4, KC_END, VIM_LAYER_MASK);
const key_override_t beg_vim = ko_make_with_layers(MOD_MASK_RSHIFT, KC_6, KC_HOME, VIM_LAYER_MASK);
const key_override_t shift_esc = ko_make_basic(MOD_MASK_SHIFT, KC_ESC, KC_SLEP);
/* doesn't work, cannot use TG */
/* const key_override_t vim_mode = ko_make_with_layers(MOD_MASK_LCTRL, KC_LBRC, TG(KM_QWERTY_VIM), -1); */

const key_override_t **key_overrides = (const key_override_t *[]){
    &ctrl_f_vim,
    &ctrl_b_vim,
    &b_vim,
    &end_vim,
    &beg_vim,
    &shift_space,
    &gui_space,
    &shift_esc,
    NULL
};

/* |`OSM(mod)`  |Hold `mod` for one keypress       | */
/* |`OSL(layer)`|Switch to `layer` for one keypress| */
/* |`OS_ON`     |Turns One Shot keys on            | */
/* |`OS_OFF`    |Turns One Shot keys off           | */
/* |`OS_TOGG`   |Toggles One Shot keys status      | */
