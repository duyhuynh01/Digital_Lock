// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: GUI_v1

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////

// SCREEN: ui_Screen1
void ui_Screen1_screen_init(void);
lv_obj_t *ui_Screen1;
void ui_event_rootpanel(lv_event_t *e);
lv_obj_t *ui_rootpanel;
lv_obj_t *ui_AreaPWHome;
void ui_event_Unlockbtn(lv_event_t *e);
lv_obj_t *ui_Unlockbtn;
void ui_event_Settingbtn(lv_event_t *e);
lv_obj_t *ui_Settingbtn;
lv_obj_t *ui_Label4;
lv_obj_t *ui_Label5;
lv_obj_t *ui_AreaPopup;
lv_obj_t *ui_KeyboardPWHome;
lv_obj_t *ui_btnPassSetting;
lv_obj_t *ui_labelPassSetting;
void ui_event_PressedOkPW(lv_event_t *e);
void ui_event_btnPassSetting( lv_event_t *e);

// SCREEN: ui_ScreenSetting
void ui_ScreenSetting_screen_init(void);
lv_obj_t *ui_ScreenSetting;
lv_obj_t *ui_Panel1;
void ui_event_HomeOptionbtn(lv_event_t *e);
lv_obj_t *ui_HomeOptionbtn;
void ui_event_PWOptionbtn(lv_event_t *e);
lv_obj_t *ui_PWOptionbtn;
void ui_event_FPOptionbtn(lv_event_t *e);
lv_obj_t *ui_FPOptionbtn;
void ui_event_CardOptionbtn(lv_event_t *e);
lv_obj_t *ui_CardOptionbtn;
lv_obj_t *ui_Label3;
lv_obj_t *ui_Label9;
lv_obj_t *ui_Label10;
lv_obj_t *ui_Label11;

// SCREEN: ui_SceenFinger
void ui_SceenFinger_screen_init(void);
lv_obj_t *ui_SceenFinger;
lv_obj_t *ui_PanelFinger;
void ui_event_PressDeleteFinger(lv_event_t *e);
lv_obj_t *ui_PressDeleteFinger;
void ui_event_PressAddFinger(lv_event_t *e);
lv_obj_t *ui_PressAddFinger;
void ui_event_PressRestoreFinger(lv_event_t *e);
lv_obj_t *ui_PressRestoreFinger;
void ui_event_PressShowFinger(lv_event_t *e);
lv_obj_t *ui_PressShowFinger;
lv_obj_t *ui_Label14;
lv_obj_t *ui_Label16;
lv_obj_t *ui_Label17;
lv_obj_t *ui_Label18;
lv_obj_t *ui_Label12;
void ui_event_btnBackFinger(lv_event_t *e);
lv_obj_t *ui_btnBackFinger;
lv_obj_t *ui_BackFinger;
lv_obj_t *ui_areaPopupFP;
void ui_event_PanelFinger(lv_event_t *e);

// SCREEN: ui_screenFingerAdd
void ui_screenFingerAdd_screen_init(void);
lv_obj_t *ui_screenFingerAdd;
void ui_event_PanelFingerAdd(lv_event_t *e);
lv_obj_t *ui_PanelFingerAdd;
lv_obj_t *ui_Label24;
void ui_event_panelAddfinger(lv_event_t *e);
lv_obj_t *ui_panelAddfinger;
lv_obj_t *ui_Label13;
void ui_event_areaEnterNameFP(lv_event_t *e);
lv_obj_t *ui_areaEnterNameFP;
lv_obj_t *ui_btnAddFinger;
lv_obj_t *ui_Label19;
void ui_event_btnBackAddFP(lv_event_t *e);
lv_obj_t *ui_btnBackAddFP;
lv_obj_t *ui_BackFinger1;
void ui_event_btnHomeAddFP(lv_event_t *e);
lv_obj_t *ui_btnHomeAddFP;
lv_obj_t *ui_BackHomeAddFinger;
lv_obj_t *ui_areaNotyfyAddFP;
lv_obj_t *ui_KeyboardFingerAdd;
void ui_event_PressedOkAddFP(lv_event_t *e);

