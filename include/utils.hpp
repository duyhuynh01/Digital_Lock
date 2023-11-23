#include "funcUi.hpp"
#define OPEN_DOOR_TIME 5000
#define CTRL_DOOR_PIN 33

extern void resetOnScreenTimer();
extern bool isTask1Finish;
extern bool isCriticalTask;
extern bool isSettingModeOn;
extern bool doorStatus;


void nonFunction();
void criticalTaskHandler(lv_obj_t *popup, const char *notify, uint32_t timerDuration, int8_t AdminFPID, bool doorStatus);

void updateDoorStatusTimer();