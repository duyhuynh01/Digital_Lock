#ifndef FUNCUI_HPP
#define FUNCUI_HPP

#include <Arduino.h>
#include <ui.h>
#include "Password.hpp"
#include "myFingerPrint.hpp"
#include "myEEPROM.hpp"
#define TimeOpenDoor 5000
    void callFuncCheckPW(lv_event_t *e);
    void callFuncAddFP(lv_event_t *e);
    void callFuncDeleteCard(lv_event_t *e);
    void notifyPopup(lv_obj_t *popup, const char *notify, uint32_t timerDuration);
    void showPopup(lv_obj_t *popup, const char *notify, uint32_t timerDuration);
    
    // void hidePopup(lv_obj_t *popup);
    void hidePopupArea(lv_timer_t *timer);
extern const char *PasswordUnlock;



#endif