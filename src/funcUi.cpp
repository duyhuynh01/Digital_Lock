#include "funcUi.hpp"
#include "realtime.hpp"
#include "historyHandler.hpp"
extern FingerPrint myFingerPrint;
extern myEEPROM eeprom;
extern Password myPassword;
extern RFID myRFID;
extern const char *setIdFP;
extern bool isSettingModeOn;
extern bool doorStatus;
extern unsigned int startOpenDoorTimer;
extern unsigned int endOpenDoorTimer;
extern uint8_t invalidCount;
extern HistoryHandler history;
extern realTime realtime;
extern lv_obj_t *table;
extern bool flagHistory;
extern lv_obj_t *tableFP;
extern bool flagShowFP;
extern lv_obj_t *tableRFID;
extern bool flagShowRFID;
extern bool isSettingMode_usedToBlockAuth;
const char *PasswordUnlock = "";
lv_timer_t *hidePopupTimer;
lv_timer_t *hidePopupTimerBtnSetting;
lv_timer_t *hideKeyboardPW;
bool screenIsOn = true;
unsigned long lastTouchTime = 0;
void hidePopupAreaHome(lv_timer_t *timer)
{
    _ui_flag_modify(ui_AreaPopup, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
}

void callFuncCheckPW(lv_event_t *e)
{

    PasswordUnlock = lv_textarea_get_text(ui_AreaPWHome);
    // Serial.println(PasswordUnlock);
    // uint8_t size_char;
    // size_char = strlen(PasswordUnlock);
    // Serial.println(size_char);
    // size_char = strlen(myPassword.getAdminPassword());
    // Serial.println(myPassword.getAdminPassword());
    // Serial.println(size_char);

    if (myPassword.checkAdminPassword() == true)
    {
        isSettingModeOn = true;
        showPopup(ui_AreaPopup, "Unlock!", 5000);
        // _ui_flag_modify(ui_KeyboardPWHome, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        // _ui_flag_modify(ui_KeyboardPWHome, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        hideKeyboard(ui_KeyboardPWHome, 5000);
        showPopupBtnSetting(ui_Settingbtn, 5000);
        // _ui_flag_modify(ui_Label5, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        lv_refr_now(NULL);
        // open door
        doorStatus = true;
        startOpenDoorTimer = millis();
        endOpenDoorTimer = startOpenDoorTimer;
        String temp = "unk";
        String log = temp + "-" + "PW" + "-" + realtime.getTimeLog();
        // Serial.println(log);
        history.updateHistory(log);
    }
    else
    {
        showPopup(ui_AreaPopup, "Incorrect passcode", TIME_POPUP);
    }
    lv_textarea_set_text(ui_AreaPWHome, "");
}

void callFuncAddFP(lv_event_t *e)
{
    // _ui_flag_modify(ui_areaNotyfyAddFP, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    myFingerPrint.enroll();
    // lv_textarea_set_text(ui_areaEnterNameFP, "");
    lv_refr_now(NULL);
}

void callFuncDeleteFP(lv_event_t *e)
{
    const char *getDelete = lv_textarea_get_text(ui_areaEnterNameFP1);
    if (strcmp(getDelete, "") != 0)
    {
        int8_t DelID = std::stoi(getDelete);
        myFingerPrint.unEnroll(DelID);
    }
    else
    {
        showPopup(ui_areaNotyfyDeleteFP, "Please enter an ID.", TIME_POPUP);
    }
    lv_textarea_set_text(ui_areaEnterNameFP1, "");
    
    lv_refr_now(NULL);
}

void callFuncShowFP(lv_event_t *e)
{
    myFingerPrint.showList();
}

void callFuncRestoreFP(lv_event_t *e)
{
    myFingerPrint.restore();
    _ui_flag_modify(ui_panelConfirmFP, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    showPopup(ui_areaPopupFP, "Successlly delete all fingerprints.", TIME_POPUP);
}

void callFuncAddCard(lv_event_t *e)
{
    myRFID.enrollCard();
    // lv_textarea_set_text(ui_areaEnterNameFP2, "");
    lv_refr_now(NULL);
}

void callFuncDeleteCard(lv_event_t *e)
{
    const char *getDelete = lv_textarea_get_text(ui_areaEnterNameDeleteCard);
    if (strcmp(getDelete, "") != 0)
    {
        myRFID.unenrollCard(getDelete);
    }
    else
    {
        showPopup(ui_areaNotyfyDeleteCard, "Please enter a name.", TIME_POPUP);
    }
    lv_textarea_set_text(ui_areaEnterNameDeleteCard, "");
    lv_refr_now(NULL);
}

void callFuncShowCard(lv_event_t *e)
{
    myRFID.showList();
}

void callFuncRestoreCard(lv_event_t *e)
{
    _ui_flag_modify(ui_panelConfirmCard, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    myRFID.restore();
    showPopup(ui_areaPopupCard, "Successlly delete all cards.", TIME_POPUP);
}

void callFuncChangePW(lv_event_t *e)
{
    const char *getCurrentPW = lv_textarea_get_text(ui_areaPWCurrent);
    const char *getNewPW = lv_textarea_get_text(ui_areaPWNew);
    const char *getConfirmPW = lv_textarea_get_text(ui_areaPWConfirm);
    if (strlen(getNewPW) != 6 || strlen(getConfirmPW) != 6)
    {
        Serial.println("Please enter a 6-digit passcode.");
        showPopup(ui_areaNotifyChangePW, "The passcode must be 6-digit", TIME_POPUP);
    }
    else
    {
        myPassword.changePassword(getCurrentPW, getNewPW, getConfirmPW);
    }
    lv_textarea_set_text(ui_areaPWCurrent, "");
    lv_textarea_set_text(ui_areaPWNew, "");
    lv_textarea_set_text(ui_areaPWConfirm, "");
    lv_refr_now(NULL);
}

void callFuncCheckSetting(lv_event_t *e)
{
    unsigned long startTime = millis();
    PasswordUnlock = lv_textarea_get_text(ui_AreaPWHome);
    if (myPassword.checkAdminPassword() == true)
    {
        _ui_screen_change(&ui_ScreenSetting, LV_SCR_LOAD_ANIM_MOVE_LEFT, 100, 0, &ui_ScreenSetting_screen_init);
        _ui_screen_delete(&ui_Screen1);
    }
    else
    {
        showPopup(ui_AreaPopup, "Incorrect password", TIME_POPUP);
    }
    lv_textarea_set_text(ui_AreaPWHome, "");
}

// void isSettingMode(lv_event_t *e)
// {
//     unsigned long startTime = millis();
//     while (millis() - startTime <= TIMEOUT)
//     {
//         myFingerPrint.scanFinger();
//         if (flagModeSetting)
//         {
//             _ui_screen_change(&ui_ScreenSetting, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_ScreenSetting_screen_init);
//             flagModeSetting = false;
//             break;
//         }
//         lv_timer_handler();
//         lv_refr_now(NULL);
//     }
// }

// extern bool flagSetting;
extern bool flagModeSetting;
// void checkbtnSetting()
// {
//     if (flagSetting && flagModeSetting)
//     {
//         while (isTask1Finish == false)
//         {
//             delayMicroseconds(35);
//         }
//         isCriticalTask = true;
//         _ui_flag_modify(ui_AreaPWHome, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
//         _ui_flag_modify(ui_KeyboardPWHome, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
//         lv_refr_now(NULL);
//         delay(2000);
//         _ui_screen_change(&ui_ScreenSetting, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_ScreenSetting_screen_init);
//         _ui_screen_delete(&ui_Screen1);
//         flagSetting = false;
//         flagModeSetting = false;
//         isCriticalTask = false;
//     }
// }

/*---------Function support-----------*/
// void notifyPopup(lv_obj_t *popup, const char *notify, uint32_t timerDuration)
// {
//     lv_textarea_set_text(popup, notify);
//     _ui_flag_modify(popup, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
//     if (hidePopupTimer)
//     {
//         lv_timer_del(hidePopupTimer);
//     }
//     hidePopupTimer = lv_timer_create(hidePopupAreaHome, timerDuration, NULL);
// }

void showPopup(lv_obj_t *popup, const char *notify, uint32_t timerDuration)
{
    lv_textarea_set_text(popup, notify);
    _ui_flag_modify(popup, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    if (hidePopupTimer)
    {
        lv_timer_del(hidePopupTimer);
    }
    // Tạo một timer để tự động ẩn thông báo sau một khoảng thời gian
    hidePopupTimer = lv_timer_create(hidePopupArea, timerDuration, popup);
    lv_refr_now(NULL);
}


void hidePopup(lv_obj_t *popup)
{
    _ui_flag_modify(popup, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
}

void hidePopupArea(lv_timer_t *timer)
{
    lv_obj_t *popup = (lv_obj_t *)timer->user_data;
    hidePopup(popup);
}


void hidePopupSetting(lv_obj_t *popup)
{
    _ui_flag_modify(popup, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
}

void hidePopupAreaBtnSetting(lv_timer_t *timer)
{
    lv_obj_t *popup = (lv_obj_t *)timer->user_data;
    hidePopupSetting(popup);
}


void showPopupBtnSetting(lv_obj_t *popup, uint32_t timerDuration)
{
    _ui_flag_modify(popup, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    if (hidePopupTimerBtnSetting)
    {
        lv_timer_del(hidePopupTimerBtnSetting);
    }
    // Tạo một timer để tự động ẩn thông báo sau một khoảng thời gian
    hidePopupTimerBtnSetting = lv_timer_create(hidePopupAreaBtnSetting, timerDuration, popup);
    lv_refr_now(NULL);
}






void showKeyboard(lv_timer_t *timer)
{
    lv_obj_t *popup = (lv_obj_t *)timer->user_data;
    _ui_flag_modify(popup, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
}
void hideKeyboard(lv_obj_t *popup, uint32_t timerDuration)
{
    _ui_flag_modify(popup, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    if (hideKeyboardPW)
    {
        lv_timer_del(hideKeyboardPW);
    }
    // Tạo một timer để tự động ẩn thông báo sau một khoảng thời gian
    hideKeyboardPW = lv_timer_create(showKeyboard, timerDuration, popup);
    lv_refr_now(NULL);
}

const char *createNotification(const char *mess, const char *name)
{
    char *buffer = new char[strlen(mess) + strlen(name) + 1];
    strcpy(buffer, mess);
    strcat(buffer, name);
    return buffer;
}

void convertNum(lv_obj_t *textarea, uint16_t value)
{
    char buffer[5];
    snprintf(buffer, sizeof(buffer), "%d", value);
    lv_textarea_add_text(textarea, buffer);
}

void isTouch()
{
    bool touched = check_touch(my_indev_driver, my_data);
    if (touched)
    {
        lastTouchTime = millis();
    }
}
void controlScreen()
{
    unsigned long currentTime = millis();

    if (currentTime - lastTouchTime >= TIMEOUT)
    {
        screenIsOn = false;
    }
    else
    {
        screenIsOn = true;
    }

    if (screenIsOn)
    {
        digitalWrite(TFT_BL, TFT_BACKLIGHT_ON);
        // if (isSettingModeOn)
        // {
        //     _ui_flag_modify(ui_KeyboardPWHome, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        // }
        // else
        // {
        //     _ui_flag_modify(ui_KeyboardPWHome, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        // }
        if(!isSettingModeOn)
        {
            _ui_flag_modify(ui_KeyboardPWHome, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        }
    }

    else
    {
        isSettingModeOn = false;
        digitalWrite(TFT_BL, TFT_BACKLIGHT_OFF);
        lv_textarea_set_text(ui_AreaPWHome, "");
        if (flagHistory)
        {
            lv_obj_del(table);
            table = NULL;
            flagHistory = false;
        }
        if(flagShowFP)
        {
            lv_obj_del(tableFP);
            tableFP = NULL;
            flagShowFP = false;
        }
        if(flagShowRFID)
        {
            lv_obj_del(tableRFID);
            tableRFID = NULL;
            flagShowRFID = false;
        }

        _ui_screen_delete(&ui_SceenCard);
        _ui_screen_delete(&ui_SceenFinger);
        _ui_screen_delete(&ui_SceenPassword);
        _ui_screen_delete(&ui_Screen1);
        // _ui_screen_delete(&ui_screenCardAdd);
        _ui_screen_delete(&ui_screenCardDelete);
        _ui_screen_delete(&ui_screenCardShow);
        // _ui_screen_delete(&ui_screenFingerAdd);
        _ui_screen_delete(&ui_screenFingerDelete);
        _ui_screen_delete(&ui_screenFingerShow);
        _ui_screen_delete(&ui_screenHistory);
        _ui_screen_delete(&ui_ScreenSetting);

        _ui_flag_modify(ui_Settingbtn, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        lv_disp_load_scr(ui_Screen1);
        isSettingMode_usedToBlockAuth = false;
    }
}

void callFuncShowHistory(lv_event_t *e)
{
    history.showHistory();  
}