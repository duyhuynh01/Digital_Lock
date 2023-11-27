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
void HistoryHandler::showHistory(){
    Serial.print("Number of history: "); 
    Serial.println(historyBuffer.size());
    String part1, part2, part3, part4;
    splitString(historyBuffer[HISTORY_LENGTH], '-', part1, part2, part3, part4);
    int8_t sizeBuffer = historyBuffer.size();
    lv_obj_t * table = lv_table_create(lv_scr_act());
    for (int i = historyBuffer.size() - 1; i >= 0; i--){
        lv_table_set_cell_value(table, i, 0, "Name");
        Serial.println(historyBuffer[i]);
    }
}