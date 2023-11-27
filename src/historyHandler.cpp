#include "historyHandler.hpp"
#include "ui.h"

HistoryHandler::HistoryHandler(){

}
HistoryHandler::~HistoryHandler(){

}
void HistoryHandler::loadHistory(){
    historyBuffer.clear(); //clear all buffer
    File file = SPIFFS.open("/history.txt", "r");
    if (!file) {
        Serial.println("Failed to open history file for reading");
        return;
    }
    while (file.available()) {
        historyBuffer.push(file.readStringUntil('\n'));
    }
}

void HistoryHandler::logHistory(const String& entry) {
    historyBuffer.push(entry);
}

void HistoryHandler::saveHistoryToFile() {
    File file = SPIFFS.open("/history.txt", "w");
    if (!file) {
        Serial.println("Failed to open history file for writing");
        return;
    }

    for (int i = 0; i < historyBuffer.size(); ++i) {
        file.println(historyBuffer[i]);
    }
    file.close();
}
void HistoryHandler::clearFileInMemory(){
    // Open the file in write mode to truncate (clear) its content
    File file = SPIFFS.open("/history.txt", "w");
    if (!file) {
        Serial.println("Failed to open history file for clearing");
        return;
    }
    file.close();
}

void HistoryHandler::updateHistory(const String& entry){
    logHistory(entry);
    clearFileInMemory();
    saveHistoryToFile();
}

void splitString(const String& input, char delimiter, String& part1, String& part2, String& part3, String& part4) {
    int firstDelimiter = input.indexOf(delimiter);
    int secondDelimiter = input.indexOf(delimiter, firstDelimiter + 1);
    int thirdDelimiter = input.indexOf(delimiter, secondDelimiter + 1);

    part1 = input.substring(0, firstDelimiter);
    part2 = input.substring(firstDelimiter + 1, secondDelimiter);
    part3 = input.substring(secondDelimiter + 1, thirdDelimiter);
    part4 = input.substring(thirdDelimiter + 1);
}

static void draw_part_event_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    lv_obj_draw_part_dsc_t * dsc = lv_event_get_draw_part_dsc(e);
    

}
void HistoryHandler::showHistory(){
    Serial.print("Number of history: "); 
    Serial.println(historyBuffer.size());
    String part1, part2, part3, part4;
    int8_t sizeBuffer = historyBuffer.size();
    lv_obj_t * table = lv_table_create(lv_scr_act());
    lv_style_t style_table;
    lv_style_init(&style_table);
    lv_style_set_bg_color(&style_table, lv_color_black());  // Màu nền đen
    lv_style_set_text_color(&style_table, lv_color_white()); // Màu chữ trắng
    lv_obj_add_style(table, &style_table, LV_PART_MAIN);
    for (int i = 0; i<historyBuffer.size(); i++) 
    {
        splitString(historyBuffer[i], '-', part1, part2, part3, part4);
        lv_table_set_cell_value(table, i, 0, part1.c_str());
        lv_table_set_cell_value(table, i, 1, part2.c_str());
        lv_table_set_cell_value(table, i, 2, part3.c_str());
        lv_table_set_cell_value(table, i, 3, part4.c_str());
        Serial.println(historyBuffer[i]);
    }
    lv_obj_set_height(table, 200);
    lv_obj_center(table);
    lv_obj_add_event_cb(table, draw_part_event_cb, LV_EVENT_DRAW_PART_BEGIN, NULL);
}