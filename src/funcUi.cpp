#include "funcUi.hpp"

extern FingerPrint myFingerPrint;
extern myEEPROM eeprom;
extern Password myPassword;
extern const char *setIdFP;
const char *PasswordUnlock = "";
lv_timer_t *hidePopupTimer;
void hidePopupAreaHome(lv_timer_t *timer)
{
    _ui_flag_modify(ui_AreaPopup, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
}


void callFuncCheckPW(lv_event_t *e)
{

    PasswordUnlock = lv_textarea_get_text(ui_AreaPWHome);
    Serial.println(PasswordUnlock);
    uint8_t size_char;
    size_char = strlen(PasswordUnlock);
    Serial.println(size_char);
    size_char = strlen(myPassword.getAdminPassword());
    Serial.println(myPassword.getAdminPassword());
    Serial.println(size_char);

    if (myPassword.checkAdminPassword() == true)
    {
        showPopup(ui_AreaPopup, "Unlock successfull!", TIME_POPUP);
    }
    else
    {
        showPopup(ui_AreaPopup, "Unlock failed!", TIME_POPUP);
    }
    lv_textarea_set_text(ui_AreaPWHome, "");
}

void callFuncAddFP(lv_event_t *e)
{
    // _ui_flag_modify(ui_areaNotyfyAddFP, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    myFingerPrint.enrollFingerprint();
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
    lv_refr_now(NULL);
}

void callFuncShowFP(lv_event_t * e)
{
    myFingerPrint.showList();
}

void callFuncRestoreFP(lv_event_t * e)
{
    myFingerPrint.restore();
    showPopup(ui_areaPopupFP, "Reset the fingerprint successfully.", TIME_POPUP);
    
}


void callFuncDeleteCard(lv_event_t *e)
{
    // myFingerPrint.restore();
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

const char *createNotification(const char *mess, const char *name) {
    char *buffer = new char[strlen(mess) + strlen(name) + 1];
    strcpy(buffer, mess);
    strcat(buffer, name);
    return buffer;
}

void convertNum(lv_obj_t *textarea, uint16_t value) {
    char buffer[5]; 
    snprintf(buffer, sizeof(buffer), "%d", value);
    lv_textarea_add_text(textarea, buffer);
}

