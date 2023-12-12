// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: GUI_v1

#ifndef _GUI_V1_UI_H
#define _GUI_V1_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
  #if __has_include("lvgl.h")
    #include "lvgl.h"
  #elif __has_include("lvgl/lvgl.h")
    #include "lvgl/lvgl.h"
  #else
    #include "lvgl.h"
  #endif
#else
  #include "lvgl.h"
#endif

#include "ui_helpers.h"
#include "ui_events.h"
// SCREEN: ui_Screen1
void ui_Screen1_screen_init(void);
extern lv_obj_t *ui_Screen1;
void ui_event_rootpanel( lv_event_t * e);
extern lv_obj_t *ui_rootpanel;
extern lv_obj_t *ui_AreaPWHome;
void ui_event_Unlockbtn( lv_event_t * e);
extern lv_obj_t *ui_Unlockbtn;
void ui_event_Settingbtn( lv_event_t * e);
extern lv_obj_t *ui_Settingbtn;
extern lv_obj_t *ui_Label4;
extern lv_obj_t *ui_Label5;
extern lv_obj_t *ui_AreaPopup;
extern lv_obj_t *ui_KeyboardPWHome;
extern lv_obj_t *ui_btnPassSetting;
extern lv_obj_t *ui_labelPassSetting;
void ui_event_PressedOkPW( lv_event_t *e);
// SCREEN: ui_ScreenSetting
void ui_ScreenSetting_screen_init(void);
extern lv_obj_t *ui_ScreenSetting;
extern lv_obj_t *ui_Panel1;
void ui_event_HomeOptionbtn( lv_event_t * e);
extern lv_obj_t *ui_HomeOptionbtn;
void ui_event_PWOptionbtn( lv_event_t * e);
extern lv_obj_t *ui_PWOptionbtn;
void ui_event_FPOptionbtn( lv_event_t * e);
extern lv_obj_t *ui_FPOptionbtn;
void ui_event_CardOptionbtn( lv_event_t * e);
extern lv_obj_t *ui_CardOptionbtn;
extern lv_obj_t *ui_Label3;
extern lv_obj_t *ui_Label9;
extern lv_obj_t *ui_Label10;
extern lv_obj_t *ui_Label11;
// SCREEN: ui_SceenFinger
void ui_SceenFinger_screen_init(void);
extern lv_obj_t *ui_SceenFinger;
extern lv_obj_t *ui_PanelFinger;
extern lv_obj_t *ui_panelConfirmFP;
void ui_event_PressDeleteFinger( lv_event_t * e);
extern lv_obj_t *ui_PressDeleteFinger;
void ui_event_PressAddFinger( lv_event_t * e);
extern lv_obj_t *ui_PressAddFinger;
void ui_event_PressRestoreFinger( lv_event_t * e);
extern lv_obj_t *ui_PressRestoreFinger;
void ui_event_PressShowFinger( lv_event_t * e);
extern lv_obj_t *ui_PressShowFinger;
extern lv_obj_t *ui_Label14;
extern lv_obj_t *ui_Label16;
extern lv_obj_t *ui_Label17;
extern lv_obj_t *ui_Label18;
extern lv_obj_t *ui_Label12;
void ui_event_btnBackFinger( lv_event_t * e);
extern lv_obj_t *ui_btnBackFinger;
extern lv_obj_t *ui_BackFinger;
extern lv_obj_t *ui_areaPopupFP;
void ui_event_PanelFinger( lv_event_t * e);
void ui_event_btnYesFP( lv_event_t * e);
extern lv_obj_t *ui_btnYesFP;
extern lv_obj_t *ui_labelYesFP;
void ui_event_btnNoFP( lv_event_t * e);
extern lv_obj_t *ui_btnNoFP;
extern lv_obj_t *ui_labelNoFP;
extern lv_obj_t *ui_labelConfirmFP;
// SCREEN: ui_screenFingerAdd

