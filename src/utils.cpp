#include "utils.hpp"

void nonFunction(){
    int a = 1;
    a++;
}

void criticalTaskHandler(lv_obj_t *popup, const char *notify, uint32_t timerDuration)
{
    while (isTask1Finish == false)
    {
        nonFunction(); // do some fake behaviour
    }
    isCriticalTask = true;
    resetOnScreenTimer();
    showPopup(popup, notify, timerDuration);
    isCriticalTask = false;
}