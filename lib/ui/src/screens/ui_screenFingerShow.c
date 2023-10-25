// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: GUI_v1

#include "../ui.h"

void ui_screenFingerShow_screen_init(void)
{
ui_screenFingerShow = lv_obj_create(NULL);
lv_obj_clear_flag( ui_screenFingerShow, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_PanelFingerShow = lv_obj_create(ui_screenFingerShow);
lv_obj_set_width( ui_PanelFingerShow, lv_pct(100));
lv_obj_set_height( ui_PanelFingerShow, lv_pct(100));
lv_obj_set_align( ui_PanelFingerShow, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_PanelFingerShow, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_PanelFingerShow, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_PanelFingerShow, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label23 = lv_label_create(ui_PanelFingerShow);
lv_obj_set_width( ui_Label23, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label23, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label23, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_Label23,"Fingerprint List");
lv_obj_set_style_text_color(ui_Label23, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label23, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label23, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_panelShowFP = lv_obj_create(ui_screenFingerShow);
lv_obj_set_height( ui_panelShowFP, 275);
lv_obj_set_width( ui_panelShowFP, lv_pct(100));
lv_obj_set_align( ui_panelShowFP, LV_ALIGN_BOTTOM_MID );
lv_obj_clear_flag( ui_panelShowFP, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_panelShowFP, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_panelShowFP, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_panelShowFP, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_btnBackShowFP = lv_btn_create(ui_screenFingerShow);
lv_obj_set_width( ui_btnBackShowFP, 50);
lv_obj_set_height( ui_btnBackShowFP, 23);
lv_obj_set_x( ui_btnBackShowFP, 5 );
lv_obj_set_y( ui_btnBackShowFP, -5 );
lv_obj_set_align( ui_btnBackShowFP, LV_ALIGN_BOTTOM_LEFT );
lv_obj_add_flag( ui_btnBackShowFP, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_btnBackShowFP, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_btnBackShowFP, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_btnBackShowFP, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_btnBackShowFP, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_BackFinger3 = lv_label_create(ui_btnBackShowFP);
lv_obj_set_width( ui_BackFinger3, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_BackFinger3, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_BackFinger3, LV_ALIGN_CENTER );
lv_label_set_text(ui_BackFinger3,"Back");
lv_obj_set_style_text_color(ui_BackFinger3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_BackFinger3, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_BackFinger3, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_btnHomeShowFP = lv_btn_create(ui_screenFingerShow);
lv_obj_set_width( ui_btnHomeShowFP, 50);
lv_obj_set_height( ui_btnHomeShowFP, 23);
lv_obj_set_x( ui_btnHomeShowFP, -7 );
lv_obj_set_y( ui_btnHomeShowFP, -5 );
lv_obj_set_align( ui_btnHomeShowFP, LV_ALIGN_BOTTOM_RIGHT );
lv_obj_add_flag( ui_btnHomeShowFP, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_btnHomeShowFP, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_btnHomeShowFP, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_btnHomeShowFP, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_btnHomeShowFP, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_BackHomeAddFinger2 = lv_label_create(ui_btnHomeShowFP);
lv_obj_set_width( ui_BackHomeAddFinger2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_BackHomeAddFinger2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_BackHomeAddFinger2, LV_ALIGN_CENTER );
lv_label_set_text(ui_BackHomeAddFinger2,"Home");
lv_obj_set_style_text_color(ui_BackHomeAddFinger2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_BackHomeAddFinger2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_BackHomeAddFinger2, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_areaShowFP = lv_textarea_create(ui_screenFingerShow);
lv_obj_set_width( ui_areaShowFP, 186);
lv_obj_set_height( ui_areaShowFP, 220);
lv_obj_set_x( ui_areaShowFP, 0 );
lv_obj_set_y( ui_areaShowFP, 12 );
lv_obj_set_align( ui_areaShowFP, LV_ALIGN_CENTER );
lv_textarea_set_text(ui_areaShowFP,"Fingerprint Count : 20");
lv_obj_set_style_text_color(ui_areaShowFP, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_areaShowFP, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_areaShowFP, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui_areaShowFP, 15, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_areaShowFP, lv_color_hex(0xE3E1E1), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_areaShowFP, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_areaShowFP, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_areaShowFP, 255, LV_PART_MAIN| LV_STATE_DEFAULT);



lv_obj_add_event_cb(ui_btnBackShowFP, ui_event_btnBackShowFP, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_btnHomeShowFP, ui_event_btnHomeShowFP, LV_EVENT_ALL, NULL);

}
