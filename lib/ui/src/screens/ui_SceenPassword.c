// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: GUI_v1

#include "../ui.h"

void ui_SceenPassword_screen_init(void)
{
ui_SceenPassword = lv_obj_create(NULL);
lv_obj_clear_flag( ui_SceenPassword, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_PanelPassword = lv_obj_create(ui_SceenPassword);
lv_obj_set_width( ui_PanelPassword, lv_pct(100));
lv_obj_set_height( ui_PanelPassword, lv_pct(100));
lv_obj_set_align( ui_PanelPassword, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_PanelPassword, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_PanelPassword, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_PanelPassword, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label41 = lv_label_create(ui_PanelPassword);
lv_obj_set_width( ui_Label41, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label41, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label41, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_Label41,"PASSWORD SETTING");
lv_obj_set_style_text_color(ui_Label41, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label41, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label41, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_areaPWCurrent = lv_textarea_create(ui_PanelPassword);
lv_obj_set_width( ui_areaPWCurrent, 160);
lv_obj_set_height( ui_areaPWCurrent, LV_SIZE_CONTENT);   /// 30
lv_obj_set_x( ui_areaPWCurrent, 0 );
lv_obj_set_y( ui_areaPWCurrent, -80 );
lv_obj_set_align( ui_areaPWCurrent, LV_ALIGN_CENTER );
lv_textarea_set_max_length(ui_areaPWCurrent,10);
lv_textarea_set_placeholder_text(ui_areaPWCurrent,"Old passcode");
lv_textarea_set_one_line(ui_areaPWCurrent,true);
lv_textarea_set_password_mode(ui_areaPWCurrent, true);
lv_obj_set_style_text_letter_space(ui_areaPWCurrent, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_line_space(ui_areaPWCurrent, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_areaPWCurrent, &lv_font_montserrat_10, LV_PART_MAIN| LV_STATE_DEFAULT);



ui_areaPWNew = lv_textarea_create(ui_PanelPassword);
lv_obj_set_width( ui_areaPWNew, 160);
lv_obj_set_height( ui_areaPWNew, LV_SIZE_CONTENT);   /// 30
lv_obj_set_x( ui_areaPWNew, 0 );
lv_obj_set_y( ui_areaPWNew, -10 );
lv_obj_set_align( ui_areaPWNew, LV_ALIGN_CENTER );
lv_textarea_set_max_length(ui_areaPWNew,10);
lv_textarea_set_placeholder_text(ui_areaPWNew,"New passcode");
lv_textarea_set_one_line(ui_areaPWNew,true);
lv_textarea_set_password_mode(ui_areaPWNew, true);
lv_obj_set_style_text_letter_space(ui_areaPWNew, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_line_space(ui_areaPWNew, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_areaPWNew, &lv_font_montserrat_10, LV_PART_MAIN| LV_STATE_DEFAULT);



ui_areaPWConfirm = lv_textarea_create(ui_PanelPassword);
lv_obj_set_width( ui_areaPWConfirm, 160);
lv_obj_set_height( ui_areaPWConfirm, LV_SIZE_CONTENT);   /// 30
lv_obj_set_x( ui_areaPWConfirm, 0 );
lv_obj_set_y( ui_areaPWConfirm, 55 );
lv_obj_set_align( ui_areaPWConfirm, LV_ALIGN_CENTER );
lv_textarea_set_max_length(ui_areaPWConfirm,10);
lv_textarea_set_placeholder_text(ui_areaPWConfirm,"Verify new passcode");
lv_textarea_set_one_line(ui_areaPWConfirm,true);
lv_textarea_set_password_mode(ui_areaPWConfirm, true);
lv_obj_set_style_text_letter_space(ui_areaPWConfirm, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_line_space(ui_areaPWConfirm, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_areaPWConfirm, &lv_font_montserrat_10, LV_PART_MAIN| LV_STATE_DEFAULT);



ui_areaPWPadding = lv_textarea_create(ui_PanelPassword);
lv_obj_set_width( ui_areaPWPadding, 160);
lv_obj_set_height( ui_areaPWPadding, LV_SIZE_CONTENT);   /// 30
lv_obj_set_x( ui_areaPWPadding, 0 );
lv_obj_set_y( ui_areaPWPadding, -80 );
lv_obj_set_align( ui_areaPWPadding, LV_ALIGN_CENTER );
lv_textarea_set_max_length(ui_areaPWPadding,10);
lv_textarea_set_one_line(ui_areaPWPadding,true);
lv_textarea_set_password_mode(ui_areaPWPadding, true);
lv_obj_add_flag( ui_areaPWPadding, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_set_style_text_letter_space(ui_areaPWPadding, 4, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_line_space(ui_areaPWPadding, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_areaPWPadding, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);



ui_btnBackPW = lv_btn_create(ui_SceenPassword);
lv_obj_set_width( ui_btnBackPW, 50);
lv_obj_set_height( ui_btnBackPW, 23);
lv_obj_set_x( ui_btnBackPW, 5 );
lv_obj_set_y( ui_btnBackPW, -5 );
lv_obj_set_align( ui_btnBackPW, LV_ALIGN_BOTTOM_LEFT );
lv_obj_add_flag( ui_btnBackPW, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_btnBackPW, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_btnBackPW, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_btnBackPW, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_btnBackPW, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_BackFinger8 = lv_label_create(ui_btnBackPW);
lv_obj_set_width( ui_BackFinger8, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_BackFinger8, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_BackFinger8, LV_ALIGN_CENTER );
lv_label_set_text(ui_BackFinger8,"Back");
lv_obj_set_style_text_color(ui_BackFinger8, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_BackFinger8, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_BackFinger8, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label37 = lv_label_create(ui_SceenPassword);
lv_obj_set_width( ui_Label37, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label37, LV_SIZE_CONTENT);   /// 1
// lv_obj_set_x( ui_Label37, 0 );
lv_obj_set_y( ui_Label37, -33 );
lv_obj_set_align( ui_Label37, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label37,"6-digit passcode");
lv_obj_set_style_text_color(ui_Label37, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label37, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label37, &lv_font_montserrat_10, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_btnChangePW = lv_btn_create(ui_SceenPassword);
lv_obj_set_width( ui_btnChangePW, 70);
lv_obj_set_height( ui_btnChangePW, 35);
lv_obj_set_x( ui_btnChangePW, 0 );
lv_obj_set_y( ui_btnChangePW, 105 );
lv_obj_set_align( ui_btnChangePW, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_btnChangePW, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_btnChangePW, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_btnChangePW, lv_color_hex(0x90A6D3), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_btnChangePW, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label38 = lv_label_create(ui_btnChangePW);
lv_obj_set_width( ui_Label38, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label38, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label38, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label38,"CHANGE");

ui_KeyboardChangePW = lv_keyboard_create(ui_SceenPassword);
lv_keyboard_set_mode(ui_KeyboardChangePW,LV_KEYBOARD_MODE_NUMBER);
lv_obj_set_height( ui_KeyboardChangePW, 200);
lv_obj_set_width( ui_KeyboardChangePW, lv_pct(100));
lv_obj_set_align( ui_KeyboardChangePW, LV_ALIGN_BOTTOM_MID );
lv_obj_add_flag( ui_KeyboardChangePW, LV_OBJ_FLAG_HIDDEN );   /// Flags

ui_areaNotifyChangePW = lv_textarea_create(ui_SceenPassword);
lv_obj_set_height( ui_areaNotifyChangePW, 80);
lv_obj_set_width( ui_areaNotifyChangePW, lv_pct(80));
lv_obj_set_align( ui_areaNotifyChangePW, LV_ALIGN_CENTER );
lv_textarea_set_placeholder_text(ui_areaNotifyChangePW,"Placeholder...");
lv_obj_add_flag( ui_areaNotifyChangePW, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_set_style_text_align(ui_areaNotifyChangePW, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_areaNotifyChangePW, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);
// lv_obj_set_style_shadow_width(ui_areaNotifyChangePW, 50, LV_PART_MAIN| LV_STATE_DEFAULT);
// lv_obj_set_style_shadow_spread(ui_areaNotifyChangePW, 20, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_left(ui_areaNotifyChangePW, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_areaNotifyChangePW, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_areaNotifyChangePW, 28, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_areaNotifyChangePW, 0, LV_PART_MAIN| LV_STATE_DEFAULT);



lv_obj_add_event_cb(ui_areaPWCurrent, ui_event_areaPWCurrent, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_areaPWNew, ui_event_areaPWNew, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_areaPWConfirm, ui_event_areaPWConfirm, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_PanelPassword, ui_event_PanelPassword, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_btnBackPW, ui_event_btnBackPW, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_btnChangePW, ui_event_btnChangePW, LV_EVENT_ALL, NULL);
lv_keyboard_set_textarea(ui_KeyboardChangePW,ui_areaPWPadding);
lv_obj_add_event_cb(ui_KeyboardChangePW, ui_event_KeyboardChangePWOk, LV_EVENT_PRESSED, NULL);

}