// void ui_screenFingerAdd_screen_init(void);
// extern lv_obj_t *ui_screenFingerAdd;
// void ui_event_PanelFingerAdd( lv_event_t * e);
// extern lv_obj_t *ui_PanelFingerAdd;
// extern lv_obj_t *ui_Label24;
// void ui_event_panelAddfinger( lv_event_t * e);
// extern lv_obj_t *ui_panelAddfinger;
// extern lv_obj_t *ui_Label13;
// void ui_event_areaEnterNameFP( lv_event_t * e);
// extern lv_obj_t *ui_areaEnterNameFP;
// extern lv_obj_t *ui_btnAddFinger;
// extern lv_obj_t *ui_Label19;
// void ui_event_btnBackAddFP( lv_event_t * e);
// extern lv_obj_t *ui_btnBackAddFP;
// extern lv_obj_t *ui_BackFinger1;
// void ui_event_btnHomeAddFP( lv_event_t * e);
// extern lv_obj_t *ui_btnHomeAddFP;
// extern lv_obj_t *ui_BackHomeAddFinger;
// extern lv_obj_t *ui_areaNotyfyAddFP;
// extern lv_obj_t *ui_KeyboardFingerAdd;
// void ui_event_btnAddFinger( lv_event_t * e);
// void ui_event_PressedOkAddFP( lv_event_t *e);

// SCREEN: ui_screenFingerDelete
void ui_screenFingerDelete_screen_init(void);
extern lv_obj_t *ui_screenFingerDelete;
void ui_event_PanelFingerDelete( lv_event_t * e);
extern lv_obj_t *ui_PanelFingerDelete;
extern lv_obj_t *ui_Label20;
void ui_event_panelDeleteFinger( lv_event_t * e);
extern lv_obj_t *ui_panelDeleteFinger;
extern lv_obj_t *ui_Label21;
void ui_event_areaEnterNameFP1( lv_event_t * e);
extern lv_obj_t *ui_areaEnterNameFP1;
extern lv_obj_t *ui_btnDeleteFinger;
extern lv_obj_t *ui_Label22;
void ui_event_btnBackFingerDelete( lv_event_t * e);
extern lv_obj_t *ui_btnBackFingerDelete;
extern lv_obj_t *ui_BackFinger2;
void ui_event_btnHomeFingerDelete( lv_event_t * e);
extern lv_obj_t *ui_btnHomeFingerDelete;
extern lv_obj_t *ui_BackHomeAddFinger1;
extern lv_obj_t *ui_areaNotyfyDeleteFP;
extern lv_obj_t *ui_KeyboardFingerDelete;
void ui_event_btnDeleteFinger( lv_event_t * e);
void ui_event_PressedOkDeleteFP( lv_event_t * e);
extern lv_obj_t *ui_areaFPDeletePadding;


