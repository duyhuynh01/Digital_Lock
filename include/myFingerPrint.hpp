#ifndef FINGERPRINT_HPP
#define FINGERPRINT_HPP

// #define debugMode
#include <Adafruit_Fingerprint.h>
#include "myEEPROM.hpp"
#include <ui.h>
#include "funcUi.hpp"
#include <vector>
#include <FS.h>
#include <SPIFFS.h>
#include <string>
#include <algorithm>

using namespace fs;

#define ScanTimeoutMillis 4000u

#define FINGERPRINT_COUNT 20
// #define TotalFP (20 + StartAddrSaveFP)
extern uint8_t errorCount;
extern bool isDoorOpen;
extern bool flagModeSetting;


enum fingerLocalStatus{
    //enum used for enroll method 
    FINGER_OK,
    FINGER_ERROR,
    FINGER_TIMEOUT,
};

struct DataFingerprint {
  int8_t id;
  String name;
};


#define FINGERPRINT_COUNT 20
#define FINGERPRINT_START_ADDRESS 100 
#define FINGERPRINT_END_ADDRESS 299

class FingerPrint {
    Adafruit_Fingerprint finger;
    std::vector<DataFingerprint> fingerprintData;
    // DataFingerprint fingerprintData[FINGERPRINT_COUNT];
public:
    FingerPrint();
    void scanFinger();
    void begin(uint16_t baudRate);
    bool enroll();
    bool storeFPToBuffer(String name,int8_t id);
    void storeFPToMem();
    void LoadFPFromMem();
    bool unEnroll(int8_t);
    void restore();
    void showList();
    const char* getNameByID(int8_t);
    int8_t getID();
    ~FingerPrint();
private:
    int16_t fingerprintCount;
};
#endif