// SCREEN: ui_screenFingerDelete
void ui_screenFingerDelete_screen_init(void);
lv_obj_t *ui_screenFingerDelete;
void ui_event_PanelFingerDelete(lv_event_t *e);
lv_obj_t *ui_PanelFingerDelete;
lv_obj_t *ui_Label20;
void ui_event_panelDeleteFinger(lv_event_t *e);
lv_obj_t *ui_panelDeleteFinger;
lv_obj_t *ui_Label21;
void ui_event_areaEnterNameFP1(lv_event_t *e);
lv_obj_t *ui_areaEnterNameFP1;
lv_obj_t *ui_btnDeleteFinger;
lv_obj_t *ui_Label22;
void ui_event_btnBackFingerDelete(lv_event_t *e);
lv_obj_t *ui_btnBackFingerDelete;
lv_obj_t *ui_BackFinger2;
void ui_event_btnHomeFingerDelete(lv_event_t *e);
lv_obj_t *ui_btnHomeFingerDelete;
lv_obj_t *ui_BackHomeAddFinger1;
lv_obj_t *ui_areaNotyfyDeleteFP;
lv_obj_t *ui_KeyboardFingerDelete;
void ui_event_btnDeleteFinger(lv_event_t *e);
void ui_event_PressedOkDeleteFP(lv_event_t *e);

// SCREEN: ui_screenFingerShow
void ui_screenFingerShow_screen_init(void);
lv_obj_t *ui_screenFingerShow;
lv_obj_t *ui_PanelFingerShow;
lv_obj_t *ui_Label23;
lv_obj_t *ui_panelShowFP;
void ui_event_btnBackShowFP(lv_event_t *e);
lv_obj_t *ui_btnBackShowFP;
lv_obj_t *ui_BackFinger3;
void ui_event_btnHomeShowFP(lv_event_t *e);
lv_obj_t *ui_btnHomeShowFP;
lv_obj_t *ui_BackHomeAddFinger2;
lv_obj_t *ui_areaShowFP;

// SCREEN: ui_SceenCard
void ui_SceenCard_screen_init(void);
lv_obj_t *ui_SceenCard;
lv_obj_t *ui_PanelCard;
void ui_event_PressDeleteCard(lv_event_t *e);
lv_obj_t *ui_PressDeleteCard;
void ui_event_PressAddCard(lv_event_t *e);
lv_obj_t *ui_PressAddCard;
void ui_event_PressRestoreCard(lv_event_t *e);
lv_obj_t *ui_PressRestoreCard;
void ui_event_PressShowCard(lv_event_t *e);
lv_obj_t *ui_PressShowCard;
lv_obj_t *ui_Label25;
lv_obj_t *ui_Label26;
lv_obj_t *ui_Label27;
lv_obj_t *ui_Label28;
lv_obj_t *ui_Label29;
void ui_event_btnBackCard(lv_event_t *e);
lv_obj_t *ui_btnBackCard;
lv_obj_t *ui_BackFinger4;
lv_obj_t *ui_areaPopupCard;
void ui_event_PanelCard(lv_event_t *e);

// SCREEN: ui_screenCardAdd
void ui_screenCardAdd_screen_init(void);
lv_obj_t *ui_screenCardAdd;
void ui_event_PanelCardAdd(lv_event_t *e);
lv_obj_t *ui_PanelCardAdd;
lv_obj_t *ui_Label30;
void ui_event_panelCardAdd(lv_event_t *e);
lv_obj_t *ui_panelCardAdd;
lv_obj_t *ui_Label31;
void ui_event_areaEnterNameFP2(lv_event_t *e);
lv_obj_t *ui_areaEnterNameFP2;
lv_obj_t *ui_btnAddFinger2;
lv_obj_t *ui_Label32;
void ui_event_btnBackAddCard(lv_event_t *e);
lv_obj_t *ui_btnBackAddCard;
lv_obj_t *ui_BackFinger5;
void ui_event_btnHomeAddCard(lv_event_t *e);
lv_obj_t *ui_btnHomeAddCard;
void ui_event_BackHomeAddFinger3(lv_event_t *e);
lv_obj_t *ui_BackHomeAddFinger3;
lv_obj_t *ui_areaNotyfyAddCard;
lv_obj_t *ui_KeyboardAddCard;
void ui_event_btnCardAdd(lv_event_t *e);
void ui_event_PressedOkAddCard(lv_event_t *e);

