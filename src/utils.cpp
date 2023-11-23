#include "utils.hpp"

extern unsigned int startOpenDoorTimer;
extern unsigned int endOpenDoorTimer;
bool tooManyInvalid = false;
extern uint8_t invalidCount;
extern uint8_t temp;

void criticalTaskHandler(lv_obj_t *popup, const char *notify, uint32_t timerDuration, int8_t AdminFPID, bool isVerified)
{
    while (isTask1Finish == false)
    {
        delayMicroseconds(35);
    }
    isCriticalTask = true;
    resetOnScreenTimer();
    showPopup(popup, notify, timerDuration);
    if (AdminFPID == 1)
    {
        isSettingModeOn = true;
        _ui_flag_modify(ui_KeyboardPWHome, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_Settingbtn, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        lv_refr_now(NULL);
    }
    //open door
    if (isVerified)
    {
        doorStatus = true;
        startOpenDoorTimer = millis();
        endOpenDoorTimer = startOpenDoorTimer;
    }
    isCriticalTask = false;
}

void updateDoorStatusTimer()
{
    if (doorStatus == true)
    {   
        if ((endOpenDoorTimer - startOpenDoorTimer) < OPEN_DOOR_TIME)
        {
            endOpenDoorTimer = millis();
            digitalWrite(CTRL_DOOR_PIN, HIGH);
            invalidCount = 0;
        }
        else
        {
            while (isCriticalTask == true)
            {
                delayMicroseconds(35);
            }
            doorStatus = false;
        }
    }
    else
    {
        endOpenDoorTimer = 0;
        digitalWrite(CTRL_DOOR_PIN, LOW);
    }
}

void checkInvalidCount(){
    if (invalidCount>=10){
        tooManyInvalid = true;
        const char *mess = "Too many invalid";
        while(temp>0)
        {
            criticalTaskHandler(ui_AreaPopup, mess, 7000, -1, false);
            temp --;
        }

    }
    else{
        tooManyInvalid = false;
        temp = 1;
    }
    Serial.print("So lan sai: "); Serial.println(invalidCount);

}