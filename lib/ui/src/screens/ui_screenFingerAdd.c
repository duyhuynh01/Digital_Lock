// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: GUI_v1

#include "../ui.h"

void ui_screenFingerAdd_screen_init(void)
{
ui_screenFingerAdd = lv_obj_create(NULL);
lv_obj_clear_flag( ui_screenFingerAdd, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_PanelFingerAdd = lv_obj_create(ui_screenFingerAdd);
lv_obj_set_width( ui_PanelFingerAdd, lv_pct(100));
lv_obj_set_height( ui_PanelFingerAdd, lv_pct(100));
lv_obj_set_align( ui_PanelFingerAdd, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_PanelFingerAdd, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_PanelFingerAdd, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_PanelFingerAdd, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label24 = lv_label_create(ui_PanelFingerAdd);
lv_obj_set_width( ui_Label24, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label24, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label24, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_Label24,"Add fingerprint");
lv_obj_set_style_text_color(ui_Label24, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label24, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label24, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_panelAddfinger = lv_obj_create(ui_screenFingerAdd);
lv_obj_set_height( ui_panelAddfinger, 275);
lv_obj_set_width( ui_panelAddfinger, lv_pct(100));
lv_obj_set_align( ui_panelAddfinger, LV_ALIGN_BOTTOM_MID );
lv_obj_clear_flag( ui_panelAddfinger, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_panelAddfinger, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_panelAddfinger, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_panelAddfinger, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label13 = lv_label_create(ui_panelAddfinger);
lv_obj_set_width( ui_Label13, 180);
lv_obj_set_height( ui_Label13, 24);
lv_obj_set_x( ui_Label13, 0 );
lv_obj_set_y( ui_Label13, 100 );
lv_obj_set_align( ui_Label13, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_Label13,"(Optional) Enter a name\n(maximum 7 character)");
lv_obj_set_style_text_color(ui_Label13, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label13, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Label13, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label13, &lv_font_montserrat_10, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_areaEnterNameFP = lv_textarea_create(ui_panelAddfinger);
lv_obj_set_width( ui_areaEnterNameFP, lv_pct(71));
lv_obj_set_height( ui_areaEnterNameFP, LV_SIZE_CONTENT);   /// 45
lv_obj_set_x( ui_areaEnterNameFP, 0 );
lv_obj_set_y( ui_areaEnterNameFP, 60 );
lv_obj_set_align( ui_areaEnterNameFP, LV_ALIGN_TOP_MID );
lv_textarea_set_max_length(ui_areaEnterNameFP,7);
lv_textarea_set_text(ui_areaEnterNameFP,"");
lv_textarea_set_one_line(ui_areaEnterNameFP,true);
lv_obj_set_style_text_align(ui_areaEnterNameFP, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);



ui_btnAddFinger = lv_btn_create(ui_panelAddfinger);
lv_obj_set_width( ui_btnAddFinger, 70);
lv_obj_set_height( ui_btnAddFinger, 35);
lv_obj_set_x( ui_btnAddFinger, 0 );
lv_obj_set_y( ui_btnAddFinger, 50 );
lv_obj_set_align( ui_btnAddFinger, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_btnAddFinger, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_btnAddFinger, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_btnAddFinger, lv_color_hex(0x90A6D3), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_btnAddFinger, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label19 = lv_label_create(ui_btnAddFinger);
lv_obj_set_width( ui_Label19, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label19, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label19, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label19,"ADD");

ui_btnBackAddFP = lv_btn_create(ui_screenFingerAdd);
lv_obj_set_width( ui_btnBackAddFP, 50);
lv_obj_set_height( ui_btnBackAddFP, 23);
lv_obj_set_x( ui_btnBackAddFP, 5 );
lv_obj_set_y( ui_btnBackAddFP, -5 );
lv_obj_set_align( ui_btnBackAddFP, LV_ALIGN_BOTTOM_LEFT );
lv_obj_add_flag( ui_btnBackAddFP, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_btnBackAddFP, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_btnBackAddFP, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_btnBackAddFP, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_btnBackAddFP, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_BackFinger1 = lv_label_create(ui_btnBackAddFP);
lv_obj_set_width( ui_BackFinger1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_BackFinger1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_BackFinger1, LV_ALIGN_CENTER );
lv_label_set_text(ui_BackFinger1,"Back");
lv_obj_set_style_text_color(ui_BackFinger1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_BackFinger1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_BackFinger1, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_btnHomeAddFP = lv_btn_create(ui_screenFingerAdd);
lv_obj_set_width( ui_btnHomeAddFP, 50);
lv_obj_set_height( ui_btnHomeAddFP, 23);
lv_obj_set_x( ui_btnHomeAddFP, -7 );
lv_obj_set_y( ui_btnHomeAddFP, -5 );
lv_obj_set_align( ui_btnHomeAddFP, LV_ALIGN_BOTTOM_RIGHT );
lv_obj_add_flag( ui_btnHomeAddFP, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_btnHomeAddFP, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_btnHomeAddFP, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_btnHomeAddFP, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_btnHomeAddFP, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_BackHomeAddFinger = lv_label_create(ui_btnHomeAddFP);
lv_obj_set_width( ui_BackHomeAddFinger, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_BackHomeAddFinger, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_BackHomeAddFinger, LV_ALIGN_CENTER );
lv_label_set_text(ui_BackHomeAddFinger,"Home");
lv_obj_set_style_text_color(ui_BackHomeAddFinger, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_BackHomeAddFinger, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_BackHomeAddFinger, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_areaNotyfyAddFP = lv_textarea_create(ui_screenFingerAdd);
lv_obj_set_height( ui_areaNotyfyAddFP, 80);
lv_obj_set_width( ui_areaNotyfyAddFP, lv_pct(80));
lv_obj_set_x( ui_areaNotyfyAddFP, 0 );
lv_obj_set_y( ui_areaNotyfyAddFP, -5 );
lv_obj_set_align( ui_areaNotyfyAddFP, LV_ALIGN_CENTER );
lv_textarea_set_text(ui_areaNotyfyAddFP,"Timeout to scan fingerprint\n");
lv_textarea_set_placeholder_text(ui_areaNotyfyAddFP,"Placeholder...");
lv_obj_add_flag( ui_areaNotyfyAddFP, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_set_style_text_align(ui_areaNotyfyAddFP, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_areaNotyfyAddFP, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);
// lv_obj_set_style_bg_color(ui_areaNotyfyAddFP, lv_color_hex(0xE3E1E1), LV_PART_MAIN | LV_STATE_DEFAULT );
// lv_obj_set_style_bg_opa(ui_areaNotyfyAddFP, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
// lv_obj_set_style_border_color(ui_areaNotyfyAddFP, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
// lv_obj_set_style_border_opa(ui_areaNotyfyAddFP, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
// lv_obj_set_style_shadow_width(ui_areaNotyfyAddFP, 50, LV_PART_MAIN| LV_STATE_DEFAULT);
// lv_obj_set_style_shadow_spread(ui_areaNotyfyAddFP, 20, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_left(ui_areaNotyfyAddFP, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_areaNotyfyAddFP, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_areaNotyfyAddFP, 28, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_areaNotyfyAddFP, 0, LV_PART_MAIN| LV_STATE_DEFAULT);



ui_KeyboardFingerAdd = lv_keyboard_create(ui_screenFingerAdd);
lv_obj_set_height( ui_KeyboardFingerAdd, 160);
lv_obj_set_width( ui_KeyboardFingerAdd, lv_pct(100));
lv_obj_set_align( ui_KeyboardFingerAdd, LV_ALIGN_BOTTOM_MID );
lv_obj_add_flag( ui_KeyboardFingerAdd, LV_OBJ_FLAG_HIDDEN );   /// Flags

lv_obj_add_event_cb(ui_PanelFingerAdd, ui_event_PanelFingerAdd, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_areaEnterNameFP, ui_event_areaEnterNameFP, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_panelAddfinger, ui_event_panelAddfinger, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_btnBackAddFP, ui_event_btnBackAddFP, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_btnHomeAddFP, ui_event_btnHomeAddFP, LV_EVENT_ALL, NULL);
lv_keyboard_set_textarea(ui_KeyboardFingerAdd,ui_areaEnterNameFP);
//////////////////
// lv_obj_add_event_cb(ui_areaNotyfyAddFP, ui_event_btnAddFinger, LV_EVENT_PRESSED, NULL);
lv_obj_add_event_cb(ui_btnAddFinger, ui_event_btnAddFinger, LV_EVENT_PRESSED, NULL);
lv_obj_add_event_cb(ui_KeyboardFingerAdd, ui_event_PressedOkAddFP, LV_EVENT_PRESSED, NULL);



}
