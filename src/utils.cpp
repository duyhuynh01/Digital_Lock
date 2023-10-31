#include "utils.hpp"


void criticalTaskHandler(lv_obj_t *popup, const char *notify, uint32_t timerDuration)
{
    while (isTask1Finish == false)
    {
        delayMicroseconds(35);
    }
    isCriticalTask = true;
    resetOnScreenTimer();
    showPopup(popup, notify, timerDuration);
    isCriticalTask = false;
}