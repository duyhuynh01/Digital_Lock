#include "historyHandler.hpp"


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

void HistoryHandler::showHistory(){
    Serial.print("Number of history: "); Serial.println(historyBuffer.size());
    for (int i = 0; i<historyBuffer.size(); i++){
        Serial.println(historyBuffer[i]);
    }
}