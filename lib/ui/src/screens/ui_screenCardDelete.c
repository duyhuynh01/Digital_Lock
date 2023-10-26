// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: GUI_v1

#include "../ui.h"

void ui_screenCardDelete_screen_init(void)
{
ui_screenCardDelete = lv_obj_create(NULL);
lv_obj_clear_flag( ui_screenCardDelete, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_PanelCardDelete = lv_obj_create(ui_screenCardDelete);
lv_obj_set_width( ui_PanelCardDelete, lv_pct(100));
lv_obj_set_height( ui_PanelCardDelete, lv_pct(100));
lv_obj_set_align( ui_PanelCardDelete, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_PanelCardDelete, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_PanelCardDelete, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_PanelCardDelete, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label33 = lv_label_create(ui_PanelCardDelete);
lv_obj_set_width( ui_Label33, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label33, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label33, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_Label33,"Delete Card");
lv_obj_set_style_text_color(ui_Label33, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label33, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label33, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_panelDeleteCard = lv_obj_create(ui_screenCardDelete);
lv_obj_set_height( ui_panelDeleteCard, 275);
lv_obj_set_width( ui_panelDeleteCard, lv_pct(100));
lv_obj_set_align( ui_panelDeleteCard, LV_ALIGN_BOTTOM_MID );
lv_obj_clear_flag( ui_panelDeleteCard, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_panelDeleteCard, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_panelDeleteCard, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_panelDeleteCard, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label34 = lv_label_create(ui_panelDeleteCard);
lv_obj_set_width( ui_Label34, 180);
lv_obj_set_height( ui_Label34, 24);
lv_obj_set_x( ui_Label34, 0 );
lv_obj_set_y( ui_Label34, 100 );
lv_obj_set_align( ui_Label34, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_Label34,"Enter a user that you want to delete\n");
lv_obj_set_style_text_color(ui_Label34, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label34, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Label34, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label34, &lv_font_montserrat_10, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_areaEnterNameDeleteCard = lv_textarea_create(ui_panelDeleteCard);
lv_obj_set_width( ui_areaEnterNameDeleteCard, lv_pct(71));
lv_obj_set_height( ui_areaEnterNameDeleteCard, LV_SIZE_CONTENT);   /// 45
lv_obj_set_x( ui_areaEnterNameDeleteCard, 0 );
lv_obj_set_y( ui_areaEnterNameDeleteCard, 60 );
lv_obj_set_align( ui_areaEnterNameDeleteCard, LV_ALIGN_TOP_MID );
lv_textarea_set_max_length(ui_areaEnterNameDeleteCard,7);
lv_textarea_set_one_line(ui_areaEnterNameDeleteCard,true);
lv_obj_set_style_text_align(ui_areaEnterNameDeleteCard, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);



ui_btnDeleteCard1 = lv_btn_create(ui_panelDeleteCard);
lv_obj_set_width( ui_btnDeleteCard1, 70);
lv_obj_set_height( ui_btnDeleteCard1, 35);
lv_obj_set_x( ui_btnDeleteCard1, 0 );
lv_obj_set_y( ui_btnDeleteCard1, 50 );
lv_obj_set_align( ui_btnDeleteCard1, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_btnDeleteCard1, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_btnDeleteCard1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_btnDeleteCard1, lv_color_hex(0x90A6D3), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_btnDeleteCard1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label35 = lv_label_create(ui_btnDeleteCard1);
lv_obj_set_width( ui_Label35, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label35, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label35, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label35,"DELETE");

ui_btnBackCardDelete = lv_btn_create(ui_screenCardDelete);
lv_obj_set_width( ui_btnBackCardDelete, 50);
lv_obj_set_height( ui_btnBackCardDelete, 23);
lv_obj_set_x( ui_btnBackCardDelete, 5 );
lv_obj_set_y( ui_btnBackCardDelete, -5 );
lv_obj_set_align( ui_btnBackCardDelete, LV_ALIGN_BOTTOM_LEFT );
lv_obj_add_flag( ui_btnBackCardDelete, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_btnBackCardDelete, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_btnBackCardDelete, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_btnBackCardDelete, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_btnBackCardDelete, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_BackFinger6 = lv_label_create(ui_btnBackCardDelete);
lv_obj_set_width( ui_BackFinger6, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_BackFinger6, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_BackFinger6, LV_ALIGN_CENTER );
lv_label_set_text(ui_BackFinger6,"Back");
lv_obj_set_style_text_color(ui_BackFinger6, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_BackFinger6, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_BackFinger6, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_btnHomeCardDelete = lv_btn_create(ui_screenCardDelete);
lv_obj_set_width( ui_btnHomeCardDelete, 50);
lv_obj_set_height( ui_btnHomeCardDelete, 23);
lv_obj_set_x( ui_btnHomeCardDelete, -7 );
lv_obj_set_y( ui_btnHomeCardDelete, -5 );
lv_obj_set_align( ui_btnHomeCardDelete, LV_ALIGN_BOTTOM_RIGHT );
lv_obj_add_flag( ui_btnHomeCardDelete, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_btnHomeCardDelete, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_btnHomeCardDelete, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_btnHomeCardDelete, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_btnHomeCardDelete, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_BackHomeAddFinger4 = lv_label_create(ui_btnHomeCardDelete);
lv_obj_set_width( ui_BackHomeAddFinger4, LV_SIZE_CONTENT);  /// 50
lv_obj_set_height( ui_BackHomeAddFinger4, LV_SIZE_CONTENT);   /// 20
lv_obj_set_align( ui_BackHomeAddFinger4, LV_ALIGN_CENTER );
lv_label_set_text(ui_BackHomeAddFinger4,"Home");
lv_obj_set_style_text_color(ui_BackHomeAddFinger4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_BackHomeAddFinger4, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_BackHomeAddFinger4, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_areaNotyfyDeleteCard = lv_textarea_create(ui_screenCardDelete);
lv_obj_set_height( ui_areaNotyfyDeleteCard, 80);
lv_obj_set_width( ui_areaNotyfyDeleteCard, lv_pct(80));
lv_obj_set_x( ui_areaNotyfyDeleteCard, 0 );
lv_obj_set_y( ui_areaNotyfyDeleteCard, -5 );
lv_obj_set_align( ui_areaNotyfyDeleteCard, LV_ALIGN_CENTER );
// lv_textarea_set_text(ui_areaNotyfyDeleteCard,"Timeout to scan fingerprint\n");
lv_textarea_set_placeholder_text(ui_areaNotyfyDeleteCard,"Placeholder...");
lv_obj_add_flag( ui_areaNotyfyDeleteCard, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_set_style_text_align(ui_areaNotyfyDeleteCard, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_areaNotyfyDeleteCard, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);
// lv_obj_set_style_bg_color(ui_areaNotyfyDeleteCard, lv_color_hex(0xE3E1E1), LV_PART_MAIN | LV_STATE_DEFAULT );
// lv_obj_set_style_bg_opa(ui_areaNotyfyDeleteCard, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
// lv_obj_set_style_border_color(ui_areaNotyfyDeleteCard, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
// lv_obj_set_style_border_opa(ui_areaNotyfyDeleteCard, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
// lv_obj_set_style_shadow_width(ui_areaNotyfyDeleteCard, 50, LV_PART_MAIN| LV_STATE_DEFAULT);
// lv_obj_set_style_shadow_spread(ui_areaNotyfyDeleteCard, 20, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_left(ui_areaNotyfyDeleteCard, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_areaNotyfyDeleteCard, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_areaNotyfyDeleteCard, 28, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_areaNotyfyDeleteCard, 0, LV_PART_MAIN| LV_STATE_DEFAULT);



ui_KeyboardCardDelete = lv_keyboard_create(ui_screenCardDelete);
lv_obj_set_height( ui_KeyboardCardDelete, 160);
lv_obj_set_width( ui_KeyboardCardDelete, lv_pct(100));
lv_obj_set_align( ui_KeyboardCardDelete, LV_ALIGN_BOTTOM_MID );
lv_obj_add_flag( ui_KeyboardCardDelete, LV_OBJ_FLAG_HIDDEN );   /// Flags

lv_obj_add_event_cb(ui_PanelCardDelete, ui_event_PanelCardDelete, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_areaEnterNameDeleteCard, ui_event_areaEnterNameDeleteCard, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_panelDeleteCard, ui_event_panelDeleteCard, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_btnBackCardDelete, ui_event_btnBackCardDelete, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_btnHomeCardDelete, ui_event_btnHomeCardDelete, LV_EVENT_ALL, NULL);
lv_keyboard_set_textarea(ui_KeyboardCardDelete,ui_areaEnterNameDeleteCard);
lv_obj_add_event_cb(ui_btnDeleteCard1, ui_event_btnDeleteCard, LV_EVENT_PRESSED, NULL);
lv_obj_add_event_cb(ui_KeyboardCardDelete, ui_event_PressedOkDeleteCard, LV_EVENT_PRESSED, NULL);

}
