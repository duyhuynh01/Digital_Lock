#ifndef MYRFID_HPP
#define MYRFID_HPP

#define SS_PIN_HSPI 27
#define RST_PIN_HSPI 26
#define SCK_PIN_HSPI 14
#define cardTimeout 7000u
#define CARD_COUNT 20
#define CARD_START_ADDRESS 300 
#define CARD_END_ADDRESS 639

#include <Arduino.h>
#include <MFRC522.h>
#include <SPI.h>
#include <EEPROM.h>
#include "myFingerPrint.hpp"
#include "gui.hpp"
#include "utils.hpp"
#include "vector"
#include <FS.h>
#include <SPIFFS.h>
#include <string>
#include <algorithm>
#include "esp_task_wdt.h" 

using namespace fs;


struct CardData
{
    char id[9];
    char name[8];
};

struct cardDataType
{
    int8_t id;
    String cardUID;
    String name;
};
class RFID
{
public:
    RFID();
    void begin();
    void scanCard();
    void showList();
    int8_t getID();
    bool enrollCard();
    bool storeCardToBuffer(int8_t id,String cardUID,String name);
    void storeCardToMem();
    void LoadCardFromMem();
    void unenrollCard(String DelID);
    void restore();
    bool saveCard();
    bool readCardFromEEPROM();
    bool deleteCardByName(const char *nameToDelete);
    ~RFID();
    
private:
    MFRC522 mfrc522;
    uint8_t cardCount;
    std::vector<cardDataType> cardBuffer;
};


extern CardData cardRegisteredData[];

#endif  