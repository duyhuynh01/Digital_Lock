// #include <lvgl.h>
// #include <TFT_eSPI.h>
// #include <ui.h>
#include "funcUi.hpp"
#include "Password.hpp"
#include "gui.hpp"
#include "myFingerPrint.hpp"
#include "myRFID.hpp"
FingerPrint myFingerPrint;
RFID myRFID;
Password myPassword;
int8_t task = -1;
lv_indev_drv_t my_indev_driver; // Khai báo và cấu hình biến indev_driver
lv_indev_data_t my_data;        // Khai báo và cấu hình biến data

void setup()
{
    EEPROM.begin(768);
    Serial.begin(115200);
    myFingerPrint.begin(57600);
    myRFID.begin();
    TFT_init();
}

void loop()
{
    controlScreen();
    // int id = 0;
    // run when task = -1
    // task = -1;
    lv_timer_handler();
    delay(5);
    myFingerPrint.scanFinger();
    myRFID.scanCard();
}

void Log(String log)
{
    Serial.println(log);
}

int readNumber()
{
    int num = 0;
    if (Serial.available())
        num = Serial.parseInt();
    return num;
}