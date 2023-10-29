#include "MyRFID.hpp"
extern bool doorStatus;
extern SPIClass SPI12;
extern FingerPrint myFingerPrint;
extern bool screenIsOn;
extern unsigned long lastTouchTime;
extern void turnLCD();
extern bool isTask1Finish;
extern bool isCriticalTask;
CardData cardRegisteredData[CARD_COUNT];
int8_t nextCardId;
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
    readCardFromEEPROM();
}

bool RFID::restore()
{
    for (int i = 0; i < CARD_COUNT; i++)
    {
        strcpy(cardRegisteredData[i].id, "xxx");
        strcpy(cardRegisteredData[i].name, "zzz");
    }
    for (int i = CARD_START_ADDRESS; i < CARD_END_ADDRESS; i += sizeof(CardData))
    {
        CardData emptyCard;
        strcpy(emptyCard.id, "xxx");
        strcpy(emptyCard.name, "zzz");
        EEPROM.put(i, emptyCard);
    }
    cardCount = 0;
    EEPROM.commit();
    Serial.println("Restored!");
    Serial.println(cardRegisteredData[19].id);
    Serial.println(cardRegisteredData[19].name);
    return true;
}

/*----------------------Save Card-----------------*/
bool RFID::saveCard()
{
    for (int i = CARD_START_ADDRESS; i <= CARD_END_ADDRESS; i += sizeof(CardData))
    {
        uint8_t index = (i - CARD_START_ADDRESS) / sizeof(CardData);
        if (index < cardCount)
        {
            EEPROM.put(i, cardRegisteredData[index]);
        }
        else
        {
            CardData emptyCard;
            strcpy(emptyCard.id, "xxx");
            strcpy(emptyCard.name, "zzz");
            EEPROM.put(i, emptyCard);
        }
    }
    EEPROM.commit();
    return true;
}

/*-----------------Read card from EEPROM------------*/

bool RFID::readCardFromEEPROM()
{
    uint8_t countList = 0;
    cardCount = 0;
    for (int i = CARD_START_ADDRESS; i < CARD_END_ADDRESS; i += sizeof(CardData))
    {
        EEPROM.get(i, cardRegisteredData[countList]);
        countList++;
    }
    for (int i = 0; i < CARD_COUNT; i++)
    {
        if (strcmp(cardRegisteredData[i].id, "xxx") != 0 && strcmp(cardRegisteredData[i].id, "yyy") != 0)
        {
            cardCount++;
        }
    }
    Serial.print("Card count: ");
    Serial.println(cardCount);
    return true;
}

/*----------------Check card is existed------------*/
void RFID::scanCard()
{
    const char *printName;
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial())
    {
        String cardUID = "";
        const char *cardID = NULL;

        for (byte i = 0; i < mfrc522.uid.size; i++)
        {
            cardUID += String(mfrc522.uid.uidByte[i], HEX);
        }
        cardUID.toUpperCase();
        cardID = cardUID.c_str();

        bool validCard = false;

        for (int i = 0; i < cardCount; i++)
        {
            if (strcmp(cardRegisteredData[i].id, cardID) == 0)
            {
                validCard = true;
                printName = cardRegisteredData[i].name;
                break;
            }
        }

        if (validCard)
        {
            Serial.println("Valid Card");
            // Xử lý thẻ hợp lệ ở đây

            const char *mess = "Hello Card ";
            uint8_t totalMess = strlen(mess) + strlen(printName) + 1;
            char notify[totalMess];
            strcpy(notify, mess);
            strcat(notify, printName);
            while(isTask1Finish == false){ 
                Serial.println(isTask1Finish);
            }
            isCriticalTask = true;
            turnLCD();
            showPopup(ui_AreaPopup, notify, 7000);
            isCriticalTask = false;
        }
        else
        {
            Serial.println("Invalid Card");
            // Xử lý thẻ không hợp lệ ở đây
            // turnLCD();
            // showPopup(ui_AreaPopup, "Unknown card", 7000);
        }
    }

    mfrc522.PICC_HaltA();
}

// function find deleted card position
int8_t findDeletedCardPosition()
{
    for (int i = 0; i < CARD_COUNT; i++)
    {
        if (strcmp(cardRegisteredData[i].id, "yyy") == 0)
        {
            return i;
        }
    }
    return -1;
}

