#include "utils.hpp"

extern unsigned int startOpenDoorTimer;
extern unsigned int endOpenDoorTimer;
bool tooManyInvalid = false;
extern uint8_t invalidCount;
extern uint8_t temp;
extern uint16_t volumeTime;
extern uint16_t startVolumeTimer;
extern uint16_t endVolumeTimer;
extern bool openDoorByButton;
// extern HistoryHandler history;
String removeSpaces(const String input)
{
    String result = "";
    for (int i = 0; i < input.length(); i++)
    {
        if (!isspace(input[i]))
        {
            result += input[i];
        }
    }
    return result;
}

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
        hideKeyboard(ui_KeyboardPWHome, 5000);
        showPopupBtnSetting(ui_Settingbtn, 5000);
        lv_refr_now(NULL);
    }
    // open door
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
            volumeStart = false;
            volumeTime = 0;
            invalidCount = 0;
        }
        else
        {
            while (isCriticalTask == true)
            {
                delayMicroseconds(35);
            }
            doorStatus = false;
            // openDoorByButton = false;
        }
    }
    else
    {
        endOpenDoorTimer = 0;
        digitalWrite(CTRL_DOOR_PIN, LOW);
    }
}

void checkInvalidCount()
{
    if (invalidCount >= 10)
    {
        tooManyInvalid = true;
        const char *mess = "Too many invalid";
        volumeTime = 10000;
        volumeStart = true;
        while (temp > 0)
        {
            criticalTaskHandler(ui_AreaPopup, mess, 7000, -1, false);
            temp--;
        }   
    }
    else
    {
        tooManyInvalid = false;
        temp = 1;
    }
    // Serial.print("So lan sai: "); Serial.println(invalidCount);
}
void volumeIsUsed()
{
    if (volumeStart)
    {
        startVolumeTimer = millis();
        volumeStart = false;
    }
}
void ctrlVolumeTimer()
{
    if (endVolumeTimer - startVolumeTimer < volumeTime)
    {
        digitalWrite(CTRL_VOLUME, HIGH);
        endVolumeTimer = millis();
    }
    else
    {
        while (isCriticalTask == true)
        {
            delayMicroseconds(35);
        }
        volumeTime = 0;
        digitalWrite(CTRL_VOLUME, LOW);
        startVolumeTimer = 0;
        endVolumeTimer = 0;
    }
}

void ctrlVolume()
{
    volumeIsUsed();
    ctrlVolumeTimer();
}
