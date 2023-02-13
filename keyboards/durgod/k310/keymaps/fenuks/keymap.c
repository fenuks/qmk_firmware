/* Copyright 2021 Don Kjer and Tyler Tidman
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
* │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│ │INS│HOM│PgU│ │NUM│ / │ * │ - │
* ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
* │ Tab │ ' │ , │ . │ P │ Y │ F │ G │ C │ R │ L │ [ │ ] │     │ │DEL│END│PgD│ │ 7 │ 8 │ 9 │   │
* ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐  ↲ │ └───┴───┴───┘ ├───┼───┼───┤ + │
* │ Caps │ A │ O │ E │ U │ I │ D │ H │ T │ N │ S │ - │ \ │    │               │ 7 │ 8 │ 9 │   │
* ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤     ┌───┐     ├───┼───┼───┼───┤
* │Shif│ < │ ; │ Q │ J │ K │ X │ B │ M │ W │ V │ Z │    Shift │     │ ↑ │     │ 1 │ 2 │ 3 │   │
* ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐ ├───┴───┼───┤ ↲ │
* │Ctrl│GUI │Alt │                        │ Alt│ GUI│Fn  │Ctrl│ │ ← │ ↓ │ → │ │   0   │ , │   │
* └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘ └───────┴───┴───┘
*/

/* Layers */
enum layer_names {
    KM_DVORAK,
    KM_DVORAK_MEDIA,
    KM_DVORAK_NUM,
    KM_DVORAK_VIM,

    KM_QWERTY,
    KM_QWERTY_MEDIA,
    KM_QWERTY_VIM,
};

/* // Defines the keycodes used by our macros in process_record_user */
enum custom_keycodes {
    KC_TGUI = SAFE_RANGE,  // Toggle between GUI Lock or Unlock
};

/* key defines */
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

/* home dvorak keys */
#define HD_A LGUI_T(KC_A)
#define HD_O LALT_T(KC_O)
#define HD_E LSFT_T(KC_E)
#define HD_U LCTL_T(KC_U)
#define HD_H RCTL_T(KC_H)
#define HD_T RSFT_T(KC_T)
#define HD_N LALT_T(KC_N)
#define HD_S RGUI_T(KC_S)

#define O_RC OSM(MOD_LCTL)

/* tap dance keys */
enum {
    TAP_DANCE_LCBR,
    TAP_DANCE_RCBR,
    TAP_DANCE_A,
    TAP_DANCE_M,
    TAP_DANCE_U,
};

tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TAP_DANCE_LCBR] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
    [TAP_DANCE_RCBR] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),
    [TAP_DANCE_A]    = ACTION_TAP_DANCE_DOUBLE(KC_A,    RALT(KC_A)),
    [TAP_DANCE_M]    = ACTION_TAP_DANCE_DOUBLE(KC_M,    KC_ENT),
    [TAP_DANCE_U]    = ACTION_TAP_DANCE_DOUBLE(KC_U,    KC_MYCM),
};