// SCREEN: ui_screenCardDelete
void ui_screenCardDelete_screen_init(void);
lv_obj_t *ui_screenCardDelete;
void ui_event_PanelCardDelete(lv_event_t *e);
lv_obj_t *ui_PanelCardDelete;
lv_obj_t *ui_Label33;
void ui_event_panelDeleteCard(lv_event_t *e);
lv_obj_t *ui_panelDeleteCard;
lv_obj_t *ui_Label34;
void ui_event_areaEnterNameDeleteCard(lv_event_t *e);
lv_obj_t *ui_areaEnterNameDeleteCard;
lv_obj_t *ui_btnDeleteCard1;
lv_obj_t *ui_Label35;
void ui_event_btnBackCardDelete(lv_event_t *e);
lv_obj_t *ui_btnBackCardDelete;
lv_obj_t *ui_BackFinger6;
void ui_event_btnHomeCardDelete(lv_event_t *e);
lv_obj_t *ui_btnHomeCardDelete;
lv_obj_t *ui_BackHomeAddFinger4;
lv_obj_t *ui_areaNotyfyDeleteCard;
lv_obj_t *ui_KeyboardCardDelete;
void ui_event_btnDeleteCard(lv_event_t *e);
void ui_event_PressedOkDeleteCard(lv_event_t *e);

// SCREEN: ui_screenCardShow
void ui_screenCardShow_screen_init(void);
lv_obj_t *ui_screenCardShow;
lv_obj_t *ui_PanelCardShow;
lv_obj_t *ui_Label36;
lv_obj_t *ui_panelShowCard;
void ui_event_btnBackShowCard(lv_event_t *e);
lv_obj_t *ui_btnBackShowCard;
lv_obj_t *ui_BackFinger7;
void ui_event_btnHomeShowCard(lv_event_t *e);
lv_obj_t *ui_btnHomeShowCard;
lv_obj_t *ui_BackHomeAddFinger5;
lv_obj_t *ui_areaShowCard;

// SCREEN: ui_SceenPassword
void ui_SceenPassword_screen_init(void);
lv_obj_t *ui_SceenPassword;
void ui_event_PanelPassword(lv_event_t *e);
lv_obj_t *ui_PanelPassword;
lv_obj_t *ui_Label41;
void ui_event_areaPWCurrent(lv_event_t *e);
lv_obj_t *ui_areaPWCurrent;
void ui_event_areaPWNew(lv_event_t *e);
lv_obj_t *ui_areaPWNew;
void ui_event_areaPWConfirm(lv_event_t *e);
lv_obj_t *ui_areaPWConfirm;
lv_obj_t *ui_areaPWPadding;
void ui_event_btnBackPW(lv_event_t *e);
lv_obj_t *ui_btnBackPW;
lv_obj_t *ui_BackFinger8;
lv_obj_t *ui_Label37;
void ui_event_btnChangePW(lv_event_t *e);
lv_obj_t *ui_btnChangePW;
lv_obj_t *ui_Label38;
lv_obj_t *ui_KeyboardChangePW;
lv_obj_t *ui_areaNotifyChangePW;
lv_obj_t *ui____initial_actions0;
void ui_event_KeyboardChangePWOk(lv_event_t *e);
///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
#error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP != 0
#error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_rootpanel(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_flag_modify(ui_AreaPWHome, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_KeyboardPWHome, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_AreaPopup, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
bool flagUnlock = false;
void ui_event_Unlockbtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_flag_modify(ui_KeyboardPWHome, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_AreaPWHome, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        flagUnlock = true;
    }
}
bool flagSetting = false;
void ui_event_Settingbtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_flag_modify(ui_KeyboardPWHome, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_AreaPWHome, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        // _ui_flag_modify(ui_btnPassSetting, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        // lv_refr_now(NULL);
        flagSetting = true;
        // isSettingMode(e);
    }
}