// SCREEN: ui_screenFingerShow
void ui_screenFingerShow_screen_init(void);
extern lv_obj_t *ui_screenFingerShow;
extern lv_obj_t *ui_PanelFingerShow;
extern lv_obj_t *ui_Label23;
extern lv_obj_t *ui_panelShowFP;
void ui_event_btnBackShowFP( lv_event_t * e);
extern lv_obj_t *ui_btnBackShowFP;
extern lv_obj_t *ui_BackFinger3;
void ui_event_btnHomeShowFP( lv_event_t * e);
extern lv_obj_t *ui_btnHomeShowFP;
extern lv_obj_t *ui_BackHomeAddFinger2;
extern lv_obj_t *ui_areaShowFP;
// SCREEN: ui_SceenCard
void ui_SceenCard_screen_init(void);
extern lv_obj_t *ui_SceenCard;
extern lv_obj_t *ui_PanelCard;
void ui_event_PressDeleteCard( lv_event_t * e);
extern lv_obj_t *ui_PressDeleteCard;
void ui_event_PressAddCard( lv_event_t * e);
extern lv_obj_t *ui_PressAddCard;
void ui_event_PressRestoreCard( lv_event_t * e);
extern lv_obj_t *ui_PressRestoreCard;
void ui_event_PressShowCard( lv_event_t * e);
extern lv_obj_t *ui_PressShowCard;
extern lv_obj_t *ui_Label25;
extern lv_obj_t *ui_Label26;
extern lv_obj_t *ui_Label27;
extern lv_obj_t *ui_Label28;
extern lv_obj_t *ui_Label29;
void ui_event_btnBackCard( lv_event_t * e);
extern lv_obj_t *ui_btnBackCard;
extern lv_obj_t *ui_BackFinger4;
extern lv_obj_t *ui_areaPopupCard;
void ui_event_PanelCard( lv_event_t * e);
void ui_event_btnYesCard( lv_event_t * e);
extern lv_obj_t *ui_btnYesCard;
extern lv_obj_t *ui_labelYesCard;
void ui_event_btnNoCard( lv_event_t * e);
extern lv_obj_t *ui_btnNoCard;
extern lv_obj_t *ui_labelNoCard;
extern lv_obj_t *ui_labelConfirmCard;
extern lv_obj_t *ui_panelConfirmCard;


// // SCREEN: ui_screenCardAdd
// void ui_screenCardAdd_screen_init(void);
// extern lv_obj_t *ui_screenCardAdd;
// void ui_event_PanelCardAdd( lv_event_t * e);
// extern lv_obj_t *ui_PanelCardAdd;
// extern lv_obj_t *ui_Label30;
// void ui_event_panelCardAdd( lv_event_t * e);
// extern lv_obj_t *ui_panelCardAdd;
// extern lv_obj_t *ui_Label31;
// void ui_event_areaEnterNameFP2( lv_event_t * e);
// extern lv_obj_t *ui_areaEnterNameFP2;
// extern lv_obj_t *ui_btnAddFinger2;
// extern lv_obj_t *ui_Label32;
// void ui_event_btnBackAddCard( lv_event_t * e);
// extern lv_obj_t *ui_btnBackAddCard;
// extern lv_obj_t *ui_BackFinger5;
// void ui_event_btnHomeAddCard( lv_event_t * e);
// extern lv_obj_t *ui_btnHomeAddCard;
// void ui_event_BackHomeAddFinger3( lv_event_t * e);
// extern lv_obj_t *ui_BackHomeAddFinger3;
// extern lv_obj_t *ui_areaNotyfyAddCard;
// extern lv_obj_t *ui_KeyboardAddCard;
// void ui_event_btnCardAdd( lv_event_t *e);
// void ui_event_PressedOkAddCard( lv_event_t *e);
// SCREEN: ui_screenCardDelete
void ui_screenCardDelete_screen_init(void);
extern lv_obj_t *ui_screenCardDelete;
void ui_event_PanelCardDelete( lv_event_t * e);
extern lv_obj_t *ui_PanelCardDelete;
extern lv_obj_t *ui_Label33;
void ui_event_panelDeleteCard( lv_event_t * e);
extern lv_obj_t *ui_panelDeleteCard;
extern lv_obj_t *ui_Label34;
void ui_event_areaEnterNameDeleteCard( lv_event_t * e);
extern lv_obj_t *ui_areaEnterNameDeleteCard;
extern lv_obj_t *ui_btnDeleteCard1;
extern lv_obj_t *ui_Label35;
void ui_event_btnBackCardDelete( lv_event_t * e);
extern lv_obj_t *ui_btnBackCardDelete;
extern lv_obj_t *ui_BackFinger6;
void ui_event_btnHomeCardDelete( lv_event_t * e);
extern lv_obj_t *ui_btnHomeCardDelete;
extern lv_obj_t *ui_BackHomeAddFinger4;
extern lv_obj_t *ui_areaNotyfyDeleteCard;
extern lv_obj_t *ui_KeyboardCardDelete;
void ui_event_btnDeleteCard( lv_event_t *e);
void ui_event_PressedOkDeleteCard( lv_event_t *e);

