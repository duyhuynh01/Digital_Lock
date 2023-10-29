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

bool isTask1Finish = false;
bool isCriticalTask = false;

TaskHandle_t Task1;
TaskHandle_t Task2;
void Task1Code(void *pvParameters);
void Task2Code(void *pvParameters);

void setup()
{
    EEPROM.begin(768);
    Serial.begin(115200);
    myFingerPrint.begin(57600);
    myRFID.begin();
    myPassword.begin();
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
                        0,          /* Priority of the task*/
                        &Task2,     /* Task handler to keep track created task*/
                        1);         /* Pin task to core 0*/

    delay(500);
}

void Task1Code(void * pvParameters){
    for(;;){
        isTask1Finish = false;
        while(isCriticalTask == true){
            // Serial.print("isCriticalTask: ");
            Serial.println(isCriticalTask);
            
        }
        // Serial.println("Task 1 running");
        lv_timer_handler();
        isTouch();
        controlScreen();
        isTask1Finish = true;
        delay(10);

    }

}
void Task2Code(void * pvParameters){
    for(;;){
    // myFingerPrint.scanFinger();
    myRFID.scanCard();
    checkbtnSetting();
    }
}

void loop()
{
    // controlScreen();
    // lv_timer_handler();
    // delay(5);
    // myFingerPrint.scanFinger();
    // myRFID.scanCard();
    // checkbtnSetting();
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