void ui_event_btnPassSetting( lv_event_t *e)
{
     lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_flag_modify(ui_KeyboardPWHome, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_AreaPWHome, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }

}
void ui_event_HomeOptionbtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_screen_change(&ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_Screen1_screen_init);
    }
}
void ui_event_PWOptionbtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_screen_change(&ui_SceenPassword, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_SceenPassword_screen_init);
    }
}
void ui_event_FPOptionbtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_screen_change(&ui_SceenFinger, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_SceenFinger_screen_init);
    }
}
void ui_event_CardOptionbtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_screen_change(&ui_SceenCard, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_SceenCard_screen_init);
    }
}
void ui_event_PressDeleteFinger(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_screen_change(&ui_screenFingerDelete, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_screenFingerDelete_screen_init);
    }
}
void ui_event_PressAddFinger(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_screen_change(&ui_screenFingerAdd, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_screenFingerAdd_screen_init);
        _ui_flag_modify(ui_areaNotyfyAddFP, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        //   callFuncAddFP( e );
    }
}
void ui_event_PressRestoreFinger(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        callFuncRestoreFP(e);
    }
}
void ui_event_PressShowFinger(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_screen_change(&ui_screenFingerShow, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_screenFingerShow_screen_init);
        callFuncShowFP(e);
    }
}
void ui_event_PanelFinger(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_flag_modify(ui_areaPopupFP, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_btnBackFinger(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_screen_change(&ui_ScreenSetting, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_ScreenSetting_screen_init);
    }
}
void ui_event_PanelFingerAdd(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_flag_modify(ui_KeyboardFingerAdd, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}

void ui_event_panelAddfinger(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_flag_modify(ui_KeyboardFingerAdd, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_areaNotyfyAddFP, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_areaEnterNameFP(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_flag_modify(ui_KeyboardFingerAdd, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
}
void ui_event_btnBackAddFP(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_screen_change(&ui_SceenFinger, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_SceenFinger_screen_init);
    }
}
void ui_event_btnHomeAddFP(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_screen_change(&ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_Screen1_screen_init);
    }
}
void ui_event_PanelFingerDelete(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_flag_modify(ui_KeyboardFingerDelete, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_panelDeleteFinger(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_flag_modify(ui_KeyboardFingerDelete, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_areaNotyfyDeleteFP, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_areaEnterNameFP1(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_flag_modify(ui_KeyboardFingerDelete, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
}
void ui_event_btnBackFingerDelete(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_screen_change(&ui_SceenFinger, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_SceenFinger_screen_init);
    }
}
void ui_event_btnHomeFingerDelete(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_screen_change(&ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_Screen1_screen_init);
    }
}
void ui_event_btnBackShowFP(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_screen_change(&ui_SceenFinger, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_SceenFinger_screen_init);
    }
}
void ui_event_btnHomeShowFP(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_screen_change(&ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_Screen1_screen_init);
    }
}
void ui_event_PressDeleteCard(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_screen_change(&ui_screenCardDelete, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_screenFingerDelete_screen_init);
    }
}
void ui_event_PressAddCard(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_screen_change(&ui_screenCardAdd, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_screenCardAdd_screen_init);
    }
}
void ui_event_PressRestoreCard(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        callFuncRestoreCard(e);
    }
}
void ui_event_PressShowCard(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_screen_change(&ui_screenCardShow, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_screenCardShow_screen_init);
        callFuncShowCard(e);
    }
}
void ui_event_btnBackCard(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_screen_change(&ui_ScreenSetting, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_ScreenSetting_screen_init);
    }
}
void ui_event_PanelCard(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_flag_modify(ui_areaPopupCard, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_PanelCardAdd(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_flag_modify(ui_KeyboardAddCard, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_panelCardAdd(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_flag_modify(ui_KeyboardAddCard, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_areaNotyfyAddCard, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_areaEnterNameFP2(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_flag_modify(ui_KeyboardAddCard, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
}
void ui_event_btnBackAddCard(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_screen_change(&ui_SceenCard, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_SceenCard_screen_init);
    }
}
void ui_event_btnHomeAddCard(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_screen_change(&ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_Screen1_screen_init);
    }
}
void ui_event_BackHomeAddFinger3(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(&ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_Screen1_screen_init);
    }
}
void ui_event_PanelCardDelete(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_flag_modify(ui_KeyboardCardDelete, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_panelDeleteCard(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_flag_modify(ui_KeyboardCardDelete, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_areaNotyfyDeleteCard, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_areaEnterNameDeleteCard(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_flag_modify(ui_KeyboardCardDelete, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
}
void ui_event_btnBackCardDelete(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_screen_change(&ui_SceenCard, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_SceenCard_screen_init);
    }
}
void ui_event_btnHomeCardDelete(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_screen_change(&ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_Screen1_screen_init);
    }
}
void ui_event_btnBackShowCard(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_screen_change(&ui_SceenCard, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_SceenCard_screen_init);
    }
}
void ui_event_btnHomeShowCard(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_screen_change(&ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_Screen1_screen_init);
    }
}
void ui_event_PanelPassword(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_flag_modify(ui_KeyboardChangePW, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_areaPWPadding, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_areaNotifyChangePW, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}

void ui_event_btnBackPW(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_screen_change(&ui_ScreenSetting, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_ScreenSetting_screen_init);
    }
}
void ui_event_btnChangePW(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        callFuncChangePW(e);
    }
}
bool passCurrent = false;
void ui_event_areaPWCurrent(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        passCurrent = true;
        _ui_flag_modify(ui_KeyboardChangePW, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_areaPWPadding, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        lv_refr_now(NULL);
        lv_timer_handler();
    }
}
bool passNew = false;
void ui_event_areaPWNew(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        passNew = true;
        _ui_flag_modify(ui_areaPWPadding, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_KeyboardChangePW, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        lv_refr_now(NULL);
        lv_timer_handler();
    }
}
bool passConfirm = false;
void ui_event_areaPWConfirm(lv_event_t *e)
{
    
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        passConfirm = true;
        _ui_flag_modify(ui_KeyboardChangePW, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_areaPWPadding, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        lv_refr_now(NULL);
        lv_timer_handler();
    }
}
void ui_event_KeyboardChangePWOk(lv_event_t *e)
{
    lv_obj_t *obj = lv_event_get_target(e);
    lv_obj_t *ta = lv_event_get_user_data(e);
    const char *txt = lv_btnmatrix_get_btn_text(obj, lv_btnmatrix_get_selected_btn(obj));
    if (strcmp(txt, LV_SYMBOL_OK) == 0)
    {
        _ui_flag_modify(ui_KeyboardChangePW, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_areaPWPadding, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        if (passCurrent)
        {
            const char *buffer = lv_textarea_get_text(ui_areaPWPadding);
            lv_textarea_set_text(ui_areaPWCurrent, buffer);
            lv_textarea_set_text(ui_areaPWPadding, "");
            passCurrent = false;
        }
        if (passNew)
        {
            const char *buffer = lv_textarea_get_text(ui_areaPWPadding);
            lv_textarea_set_text(ui_areaPWNew, buffer);
            lv_textarea_set_text(ui_areaPWPadding, "");
            passNew = false;
        }
        if (passConfirm)
        {
            const char *buffer = lv_textarea_get_text(ui_areaPWPadding);
            lv_textarea_set_text(ui_areaPWConfirm, buffer);
            lv_textarea_set_text(ui_areaPWPadding, "");
            passConfirm = false;
        }
        lv_refr_now(NULL);
        lv_timer_handler();
    }
}

/*---------------Screen add fingerpint---------------*/
bool addFinger = false;
void ui_event_btnAddFinger(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        // addFinger = true;
        _ui_flag_modify(ui_areaNotyfyAddFP, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        lv_refr_now(NULL);
        callFuncAddFP(e);
    }
}
void ui_event_PressedOkAddFP(lv_event_t *e)
{
    lv_obj_t *obj = lv_event_get_target(e);
    lv_obj_t *ta = lv_event_get_user_data(e);
    const char *txt = lv_btnmatrix_get_btn_text(obj, lv_btnmatrix_get_selected_btn(obj));
    if (strcmp(txt, LV_SYMBOL_OK) == 0)
    {
        _ui_flag_modify(ui_KeyboardFingerAdd, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}

/*--------------Screen delete fingerprint-------------------*/
void ui_event_btnDeleteFinger(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        // addFinger = true;
        _ui_flag_modify(ui_areaNotyfyDeleteFP, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        lv_refr_now(NULL);
        callFuncDeleteFP(e);
    }
}
void ui_event_PressedOkDeleteFP(lv_event_t *e)
{
    lv_obj_t *obj = lv_event_get_target(e);
    lv_obj_t *ta = lv_event_get_user_data(e);
    const char *txt = lv_btnmatrix_get_btn_text(obj, lv_btnmatrix_get_selected_btn(obj));
    if (strcmp(txt, LV_SYMBOL_OK) == 0)
    {
        _ui_flag_modify(ui_KeyboardFingerDelete, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}

/*--------------Screen card add------------------*/
void ui_event_btnCardAdd(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_flag_modify(ui_areaNotyfyAddCard, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        lv_refr_now(NULL);
        callFuncAddCard(e);
        // callFuncDeleteCard( e );
    }
}
void ui_event_PressedOkAddCard(lv_event_t *e)
{
    lv_obj_t *obj = lv_event_get_target(e);
    lv_obj_t *ta = lv_event_get_user_data(e);
    const char *txt = lv_btnmatrix_get_btn_text(obj, lv_btnmatrix_get_selected_btn(obj));
    if (strcmp(txt, LV_SYMBOL_OK) == 0)
    {
        _ui_flag_modify(ui_KeyboardAddCard, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}

/*----------------Screen card delete----------------*/
void ui_event_btnDeleteCard(lv_event_t *e)
{
    _ui_flag_modify(ui_areaNotyfyDeleteCard, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    lv_refr_now(NULL);
    callFuncDeleteCard(e);
}

void ui_event_PressedOkDeleteCard(lv_event_t *e)
{
    lv_obj_t *obj = lv_event_get_target(e);
    lv_obj_t *ta = lv_event_get_user_data(e);
    const char *txt = lv_btnmatrix_get_btn_text(obj, lv_btnmatrix_get_selected_btn(obj));
    if (strcmp(txt, LV_SYMBOL_OK) == 0)
    {
        _ui_flag_modify(ui_KeyboardCardDelete, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
/*-------------------------------------*/

void ui_event_PressedOkPW(lv_event_t *e)
{
    lv_obj_t *obj = lv_event_get_target(e);
    lv_obj_t *ta = lv_event_get_user_data(e);
    const char *txt = lv_btnmatrix_get_btn_text(obj, lv_btnmatrix_get_selected_btn(obj));
    if (strcmp(txt, LV_SYMBOL_OK) == 0)
    {
        _ui_flag_modify(ui_KeyboardPWHome, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_AreaPWHome, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        if(flagUnlock)
        {
            callFuncCheckPW(e);
            flagUnlock = false;
        }
        if(flagSetting)
        {
            callFuncCheckSetting(e);
            flagSetting = false;
        }
        
        
        // _ui_flag_modify(ui_AreaPopup, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
}

///////////////////// SCREENS ////////////////////

void ui_init(void)
{
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    ui_ScreenSetting_screen_init();
    ui_SceenFinger_screen_init();
    ui_screenFingerAdd_screen_init();
    ui_screenFingerDelete_screen_init();
    ui_screenFingerShow_screen_init();
    ui_SceenCard_screen_init();
    ui_screenCardAdd_screen_init();
    ui_screenCardDelete_screen_init();
    ui_screenCardShow_screen_init();
    ui_SceenPassword_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_Screen1);
}