// SCREEN: ui_screenCardShow
void ui_screenCardShow_screen_init(void);
extern lv_obj_t *ui_screenCardShow;
extern lv_obj_t *ui_PanelCardShow;
extern lv_obj_t *ui_Label36;
extern lv_obj_t *ui_panelShowCard;
void ui_event_btnBackShowCard( lv_event_t * e);
extern lv_obj_t *ui_btnBackShowCard;
extern lv_obj_t *ui_BackFinger7;
void ui_event_btnHomeShowCard( lv_event_t * e);
extern lv_obj_t *ui_btnHomeShowCard;
extern lv_obj_t *ui_BackHomeAddFinger5;
extern lv_obj_t *ui_areaShowCard;
// SCREEN: ui_SceenPassword
void ui_SceenPassword_screen_init(void);
extern lv_obj_t *ui_SceenPassword;
void ui_event_PanelPassword( lv_event_t * e);
extern lv_obj_t *ui_PanelPassword;
extern lv_obj_t *ui_Label41;
void ui_event_areaPWCurrent( lv_event_t * e);
extern lv_obj_t *ui_areaPWCurrent;
void ui_event_areaPWNew( lv_event_t * e);
extern lv_obj_t *ui_areaPWNew;
void ui_event_areaPWConfirm( lv_event_t * e);
extern lv_obj_t *ui_areaPWConfirm;
extern lv_obj_t *ui_areaPWPadding;
void ui_event_btnBackPW( lv_event_t * e);
void ui_event_btnHomePW(lv_event_t *e);
extern lv_obj_t *ui_btnBackPW;
extern lv_obj_t *ui_BackFinger8;
extern lv_obj_t *ui_Label37;
void ui_event_btnChangePW( lv_event_t * e);
extern lv_obj_t *ui_btnChangePW;
extern lv_obj_t *ui_Label38;
extern lv_obj_t *ui_KeyboardChangePW;
extern lv_obj_t *ui_areaNotifyChangePW;
extern lv_obj_t *ui____initial_actions0;
extern lv_obj_t *ui_btnHomePW;
extern lv_obj_t *ui_HomePW;
void ui_event_KeyboardChangePWOk( lv_event_t * e);
//ScreenHistory
// SCREEN: ui_screenHistory
void ui_screenHistory_screen_init(void);
extern lv_obj_t *ui_screenHistory;
extern lv_obj_t *ui_PanelHistoryHeader;
extern lv_obj_t *ui_LabelHistory;
extern lv_obj_t *ui_panelHistory;
void ui_event_btnBackHistory( lv_event_t * e);
extern lv_obj_t *ui_btnBackHistory;
extern lv_obj_t *ui_BackHistory;
void ui_event_btnHomeHistory (lv_event_t * e);
extern lv_obj_t *ui_btnHomeHistory;
extern lv_obj_t *ui_BackHomeHistory;
extern lv_obj_t *ui_areaShowHistory;

LV_IMG_DECLARE( ui_img_iconunlock_png);   // assets\iconUnlock.png
LV_IMG_DECLARE( ui_img_iconsetting_png);   // assets\iconSetting.png
LV_IMG_DECLARE( ui_img_iconhome_png);   // assets\iconHome.png
LV_IMG_DECLARE( ui_img_iconpassword_png);   // assets\iconPassword.png
LV_IMG_DECLARE( ui_img_iconfinger_png);   // assets\iconFinger.png
LV_IMG_DECLARE( ui_img_iconcard_png);   // assets\iconCard.png

//Screen Add fingerprint

extern bool addFinger;

extern uint16_t volumeTime;
extern bool volumeStart;
void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
