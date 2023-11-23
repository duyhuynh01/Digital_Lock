#include "utils.hpp"

extern unsigned int startOpenDoorTimer;
extern unsigned int endOpenDoorTimer;

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
    }
    isCriticalTask = false;
}

void updateDoorStatusTimer()
{
    if (doorStatus == true)
    {   
        endOpenDoorTimer = startOpenDoorTimer;
        if ((endOpenDoorTimer - startOpenDoorTimer) < OPEN_DOOR_TIME)
        {
            endOpenDoorTimer += millis();
            digitalWrite(CTRL_DOOR_PIN, HIGH);
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