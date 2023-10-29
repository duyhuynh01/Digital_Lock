#include "gui.hpp"


TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight);
/* Display flushing */
void my_disp_flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p )
{
    uint32_t w = ( area->x2 - area->x1 + 1 );
    uint32_t h = ( area->y2 - area->y1 + 1 );

    tft.startWrite();
    tft.setAddrWindow( area->x1, area->y1, w, h );
    tft.pushColors( ( uint16_t * )&color_p->full, w * h, true );
    tft.endWrite();

    lv_disp_flush_ready( disp );
}

/*Read the touchpad*/
void my_touchpad_read( lv_indev_drv_t * indev_driver, lv_indev_data_t * data )
{
    uint16_t touchX = 0, touchY = 0;

    bool touched = tft.getTouch( &touchX, &touchY, 600 );

    if( !touched )
    {
        data->state = LV_INDEV_STATE_REL;
    }
    else
    {
        data->state = LV_INDEV_STATE_PR;

        /*Set the coordinates*/
        data->point.x = touchX;
        data->point.y = touchY;

        // Serial.print( "Data x " );
        // Serial.println( touchX );

        // Serial.print( "Data y " );
        // Serial.println( touchY );
    }
}
// bool check_touch(lv_indev_drv_t &indev_driver, lv_indev_data_t &data) {
//     uint16_t touchX = 0, touchY = 0;

//     bool touched = tft.getTouch(&touchX, &touchY, 600);

//     if (!touched) {
//         return false;
//     } else {

//         return true;
//     }
// }

bool check_touch(lv_indev_drv_t &indev_driver, lv_indev_data_t &data) {
    uint16_t touchX = 0, touchY = 0;

    bool touched = tft.getTouch(&touchX, &touchY, 600);

    if (!touched) {
        return false;
    } else {
        data.point.x = touchX;
        data.point.y = touchY;
        return true;
    }
}
void turnLCD()
{
    // screenIsOn = true;
    lastTouchTime = millis();
    // digitalWrite(TFT_BL, TFT_BACKLIGHT_ON);
}

void TFT_init()
{
    lv_init();

    tft.begin();          /* TFT init */
        
tft.setRotation( 0 ); /* Landscape orientation, flipped */
    uint16_t calData[5] = {429, 3210, 325, 3281, 2};
    // uint16_t calData[15];
    tft.setTouch(calData);
    // tft.calibrateTouch(calData, TFT_MAGENTA, TFT_BLACK, 15);
   
    lv_disp_draw_buf_init( &draw_buf, buf, NULL, screenWidth * screenHeight / 10 );

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init( &disp_drv );
    /*Change the following line to your display resolution*/
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register( &disp_drv );

    /*Initialize the (dummy) input device driver*/
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init( &indev_drv );
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touchpad_read;
    lv_indev_drv_register( &indev_drv );


    ui_init();

    Serial.println( "Setup done" );
        }