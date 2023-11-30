#include "historyHandler.hpp"
#include "ui.h"

HistoryHandler::HistoryHandler()
{
}
HistoryHandler::~HistoryHandler()
{
}
void HistoryHandler::loadHistory()
{
    historyBuffer.clear(); // clear all buffer
    File file = SPIFFS.open("/history.txt", "r");
    if (!file)
    {
        Serial.println("Failed to open history file for reading");
        return;
    }
    while (file.available())
    {
        historyBuffer.push(file.readStringUntil('\n'));
    }
}

void HistoryHandler::logHistory(const String &entry)
{
    historyBuffer.push(entry);
}

void HistoryHandler::saveHistoryToFile()
{
    File file = SPIFFS.open("/history.txt", "w");
    if (!file)
    {
        Serial.println("Failed to open history file for writing");
        return;
    }

    for (int i = 0; i < historyBuffer.size(); ++i)
    {
        file.println(historyBuffer[i]);
    }
    file.close();
}
void HistoryHandler::clearFileInMemory()
{
    // Open the file in write mode to truncate (clear) its content
    File file = SPIFFS.open("/history.txt", "w");
    if (!file)
    {
        Serial.println("Failed to open history file for clearing");
        return;
    }
    file.close();
}

void HistoryHandler::updateHistory(const String &entry)
{
    logHistory(entry);
    clearFileInMemory();
    saveHistoryToFile();
}

// void splitString(const String &input, char delimiter, String &part1, String &part2, String &part3, String &part4)
// {
//     int firstDelimiter = input.indexOf(delimiter);
//     int secondDelimiter = input.indexOf(delimiter, firstDelimiter + 1);
//     int thirdDelimiter = input.indexOf(delimiter, secondDelimiter + 1);

//     part1 = input.substring(0, firstDelimiter);
//     part2 = input.substring(firstDelimiter + 1, secondDelimiter);
//     part3 = input.substring(secondDelimiter + 1, thirdDelimiter);
//     part4 = input.substring(thirdDelimiter + 1);
// }

bool splitString(const String &input, char delimiter, String &part1, String &part2, String &part3, String &part4)
{
    int delimiterCount = 0;
    int startIndex = 0;
    String bufferInput = input;
    bufferInput.replace("\n", "");
    bufferInput.replace("\r", "");

    for (int i = 0; i < bufferInput.length(); i++)
    {
        if (bufferInput.charAt(i) == delimiter)
        {
            delimiterCount++;

            if (delimiterCount == 1)
            {
                part1 = bufferInput.substring(startIndex, i);
                if (part1.charAt(0) == '-')
                {
                    part1 = part1.substring(1);
                }
                startIndex = i + 1;
            }
            else if (delimiterCount == 2)
            {
                part2 = bufferInput.substring(startIndex, i);
                if (part2.charAt(0) == '-')
                {
                    part2 = part2.substring(1);
                }
                startIndex = i + 1;
            }
            else if (delimiterCount == 5)
            {
                part3 = bufferInput.substring(startIndex, i);
                if (part3.charAt(0) == '-')
                {
                    part3 = part3.substring(1);
                }
                startIndex = i;
            }
        }
    }

    // The remaining part is the last segment
    part4 = bufferInput.substring(startIndex);
    if (part4.charAt(0) == '-')
    {
        part4 = part4.substring(1);
    }
    // Serial.print("count buffer: ");
    // Serial.print(bufferInput);
    return true;
}

void draw_part_event_cb(lv_event_t *e)
{
    lv_obj_t *obj = lv_event_get_target(e);
    lv_obj_draw_part_dsc_t *dsc = lv_event_get_draw_part_dsc(e);
    if (dsc->part == LV_PART_ITEMS)
    {
        uint32_t row = dsc->id / lv_table_get_col_cnt(obj);
        uint32_t col = dsc->id - row * lv_table_get_col_cnt(obj);
    }
}

// extern bool flagHistory;
lv_obj_t *table;
bool flagHistory = false;
void HistoryHandler::showHistory()
{
    // Serial.print("Number of history: "); Serial.println(historyBuffer.size());
    // for (int i = 0; i<historyBuffer.size(); i++){
    //     Serial.println(historyBuffer[i]);
    // }

    

    // // Tạo bảng và khởi tạo style
    table = lv_table_create(ui_panelHistory);
    int8_t sizeBuffer = historyBuffer.size();
    String Part1, Part2, Part3, Part4;
    // Thêm các dòng vào bảng
    for (int i = 0; i < sizeBuffer; i++)
    {
        
        if (splitString(historyBuffer[i], '-', Part1, Part2, Part3, Part4))
        {

    //         // if (i < historyBuffer.size())
    //         // {
        // Serial.print(Part1.c_str());Serial.print(";");
        // Serial.print(Part2.c_str());Serial.print(";");
        // Serial.print(Part3.c_str());Serial.print(";");
        // Serial.print(Part4.c_str());Serial.println(";");
            lv_table_set_cell_value(table, i, 0, Part1.c_str());
            lv_table_set_cell_value(table, i, 1, Part2.c_str());
            lv_table_set_cell_value(table, i, 2, Part3.c_str());
            lv_table_set_cell_value(table, i, 3, Part4.c_str());

    //         // Serial.println("-----------");
    //         // Serial.print(Part1.c_str());
    //         // Serial.print(Part2.c_str());
    //         // Serial.print(Part3.c_str());
    // //         // Serial.print(Part4.c_str());
            // lv_table_set_cell_value(table, i, 0, "admin");
            // lv_table_set_cell_value(table, i, 1, "RFID");
            // lv_table_set_cell_value(table, i, 2, "22-11-2001");
            // lv_table_set_cell_value(table, i, 3, "12-45");
    //         // }
    //         // Serial.println(historyBuffer[i]);
        }
    }

    lv_table_set_col_width(table, 0, 60);
    lv_table_set_col_width(table, 1, 50);
    lv_table_set_col_width(table, 2, 80);
    lv_table_set_col_width(table, 3, 60);
    lv_obj_set_style_text_font(table, &lv_font_montserrat_10, LV_PART_MAIN);
    lv_obj_set_style_text_color(table, lv_color_hex(0x000000), LV_PART_MAIN );
    lv_obj_set_style_bg_color(table, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    // lv_obj_set_size(table, 235, 220);
    lv_obj_set_height(table, 230);
    lv_obj_center(table);
    lv_obj_set_y(table, -10);
    lv_obj_add_event_cb(table, draw_part_event_cb, LV_EVENT_DRAW_PART_BEGIN, NULL);
    flagHistory = true;
}