#define TD_A TD(TAP_DANCE_A)
#define TD_LB TD(TAP_DANCE_LCBR)
#define TD_RB TD(TAP_DANCE_RCBR)
#define TD_M TD(TAP_DANCE_M)
#define TD_U TD(TAP_DANCE_U)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Dvorak layout (modified)
  * ┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
  * │ESC│   │F1 │F2 │F3 │F4 │ │F5 │F6 │F7 │F8 │ │F9 │F10│F11│F12│ │PRT│SCR│PAU│
  * └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘
  * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
  * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│ │INS│HOM│PgU│ │NUM│ / │ * │ - │
  * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
  * │ Tab │ ' │ , │ . │ P │ Y │ F │ G │ C │ R │ L │ [ │ ] │     │ │DEL│END│PgD│ │ 7 │ 8 │ 9 │   │
  * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐  ↲ │ └───┴───┴───┘ ├───┼───┼───┤ + │
  * │ Caps │ A │ O │ E │ U │ I │ D │ H │ T │ N │ S │ - │ \ │    │               │ 7 │ 8 │ 9 │   │
  * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤     ┌───┐     ├───┼───┼───┼───┤
  * │Shif│ < │ ; │ Q │ J │ K │ X │ B │ M │ W │ V │ Z │    Shift │     │ ↑ │     │ 1 │ 2 │ 3 │   │
  * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐ ├───┴───┼───┤ ↲ │
  * │Ctrl│GUI │Alt │                        │ Alt│ GUI│Fn  │Ctrl│ │ ← │ ↓ │ → │ │   0   │ , │   │
  * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘ └───────┴───┴───┘
  */
        [KM_DVORAK] = LAYOUT_all(
KC_ESC,       KC_F1, KC_F2, KC_F3, KC_F4,  KC_F5,KC_F6,KC_F7,KC_F8,  KC_F9, KC_F10,  KC_F11, KC_F12,     KC_PSCR, DF_Q,    KC_PAUS,
KC_GRV, KC_1, KC_2, KC_3, KC_4,KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_LBRC,KC_RBRC, KC_BSPC, KC_INS,  KC_HOME, KC_PGUP,  KC_NUM, KC_PSLS,KC_PAST,KC_PMNS,
KC_TAB, KC_QUOT,KC_COMM,KC_DOT,KC_P, KC_Y, KC_F,   KC_G, KC_C, KC_R,   KC_L,   KC_SLSH, KC_EQL, KC_BSLS, KC_DEL,  KC_END,  KC_PGDN,  KC_P7,  KC_P8,  KC_P9,  KC_PPLS,
RC_ESC, HD_A,   HD_O,   HD_E,  HD_U, KC_I, KC_D,   HD_H, HD_T, HD_N,   HD_S,   KC_MINS, KC_NUHS,KC_ENT,                              KC_P4,  KC_P5,  KC_P6,
SC_LSPO,KC_UNDS,KC_SCLN,KC_Q,  KC_J, KC_K, KC_X,   KC_B, KC_M, KC_W,   KC_V,   KC_Z,            SC_RSPC,          KC_UP,             KC_P1,  KC_P2,  KC_P3,  KC_PENT,
O_RC,  KC_LGUI,LA_LB,                          KC_SPC,            KC_RALT,    MO_DM,    KC_APP,  KC_RCTL,    KC_LEFT,KC_DOWN,  KC_RGHT,  KC_P0,          KC_PDOT
    ),
        [KM_DVORAK_NUM] = LAYOUT_all(
_______,    _______,_______,_______,_______,  _______,_______,_______,_______,  _______,_______,_______,_______,    _______,_______,_______,
_______,KC_MINS,   KC_7,   KC_5,  KC_3, KC_1, KC_9,   KC_0, KC_2, KC_4,   KC_6,   KC_8, KC_EQL, _______,    _______,_______,_______,           NNN,NNN,NNN,NNN,
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,    _______,_______,_______,   NNN,NNN,NNN,NNN,
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,                               NNN,NNN,NNN,
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,                    _______,           NNN,NNN,NNN,NNN,
_______,_______,_______,                        _______,                        _______,_______,_______,_______,    _______,_______,_______,   NNN,    NNN),
        [KM_DVORAK_MEDIA] = LAYOUT_all(
KC_SLEP,  KC_MPLY, KC_MSTP, KC_MPRV, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,_______,  TG_DV,_______,_______,AS_RPT,      DB_TOGG, PB_1, QK_BOOT,
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______,_______,_______, TG_DN,NNN,NNN,AS_DOWN,
_______,DT_PRNT,DT_DOWN,DT_UP  , KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19,_______,_______,_______,     OS_TOGG,_______,_______, NNN,NNN,NNN,AS_UP,
CW_TOGG, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24,KC_MAIL,KC_WHOM,KC_WBAK,KC_WFWD,KC_WSTP,_______,_______,_______,                              NNN,NNN,NNN,
DM_PLY2,KC_WREF,KC_WFAV,_______,_______,TG_DV  ,_______,_______,_______,_______,_______,_______,DM_REC2,                     _______,         NNN,NNN,NNN,AS_TOGG,
DM_PLY1,KC_TGUI,_______,                  QK_LOCK,                      _______,_______,TG_DV,   DM_REC1,             _______,_______,_______, NNN,    NNN),
        [KM_DVORAK_VIM] = LAYOUT_all(
_______,    _______,_______,_______,_______,  _______,_______,_______,_______,  _______,_______,_______,_______,    _______,KC_SCRL,_______,
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,    _______,_______,_______,   NNN,NNN,NNN,NNN,
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_RGHT,_______,_______,_______,    _______,_______,_______,   NNN,NNN,NNN,NNN,
_______,_______,_______,_______,_______,TG_DV  ,_______,KC_LEFT,_______,TG_DV,  _______,_______,_______,_______,                               NNN,NNN,NNN,
_______,_______,_______,_______,KC_DOWN,KC_UP, _______,C(KC_LEFT),_______,C(KC_RGHT),_______,_______,_______,                    _______,           NNN,NNN,NNN,NNN,
_______,_______,_______,                        _______,                        _______,MO_DM,_______,  _______,    _______,_______,_______,   NNN,    NNN),

  /* Keymap KM_QWERTY
   * ┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
   * │Esc│   │F1 │F2 │F3 │F4 │ │F5 │F6 │F7 │F8 │ │F9 │F10│F11│F12│ │PSc│L_D│Pse│
   * └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
   * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│ │Ins│Hom│PgU│ │Num│ / │ * │ - │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
   * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │ │Del│End│PgD│ │ 7 │ 8 │ 9 │   │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬┈┈┈┈┤ └───┴───┴───┘ ├───┼───┼───┤ + │
   * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ # │Entr│               │ 4 │ 5 │ 6 │   │
   * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤     ┌───┐     ├───┼───┼───┼───┤
   * │Shft│ \ │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │    Shift │     │ ↑ │     │ 1 │ 2 │ 3 │   │
   * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐ ├───┴───┼───┤Ent│
   * │Ctrl│GUI │Alt │                        │ Alt│Func│ App│Ctrl│ │ ← │ ↓ │ → │ │   0   │ . │   │
   * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘ └───────┴───┴───┘
   */
    [KM_QWERTY] = LAYOUT_all(
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,     KC_PSCR, DF_D,   KC_PAUS,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,    KC_INS,  KC_HOME, KC_PGUP,    KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,    KC_DEL,  KC_END,  KC_PGDN,    KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,                                   KC_P4,   KC_P5,   KC_P6,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,             KC_UP,               KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO_QM,    KC_APP,  KC_RCTL,    KC_LEFT, KC_DOWN, KC_RGHT,    KC_P0,            KC_PDOT
    ),
  /* Keymap KM_QWERTY_MEDIA
   * ┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
   * │   │   │Ply│Stp│Prv│Nxt│ │Mut│Vo+│Vo-│   │ │   │   │   │   │ │   │   │Mut│
   * └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
   * │   │   │   │   │   │   │   │   │   │   │   │   │   │       │ │   │   │Vo+│ │   │   │   │   │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
   * │     │   │   │   │   │   │   │   │   │   │   │   │   │     │ │   │   │Vo-│ │   │   │   │   │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬┈┈┈┈┤ └───┴───┴───┘ ├───┼───┼───┤   │
   * │      │   │   │   │   │   │   │   │   │   │   │   │   │    │               │   │   │   │   │
   * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤     ┌───┐     ├───┼───┼───┼───┤
   * │    │   │   │   │   │   │   │   │   │   │   │   │          │     │   │     │   │   │   │   │
   * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐ ├───┴───┼───┤   │
   * │    │Lock│    │                        │    │Func│ Sys│    │ │   │   │   │ │       │   │   │
   * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘ └───────┴───┴───┘
   */
  [KM_QWERTY_MEDIA] = LAYOUT_all( /* Windows Function Layer */
        _______,          KC_MPLY, KC_MSTP, KC_MPRV, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, _______, _______,    _______, _______, KC_MUTE,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, KC_VOLU,    _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, KC_VOLD,    _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                                  _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,             _______,             _______, _______, _______, _______,
        _______, KC_TGUI, _______,                            _______,                            _______, _______,_______,    _______,    _______, _______, _______,    _______,          _______
    ),
};

