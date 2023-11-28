#include "funcUi.hpp"
#define OPEN_DOOR_TIME 5000
#define CTRL_DOOR_PIN 33
#define CTRL_VOLUME 25

extern void resetOnScreenTimer();
extern bool isTask1Finish;
extern bool isCriticalTask;
extern bool isSettingModeOn;
extern bool doorStatus;


void nonFunction();
void criticalTaskHandler(lv_obj_t *popup, const char *notify, uint32_t timerDuration, int8_t AdminFPID, bool doorStatus);

void updateDoorStatusTimer();

void checkInvalidCount(); //this function is used to check totally user has raised an invalid auth


String removeSpaces(const String input);

void ctrlVolume();

