// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: GUI_v1

#include "../ui.h"

void ui_screenCardAdd_screen_init(void)
{
ui_screenCardAdd = lv_obj_create(NULL);
lv_obj_clear_flag( ui_screenCardAdd, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_PanelCardAdd = lv_obj_create(ui_screenCardAdd);
lv_obj_set_width( ui_PanelCardAdd, lv_pct(100));
lv_obj_set_height( ui_PanelCardAdd, lv_pct(100));
lv_obj_set_align( ui_PanelCardAdd, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_PanelCardAdd, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_PanelCardAdd, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_PanelCardAdd, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label30 = lv_label_create(ui_PanelCardAdd);
lv_obj_set_width( ui_Label30, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label30, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label30, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_Label30,"Card  Add");
lv_obj_set_style_text_color(ui_Label30, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label30, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label30, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_panelCardAdd = lv_obj_create(ui_screenCardAdd);
lv_obj_set_height( ui_panelCardAdd, 275);
lv_obj_set_width( ui_panelCardAdd, lv_pct(100));
lv_obj_set_align( ui_panelCardAdd, LV_ALIGN_BOTTOM_MID );
lv_obj_clear_flag( ui_panelCardAdd, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_panelCardAdd, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_panelCardAdd, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_panelCardAdd, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label31 = lv_label_create(ui_panelCardAdd);
lv_obj_set_width( ui_Label31, 180);
lv_obj_set_height( ui_Label31, 24);
lv_obj_set_x( ui_Label31, 0 );
lv_obj_set_y( ui_Label31, 100 );
lv_obj_set_align( ui_Label31, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_Label31,"Enter a name, if necessary.\n(maximum 7 characters)\n");
lv_obj_set_style_text_color(ui_Label31, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label31, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Label31, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label31, &lv_font_montserrat_10, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_areaEnterNameFP2 = lv_textarea_create(ui_panelCardAdd);
lv_obj_set_width( ui_areaEnterNameFP2, lv_pct(71));
lv_obj_set_height( ui_areaEnterNameFP2, LV_SIZE_CONTENT);   /// 45
lv_obj_set_x( ui_areaEnterNameFP2, 0 );
lv_obj_set_y( ui_areaEnterNameFP2, 60 );
lv_obj_set_align( ui_areaEnterNameFP2, LV_ALIGN_TOP_MID );
lv_textarea_set_max_length(ui_areaEnterNameFP2,7);
lv_textarea_set_text(ui_areaEnterNameFP2,"");
lv_textarea_set_one_line(ui_areaEnterNameFP2,true);
lv_obj_set_style_text_align(ui_areaEnterNameFP2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);



ui_btnAddFinger2 = lv_btn_create(ui_panelCardAdd);
lv_obj_set_width( ui_btnAddFinger2, 70);
lv_obj_set_height( ui_btnAddFinger2, 35);
lv_obj_set_x( ui_btnAddFinger2, 0 );
lv_obj_set_y( ui_btnAddFinger2, 50 );
lv_obj_set_align( ui_btnAddFinger2, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_btnAddFinger2, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_btnAddFinger2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_btnAddFinger2, lv_color_hex(0x90A6D3), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_btnAddFinger2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label32 = lv_label_create(ui_btnAddFinger2);
lv_obj_set_width( ui_Label32, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label32, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label32, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label32,"ADD");

ui_btnBackAddCard = lv_btn_create(ui_screenCardAdd);
lv_obj_set_width( ui_btnBackAddCard, 50);
lv_obj_set_height( ui_btnBackAddCard, 23);
lv_obj_set_x( ui_btnBackAddCard, 5 );
lv_obj_set_y( ui_btnBackAddCard, -5 );
lv_obj_set_align( ui_btnBackAddCard, LV_ALIGN_BOTTOM_LEFT );
lv_obj_add_flag( ui_btnBackAddCard, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_btnBackAddCard, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_btnBackAddCard, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_btnBackAddCard, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_btnBackAddCard, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_BackFinger5 = lv_label_create(ui_btnBackAddCard);
lv_obj_set_width( ui_BackFinger5, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_BackFinger5, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_BackFinger5, LV_ALIGN_CENTER );
lv_label_set_text(ui_BackFinger5,"Back");
lv_obj_set_style_text_color(ui_BackFinger5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_BackFinger5, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_BackFinger5, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_btnHomeAddCard = lv_btn_create(ui_screenCardAdd);
lv_obj_set_width( ui_btnHomeAddCard, 50);
lv_obj_set_height( ui_btnHomeAddCard, 23);
lv_obj_set_x( ui_btnHomeAddCard, -7 );
lv_obj_set_y( ui_btnHomeAddCard, -5 );
lv_obj_set_align( ui_btnHomeAddCard, LV_ALIGN_BOTTOM_RIGHT );
lv_obj_add_flag( ui_btnHomeAddCard, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_btnHomeAddCard, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_btnHomeAddCard, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_btnHomeAddCard, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_btnHomeAddCard, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_BackHomeAddFinger3 = lv_label_create(ui_btnHomeAddCard);
lv_obj_set_width( ui_BackHomeAddFinger3, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_BackHomeAddFinger3, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_BackHomeAddFinger3, LV_ALIGN_CENTER );
lv_label_set_text(ui_BackHomeAddFinger3,"Home");
lv_obj_set_style_text_color(ui_BackHomeAddFinger3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_BackHomeAddFinger3, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_BackHomeAddFinger3, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_areaNotyfyAddCard = lv_textarea_create(ui_screenCardAdd);
lv_obj_set_height( ui_areaNotyfyAddCard, 80);
lv_obj_set_width( ui_areaNotyfyAddCard, lv_pct(80));
lv_obj_set_x( ui_areaNotyfyAddCard, 0 );
lv_obj_set_y( ui_areaNotyfyAddCard, -5 );
lv_obj_set_align( ui_areaNotyfyAddCard, LV_ALIGN_CENTER );
// lv_textarea_set_text(ui_areaNotyfyAddCard,"Timeout to scan fingerprint\n");
// lv_textarea_set_placeholder_text(ui_areaNotyfyAddCard,"Placeholder...");
lv_obj_add_flag( ui_areaNotyfyAddCard, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_set_style_text_align(ui_areaNotyfyAddCard, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_areaNotyfyAddCard, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);
// lv_obj_set_style_bg_color(ui_areaNotyfyAddCard, lv_color_hex(0xE3E1E1), LV_PART_MAIN | LV_STATE_DEFAULT );
// lv_obj_set_style_bg_opa(ui_areaNotyfyAddCard, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
// lv_obj_set_style_border_color(ui_areaNotyfyAddCard, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
// lv_obj_set_style_border_opa(ui_areaNotyfyAddCard, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
// lv_obj_set_style_shadow_width(ui_areaNotyfyAddCard, 50, LV_PART_MAIN| LV_STATE_DEFAULT);
// lv_obj_set_style_shadow_spread(ui_areaNotyfyAddCard, 20, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_left(ui_areaNotyfyAddCard, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_areaNotyfyAddCard, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_areaNotyfyAddCard, 28, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_areaNotyfyAddCard, 0, LV_PART_MAIN| LV_STATE_DEFAULT);



ui_KeyboardAddCard = lv_keyboard_create(ui_screenCardAdd);
lv_obj_set_height( ui_KeyboardAddCard, 160);
lv_obj_set_width( ui_KeyboardAddCard, lv_pct(100));
lv_obj_set_align( ui_KeyboardAddCard, LV_ALIGN_BOTTOM_MID );
lv_obj_add_flag( ui_KeyboardAddCard, LV_OBJ_FLAG_HIDDEN );   /// Flags

lv_obj_add_event_cb(ui_PanelCardAdd, ui_event_PanelCardAdd, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_areaEnterNameFP2, ui_event_areaEnterNameFP2, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_panelCardAdd, ui_event_panelCardAdd, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_btnBackAddCard, ui_event_btnBackAddCard, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_BackHomeAddFinger3, ui_event_BackHomeAddFinger3, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_btnHomeAddCard, ui_event_btnHomeAddCard, LV_EVENT_ALL, NULL);
lv_keyboard_set_textarea(ui_KeyboardAddCard,ui_areaEnterNameFP2);
lv_obj_add_event_cb(ui_btnAddFinger2, ui_event_btnCardAdd, LV_EVENT_PRESSED, NULL);
lv_obj_add_event_cb(ui_KeyboardAddCard, ui_event_PressedOkAddCard, LV_EVENT_PRESSED, NULL);
}