/* masks */
#define MOD_MASK_RCTRL MOD_BIT(KC_RCTL)
#define MOD_MASK_LCTRL MOD_BIT(KC_LCTL)
#define MOD_MASK_RSHIFT MOD_BIT(KC_RSFT)
#define MOD_MASK_LSHIFT MOD_BIT(KC_LSFT)
#define VIM_LAYER_MASK (1 << KM_QWERTY_VIM)
#define DEF_LAYER_MASK (1 << KM_QWERTY)

const key_override_t shift_esc = ko_make_basic(MOD_MASK_SHIFT, KC_ESC, KC_SLEP);
const key_override_t shift_pause = ko_make_basic(MOD_MASK_SHIFT, KC_PAUS, KC_PWR);
const key_override_t shift_caps = ko_make_basic(MOD_MASK_SHIFT, RC_ESC, KC_CAPS);
/* const key_override_t rshift_space = ko_make_basic(MOD_MASK_RSHIFT, KC_SPC, KC_ENT); */
const key_override_t shift_unds = ko_make_basic(MOD_MASK_SHIFT, KC_UNDS, KC_MINS);
const key_override_t vim_b = ko_make_with_layers(0, KC_B, C(KC_LEFT), VIM_LAYER_MASK);
const key_override_t vim_caret = ko_make_with_layers(MOD_MASK_RSHIFT, KC_6, KC_HOME, VIM_LAYER_MASK);
const key_override_t vim_ctrl_b = ko_make_with_layers(MOD_MASK_RCTRL, KC_B, KC_PGUP, VIM_LAYER_MASK);
const key_override_t vim_ctrl_f = ko_make_with_layers(MOD_MASK_RCTRL, KC_F, KC_PGDN, VIM_LAYER_MASK);
const key_override_t vim_end = ko_make_with_layers(MOD_MASK_RSHIFT, KC_4, KC_END, VIM_LAYER_MASK);

