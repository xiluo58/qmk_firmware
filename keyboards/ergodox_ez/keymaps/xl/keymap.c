/*
 * Link: https://configure.ergodox-ez.com/layouts/mORP/latest/0
 */
#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MAGIC 2 // layer of bootmagic

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  SOURCE,
  RGB_SLD,

};

/*
 all translate layer to be copied and modified
[] = LAYOUT_ergodox(
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______,  _______, _______, _______, _______, _______, _______,
       _______,  _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______,
       _______,  _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_ergodox(
      // left hand
      KC_GRAVE         , KC_1    , KC_2            , KC_3         , KC_4           , KC_5 , KC_HOME     ,
      KC_TAB           , KC_Q    , KC_W            , KC_E         , KC_R           , KC_T , KC_LBRACKET ,
      CTL_T(KC_ESCAPE) , KC_A    , KC_S            , KC_D         , KC_F           , KC_G ,
      KC_LSPO          , KC_Z    , KC_X            , KC_C         , KC_V           , KC_B , KC_MINUS    ,
      MO(SYMB)         , KC_LEFT , ALT_T(KC_RIGHT) , GUI_T(KC_UP) , MEH_T(KC_DOWN) ,
      MO(MAGIC),	TG(SYMB),
      KC_PGUP,
      KC_ENTER,	KC_LSHIFT,	KC_PGDOWN,
      // right hand
      KC_END      , KC_6             , KC_7    , KC_8     , KC_9      , KC_0     , KC_BSPACE ,
      KC_RBRACKET , KC_Y             , KC_U    , KC_I     , KC_O      , KC_P     , KC_BSLASH ,
      KC_H        , KC_J             , KC_K    , KC_L     , KC_SCOLON , KC_QUOTE ,
      KC_EQUAL    , KC_N             , KC_M    , KC_COMMA , KC_DOT    , KC_SLASH , KC_RSPC   ,
      KC_SPACE    , RGUI_T(KC_EQUAL) , KC_RALT , KC_RCTRL , MO(SYMB)  ,
      KC_LEFT,KC_RIGHT,
      KC_UP,
      KC_DOWN,KC_DELETE,KC_SPACE
      ),

      [SYMB] = LAYOUT_ergodox(
          // left hand
          VRSN    , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   ,
          RESET   , KC_EXLM , KC_AT   , KC_LCBR , KC_RCBR , KC_PIPE , KC_TRNS ,
          SOURCE  , KC_HASH , KC_DLR  , KC_LPRN , KC_RPRN , KC_GRV  ,
          KC_TRNS , KC_PERC , KC_CIRC , KC_LBRC , KC_RBRC , KC_TILD , KC_TRNS ,
          EPRM    , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,
          RGB_MOD,KC_TRNS,
          KC_TRNS,
          RGB_VAD,RGB_VAI,KC_TRNS,
          // right hand
          KC_F7   , KC_F8   , KC_F9 , KC_F10 , KC_F11  , KC_F12  , _______ ,
          KC_TRNS , KC_UP   , KC_7  , KC_8   , KC_9    , KC_ASTR , _______ ,
          KC_DOWN , KC_4    , KC_5  , KC_6   , KC_PLUS , KC_TRNS ,
          KC_TRNS , KC_AMPR , KC_1  , KC_2   , KC_3    , KC_BSLS , KC_TRNS ,
          KC_TRNS , KC_DOT  , KC_0  , KC_EQL , KC_TRNS ,
          _______, _______,
          KC_TRNS,
          KC_TRNS, _______, _______
          ),

      [MAGIC] = LAYOUT_ergodox(
             AG_SWAP, AG_NORM, AG_TOGG, _______, _______, _______, _______,
             _______, _______, _______, _______, _______, _______, _______,
             _______, _______, _______, _______, _______, _______,
             _______, _______, _______, _______, _______, _______, _______,
             _______, _______, _______, _______, _______,
                                                 _______, _______,
                                                          _______,
                                        _______, _______, _______,
          // right hand
             _______,  _______, _______, _______, _______, _______, _______,
             _______,  _______, _______, _______, _______, _______, _______,
                       _______, _______, _______, _______, _______, _______,
             _______,  _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______,
             _______, _______,
             _______,
             _______, _______, _______
      ),
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
  }
  return MACRO_NONE;
};

void matrix_init_user(void) {
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case SOURCE:
      if (record->event.pressed) {
        SEND_STRING ("https://github.com/xiluo58/qmk_firmware/blob/master/keyboards/ergodox_ez/keymaps/xl/keymap.c");
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;

  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

  uint8_t layer = biton32(state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 0:
      break;
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;

};
