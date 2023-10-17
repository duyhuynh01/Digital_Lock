// #include <lvgl.h>
// #include <TFT_eSPI.h>
// #include <ui.h>
#include "funcUi.hpp"
#include "Password.hpp"
#include "gui.hpp"
#include "myEEPROM.hpp"
#include "myFingerPrint.hpp"
#include "myRFID.hpp"
TaskHandle_t Task1;
TaskHandle_t Task2;
void Task1Code(void *pvParameters);
void Task2Code(void *pvParameters);
FingerPrint myFingerPrint;
myEEPROM eeprom;
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
    eeprom.begin();
    TFT_init();
    xTaskCreatePinnedToCore(
                    Task1Code,  /* Task function*/
                    "Task1",    /* Task name */
                    10000,      /* Stack size of task*/
                    NULL,       /* Parameter of the task*/
                    1,          /* Priority of the task*/
                    &Task1,     /* Task handler to keep track created task*/
                    0);         /* Pin task to core 0*/

    delay(500);
    xTaskCreatePinnedToCore(
                        Task2Code,  /* Task function*/
                        "Task2",    /* Task name */
                        10000,      /* Stack size of task*/
                        NULL,       /* Parameter of the task*/
                        1,          /* Priority of the task*/
                        &Task2,     /* Task handler to keep track created task*/
                        1);         /* Pin task to core 0*/

    delay(500);
}
void Task1Code(void * pvParameters){
    for(;;){
        myFingerPrint.scanFinger();
        myRFID.scanRFID();
        controlScreen();
        delay(50);
        //Serial.println("Task 1 running");
    }
 
}
void Task2Code(void * pvParameters){
    for(;;){
        lv_timer_handler();
        delay(5);
        //Serial.println("Task 2 running");
    }
}

void loop()
{
    vTaskDelete(NULL);
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