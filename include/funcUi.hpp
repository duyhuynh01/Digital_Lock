#ifndef FUNCUI_HPP
#define FUNCUI_HPP

#include <Arduino.h>
#include <ui.h>
#include "Password.hpp"
#include "myFingerPrint.hpp"
#include "myEEPROM.hpp"
#define TimeOpenDoor 5000u
#define TIME_POPUP 5000u
    void callFuncCheckPW(lv_event_t *e);
    void callFuncAddFP(lv_event_t *e);
    void callFuncDeleteFP(lv_event_t * e);
    void callFuncDeleteCard(lv_event_t *e);
    void callFuncShowFP(lv_event_t * e);
    // void notifyPopup(lv_obj_t *popup, const char *notify, uint32_t timerDuration);
    void showPopup(lv_obj_t *popup, const char *notify, uint32_t timerDuration);
    const char *createNotification(const char *mess, const char *name);
    void convertNum(lv_obj_t *textarea, uint16_t value);
    void callFuncRestoreFP(lv_event_t * e);
    
    // void hidePopup(lv_obj_t *popup);
    void hidePopupArea(lv_timer_t *timer);
extern const char *PasswordUnlock;



#endif