#ifndef FINGERPRINT_HPP
#define FINGERPRINT_HPP

// #define debugMode
#include <Adafruit_Fingerprint.h>
#include "myEEPROM.hpp"
#include <vector>
#include <ui.h>

#define ScanTimeoutMillis 5000u

#define FINGERPRINT_COUNT 20
// #define TotalFP (20 + StartAddrSaveFP)
extern uint8_t errorCount;
extern bool isDoorOpen;



enum fingerLocalStatus{
    //enum used for enroll method 
    FINGER_OK,
    FINGER_ERROR,
    FINGER_TIMEOUT,
};

struct DataFingerprint {
  uint16_t id;
  char name[8];
};

extern DataFingerprint fingerprintData[];

#define FINGERPRINT_COUNT 20
#define FINGERPRINT_START_ADDRESS 100 
#define FINGERPRINT_END_ADDRESS 299

class FingerPrint {
    Adafruit_Fingerprint finger;
public:
    FingerPrint();
    void scanFinger();
    void begin(uint16_t baudRate);
    bool enroll(uint16_t &id);
    bool enrollFingerprint();
    bool unEnroll(const char* admin);
    void getLog();
    bool debugFinger();
    void diagFingerPrint();
    void restore();
    void queryFinger();
    void readFingerprintFromEEPROM();
    int findFingerprintByName(const char *name);
    bool deleteFingerprintByName(const char *nameToDelete, uint16_t *id);
    bool saveFingerprintToEEPROM();
    void showList();
    void changeFingerprintAdmin();
    // std::vector<int> getFPInUsed();
    ~FingerPrint();
};


#endif