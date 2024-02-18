#include "MyRFID.hpp"
#include "realtime.hpp"
#include "utils.hpp"
#include "historyHandler.hpp"
extern bool doorStatus;
extern SPIClass SPI12;
extern FingerPrint myFingerPrint;
extern bool screenIsOn;
extern unsigned long lastTouchTime;
extern uint8_t invalidCount;
extern HistoryHandler history;
extern realTime realtime;
unsigned int timeReadRFID = 1500;
RFID::RFID() : mfrc522(SS_PIN_HSPI, RST_PIN_HSPI)
{
}

RFID::~RFID() {}
/*-------------Init RFID-------------*/

void RFID::begin()
{
    // SPI.begin(14, 12, 13);
    SPI12.begin(14, 12, 13, 27);
    mfrc522.PCD_Init();
    Serial.println("RFID Started");
    Serial.println(mfrc522.uid.size);
}

void RFID::restore()
{
    File file = SPIFFS.open("/cardlist.txt", "w");
    if (!file)
    {
        Serial.println("Failed to open cardlist file for clearing");
        return;
    }
    LoadCardFromMem();
    file.close();
    Serial.println("Successfully delete all card");
}

void RFID::scanCard()
{
    const char *printName;
    static unsigned long lastScanTime = 0; 

    if (millis() - lastScanTime < timeReadRFID) {
        
        return;
    }
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial())
    {
        lastScanTime = millis();
        String cardUID;
        const char *cardID = NULL;
        for (byte i = 0; i < mfrc522.uid.size; i++)
        {
            cardUID += String(mfrc522.uid.uidByte[i], HEX);
        }
        cardUID.toUpperCase();
        Serial.println(cardUID);
        for (int j = 0; j < cardBuffer.size(); j++)
        {
            if (cardUID == cardBuffer[j].cardUID)
            {
                Serial.print("Hello ");
                Serial.println(cardBuffer[j].name);
                criticalTaskHandler(ui_AreaPopup, "Unlock", 5000, -1, true); //-1 value means do not consider for adminFP to enter setting mode
                String log = removeSpaces(cardBuffer[j].name) + "-" + "RFID" + "-" + realtime.getTimeLog();
                history.updateHistory(log);
                return;
            }
        }
        Serial.println("Invalid Card");
        criticalTaskHandler(ui_AreaPopup, "Unknown", 5000, -1, false); //-1 value means do not consider for adminFP to enter setting mode
        invalidCount += 1;
    }
    mfrc522.PICC_HaltA();
}

