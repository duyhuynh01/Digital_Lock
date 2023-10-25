// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: GUI_v1

#include "../ui.h"

void ui_SceenFinger_screen_init(void)
{
ui_SceenFinger = lv_obj_create(NULL);
lv_obj_clear_flag( ui_SceenFinger, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_PanelFinger = lv_obj_create(ui_SceenFinger);
lv_obj_set_width( ui_PanelFinger, lv_pct(100));
lv_obj_set_height( ui_PanelFinger, lv_pct(100));
lv_obj_set_align( ui_PanelFinger, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_PanelFinger, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_PanelFinger, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_PanelFinger, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_PressDeleteFinger = lv_imgbtn_create(ui_PanelFinger);
lv_imgbtn_set_src(ui_PressDeleteFinger, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_iconfinger_png, NULL);
lv_obj_set_width( ui_PressDeleteFinger, 50);
lv_obj_set_height( ui_PressDeleteFinger, 50);
lv_obj_set_x( ui_PressDeleteFinger, 50 );
lv_obj_set_y( ui_PressDeleteFinger, 54 );
lv_obj_set_align( ui_PressDeleteFinger, LV_ALIGN_TOP_MID );

ui_PressAddFinger = lv_imgbtn_create(ui_PanelFinger);
lv_imgbtn_set_src(ui_PressAddFinger, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_iconfinger_png, NULL);
lv_obj_set_width( ui_PressAddFinger, 50);
lv_obj_set_height( ui_PressAddFinger, 50);
lv_obj_set_x( ui_PressAddFinger, -50 );
lv_obj_set_y( ui_PressAddFinger, 54 );
lv_obj_set_align( ui_PressAddFinger, LV_ALIGN_TOP_MID );

ui_PressRestoreFinger = lv_imgbtn_create(ui_PanelFinger);
lv_imgbtn_set_src(ui_PressRestoreFinger, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_iconfinger_png, NULL);
lv_obj_set_width( ui_PressRestoreFinger, 50);
lv_obj_set_height( ui_PressRestoreFinger, 50);
lv_obj_set_x( ui_PressRestoreFinger, -50 );
lv_obj_set_y( ui_PressRestoreFinger, 169 );
lv_obj_set_align( ui_PressRestoreFinger, LV_ALIGN_TOP_MID );

ui_PressShowFinger = lv_imgbtn_create(ui_PanelFinger);
lv_imgbtn_set_src(ui_PressShowFinger, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_iconfinger_png, NULL);
lv_obj_set_width( ui_PressShowFinger, 50);
lv_obj_set_height( ui_PressShowFinger, 50);
lv_obj_set_x( ui_PressShowFinger, 50 );
lv_obj_set_y( ui_PressShowFinger, 169 );
lv_obj_set_align( ui_PressShowFinger, LV_ALIGN_TOP_MID );

ui_Label14 = lv_label_create(ui_PanelFinger);
lv_obj_set_width( ui_Label14, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label14, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label14, -50 );
lv_obj_set_y( ui_Label14, 107 );
lv_obj_set_align( ui_Label14, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_Label14,"Add");
lv_obj_set_style_text_color(ui_Label14, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label14, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label14, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label16 = lv_label_create(ui_PanelFinger);
lv_obj_set_width( ui_Label16, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label16, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label16, 50 );
lv_obj_set_y( ui_Label16, 107 );
lv_obj_set_align( ui_Label16, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_Label16,"Delete");
lv_obj_set_style_text_color(ui_Label16, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label16, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label16, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label17 = lv_label_create(ui_PanelFinger);
lv_obj_set_width( ui_Label17, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label17, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label17, 50 );
lv_obj_set_y( ui_Label17, 222 );
lv_obj_set_align( ui_Label17, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_Label17,"Show list");
lv_obj_set_style_text_color(ui_Label17, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label17, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label17, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label18 = lv_label_create(ui_PanelFinger);
lv_obj_set_width( ui_Label18, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label18, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label18, -50 );
lv_obj_set_y( ui_Label18, 222 );
lv_obj_set_align( ui_Label18, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_Label18,"Restore");
lv_obj_set_style_text_color(ui_Label18, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label18, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label18, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label12 = lv_label_create(ui_PanelFinger);
lv_obj_set_width( ui_Label12, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label12, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label12, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_Label12,"FINGERPRINT SETTING");
lv_obj_set_style_text_color(ui_Label12, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label12, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label12, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_btnBackFinger = lv_btn_create(ui_SceenFinger);
lv_obj_set_width( ui_btnBackFinger, 50);
lv_obj_set_height( ui_btnBackFinger, 23);
lv_obj_set_x( ui_btnBackFinger, 5 );
lv_obj_set_y( ui_btnBackFinger, -5 );
lv_obj_set_align( ui_btnBackFinger, LV_ALIGN_BOTTOM_LEFT );
lv_obj_add_flag( ui_btnBackFinger, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_btnBackFinger, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_btnBackFinger, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_btnBackFinger, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_btnBackFinger, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_BackFinger = lv_label_create(ui_btnBackFinger);
lv_obj_set_width( ui_BackFinger, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_BackFinger, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_BackFinger, LV_ALIGN_CENTER );
lv_label_set_text(ui_BackFinger,"Back");
lv_obj_set_style_text_color(ui_BackFinger, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_BackFinger, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_BackFinger, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_areaPopupFP = lv_textarea_create(ui_SceenFinger);
lv_obj_set_height( ui_areaPopupFP, 80);
lv_obj_set_width( ui_areaPopupFP, lv_pct(80));
lv_obj_set_x( ui_areaPopupFP, 0 );
lv_obj_set_y( ui_areaPopupFP, -5 );
lv_obj_set_align( ui_areaPopupFP, LV_ALIGN_CENTER );
lv_textarea_set_text(ui_areaPopupFP,"Restored Fingerprint");
lv_obj_add_flag( ui_areaPopupFP, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_set_style_text_align(ui_areaPopupFP, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_areaPopupFP, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);
// lv_obj_set_style_bg_color(ui_areaPopupFP, lv_color_hex(0xE3E1E1), LV_PART_MAIN | LV_STATE_DEFAULT );
// lv_obj_set_style_bg_opa(ui_areaPopupFP, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
// lv_obj_set_style_shadow_color(ui_areaPopupFP, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
// lv_obj_set_style_shadow_opa(ui_areaPopupFP, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
// lv_obj_set_style_shadow_width(ui_areaPopupFP, 50, LV_PART_MAIN| LV_STATE_DEFAULT);
// lv_obj_set_style_shadow_spread(ui_areaPopupFP, 20, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_left(ui_areaPopupFP, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_areaPopupFP, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_areaPopupFP, 28, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_areaPopupFP, 0, LV_PART_MAIN| LV_STATE_DEFAULT);



lv_obj_add_event_cb(ui_PressDeleteFinger, ui_event_PressDeleteFinger, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_PressAddFinger, ui_event_PressAddFinger, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_PressRestoreFinger, ui_event_PressRestoreFinger, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_PressShowFinger, ui_event_PressShowFinger, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_btnBackFinger, ui_event_btnBackFinger, LV_EVENT_ALL, NULL);

}
