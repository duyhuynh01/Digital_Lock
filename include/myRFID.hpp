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
class RFID
{
public:
    RFID();
    void begin();
    void scanCard();
    void showList();
    bool enrollCard();
    bool unenrollCard(const char* user);
    bool restore();
    bool saveCard();
    bool readCardFromEEPROM();
    bool deleteCardByName(const char *nameToDelete);
    int8_t findCardByName(const char *name);
    ~RFID();
    
private:
    MFRC522 mfrc522;
    uint8_t cardCount;
};

struct CardData
{
    char id[9];
    char name[8];
};

extern CardData cardRegisteredData[];

#endif  