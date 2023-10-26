#include "funcUi.hpp"
extern bool flagModeSetting;
extern FingerPrint myFingerPrint;
extern myEEPROM eeprom;
extern Password myPassword;
extern RFID myRFID;
extern const char *setIdFP;
extern bool flagModeSetting;
const char *PasswordUnlock = "";
lv_timer_t *hidePopupTimer;
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
        showPopup(ui_AreaPopup, "Unlock!", TIME_POPUP);
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
    myFingerPrint.enrollFingerprint();
    lv_textarea_set_text(ui_areaEnterNameFP, "");
    lv_refr_now(NULL);
}

void callFuncDeleteFP(lv_event_t *e)
{
    const char *getDelete = lv_textarea_get_text(ui_areaEnterNameFP1);
    if (strcmp(getDelete, "") != 0)
    {
        myFingerPrint.unEnroll(getDelete);
    }
    else
    {
        showPopup(ui_areaNotyfyDeleteFP, "Please enter a name.", TIME_POPUP);
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
    showPopup(ui_areaPopupFP, "Successlly delete all fingerprints.", TIME_POPUP);
}

void callFuncAddCard(lv_event_t *e)
{
    myRFID.enrollCard();
    lv_textarea_set_text(ui_areaEnterNameFP2, "");
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
        _ui_screen_change(&ui_ScreenSetting, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_ScreenSetting_screen_init);
    }
    else
    {
        showPopup(ui_AreaPopup, "Incorrect password", TIME_POPUP);
    }
    lv_textarea_set_text(ui_AreaPWHome, "");
}

void isSettingMode(lv_event_t *e)
{
    unsigned long startTime = millis();
    while (millis() - startTime <= TIMEOUT)
    {
        myFingerPrint.scanFinger();
        if (flagModeSetting)
        {
            _ui_screen_change(&ui_ScreenSetting, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_ScreenSetting_screen_init);
            flagModeSetting = false;
            break;
        }
        lv_timer_handler();
        lv_refr_now(NULL);
    }
}

extern bool flagSetting;
extern bool flagModeSetting;
void checkbtnSetting()
{
    if (flagSetting && flagModeSetting)
    {
        _ui_flag_modify(ui_AreaPWHome, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_KeyboardPWHome, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        delay(2000);
        _ui_screen_change(&ui_ScreenSetting, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_ScreenSetting_screen_init);
        flagSetting = false;
        flagModeSetting = false;

    }
}

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

void controlScreen()
{
    unsigned long currentTime = millis();
    bool touched = check_touch(my_indev_driver, my_data);

    if (touched)
    {
        if (!screenIsOn)
        {
            digitalWrite(TFT_BL, TFT_BACKLIGHT_ON);
            screenIsOn = true;
        }
        lastTouchTime = currentTime;
    }
    else
    {
        if (screenIsOn && (currentTime - lastTouchTime >= TIMEOUT))
        {
            digitalWrite(TFT_BL, TFT_BACKLIGHT_OFF);
            _ui_screen_change(&ui_Screen1, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_ScreenSetting_screen_init);
            screenIsOn = false;
        }
    }
}