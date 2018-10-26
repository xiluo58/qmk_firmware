/*
 * Link: https://configure.ergodox-ez.com/layouts/mORP/latest/0
 */
#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define IDEA 2 // idea shortcuts (based on windows shortcuts)
#define MAGIC 3 // layer of bootmagic, keep it biggest to avoid other layer has transparent key and therefore key in this layer is pressed by mistake

#define MACRO_DELAY _delay_ms(50)
#define SHORT_DELAY _delay_ms(10)

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  SOURCE,
  // idea shortcuts
  SEARCH_EVERYWHERE,
  NB_FOLDER, // open folder of current file in navigation bar
  NB_VS, // in navigation bar, open file under cursor in vertical split window
  NB_HTML,
  NB_STYLE,
  NB_SPEC,
  NB_TS,
  RUN_TASK,
  HIDE_ALL,
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
      OSL(IDEA), MO(MAGIC),
      KC_PGUP,
      KC_ENTER,	KC_LEAD,	KC_PGDOWN,
      // right hand
      KC_END      , KC_6             , KC_7    , KC_8     , KC_9      , KC_0     , KC_BSPACE ,
      KC_RBRACKET , KC_Y             , KC_U    , KC_I     , KC_O      , KC_P     , KC_BSLASH ,
      KC_H        , KC_J             , KC_K    , KC_L     , KC_SCOLON , LT(IDEA, KC_QUOTE) ,
      KC_EQUAL    , KC_N             , KC_M    , KC_COMMA , KC_DOT    , KC_SLASH , KC_RSPC   ,
      KC_SPACE    , RGUI_T(KC_EQUAL) , KC_RALT , KC_RCTRL , MO(SYMB)  ,
      KC_LEFT,KC_RIGHT,
      KC_UP,
      KC_DOWN,KC_DELETE, OSL(IDEA)
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
          KC_0 , KC_DOT  , _______  , KC_EQL , KC_TRNS ,
          _______, _______,
          KC_TRNS,
          KC_TRNS, _______, _______
          ),

      /*
        MAGIC_HOST_NKRO   Force N-Key Rollover (NKRO) on
        MAGIC_UNHOST_NKRO   Force NKRO off
        MAGIC_TOGGLE_NKRO   Turn NKRO on or off
        MAGIC_NO_GUI    Disable the GUI keys (useful when gaming)
        MAGIC_UNNO_GUI    Enable the GUI keys
        MAGIC_SWAP_ALT_GUI  AG_SWAP Swap Alt and GUI on both sides (for macOS)
        MAGIC_UNSWAP_ALT_GUI  AG_NORM Unswap Left Alt and Left GUI
        MAGIC_TOGGLE_ALT_GUI  AG_TOGG Toggle Left Alt and GUI swap
        MAGIC_SWAP_LALT_LGUI    Swap Left Alt and Left GUI
        MAGIC_UNSWAP_LALT_LGUI    Unswap Left Alt and Left GUI
        MAGIC_SWAP_RALT_RGUI    Swap Right Alt and Right GUI
        MAGIC_UNSWAP_RALT_RGUI    Unswap Right Alt and Right GUI
      */

      [MAGIC] = LAYOUT_ergodox(
             _______ , MAGIC_HOST_NKRO      , MAGIC_UNHOST_NKRO      , MAGIC_TOGGLE_NKRO    , MAGIC_NO_GUI           , MAGIC_UNNO_GUI , _______ ,
             _______ , MAGIC_SWAP_ALT_GUI   , MAGIC_UNSWAP_ALT_GUI   , MAGIC_TOGGLE_ALT_GUI , _______                , _______        , _______ ,
             _______ , MAGIC_SWAP_LALT_LGUI , MAGIC_UNSWAP_LALT_LGUI , MAGIC_SWAP_RALT_RGUI , MAGIC_UNSWAP_RALT_RGUI , _______        ,
             _______ , _______              , _______                , _______              , _______                , _______        , _______ ,
             _______ , _______              , _______                , _______              , _______                ,
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

      [IDEA] = LAYOUT_ergodox(
             _______ , _______ , _______ , _______ , _______   , _______ , _______           ,
             _______ , _______ , _______ , _______ , _______   , _______ , _______           ,
             _______ , NB_STYLE , NB_HTML , NB_TS  , NB_SPEC, NB_FOLDER ,
             _______ , _______ , _______ , _______ , NB_VS   , _______ , SEARCH_EVERYWHERE ,
             _______ , _______ , _______ , _______ , _______   ,
                                                 _______, _______,
                                                          _______,
                                        _______, _______, _______,
          // right hand
             _______,  _______, _______, _______, RUN_TASK, HIDE_ALL, _______,
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

// idea shortcuts that opens the folder of current file in navigation bar
void open_current_folder(void) {
  SEND_STRING (SS_DOWN(X_LALT)SS_TAP(X_HOME)SS_UP(X_LALT));
  _delay_ms(50);
  SEND_STRING (SS_TAP(X_DOWN));
}

void copy_relative_path(void) {
  SEND_STRING(SS_LCTRL(SS_LALT(SS_LSFT("c"))));
}

// open file, file path is copied to clipboard
void open_file_clipboard(void) {
  MACRO_DELAY;
  SEND_STRING(":");
  MACRO_DELAY;
  SEND_STRING("e ");
  MACRO_DELAY;
  SEND_STRING(SS_LCTRL("v"));
  MACRO_DELAY;
  SEND_STRING(SS_TAP(X_ENTER));
}

// navigation bar is opened, a file is under cursor, open the file in vertical split window
void vs_file(void) {
  copy_relative_path();
  MACRO_DELAY;
  SEND_STRING(SS_TAP(X_ESCAPE));
  MACRO_DELAY;
  SEND_STRING(SS_LCTRL("h"));
  open_file_clipboard();
}

// Leader key
LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_S) {
      vs_file();
    }
  }
}


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
    // IDEA shortcuts
    case SEARCH_EVERYWHERE:
      if (record->event.pressed) {
        SEND_STRING (SS_TAP(X_LSHIFT)SS_TAP(X_LSHIFT));
      }
      return false;
      break;
    case NB_FOLDER:
      if (record->event.pressed) {
        open_current_folder();
      }
      return false;
      break;
    case NB_VS:
      if (record->event.pressed) {
        vs_file();
      }
      return false;
      break;
    case NB_HTML:
      if (record->event.pressed) {
        open_current_folder();
        SEND_STRING("component.html");
      }
      return false;
      break;
    case NB_STYLE:
      if (record->event.pressed) {
        open_current_folder();
        SEND_STRING("component.less");
      }
      return false;
      break;
    case NB_SPEC:
      if (record->event.pressed) {
        open_current_folder();
        SEND_STRING("component.spec.ts");
      }
      return false;
      break;
    case NB_TS:
      if (record->event.pressed) {
        open_current_folder();
        SEND_STRING("component.ts"SS_TAP(X_DOWN));
      }
      return false;
      break;
    case HIDE_ALL:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LSHIFT)SS_TAP(X_F12)SS_UP(X_LSHIFT)SS_UP(X_LCTRL));
      }
      return false;
      break;
    case RUN_TASK:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_F11)SS_UP(X_LALT));
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
