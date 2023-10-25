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
    myRFID.begin();
    TFT_init();
    myFingerPrint.readFingerprintFromEEPROM();
    myRFID.readCardFromEEPROM();
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
    delay(10);

//     task = readNumber();
//     switch (task)
//     {
//     case 1:
//         myFingerPrint.enrollFingerprint();
//         task = -1;
//         break;
//     case 2:
//         // Log("Enter ID of your fingerprint to unenroll: ");
//         myFingerPrint.unEnroll("User3");
//         task = -1;
//         break;
//     case 3:
//         myFingerPrint.restore();
//         task = -1;
//         break;
//     case 4:
//         myFingerPrint.showList();
//         task = -1;
//         break;
//     case 5:
//         myFingerPrint.changeFingerprintAdmin();
//         task = -1;
//         break;

//     case 6:
//         Log("Scan your RFID card to add new");
//         myRFID.enrollCard();
//         task = -1;
//         break;
//     case 7:
//         Log("Scan your RFID card which you want to remove");
//         myRFID.unenrollCard("User3");
//         task = -1;
//         break;
//     case 8:
//         myRFID.showList();
//         task = -1;
//         break;
//     case 9:
//         myRFID.restore();
//         task = -1;
//         break;
//     }
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