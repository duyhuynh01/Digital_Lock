// #include <lvgl.h>
// #include <TFT_eSPI.h>
// #include <ui.h>
#include "funcUi.hpp"
#include "Password.hpp"
#include "gui.hpp"
#include "myEEPROM.hpp"
#include "myFingerPrint.hpp"
#include "myRFID.hpp"
FingerPrint myFingerPrint;
myEEPROM eeprom;
RFID myRFID;
int8_t task = -1;
void setup()
{
    Serial.begin(115200);
    if (!passwordExists())
    {
        createPasswords();
        Serial.println("--Created password!---");
    }
    else
    {
        Serial.println("Created password!");
    }
    myFingerPrint.begin(57600);
  // myRFID.begin();
    eeprom.begin();
    TFT_init();
}

void loop()
{
    lv_timer_handler(); 
    myFingerPrint.scanFinger();
    delay(5);
    // int id = 0;
    //run when task = -1
    // myFingerPrint.scanFinger();
    // myRFID.scanRFID();
    // delay(10);

    // task = readNumber();
    // switch (task)
    // {
    // case 1: 
    //     myFingerPrint.enroll();
    //     task = -1;
    //     break;
    // case 2: 
    //     Log("Enter ID of your fingerprint to unenroll: ");
    //     while(id == 0){
    //     id = readNumber();
    //     }
    //     myFingerPrint.unEnroll(id);
    //     task = -1;
    //     break;
    // case 3:
    //     myFingerPrint.restore();
    //     task = -1;
    //     break;
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
    // }
    

}

void Log(String log){
  Serial.println(log);
}

int readNumber()
{
    int num = 0;
    if (Serial.available())
        num = Serial.parseInt();
    return num;
}