#include "funcUi.hpp"

extern void resetOnScreenTimer();
extern bool isTask1Finish;
extern bool isCriticalTask;


void nonFunction();
void criticalTaskHandler(lv_obj_t *popup, const char *notify, uint32_t timerDuration);