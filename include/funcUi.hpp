#ifndef FUNCUI_HPP
#define FUNCUI_HPP
#include <Arduino.h>
#include <ui.h>
#include "Password.hpp"
#define TimeOpenDoor 5000
void callFuncCheckPW(lv_event_t *e);
void callFuncDeleteCard(lv_event_t * e);
void notifyCheckPWHome(lv_obj_t *popup, lv_obj_t *resetAreatext, const char *notify, uint32_t timerDuration);
extern const char *PasswordUnlock;


#endif