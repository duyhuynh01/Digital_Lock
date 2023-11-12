// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: GUI_v1

#include "../ui.h"

void ui_SceenCard_screen_init(void)
{
ui_SceenCard = lv_obj_create(NULL);
lv_obj_clear_flag( ui_SceenCard, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_PanelCard = lv_obj_create(ui_SceenCard);
lv_obj_set_width( ui_PanelCard, lv_pct(100));
lv_obj_set_height( ui_PanelCard, lv_pct(100));
lv_obj_set_align( ui_PanelCard, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_PanelCard, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_PanelCard, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_PanelCard, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_PressDeleteCard = lv_imgbtn_create(ui_PanelCard);
lv_imgbtn_set_src(ui_PressDeleteCard, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_iconcard_png, NULL);
lv_obj_set_width( ui_PressDeleteCard, 50);
lv_obj_set_height( ui_PressDeleteCard, 50);
lv_obj_set_x( ui_PressDeleteCard, 50 );
lv_obj_set_y( ui_PressDeleteCard, 54 );
lv_obj_set_align( ui_PressDeleteCard, LV_ALIGN_TOP_MID );

ui_PressAddCard = lv_imgbtn_create(ui_PanelCard);
lv_imgbtn_set_src(ui_PressAddCard, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_iconcard_png, NULL);
lv_obj_set_width( ui_PressAddCard, 50);
lv_obj_set_height( ui_PressAddCard, 50);
lv_obj_set_x( ui_PressAddCard, -50 );
lv_obj_set_y( ui_PressAddCard, 54 );
lv_obj_set_align( ui_PressAddCard, LV_ALIGN_TOP_MID );

ui_PressRestoreCard = lv_imgbtn_create(ui_PanelCard);
lv_imgbtn_set_src(ui_PressRestoreCard, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_iconcard_png, NULL);
lv_obj_set_width( ui_PressRestoreCard, 50);
lv_obj_set_height( ui_PressRestoreCard, 50);
lv_obj_set_x( ui_PressRestoreCard, -50 );
lv_obj_set_y( ui_PressRestoreCard, 169 );
lv_obj_set_align( ui_PressRestoreCard, LV_ALIGN_TOP_MID );

ui_PressShowCard = lv_imgbtn_create(ui_PanelCard);
lv_imgbtn_set_src(ui_PressShowCard, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_iconcard_png, NULL);
lv_obj_set_width( ui_PressShowCard, 50);
lv_obj_set_height( ui_PressShowCard, 50);
lv_obj_set_x( ui_PressShowCard, 50 );
lv_obj_set_y( ui_PressShowCard, 169 );
lv_obj_set_align( ui_PressShowCard, LV_ALIGN_TOP_MID );

ui_Label25 = lv_label_create(ui_PanelCard);
lv_obj_set_width( ui_Label25, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label25, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label25, -50 );
lv_obj_set_y( ui_Label25, 107 );
lv_obj_set_align( ui_Label25, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_Label25,"Add");
lv_obj_set_style_text_color(ui_Label25, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label25, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label25, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label26 = lv_label_create(ui_PanelCard);
lv_obj_set_width( ui_Label26, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label26, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label26, 50 );
lv_obj_set_y( ui_Label26, 107 );
lv_obj_set_align( ui_Label26, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_Label26,"Delete");
lv_obj_set_style_text_color(ui_Label26, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label26, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label26, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label27 = lv_label_create(ui_PanelCard);
lv_obj_set_width( ui_Label27, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label27, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label27, 50 );
lv_obj_set_y( ui_Label27, 222 );
lv_obj_set_align( ui_Label27, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_Label27,"Show list");
lv_obj_set_style_text_color(ui_Label27, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label27, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label27, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label28 = lv_label_create(ui_PanelCard);
lv_obj_set_width( ui_Label28, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label28, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label28, -50 );
lv_obj_set_y( ui_Label28, 222 );
lv_obj_set_align( ui_Label28, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_Label28,"Restore");
lv_obj_set_style_text_color(ui_Label28, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label28, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label28, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label29 = lv_label_create(ui_PanelCard);
lv_obj_set_width( ui_Label29, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label29, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label29, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_Label29,"CARD SETTING");
lv_obj_set_style_text_color(ui_Label29, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label29, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label29, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_btnBackCard = lv_btn_create(ui_SceenCard);
lv_obj_set_width( ui_btnBackCard, 50);
lv_obj_set_height( ui_btnBackCard, 23);
lv_obj_set_x( ui_btnBackCard, 5 );
lv_obj_set_y( ui_btnBackCard, -5 );
lv_obj_set_align( ui_btnBackCard, LV_ALIGN_BOTTOM_LEFT );
lv_obj_add_flag( ui_btnBackCard, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_btnBackCard, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_btnBackCard, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_btnBackCard, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_btnBackCard, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_BackFinger4 = lv_label_create(ui_btnBackCard);
lv_obj_set_width( ui_BackFinger4, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_BackFinger4, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_BackFinger4, LV_ALIGN_CENTER );
lv_label_set_text(ui_BackFinger4,"Back");
lv_obj_set_style_text_color(ui_BackFinger4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_BackFinger4, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_BackFinger4, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_areaPopupCard = lv_textarea_create(ui_SceenCard);
lv_obj_set_height( ui_areaPopupCard, 80);
lv_obj_set_width( ui_areaPopupCard, lv_pct(80));
lv_obj_set_x( ui_areaPopupCard, 0 );
lv_obj_set_y( ui_areaPopupCard, -5 );
lv_obj_set_align( ui_areaPopupCard, LV_ALIGN_CENTER );
lv_textarea_set_text(ui_areaPopupCard,"Restored Card successfull!");
lv_obj_add_flag( ui_areaPopupCard, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_set_style_text_align(ui_areaPopupCard, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_areaPopupCard, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);
// lv_obj_set_style_bg_color(ui_areaPopupCard, lv_color_hex(0xE3E1E1), LV_PART_MAIN | LV_STATE_DEFAULT );
// lv_obj_set_style_bg_opa(ui_areaPopupCard, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
// lv_obj_set_style_shadow_width(ui_areaPopupCard, 50, LV_PART_MAIN| LV_STATE_DEFAULT);
// lv_obj_set_style_shadow_spread(ui_areaPopupCard, 20, LV_PART_MAIN| LV_STATE_DEFAULT);
// lv_obj_set_style_pad_left(ui_areaPopupCard, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
// lv_obj_set_style_pad_right(ui_areaPopupCard, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_areaPopupCard, 28, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_areaPopupCard, 0, LV_PART_MAIN| LV_STATE_DEFAULT);


ui_panelConfirmCard = lv_obj_create(ui_SceenCard);
lv_obj_set_width( ui_panelConfirmCard, lv_pct(85));
lv_obj_set_height( ui_panelConfirmCard, 90);
lv_obj_set_align( ui_panelConfirmCard, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_panelConfirmCard, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_clear_flag( ui_panelConfirmCard, LV_OBJ_FLAG_SCROLLABLE );    /// Flags


ui_labelConfirmCard = lv_label_create(ui_panelConfirmCard);
lv_obj_set_width( ui_labelConfirmCard, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_labelConfirmCard, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_labelConfirmCard, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_labelConfirmCard,"Are you sure to delete all?");

ui_btnYesCard = lv_btn_create(ui_panelConfirmCard);
lv_obj_set_width( ui_btnYesCard, 50);
lv_obj_set_height( ui_btnYesCard, 30);
lv_obj_set_align( ui_btnYesCard, LV_ALIGN_BOTTOM_LEFT );

ui_btnNoCard = lv_btn_create(ui_panelConfirmCard);
lv_obj_set_width( ui_btnNoCard, 50);
lv_obj_set_height( ui_btnNoCard, 30);
lv_obj_set_align( ui_btnNoCard, LV_ALIGN_BOTTOM_RIGHT );


ui_labelYesCard = lv_label_create(ui_btnYesCard);
lv_obj_set_width( ui_labelYesCard, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_labelYesCard, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_labelYesCard, LV_ALIGN_CENTER );
lv_label_set_text(ui_labelYesCard,"YES");

ui_labelNoCard = lv_label_create(ui_btnNoCard);
lv_obj_set_width( ui_labelNoCard, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_labelNoCard, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_labelNoCard, LV_ALIGN_CENTER );
lv_label_set_text(ui_labelNoCard,"NO");


lv_obj_add_event_cb(ui_PressDeleteCard, ui_event_PressDeleteCard, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_PressAddCard, ui_event_PressAddCard, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_PressRestoreCard, ui_event_PressRestoreCard, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_PressShowCard, ui_event_PressShowCard, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_btnBackCard, ui_event_btnBackCard, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_PanelCard, ui_event_PanelCard, LV_EVENT_ALL, NULL);


lv_obj_add_event_cb(ui_btnYesCard, ui_event_btnYesCard, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_btnNoCard, ui_event_btnNoCard, LV_EVENT_ALL, NULL);
}
