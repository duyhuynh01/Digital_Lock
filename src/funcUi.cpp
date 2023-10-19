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
        notifyCheckPWHome(ui_AreaPopup, ui_AreaPWHome, "Unlock successfull!", 5000);
    }
    else
    {
        notifyCheckPWHome(ui_AreaPopup, ui_AreaPWHome, "Unlock failed!", 5000);
    }
}

void callFuncAddFP(lv_event_t *e)
{
    // if (myFingerPrint.enroll())
    // {
    //     // lv_textarea_set_text(ui_AreaAddFP, setIdFP);
    //     // _ui_flag_modify(ui_AreaAddFP, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    // }
}

void callFuncDeleteCard(lv_event_t *e)
{
   myFingerPrint.restore();
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

