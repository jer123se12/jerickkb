#include QMK_KEYBOARD_H
#include "keymap_steno.h"

    
enum custom_keycodes {
    LAYER0 = SAFE_RANGE,
    PU,
    PD,
    TS,
    SV,
    RN
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0]=LAYOUT_all(
		KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, 
		KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_ENT, 
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, 
		KC_LGUI, KC_LCTL, KC_LALT, KC_BSPC, KC_SPC, KC_SPC, MO(1), MO(2), KC_TAB, KC_BSPC),

	[1]=LAYOUT_all(
		KC_1, KC_2, KC_3, KC_PLUS, KC_MINUS, KC_TRNS, KC_GRAVE, KC_RBRC, KC_LBRC, KC_BSLASH, 
		KC_4, KC_5, KC_6, KC_ASTERISK,KC_SLASH , KC_DOLLAR, KC_SCOLON, KC_RPRN, KC_LPRN, KC_ENT, 
		MT(MOD_LSFT, KC_7), KC_8, KC_9, KC_EQUAL, KC_PERCENT, KC_AMPERSAND, KC_QUOTE, KC_RCBR, KC_LCBR, KC_ESC, 
		MT(KC_LGUI,KC_DOT), MT(MOD_LCTL,KC_0), KC_LALT, KC_BSPC, KC_SPC, KC_SPC, MO(1), MO(2), KC_TRNS, KC_BSPC),
	[2]=LAYOUT_all(
		KC_WAKE, KC_TRNS,KC_TRNS, RESET, SV,RN, PD, PU,TS , DF(3), 
		KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT, 
		KC_LSFT, KC_TRNS, KC_VOLU, KC_VOLD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_LGUI, KC_LCTL, KC_LALT, KC_BSPC, KC_SPC, KC_SPC, MO(4), MO(2), KC_TAB, KC_BSPC),
	
	[ 3] = LAYOUT_all(
  		    
  		STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR ,
  		STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR ,
  		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  		XXXXXXX, XXXXXXX, STN_A,   STN_O,   XXXXXXX, STN_E,   STN_U,   XXXXXXX, XXXXXXX, DF(0)
	),
	[4]=LAYOUT_all(
		KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10, 
		KC_F11,KC_F12,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, 
		XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, 
		XXXXXXX,XXXXXXX,XXXXXXX,LALT(LCTL(KC_DEL)),XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX )
	};


float pitch=440.f;
float step= 105.946309436;
bool rn=true;
bool on=true;

float my_song[][2] = SONG(QWERTY_SOUND);
float reject_song[][2]          = SONG(GOODBYE_SOUND);
void keyboard_post_init_user(void) {
	pitch =rgblight_get_sat();
	on=rgblight_get_hue();
	rn=rgblight_get_val();
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) {
		if (keycode ==PU ){if(pitch<100){ pitch+=1;}
		}else if (keycode ==PD){if(pitch>12){ pitch-=1;}
		}else if (keycode==SV){
				PLAY_SONG(my_song);
				rgblight_sethsv(on, pitch,rn);
			layer_move(0);}else if (keycode==TS){on=!on;}else if (keycode==RN){rn=!rn;}
		if (on==1){
		audio_play_note((pitch+(rand()%7*rn))*step, 5);
		}
	}
		return true;
}
