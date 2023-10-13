#include "funcUi.hpp"
#include "myFingerPrint.hpp"
#include "myEEPROM.hpp"

extern FingerPrint myFingerPrint;
extern myEEPROM eeprom;

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
    size_char = strlen(adminPassword);
    Serial.println(adminPassword);
    Serial.println(size_char);

    if (checkPasswordUnlock() == true)
    {
        notifyCheckPWHome(ui_AreaPopup, ui_AreaPWHome, "Unlock successfull!", 5000);
    }
    else
    {
        notifyCheckPWHome(ui_AreaPopup, ui_AreaPWHome, "Unlock failed!", 5000);
    }
}

// void hidePopupCallback(lv_timer_t *timer)
// {
//     _ui_flag_modify(ui_AreaPopup, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
//     lv_timer_del(timer);
// }

// void callFuncCheckPW(lv_event_t *e)
// {
//     unsigned long startTimeNotify;
//     unsigned long currentTime;
//     const char *notify;
//     PasswordUnlock = lv_textarea_get_text(ui_AreaPWHome);
//     Serial.println(PasswordUnlock);
//     uint8_t size_char;
//     size_char = strlen(PasswordUnlock);
//     Serial.println(size_char);
//     size_char = strlen(adminPassword);
//     Serial.println(adminPassword);
//     Serial.println(size_char);

//     if (checkPasswordUnlock() == true)
//     {
//         notify = "Unlock successfull!";

//         Serial.println("Open");
//     }
//     else
//     {
//         notify = "Unlock failed!";

//         // const char *notifyFailed;
//         // notifyFailed = "Unlock failed!";
//         // lv_textarea_set_text(ui_AreaPopup, notifyFailed);
//         // _ui_flag_modify(ui_AreaPopup, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
//         // delay(5000);
//         // _ui_flag_modify(ui_AreaPopup, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);

//         // lv_textarea_set_text(ui_AreaPopup, notify);

//         // _ui_flag_modify(ui_AreaPopup, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);

//         // _ui_flag_modify(ui_AreaPopup, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);

//         Serial.println("failed");
//     }

//     // notifySuccessfull = "Unlock successfull!";
//     // lv_textarea_set_text(ui_AreaPopup, notify);
//     // signed long startTimeNotify = millis();
//     // while (startTimeNotify < 5000)
//     //     ;
//     // _ui_flag_modify(ui_AreaPopup, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
//     lv_textarea_set_text(ui_AreaPopup, notify);
//     Serial.println(notify);
//     _ui_flag_modify(ui_AreaPopup, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
//     hidePopupTimer = lv_timer_create(hidePopupCallback, 5000, NULL);

//     lv_textarea_set_text(ui_AreaPWHome, "");
// }

void callFuncAddFP(lv_event_t *e)
{
    if (myFingerPrint.enroll())
    {
        // lv_textarea_set_text(ui_AreaAddFP, setIdFP);
        // _ui_flag_modify(ui_AreaAddFP, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
}

void callFuncDeleteCard(lv_event_t *e)
{
    if (myFingerPrint.restore())
    {
    }
}



/*---------Function support-----------*/
void notifyCheckPWHome(lv_obj_t *popup, lv_obj_t *resetAreatext, const char *notify, uint32_t timerDuration) {
    // Cập nhật nội dung và hiển thị ui_AreaPopup
    lv_textarea_set_text(popup, notify);
    _ui_flag_modify(popup, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);

    // Xóa hẹn giờ cũ (nếu có)
    if (hidePopupTimer) {
        lv_timer_del(hidePopupTimer);
    }

    // Tạo hoặc đặt lại hẹn giờ hidePopupTimer với thời gian mới
    hidePopupTimer = lv_timer_create(hidePopupAreaHome, timerDuration, NULL);

    // Xóa nội dung của ui_AreaPWHome
    lv_textarea_set_text(resetAreatext, "");
}
