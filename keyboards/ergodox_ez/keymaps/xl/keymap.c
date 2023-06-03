/*
 * Link: https://configure.ergodox-ez.com/layouts/mORP/latest/0
 */
#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define MACRO_DELAY _delay_ms(50)
#define SHORT_DELAY _delay_ms(10)

enum layers {
    WORKMAN,  // workman layout
    QWERTY,   // qwerty layer
    SYMB,     // symbols
    IDEA,     // idea shortcuts (based on windows shortcuts)
    MAGIC,    // layer of bootmagic, keep it biggest to avoid other layer has transparent key and therefore key in this layer is pressed by mistake
};

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
  TOGGLE_LOG
};

bool log_enable = false;

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

  [WORKMAN] = LAYOUT_ergodox(
      // left hand
      KC_GRAVE         , KC_1             , KC_2            , KC_3         , KC_4           , KC_5      , KC_HOME     ,
      KC_TAB           , KC_Q             , KC_D            , KC_R         , KC_W           , KC_B      , KC_LEFT_BRACKET ,
      CTL_T(KC_ESCAPE) , KC_A             , KC_S            , KC_H         , KC_T           , KC_G      ,
      SC_LSPO          , KC_Z             , KC_X            , KC_M         , KC_C           , KC_V      , KC_MINUS    ,
      MO(SYMB)         , KC_LEFT          , ALT_T(KC_RIGHT) , GUI_T(KC_UP) , MEH_T(KC_DOWN) ,
      OSL(IDEA)        , MO(MAGIC)        ,
      KC_PGUP          ,
      KC_ENTER         , QK_LEAD          , KC_PGDN       ,
      // right hand
      KC_END           , KC_6             , KC_7            , KC_8         , KC_9           , KC_0      , KC_BACKSPACE   ,
      KC_RIGHT_BRACKET , KC_J             , KC_F            , KC_U         , KC_P           , KC_SEMICOLON , KC_BACKSLASH   ,
       KC_Y            , KC_N             , KC_E            , KC_O         , KC_I           , LT(IDEA   , KC_QUOTE)   ,
      KC_EQUAL         , KC_K             , KC_L            , KC_COMMA     , KC_DOT         , KC_SLASH  , SC_RSPC     ,
      KC_SPACE         , RGUI_T(KC_EQUAL) , KC_RALT         , KC_RIGHT_CTRL, TT(SYMB)       ,
      KC_LEFT          , KC_RIGHT         ,
      KC_UP            ,
      KC_DOWN          , KC_DELETE        , TG(QWERTY)
      ),

  [QWERTY] = LAYOUT_ergodox(
      // left hand
      KC_GRAVE         , KC_1    , KC_2            , KC_3         , KC_4           , KC_5 , KC_HOME     ,
      KC_TAB           , KC_Q    , KC_W            , KC_E         , KC_R           , KC_T , KC_LEFT_BRACKET ,
      CTL_T(KC_ESCAPE) , KC_A    , KC_S            , KC_D         , KC_F           , KC_G ,
      SC_LSPO          , KC_Z    , KC_X            , KC_C         , KC_V           , KC_B , KC_MINUS    ,
      MO(SYMB)         , KC_LEFT , ALT_T(KC_RIGHT) , GUI_T(KC_UP) , MEH_T(KC_DOWN) ,
      OSL(IDEA), MO(MAGIC),
      KC_PGUP,
      KC_ENTER,	QK_LEAD,	KC_PAGE_DOWN,
      // right hand
      KC_END      , KC_6             , KC_7    , KC_8     , KC_9      , KC_0     , KC_BACKSPACE ,
      KC_RIGHT_BRACKET , KC_Y        , KC_U    , KC_I     , KC_O      , KC_P     , KC_BACKSLASH ,
      KC_H        , KC_J             , KC_K    , KC_L     , KC_SEMICOLON , LT(IDEA, KC_QUOTE) ,
      KC_EQUAL    , KC_N             , KC_M    , KC_COMMA , KC_DOT    , KC_SLASH , SC_RSPC   ,
      KC_SPACE    , RGUI_T(KC_EQUAL) , KC_RALT , KC_RIGHT_CTRL , TT(SYMB)  ,
      KC_LEFT,KC_RIGHT,
      KC_UP,
      KC_DOWN,KC_DELETE, _______
      ),

  [SYMB] = LAYOUT_ergodox(
      // left hand
      VRSN    , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   ,
      QK_BOOT, KC_EXLM , KC_AT   , KC_LCBR , KC_RCBR , KC_PIPE , KC_TRNS ,
      SOURCE  , KC_HASH , KC_DLR  , KC_LPRN , KC_RPRN , KC_GRV  ,
      KC_TRNS , KC_PERC , KC_CIRC , KC_LBRC , KC_RBRC , KC_TILD , KC_TRNS ,
      EPRM    , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,
      KC_MPRV , KC_MNXT,
      KC_MPLY,
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
         _______ , MAGIC_TOGGLE_CTL_GUI , _______                , _______              , _______                , _______        , _______ ,
         _______ , _______              , _______                , _______              , _______                ,
                                             _______, _______,
                                                      _______,
                                    _______, _______, _______,
      // right hand
         TOGGLE_LOG,  _______, _______, _______, _______, _______, _______,
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

/*
void matrix_init_user(void) {
};
*/

// idea shortcuts that opens the folder of current file in navigation bar
void open_current_folder(void) {
  SEND_STRING (SS_DOWN(X_LALT)SS_TAP(X_HOME)SS_UP(X_LALT));
  _delay_ms(50);
  SEND_STRING (SS_TAP(X_DOWN));
}

void copy_relative_path(void) {
  SEND_STRING(SS_LCTL(SS_LALT(SS_LSFT("c"))));
}

// open file, file path is copied to clipboard
void open_file_clipboard(void) {
  MACRO_DELAY;
  SEND_STRING(":");
  MACRO_DELAY;
  SEND_STRING("e ");
  MACRO_DELAY;
  SEND_STRING(SS_LCTL("v"));
  MACRO_DELAY;
  SEND_STRING(SS_TAP(X_ENTER));
}

// navigation bar is opened, a file is under cursor, open the file in vertical split window
void vs_file(void) {
  copy_relative_path();
  MACRO_DELAY;
  SEND_STRING(SS_TAP(X_ESCAPE));
  MACRO_DELAY;
  SEND_STRING(SS_LCTL("h"));
  open_file_clipboard();
}

// Leader key
void leader_start_user(void) {

}

void leader_end_user(void) {
  if (leader_sequence_one_key(KC_S)) {
      vs_file();
  }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  /*
  if (log_enable) {
    uint8_t layer = biton32(layer_state);
    uprintf ("%d,%d,%d,%d\n", record->event.key.col,
        record->event.key.row, record->event.pressed, layer);
  }
  */

  if (record->event.pressed) {
    switch (keycode) {
      // dynamically generate these.
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      case SOURCE:
        SEND_STRING ("https://github.com/xiluo58/qmk_firmware/blob/master/keyboards/ergodox_ez/keymaps/xl/keymap.c");
        return false;
        // IDEA shortcuts
      case SEARCH_EVERYWHERE:
        SEND_STRING (SS_TAP(X_LEFT_SHIFT)SS_TAP(X_LEFT_SHIFT));
        return false;
      case NB_FOLDER:
        open_current_folder();
        return false;
      case NB_VS:
        vs_file();
        return false;
      case NB_HTML:
        open_current_folder();
        MACRO_DELAY;
        SEND_STRING("component.html");
        return false;
      case NB_STYLE:
        open_current_folder();
        MACRO_DELAY;
        SEND_STRING("component.less");
        return false;
      case NB_SPEC:
        open_current_folder();
        MACRO_DELAY;
        SEND_STRING("component.spec.ts");
        return false;
      case NB_TS:
        open_current_folder();
        MACRO_DELAY;
        SEND_STRING("component.ts"SS_TAP(X_DOWN));
        return false;
      case HIDE_ALL:
        SEND_STRING(SS_DOWN(X_LEFT_CTRL)SS_DOWN(X_LEFT_SHIFT)SS_TAP(X_F12)SS_UP(X_LEFT_SHIFT)SS_UP(X_LEFT_CTRL));
        return false;
      case RUN_TASK:
        SEND_STRING(SS_DOWN(X_LEFT_ALT)SS_TAP(X_F11)SS_UP(X_LEFT_ALT));
        return false;
      case TOGGLE_LOG:
        ergodox_led_all_on();
        wait_ms(100);
        ergodox_led_all_off();
        log_enable = !log_enable;
        return false;
    }
  }
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {

  uint8_t layer = get_highest_layer(state);

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
