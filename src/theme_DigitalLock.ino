// #include <lvgl.h>
// #include <TFT_eSPI.h>
// #include <ui.h>
#include "funcUi.hpp"
#include "Password.hpp"
#include "gui.hpp"
#include "myEEPROM.hpp"
#include "myFingerPrint.hpp"
FingerPrint myFingerPrint;
myEEPROM eeprom;
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
    delay(5);
}
