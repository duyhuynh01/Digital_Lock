// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: GUI_v1

#include "../ui.h"

void ui_screenFingerDelete_screen_init(void)
{
ui_screenFingerDelete = lv_obj_create(NULL);
lv_obj_clear_flag( ui_screenFingerDelete, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_PanelFingerDelete = lv_obj_create(ui_screenFingerDelete);
lv_obj_set_width( ui_PanelFingerDelete, lv_pct(100));
lv_obj_set_height( ui_PanelFingerDelete, lv_pct(100));
lv_obj_set_align( ui_PanelFingerDelete, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_PanelFingerDelete, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_PanelFingerDelete, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_PanelFingerDelete, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label20 = lv_label_create(ui_PanelFingerDelete);
lv_obj_set_width( ui_Label20, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label20, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label20, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_Label20,"Delete fingerprint");
lv_obj_set_style_text_color(ui_Label20, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label20, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label20, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_panelDeleteFinger = lv_obj_create(ui_screenFingerDelete);
lv_obj_set_height( ui_panelDeleteFinger, 275);
lv_obj_set_width( ui_panelDeleteFinger, lv_pct(100));
lv_obj_set_align( ui_panelDeleteFinger, LV_ALIGN_BOTTOM_MID );
lv_obj_clear_flag( ui_panelDeleteFinger, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_panelDeleteFinger, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_panelDeleteFinger, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_panelDeleteFinger, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label21 = lv_label_create(ui_panelDeleteFinger);
lv_obj_set_width( ui_Label21, 200);
lv_obj_set_height( ui_Label21, 40);
lv_obj_set_x( ui_Label21, 0 );
lv_obj_set_y( ui_Label21, 100 );
lv_obj_set_align( ui_Label21, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_Label21,"Enter a user that you want to delete\n");
lv_obj_set_style_text_color(ui_Label21, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label21, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Label21, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label21, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_areaEnterNameFP1 = lv_textarea_create(ui_panelDeleteFinger);
lv_obj_set_width( ui_areaEnterNameFP1, lv_pct(80));
lv_obj_set_height( ui_areaEnterNameFP1, LV_SIZE_CONTENT);   /// 45
lv_obj_set_x( ui_areaEnterNameFP1, 0 );
lv_obj_set_y( ui_areaEnterNameFP1, 60 );
lv_obj_set_align( ui_areaEnterNameFP1, LV_ALIGN_TOP_MID );
lv_textarea_set_max_length(ui_areaEnterNameFP1,7);
lv_textarea_set_one_line(ui_areaEnterNameFP1,true);
lv_obj_set_style_text_align(ui_areaEnterNameFP1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);



ui_btnDeleteFinger = lv_btn_create(ui_panelDeleteFinger);
lv_obj_set_width( ui_btnDeleteFinger, 80);
lv_obj_set_height( ui_btnDeleteFinger, 35);
lv_obj_set_x( ui_btnDeleteFinger, 0 );
lv_obj_set_y( ui_btnDeleteFinger, 50 );
lv_obj_set_align( ui_btnDeleteFinger, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_btnDeleteFinger, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_btnDeleteFinger, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_btnDeleteFinger, lv_color_hex(0x90A6D3), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_btnDeleteFinger, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label22 = lv_label_create(ui_btnDeleteFinger);
lv_obj_set_width( ui_Label22, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label22, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label22, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label22,"DELETE");
lv_obj_set_style_text_font(ui_Label22, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_btnBackFingerDelete = lv_btn_create(ui_screenFingerDelete);
lv_obj_set_width( ui_btnBackFingerDelete, 50);
lv_obj_set_height( ui_btnBackFingerDelete, 26);
lv_obj_set_x( ui_btnBackFingerDelete, 5 );
lv_obj_set_y( ui_btnBackFingerDelete, -5 );
lv_obj_set_align( ui_btnBackFingerDelete, LV_ALIGN_BOTTOM_LEFT );
lv_obj_add_flag( ui_btnBackFingerDelete, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_btnBackFingerDelete, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_btnBackFingerDelete, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_btnBackFingerDelete, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_btnBackFingerDelete, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_BackFinger2 = lv_label_create(ui_btnBackFingerDelete);
lv_obj_set_width( ui_BackFinger2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_BackFinger2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_BackFinger2, LV_ALIGN_CENTER );
lv_label_set_text(ui_BackFinger2,"Back");
lv_obj_set_style_text_color(ui_BackFinger2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_BackFinger2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_BackFinger2, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_btnHomeFingerDelete = lv_btn_create(ui_screenFingerDelete);
lv_obj_set_width( ui_btnHomeFingerDelete, 53);
lv_obj_set_height( ui_btnHomeFingerDelete, 26);
lv_obj_set_x( ui_btnHomeFingerDelete, -7 );
lv_obj_set_y( ui_btnHomeFingerDelete, -5 );
lv_obj_set_align( ui_btnHomeFingerDelete, LV_ALIGN_BOTTOM_RIGHT );
lv_obj_add_flag( ui_btnHomeFingerDelete, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_btnHomeFingerDelete, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_btnHomeFingerDelete, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_btnHomeFingerDelete, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_btnHomeFingerDelete, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_BackHomeAddFinger1 = lv_label_create(ui_btnHomeFingerDelete);
lv_obj_set_width( ui_BackHomeAddFinger1, 50);
lv_obj_set_height( ui_BackHomeAddFinger1, 20);
lv_obj_set_align( ui_BackHomeAddFinger1, LV_ALIGN_CENTER );
lv_label_set_text(ui_BackHomeAddFinger1,"Home");
lv_obj_set_style_text_color(ui_BackHomeAddFinger1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_BackHomeAddFinger1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_BackHomeAddFinger1, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_areaNotyfyDeleteFP = lv_textarea_create(ui_screenFingerDelete);
lv_obj_set_height( ui_areaNotyfyDeleteFP, 80);
lv_obj_set_width( ui_areaNotyfyDeleteFP, lv_pct(90));
lv_obj_set_x( ui_areaNotyfyDeleteFP, 0 );
lv_obj_set_y( ui_areaNotyfyDeleteFP, -5 );
lv_obj_set_align( ui_areaNotyfyDeleteFP, LV_ALIGN_CENTER );
// lv_textarea_set_text(ui_areaNotyfyDeleteFP,"Timeout to scan fingerprint\n");
lv_textarea_set_placeholder_text(ui_areaNotyfyDeleteFP,"Placeholder...");
lv_obj_add_flag( ui_areaNotyfyDeleteFP, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_set_style_text_color(ui_areaNotyfyDeleteFP, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_color(ui_areaNotyfyDeleteFP, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_align(ui_areaNotyfyDeleteFP, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_areaNotyfyDeleteFP, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);
// lv_obj_set_style_bg_color(ui_areaNotyfyDeleteFP, lv_color_hex(0xE3E1E1), LV_PART_MAIN | LV_STATE_DEFAULT );
// lv_obj_set_style_bg_opa(ui_areaNotyfyDeleteFP, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
// lv_obj_set_style_border_color(ui_areaNotyfyDeleteFP, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
// lv_obj_set_style_border_opa(ui_areaNotyfyDeleteFP, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
// lv_obj_set_style_shadow_width(ui_areaNotyfyDeleteFP, 50, LV_PART_MAIN| LV_STATE_DEFAULT);
// lv_obj_set_style_shadow_spread(ui_areaNotyfyDeleteFP, 20, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_left(ui_areaNotyfyDeleteFP, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_areaNotyfyDeleteFP, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_areaNotyfyDeleteFP, 28, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_areaNotyfyDeleteFP, 0, LV_PART_MAIN| LV_STATE_DEFAULT);



ui_KeyboardFingerDelete = lv_keyboard_create(ui_screenFingerDelete);
lv_obj_set_height( ui_KeyboardFingerDelete, 160);
lv_obj_set_width( ui_KeyboardFingerDelete, lv_pct(100));
lv_obj_set_align( ui_KeyboardFingerDelete, LV_ALIGN_BOTTOM_MID );
lv_obj_add_flag( ui_KeyboardFingerDelete, LV_OBJ_FLAG_HIDDEN );   /// Flags

lv_obj_add_event_cb(ui_PanelFingerDelete, ui_event_PanelFingerDelete, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_areaEnterNameFP1, ui_event_areaEnterNameFP1, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_panelDeleteFinger, ui_event_panelDeleteFinger, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_btnBackFingerDelete, ui_event_btnBackFingerDelete, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_btnHomeFingerDelete, ui_event_btnHomeFingerDelete, LV_EVENT_ALL, NULL);
lv_keyboard_set_textarea(ui_KeyboardFingerDelete,ui_areaEnterNameFP1);
lv_obj_add_event_cb(ui_btnDeleteFinger, ui_event_btnDeleteFinger, LV_EVENT_PRESSED, NULL );
lv_obj_add_event_cb(ui_KeyboardFingerDelete, ui_event_PressedOkDeleteFP, LV_EVENT_PRESSED, NULL);

}