int8_t RFID::getID()
{
    int8_t dataSize = cardBuffer.size();
    int8_t id = -1;
    for (int8_t i = 1; i <= CARD_COUNT; i++)
    {
        bool found = (std::find_if(cardBuffer.begin(), cardBuffer.end(),
                                   [i](const cardDataType &data)
                                   { return data.id == i; }) != cardBuffer.end());
        if (!found)
        {
            id = i;
            return (id <= CARD_COUNT) ? id : -1;
        }
    }
    return -1;
}
bool RFID::enrollCard()
{
    int8_t id = getID();
    if (id == -1)
    {
        Serial.println("Card list is full");
        lv_textarea_set_text(ui_areaPopupCard, "Card list is full.");
        _ui_screen_change(&ui_SceenCard, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_SceenFinger_screen_init);
        lv_refr_now(NULL);
        return false;
    }
    unsigned long startTime = millis();
    bool cardDetected = false;
    _ui_flag_modify(ui_areaPopupCard, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    lv_textarea_set_text(ui_areaPopupCard, "Place card on sensor");
    lv_refr_now(NULL);
    unsigned long timeStamp = 0;
    esp_task_wdt_init(10, true); // Set watchdog timeout to 10 seconds
    while (timeStamp <= cardTimeout)
    {
        resetOnScreenTimer();
        timeStamp = millis() - startTime;
        if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial())
        {
            cardDetected = true;
            break;
        }
    }
    if (cardDetected)
    {
        String cardUID = "";
        for (byte i = 0; i < mfrc522.uid.size; i++)
        {
            cardUID += String(mfrc522.uid.uidByte[i], HEX);
        }
        cardUID.toUpperCase();
        mfrc522.PICC_HaltA();
        Serial.print("Add new card ");
        Serial.print(cardUID);
        Serial.print(":");
        Serial.print(id);
        Serial.print(":");
        String tempName = "user" + String(id);
        Serial.println(tempName);
        storeCardToBuffer(id, cardUID, tempName);
        const char *notify = "Successful";
        showPopup(ui_areaPopupCard, notify, TIME_POPUP);
        Serial.println("Successfully add new card");
        // store to memory
        storeCardToMem();
        LoadCardFromMem();
    }
    else
    {
        Serial.println("No card detected!");
        showPopup(ui_areaPopupCard, "No card detected!", TIME_POPUP);
        return false;
    }
    return true;
}
bool RFID::storeCardToBuffer(int8_t id, String cardUID, String name)
{
    cardDataType newCard;
    newCard.id = id;
    newCard.cardUID = cardUID;
    newCard.name = name;
    cardBuffer.push_back(newCard);
    return true;
}
void RFID::storeCardToMem()
{
    File file = SPIFFS.open("/cardlist.txt", "w");
    if (!file)
    {
        Serial.println("Failed to open cardlist file for writing");
        return;
    }
    for (int i = 0; i < cardBuffer.size(); ++i)
    {
        file.print(cardBuffer[i].id);
        file.print("-");
        file.print(cardBuffer[i].cardUID);
        file.print("-");
        file.println(cardBuffer[i].name);
    }
    file.close();
}
bool compareById(const cardDataType &a, const cardDataType &b)
{
    return a.id < b.id;
}
void RFID::LoadCardFromMem()
{
    cardBuffer.clear(); // clear all buffer
    File file = SPIFFS.open("/cardlist.txt", "r");
    if (!file)
    {
        Serial.println("Failed to open cardlist file for reading");
        return;
    }
    while (file.available())
    {
        cardDataType card;
        String line = file.readStringUntil('\n');
        int hyphenPos = line.indexOf('-');
        // Extract the ID part
        String idStr = line.substring(0, hyphenPos);
        card.id = idStr.toInt();
        int hyphenPos2 = line.indexOf('-', hyphenPos + 1);
        String tempUID = line.substring(hyphenPos + 1, hyphenPos2);
        String tempName = line.substring(hyphenPos2 + 1);
        for (char c : tempUID)
        {
            if (!isspace(c))
            {
                card.cardUID += c;
            }
        }
        for (char c : tempName)
        {
            if (!isspace(c))
            {
                card.name += c;
            }
        }
        // Serial.println(card.id);
        // Serial.println(card.cardUID);
        // Serial.println(card.name);
        cardBuffer.push_back(card);
    }
    // sort
    std::sort(cardBuffer.begin(), cardBuffer.end(), compareById);
}
/*--------------------Delete card--------------------*/
void RFID::unenrollCard(String DelID)
{
    if (cardBuffer.size() <= 0)
    {
        Serial.println("Card list is empty");
    }
    if (DelID == "")
    {
        unsigned long startTime = millis();
        while (millis() - startTime <= cardTimeout)
        {
            showPopup(ui_areaNotyfyDeleteCard, "Place card on sensor", 5000);
            if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial())
            {
                String cardUID;
                const char *cardID = NULL;
                for (byte i = 0; i < mfrc522.uid.size; i++)
                {
                    cardUID += String(mfrc522.uid.uidByte[i], HEX);
                }
                cardUID.toUpperCase();
                Serial.println(cardUID);
                for (int i = 0; i < cardBuffer.size(); i++)
                {
                    if (cardUID == cardBuffer[i].cardUID)
                    {
                        String notify = "Deleted " + cardBuffer[i].name + "'s card";
                        cardBuffer.erase(std::remove_if(cardBuffer.begin(), cardBuffer.end(),
                                                        [cardUID](const cardDataType &data)
                                                        { return data.cardUID == cardUID; }),
                                         cardBuffer.end());
                        Serial.println(notify);
                        showPopup(ui_areaNotyfyDeleteCard, notify.c_str(), TIME_POPUP);
                        return;
                    }
                }
                showPopup(ui_areaNotyfyDeleteCard, "Not found", TIME_POPUP);
                Serial.println("not found");
                return;
            }
        }
        showPopup(ui_areaNotyfyDeleteCard, "Not found", TIME_POPUP);
        Serial.println("not found");
    }
    else
    {
        int8_t ID = std::stoi(DelID.c_str());
        for (int j = 0; j < cardBuffer.size(); j++)
        {
            if (ID == cardBuffer[j].id)
            {
                String notify = "Deleted " + cardBuffer[j].name + "'s card";
                cardBuffer.erase(std::remove_if(cardBuffer.begin(), cardBuffer.end(),
                                                [ID](const cardDataType &data)
                                                { return data.id == ID; }),
                                 cardBuffer.end());
                showPopup(ui_areaNotyfyDeleteCard, notify.c_str(), TIME_POPUP);
                Serial.println(notify);
                return;
            }
        }
        showPopup(ui_areaNotyfyDeleteCard, "Not found", TIME_POPUP);
        Serial.println("not found");
        return;
    }
}
void draw_part_event_RFID(lv_event_t *e)
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
lv_obj_t *tableRFID;
bool flagShowRFID = false;
void RFID::showList()
{
    tableRFID = lv_table_create(ui_panelShowCard);
    int8_t countRFID = 0;
    for (int i = 0; i < cardBuffer.size(); i++)
    {
        lv_table_set_cell_value(tableRFID, countRFID, 0, String(cardBuffer[i].id).c_str());
        lv_table_set_cell_value(tableRFID, countRFID, 1, cardBuffer[i].name.c_str());
        countRFID++;
    }
    lv_obj_set_style_text_font(tableRFID, &lv_font_montserrat_10, LV_PART_MAIN);
    lv_obj_set_style_text_color(tableRFID, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_set_style_bg_color(tableRFID, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_set_style_text_align(tableRFID, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(tableRFID, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    // lv_obj_set_size(table, 235, 220);
    lv_obj_set_height(tableRFID, 230);
    lv_obj_center(tableRFID);
    lv_obj_set_y(tableRFID, -10);
    lv_obj_add_event_cb(tableRFID, draw_part_event_RFID, LV_EVENT_DRAW_PART_BEGIN, NULL);
    flagShowRFID = true;
}