const key_override_t **key_overrides = (const key_override_t *[]){
    &shift_esc,
    &shift_pause,
    &shift_caps,
    /* &rshift_space, */
    &shift_unds,
    &vim_b,
    &vim_caret,
    &vim_ctrl_b,
    &vim_ctrl_f,
    &vim_end,
    NULL
};
/* late initialization */
// void keyboard_post_init_user(void) {
//   debug_enable=true;
//   debug_matrix=true;
//   debug_keyboard=true;
//   /* debug_mouse=true; */
// }

static bool caps_word_active = false;
static bool win_key_locked = false;
static bool recording_macro = false;
static bool dvorak_vim_layer_active = false;

void my_unlock_win_key(void) {
    win_key_locked = false;
    writePinHigh(LED_WIN_LOCK_PIN);
}

void my_toggle_lock_win_key(void) {
    win_key_locked = !win_key_locked;
    writePin(LED_WIN_LOCK_PIN, !win_key_locked);
}

/* runs on caps word state change */
void caps_word_set_user(bool active) {
    caps_word_active = active;
    if (active) {
        writePinLow(LED_CAPS_LOCK_PIN);
    } else {
        bool caps_lock = host_keyboard_led_state().caps_lock;
        if (!caps_lock) {
            writePinHigh(LED_CAPS_LOCK_PIN);
        }
    }
}

/* called when macro recording is started */
void dynamic_macro_record_start_user(void) {
    recording_macro = true;
    writePinLow(LED_MR_LOCK_PIN);
}

/* called when macro recording has ended */
void dynamic_macro_record_end_user(int8_t direction) {
    recording_macro = false;
    writePinHigh(LED_MR_LOCK_PIN);
}

bool led_update_user(led_t led_state) {
    if (caps_word_active && !led_state.caps_lock) {
        /* writePinLow(LED_CAPS_LOCK_PIN); */
        return false;
    }
    if (dvorak_vim_layer_active) {
        return false;
    }
    /* led_state.scroll_lock = dvorak_vim_layer_active; */
    /* led_update_ports(led_state); */
    return true;
}


/* when key should be autoshifted */
bool get_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_SCLN:
            return true;
        default:
            return false;
    }
}

/* Callback for layer functions, for users. */
layer_state_t layer_state_set_user(layer_state_t state) {
    dvorak_vim_layer_active = IS_LAYER_ON_STATE(state, KM_DVORAK_VIM);
#ifdef CONSOLE_ENABLE
    dprintf("Top layer: %u, dvorak_vim_layer_active=%u\n", get_highest_layer(state), dvorak_vim_layer_active);
#endif 
    if (dvorak_vim_layer_active) {
        writePinLow(LED_SCROLL_LOCK_PIN);
    } else {
        writePinHigh(LED_SCROLL_LOCK_PIN);
    }

    return state;
}

/* Callback for default layer functions, for users. Called on keyboard initialization. */
layer_state_t default_layer_state_set_user(layer_state_t state) {
    // Disable windows key lock on default layer transition.
    my_unlock_win_key();
    if (IS_LAYER_ON_STATE(state, KM_QWERTY)) {
        writePinLow(LED_MR_LOCK_PIN);
    } else {
        writePinHigh(LED_MR_LOCK_PIN);
    }
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    dprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif 
    switch (keycode) {
        case KC_TGUI:
            if (!record->event.pressed) {
                // Toggle GUI lock on key release
                my_toggle_lock_win_key();
            }
            break;
        case KC_LGUI:
            if (win_key_locked) { return false; }
            break;
        case QK_BOOT:
            if (record->event.pressed) {
                // Flash LEDs to indicate bootloader mode is enabled.
                on_all_leds();
            }
            break;
    }
    return true;
}
