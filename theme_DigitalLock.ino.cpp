# 1 "C:\\Users\\Admin\\AppData\\Local\\Temp\\tmpc6vku28l"
#include <Arduino.h>
# 1 "C:/Users/Admin/Desktop/PROJECT/Repo_main/Smart_Door/src/theme_DigitalLock.ino"



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
void setup();
void loop();
void Log(String log);
int readNumber();
#line 14 "C:/Users/Admin/Desktop/PROJECT/Repo_main/Smart_Door/src/theme_DigitalLock.ino"
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

    eeprom.begin();
    TFT_init();
}

void loop()
{
    lv_timer_handler();
    myFingerPrint.scanFinger();
    delay(5);
# 87 "C:/Users/Admin/Desktop/PROJECT/Repo_main/Smart_Door/src/theme_DigitalLock.ino"
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