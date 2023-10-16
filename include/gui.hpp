#ifndef GUI_HPP
#define GUI_HPP
#include <ui.h>
#include <TFT_eSPI.h>

static const uint16_t screenWidth  = 240;
static const uint16_t screenHeight = 320;
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[ screenWidth * screenHeight / 10 ];
extern TFT_eSPI tft;
// TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight); /* TFT instance */
void my_disp_flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p );
void my_touchpad_read( lv_indev_drv_t * indev_driver, lv_indev_data_t * data );
void TFT_init();
bool check_touch(lv_indev_drv_t &indev_driver, lv_indev_data_t &data);
void controlScreen();
extern lv_indev_drv_t my_indev_driver; // Khai báo và cấu hình biến indev_driver
extern lv_indev_data_t my_data;        // Khai báo và cấu hình biến data
extern bool screenIsOn;
extern unsigned long lastTouchTime;
extern const unsigned long screenOffTimeout; // 10 seconds


#endif