/*-------------------Add card--------------------*/
bool RFID::enrollCard()
{
    readCardFromEEPROM();
    if (cardCount >= CARD_COUNT)
    {
        Serial.println("Card list is full");
        lv_textarea_set_text(ui_areaNotyfyAddCard, "Card list is full.");
        _ui_screen_change(&ui_SceenCard, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_SceenFinger_screen_init);
        lv_refr_now(NULL);
        return false;
    }
    unsigned long startTime = millis();
    bool cardDetected = false;

    while (millis() - startTime <= cardTimeout)
    {
        _ui_flag_modify(ui_areaNotyfyAddCard, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        lv_textarea_set_text(ui_areaNotyfyAddCard, "Place card on sensor");
        lv_refr_now(NULL);
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
        // Serial.print("Card add is: ");
        Serial.println(cardUID);
        const char *cardID = cardUID.c_str();
        int8_t position = findDeletedCardPosition();
        int8_t userId;
        char name[8];
        const char *getName = lv_textarea_get_text(ui_areaEnterNameFP2);
        if (position >= 0)
        {
            userId = position + 1;
            snprintf(name, sizeof(name), "user%d", userId);
            if (strcmp(getName, "") != 0)
            {
                strcpy(name, getName);
            }
            myFingerPrint.padNameWithSpaces(name);
            strcpy(cardRegisteredData[position].id, cardID);
            strcpy(cardRegisteredData[position].name, name);
            cardCount++;
        }
        else
        {
            userId = cardCount + 1;
            snprintf(name, sizeof(name), "user%d", userId);
            if (strcmp(getName, "") != 0)
            {
                strcpy(name, getName);
            }
            myFingerPrint.padNameWithSpaces(name);
            int8_t lastPosition = cardCount;
            strcpy(cardRegisteredData[lastPosition].id, cardID);
            strcpy(cardRegisteredData[lastPosition].name, name);
            cardCount++;
        }
        if (saveCard())
        {
            const char *notify = createNotification("Successfully add card ", name);
            showPopup(ui_areaNotyfyAddCard, notify, TIME_POPUP);
            Serial.println("Successfully add new card");
            readCardFromEEPROM();
            return true;
        }
        else
        {
            Serial.println("Failed to save a new card. Please try again!");
            showPopup(ui_areaNotyfyAddCard, "Failed to add new card", TIME_POPUP);
            // behavior for fail
            return false;
        }
    }
    else
    {
        Serial.println("No card detected!");
        showPopup(ui_areaNotyfyAddCard, "No card detected!", TIME_POPUP);
        return false;
    }
    return true;
}

// function find card by name
int8_t RFID::findCardByName(const char *name)
{
    for (int i = 0; i < cardCount; i++)
    {
        if (strcmp(cardRegisteredData[i].name, name) == 0)
        {
            return i;
        }
    }
    return -1;
}

// function delete card by name
bool RFID::deleteCardByName(const char *nameToDelete)
{
    int8_t position = findCardByName(nameToDelete);

    if (position >= 0)
    {
        strcpy(cardRegisteredData[position].id, "yyy");
        strcpy(cardRegisteredData[position].name, "");
        return true;
    }
    else
        return false;
}
/*--------------------Delete card--------------------*/
bool RFID::unenrollCard(const char *user)
{
    // if (cardCount <= 0)
    // {
    //     Serial.println("Card list is empty");
    // }
    unsigned long startTime = millis();
    while (millis() - startTime <= cardTimeout)
    {
        const char *getName = user;
        char name[8];
        strcpy(name, getName);
        myFingerPrint.padNameWithSpaces(name);
        if (deleteCardByName(name))
        {
            Serial.print("Deleting card: ");
            Serial.println(name);
        }
        else
        {
            Serial.println("Name not found!");
            const char *notify = createNotification("Not found user ", getName);
            showPopup(ui_areaNotyfyDeleteCard, notify, TIME_POPUP);
            return false;
        }
        saveCard();
        readCardFromEEPROM();
        Serial.print("Deleted card: ");
        Serial.println(name);
        const char *notify = createNotification("Successlly delete card ", getName);
        showPopup(ui_areaNotyfyDeleteCard, notify, TIME_POPUP);
        return true;
    }
    return true;
}

/*------------Print list card----------*/
void RFID::showList()
{
    readCardFromEEPROM();
    lv_textarea_set_text(ui_areaShowCard, "");
    lv_textarea_add_text(ui_areaShowCard, "Total card is ");
    convertNum(ui_areaShowCard, cardCount);
    lv_textarea_add_text(ui_areaShowCard, "\n\n");
    Serial.print("Registered Cards: ");
    Serial.println(cardCount);
    for (int i = 0; i < CARD_COUNT; i++)
    {
        if (strcmp(cardRegisteredData[i].id, "xxx") != 0 && strcmp(cardRegisteredData[i].id, "yyy") != 0)
        {
            Serial.print(cardRegisteredData[i].id);
            Serial.print(" : ");
            Serial.println(cardRegisteredData[i].name);
            lv_textarea_add_text(ui_areaShowCard, cardRegisteredData[i].id);
            lv_textarea_add_text(ui_areaShowCard, " : ");
            lv_textarea_add_text(ui_areaShowCard, cardRegisteredData[i].name);
            lv_textarea_add_text(ui_areaShowCard, "\n");
        }
    }
}
