#ifndef FUNCUI_HPP
#define FUNCUI_HPP

#include <Arduino.h>
#include <ui.h>
#include "Password.hpp"
#include "myFingerPrint.hpp"
#include "myEEPROM.hpp"
#include "myRFID.hpp"
#include "gui.hpp"
#define TimeOpenDoor 5000u
#define TIME_POPUP 5000u
#define TIME_OUT_SETTNG 10000u
#define TIMEOUT 15000u
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
    void callFuncAddCard(lv_event_t *e);
    void callFuncDeleteCard(lv_event_t *e);
    void callFuncShowCard(lv_event_t * e);
    // void hidePopup(lv_obj_t *popup);
    void hidePopupArea(lv_timer_t *timer);
    void isSettingMode(lv_event_t * e);
    void callFuncCheckSetting(lv_event_t *e);
    void checkbtnSetting();
extern const char *PasswordUnlock;



#endif