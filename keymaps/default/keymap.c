#include QMK_KEYBOARD_H
#include "keymap_steno.h"
enum {
    TD_POWER_SLEEP

    
};
qk_tap_dance_action_t tap_dance_actions[] = {

	[TD_POWER_SLEEP]=ACTION_TAP_DANCE_DOUBLE(KC_SYSTEM_SLEEP, KC_SYSTEM_POWER)

};
const uint16_t PROGMEM test_combo1[] = {DF(0), DF(1), COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(test_combo1, TG(4)),
    
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0]=LAYOUT_all(
		KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, 
		KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_ENT, 
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, 
		KC_LGUI, KC_LCTL, KC_LALT, DF(0), KC_SPC, KC_SPC, DF(1), DF(2), KC_TAB, KC_BSPC),

	[1]=LAYOUT_all(
		KC_1, KC_2, KC_3, KC_PLUS, KC_MINUS, KC_TRNS, KC_GRAVE, KC_RBRC, KC_LBRC, KC_BSLASH, 
		KC_4, KC_5, KC_6, KC_ASTERISK,KC_SLASH , KC_DOLLAR, KC_SCOLON, KC_RPRN, KC_LPRN, KC_ENT, 
		MT(MOD_LSFT, KC_7), KC_8, KC_9, KC_EQUAL, KC_PERCENT, KC_AMPERSAND, KC_QUOTE, KC_RCBR, KC_LCBR, KC_ESC, 
		KC_LGUI, MT(MOD_LCTL,KC_0), KC_LALT, DF(0), KC_SPC, KC_SPC, DF(1), DF(2), KC_TRNS, KC_BSPC),
	[2]=LAYOUT_all(
		KC_WAKE, TD(TD_POWER_SLEEP),KC_TRNS, RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DF(3), 
		KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT, 
		KC_LSFT, KC_TRNS, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_LGUI, KC_LCTL, KC_LALT, DF(0), KC_SPC, KC_SPC, DF(1), DF(2), KC_TAB, KC_BSPC),
	
	[ 3] = LAYOUT_all(
  		    
  		STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR ,
  		STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR ,
  		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  		XXXXXXX, XXXXXXX, STN_A,   STN_O,   XXXXXXX, STN_E,   STN_U,   XXXXXXX, XXXXXXX, DF(2)
	),
	[4]=LAYOUT_all(
		KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, 
		KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_ENT, 
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, 
		KC_LGUI, KC_LCTL, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_SPC, TG(4), KC_TAB, KC_BSPC)
	};
