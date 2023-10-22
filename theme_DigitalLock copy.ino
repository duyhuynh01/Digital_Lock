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
bool screenIsOn = true;
unsigned long lastTouchTime = 0;
const unsigned long screenOffTimeout = 10000; // 10 seconds
void setup()
{
    EEPROM.begin(512);
    Serial.begin(115200);
    if (!myPassword.passwordExists())
    {
        myPassword.createPasswords();
        Serial.println("--Created password!---");
    }
    else
    {
        Serial.println("Created password!");
    }
    myFingerPrint.begin(57600);
    // myRFID.begin();
    // eeprom.begin();
    // TFT_init();
}

void loop()
{
    // controlScreen();

    // unsigned long currentTime = millis();
    // bool touched = check_touch(my_indev_driver, my_data);
    // if (touched)
    // {
    //     if (!screenIsOn)
    //     {
    //         digitalWrite(TFT_BL, TFT_BACKLIGHT_ON);
    //         screenIsOn = true;
    //     }
    //     lastTouchTime = currentTime;
    // }
    // else
    // {
    //     if (screenIsOn && (currentTime - lastTouchTime >= screenOffTimeout))
    //     {
    //         digitalWrite(TFT_BL, TFT_BACKLIGHT_OFF);
    //         screenIsOn = false;
    //     }
    // }

    // myFingerPrint.scanFinger();

    // myRFID.scanRFID();
    int id = 0;
    // run when task = -1
    task = -1;
    // lv_timer_handler();
    delay(5);
    myFingerPrint.scanFinger();
    // myRFID.scanRFID();
    delay(10);

    task = readNumber();
    switch (task)
    {
    case 1:
        myFingerPrint.enrollFingerprint();
        task = -1;
        break;
    case 2:
        // Log("Enter ID of your fingerprint to unenroll: ");
        myFingerPrint.unEnroll("User3");
        task = -1;
        break;
    case 3:
        myFingerPrint.restore();
        task = -1;
        break;
    case 4:
        myFingerPrint.showList();
        task = -1;
        break;
    case 5:
        myFingerPrint.changeFingerprintAdmin();
        task = -1;
        break;
    case 6: 
        Serial.println(myFingerPrint.getFingerprintCount());
        task = -1;
        break;
        // case 4:
        //     Log("Scan your RFID card to add new");
        //     myRFID.addCard();
        //     task = -1;
        //     break;
        // case 5:
        //     Log("Scan your RFID card which you want to remove");
        //     myRFID.removeCard();
        //     task = -1;
        //     break;
        // case 6:
        //     myRFID.printCardList();
        //     task = -1;
        //     break;
        // case 7:
        //     myRFID.restore();
        //     task = -1;
        //     break;
        // case 8:
        //     eeprom.readAll();
        //     task = -1;
        //     break;
    }
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