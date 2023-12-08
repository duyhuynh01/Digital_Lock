#include "myFingerPrint.hpp"
#include <TFT_eSPI.h>
#include "realtime.hpp"
#include "utils.hpp"
#include "historyHandler.hpp"
DataFingerprint fingerprintData[FINGERPRINT_COUNT];
bool flagModeSetting = false;
// extern bool flagSetting;
extern bool screenIsOn;
extern unsigned long lastTouchTime;
extern void resetOnScreenTimer();
extern bool addFinger;
extern bool isTask2Finish;
extern bool isEnrollFP;
extern bool isSettingModeOn;
extern uint8_t invalidCount;
extern HistoryHandler history;
extern realTime realtime;

// int16_t fingerprintCount = 0;
FingerPrint::FingerPrint() : finger(&Serial2)
{
}

FingerPrint::~FingerPrint()
{
}

int16_t FingerPrint::getFingerprintCount()
{
  readFingerprintFromEEPROM();
  return fingerprintCount;
}

void FingerPrint::begin(uint16_t baudRate)
{
  finger.begin(baudRate);

  if (finger.verifyPassword())
  {
    Serial.println("Found fingerprint sensor!");
  }
  else
  {
    Serial.println("Did not find fingerprint sensor :(");
    while (1)
    {
      delay(1);
    }
  }
  // update database
  readFingerprintFromEEPROM();

  Serial.println(F("Reading sensor parameters"));
  finger.getParameters();
  Serial.print(F("Status: 0x"));
  Serial.println(finger.status_reg, HEX);
  Serial.print(F("Sys ID: 0x"));
  Serial.println(finger.system_id, HEX);
  Serial.print(F("Capacity: "));
  Serial.println(finger.capacity);
  Serial.print(F("Security level: "));
  Serial.println(finger.security_level);
  Serial.print(F("Device address: "));
  Serial.println(finger.device_addr, HEX);
  Serial.print(F("Packet len: "));
  Serial.println(finger.packet_len);
  Serial.print(F("Baud rate: "));
  Serial.println(finger.baud_rate);
  // get number of templates
  finger.getTemplateCount();
  Serial.print(F("Sensor contains: "));
  Serial.print(finger.templateCount);
  Serial.println(" templates");
}

void FingerPrint::scanFinger()
{
  int status = -1;
  // first stage: get image
  status = finger.getImage();
  if (status == FINGERPRINT_NOFINGER)
  {
    return;
  }
  else if (status != FINGERPRINT_OK)
  {
    Serial.print("Your FingerPrint module has an issue at first stage of scanFinger (get image) , issue code: 0x0");
    Serial.println(status);
    return;
  }

  // second stage: convert image
  status = finger.image2Tz();
  if (status != FINGERPRINT_OK)
  {
    Serial.print("Your FingerPrint module has an issue at second stage of scanFinger (convert image) , issue code: 0x0");
    Serial.println(status);
    return;
  }

  // third stage: searching!
  status = finger.fingerSearch();
  if (status == FINGERPRINT_NOTFOUND)
  {
    Serial.println("Did not find a match");
    // _ui_flag_modify(ui_KeyboardPWHome, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    // _ui_flag_modify(ui_AreaPWHome, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    criticalTaskHandler(ui_AreaPopup, "Unknown fingerprint!", 7000, -1, false); //-1 value means do not consider for adminFP to enter setting mode
    invalidCount += 1;
    return;
  }
  else if (status == FINGERPRINT_OK)
  {
    Serial.print("Found ID #");
    Serial.print(finger.fingerID);
    Serial.print(" with confidence of ");
    Serial.println(finger.confidence);
    const char *printName;
    const char *logName; // name used to log
    for (int8_t i = 0; i < fingerprintCount; i++)
    {
      if (fingerprintData[i].id == finger.fingerID)
      {
        printName = fingerprintData[i].name;
      }
    }

    const char *mess = "Hello ";
    uint8_t totalMess = strlen(mess) + strlen(printName) + 1;
    char notify[totalMess];
    strcpy(notify, mess);
    strcat(notify, printName);
    // _ui_flag_modify(ui_KeyboardPWHome, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    _ui_flag_modify(ui_AreaPWHome, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);

    criticalTaskHandler(ui_AreaPopup, notify, 5000, finger.fingerID, true);
    String log = removeSpaces(String(printName)) + "-" + "FP" + "-" + realtime.getTimeLog();
    // Serial.println(log);
    history.updateHistory(log);
    return;
  }
}

int FingerPrint::findFingerprintByName(const char *name)
{
  for (int i = 0; i < fingerprintCount; i++)
  {
    if (strcmp(fingerprintData[i].name, name) == 0)
    {
      return i;
    }
  }
  return -1;
}

bool FingerPrint::deleteFingerprintByName(const char *nameToDelete, uint16_t *id)
{
  int position = findFingerprintByName(nameToDelete);

  if (position >= 0)
  {
    *id = fingerprintData[position].id;
    fingerprintData[position].id = 65534;
    strcpy(fingerprintData[position].name, "");

    return true;
  }
  else
    return false;
}

bool isIDUsed(uint16_t id)
{
  for (int i = 0; i < FINGERPRINT_COUNT; i++)
  {
    if (fingerprintData[i].id == id)
    {
      return true;
    }
  }
  return false;
}

int findDeletedPosition()
{
  for (int i = 0; i < FINGERPRINT_COUNT; i++)
  {
    if (fingerprintData[i].id == 65534)
    {
      return i;
    }
  }
  return -1;
}

bool FingerPrint::saveFingerprintToEEPROM()
{
  for (int i = FINGERPRINT_START_ADDRESS; i <= FINGERPRINT_END_ADDRESS; i += sizeof(DataFingerprint))
  {
    uint8_t index = (i - FINGERPRINT_START_ADDRESS) / sizeof(DataFingerprint);
    if (index < fingerprintCount)
    {
      EEPROM.put(i, fingerprintData[index]);
    }
    else
    {
      DataFingerprint emptyFingerprint;
      emptyFingerprint.id = 65535;
      strcpy(emptyFingerprint.name, "");
      EEPROM.put(i, emptyFingerprint);
    }
  }
  EEPROM.commit();
  readFingerprintFromEEPROM();
  return true;
}

/*------------------Load data from EEPROM---------------------*/
void FingerPrint::readFingerprintFromEEPROM()
{
  uint8_t countList = 0; // Đặt giá trị ban đầu của fingerprintCount là 0
  fingerprintCount = 0;
  for (int i = FINGERPRINT_START_ADDRESS; i < FINGERPRINT_END_ADDRESS; i += sizeof(DataFingerprint))
  {
    EEPROM.get(i, fingerprintData[countList]);
    countList++;
  }
  for (int i = 0; i < FINGERPRINT_COUNT; i++)
  {
    if (fingerprintData[i].id != 65535 && fingerprintData[i].id != 65534)
    {
      fingerprintCount++;
    }
  }
  Serial.print("fingecount: ");
  Serial.println(fingerprintCount);
}

/*----------------Padding name---------------------*/
void FingerPrint::padNameWithSpaces(char *name)
{
  int nameLength = strlen(name);
  if (nameLength < 7)
  {
    for (int i = nameLength; i < 7; i++)
    {
      name[i] = ' ';
    }
  }
  name[7] = '\0';
}
bool FingerPrint::enroll(uint16_t &id)
{
  int status = -1;
  // first stage: get image
  unsigned int startTime = millis();
  Serial.println("Place your finger on sensor");
  // lv_textarea_set_text(ui_areaNotyfyAddFP, "Place your finger on sensor");
  // lv_refr_now(NULL);
  showPopup(ui_areaNotyfyAddFP, "Place your finger on sensor", TIME_POPUP);
  while (status != FINGERPRINT_OK && (millis() - startTime) < ScanTimeoutMillis)
  {
    status = finger.getImage();
    if (status == FINGERPRINT_OK)
    {
      Serial.println("Image taken");
      break;
    }
    else if (status == FINGERPRINT_NOFINGER)
    {
    }
    else
    {
      Serial.print("Your FingerPrint module has an issue at first stage of enroll (get image) , issue code: 0x0");
      Serial.println(status);
      // lv_textarea_set_text(ui_areaNotyfyAddFP, "Failed to add new fingerprint due to issues");
      // lv_refr_now(NULL);
      showPopup(ui_areaNotyfyAddFP, "Failed to add new fingerprint due to issues", TIME_POPUP);
      // delay(2000);
      return false;
    }
  }
  // check if timeout
  if (status == FINGERPRINT_NOFINGER)
  {
    Serial.println("Timeout to scan fingerprint");
    // lv_textarea_set_text(ui_areaNotyfyAddFP, "No fingerprint detected");
    // lv_refr_now(NULL);
    // delay(2000);
    showPopup(ui_areaNotyfyAddFP, "No fingerprint detected", TIME_POPUP);
    return false;
  }

  // first stage: convert image
  status = finger.image2Tz(1);
  if (status != FINGERPRINT_OK)
  {
    Serial.print("Your FingerPrint module has an issue at first stage of enroll (convert image) , issue code: 0x0");
    Serial.println(status);
    // lv_textarea_set_text(ui_areaNotyfyAddFP, "Failed to add new fingerprint due to issues");
    // lv_refr_now(NULL);
    // delay(2000);
    showPopup(ui_areaNotyfyAddFP, "Failed to add new fingerprint due to issues", TIME_POPUP);
    return false;
  }

  status = 0;
  delay(1000);
  while (status != FINGERPRINT_NOFINGER)
  {
    Serial.println("Remove your finger");
    // lv_textarea_set_text(ui_areaNotyfyAddFP, "Remove your finger");
    // lv_refr_now(NULL);
    showPopup(ui_areaNotyfyAddFP, "Remove your finger", TIME_POPUP);
    status = finger.getImage();
  }
  delay(1000);

  // second stage: get image
  startTime = millis();
  Serial.println("Place your same finger on sensor again");
  // lv_textarea_set_text(ui_areaNotyfyAddFP, "Place your same finger on sensor again");
  // lv_refr_now(NULL);
  showPopup(ui_areaNotyfyAddFP, "Place your same finger on sensor again", TIME_POPUP);
  while (status != FINGERPRINT_OK && (millis() - startTime) < ScanTimeoutMillis)
  {
    status = finger.getImage();
    if (status == FINGERPRINT_OK)
    {
      Serial.println("Image taken");
      break;
    }
    else if (status == FINGERPRINT_NOFINGER)
    {
    }
    else
    {
      Serial.print("Your FingerPrint module has an issue at second stage of enroll (get image) , issue code: 0x0");
      Serial.println(status);
      return false;
    }
  }
  // check if timeout
  if (status == FINGERPRINT_NOFINGER)
  {
    Serial.println("Timeout to scan fingerprint");
    // lv_textarea_set_text(ui_areaNotyfyAddFP, "No fingerprint detected");
    // lv_refr_now(NULL);
    // delay(2000);
    showPopup(ui_areaNotyfyAddFP, "No fingerprint detected", TIME_POPUP);
    return false;
  }

  // second stage: convert image
  status = finger.image2Tz(2);
  if (status != FINGERPRINT_OK)
  {
    Serial.print("Your FingerPrint module has an issue at second stage of enroll (convert image) , issue code: 0x0");
    Serial.println(status);
    // lv_textarea_set_text(ui_areaNotyfyAddFP, "Failed to add new fingerprint due to issues");
    // lv_refr_now(NULL);
    // delay(2000);
    showPopup(ui_areaNotyfyAddFP, "Failed to add new fingerprint due to issues", TIME_POPUP);
    return false;
  }

  // third stage:create model

  Serial.print("Creating model for #");
  // lv_textarea_set_text(ui_areaEnterNameFP, "Creating model...");
  Serial.println(id);
  status = finger.createModel();
  if (status == FINGERPRINT_ENROLLMISMATCH)
  {
    Serial.println("Failed to add new finger because your two fingers do not match");
    // lv_textarea_set_text(ui_areaEnterNameFP, "Failed to add new fingerprint due to your two fingerprints do not match");
    // lv_refr_now(NULL);
    // delay(2000);
    showPopup(ui_areaNotyfyAddFP, "Failed to add new fingerprint due to your two fingerprints do not match", TIME_POPUP);
    return false;
  }
  else if (status != FINGERPRINT_OK)
  {
    Serial.print("Your FingerPrint module has an issue at third stage of enroll (create model) , issue code: 0x0");
    Serial.println(status);
    // lv_textarea_set_text(ui_areaEnterNameFP, "Failed to add new fingerprint due to issues");
    // lv_refr_now(NULL);
    // delay(2000);
    showPopup(ui_areaNotyfyAddFP, "Failed to add new fingerprint due to issues", TIME_POPUP);
    return false;
  }

  // third stage: save model
  Serial.print("Saving model for #");
  // lv_textarea_set_text(ui_areaEnterNameFP, "Saving model...");
  Serial.println(id);
  status = finger.storeModel(id);
  if (status != FINGERPRINT_OK)
  {
    Serial.print("Your FingerPrint module has an issue at third stage of enroll (save model) , issue code: 0x0");
    Serial.println(status);
    // lv_textarea_set_text(ui_areaEnterNameFP, "Failed to add new fingerprint due to issues");
    // lv_refr_now(NULL);
    // delay(2000);
    showPopup(ui_areaNotyfyAddFP, "Failed to add new fingerprint due to issues", TIME_POPUP);
    return false;
  }
  return true;
}
/*--------------------Enroll Fingerprint-----------------*/
bool FingerPrint::enrollFingerprint()
{
  while (isTask2Finish == false)
  {
    delayMicroseconds(35);
  }
  isEnrollFP = true;
  readFingerprintFromEEPROM();
  if (fingerprintCount >= FINGERPRINT_COUNT)
  {
    Serial.println("Fingerprint list is full.");
    showPopup(ui_areaNotyfyAddFP, "Fingerprint list is full.", TIME_POPUP);
    _ui_screen_change(&ui_SceenFinger, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_SceenFinger_screen_init);
    lv_refr_now(NULL);
    return false;
  }
  uint16_t id;
  char name[8];
  const char *getName = lv_textarea_get_text(ui_areaEnterNameFP);
  int8_t position = findDeletedPosition();
  id = position + 1;
  if (position >= 0)
  {
    if (id == 1)
    {
      strcpy(name, "admin");
    }
    else
    {
      snprintf(name, sizeof(name), "user%d", id);
    }
    if (strcmp(getName, "") != 0)
    {
      strcpy(name, getName);
    }
    padNameWithSpaces(name);
    fingerprintData[position].id = id;
    strcpy(fingerprintData[position].name, name);
    fingerprintCount++;
  }
  else
  {
    id = fingerprintCount + 1;
    if (id == 1)
    {
      strcpy(name, "admin");
    }
    else
    {
      snprintf(name, sizeof(name), "user%d", id);
    }
    if (strcmp(getName, "") != 0)
    {
      strcpy(name, getName);
    }
    padNameWithSpaces(name);
    // fourth stage: save id into EEPROM
    int lastPosition = fingerprintCount;
    fingerprintData[lastPosition].id = id;
    strcpy(fingerprintData[lastPosition].name, name);
    fingerprintCount++;
  }

  if (enroll(id))
  {
    saveFingerprintToEEPROM();
    // const char *mess = "Added fingerprint ";
    // char notify[30];
    // strcpy(notify, mess);
    // strcat(notify, name);
    const char *notify = createNotification("Successfully add ", name);
    showPopup(ui_areaNotyfyAddFP, notify, TIME_POPUP);
    Serial.println("saved succcessfull!");
  }
  readFingerprintFromEEPROM();
  isEnrollFP = false;
  return true;
}

/*-------------------Delete Fingerprint-----------------*/
bool FingerPrint::unEnroll(const char *admin)
{
  const char *getName = admin;
  char name[8];
  strcpy(name, getName);
  padNameWithSpaces(name);
  uint16_t ID;
  if (deleteFingerprintByName(name, &ID))
  {
    Serial.print("id: ");
    Serial.println(ID);
    uint8_t status = -1;
    uint16_t id = ID;
    status = finger.deleteModel(id);
    Serial.print("Deleteting model #");
    Serial.println(id);
    if (status != FINGERPRINT_OK)
    {
      Serial.println("Failed to delete model");
      showPopup(ui_areaNotyfyDeleteFP, "Failed to delete!", TIME_POPUP);
      readFingerprintFromEEPROM();
      return false;
    }

    Serial.print("Model # ");
    Serial.print(id);
    Serial.println(" has been deleted");
    const char *notify = createNotification("Deleted fingerprint ", getName);
    showPopup(ui_areaNotyfyDeleteFP, notify, TIME_POPUP);
    lv_timer_handler();
    lv_refr_now(NULL);
  }
  else
  {
    showPopup(ui_areaNotyfyDeleteFP, "Name not found!", TIME_POPUP);
    lv_timer_handler();
    lv_refr_now(NULL);
    Serial.println("Name not found!");
    readFingerprintFromEEPROM();
    return false;
  }

  saveFingerprintToEEPROM();

  return true;
}

bool FingerPrint::debugFinger()
{
  // This method is used to check if number of template in eeprom not match with in sensor
  return true;
}

void FingerPrint::diagFingerPrint()
{
  // This method is used to check if there are any issue with fingerprint module (connection,...)

  // This method will run on diag main function
}

void FingerPrint::restore()
{
  // This method is used to delete all template (both eeprom and sensor)
  for (int i = 0; i < FINGERPRINT_COUNT; i++)
  {
    fingerprintData[i].id = 0;
    memset(fingerprintData[i].name, 0, sizeof(fingerprintData[i].name));
  }
  for (int i = FINGERPRINT_START_ADDRESS; i < FINGERPRINT_END_ADDRESS; i += sizeof(DataFingerprint))
  {
    DataFingerprint emptyFingerprint;
    emptyFingerprint.id = 65535;
    strcpy(emptyFingerprint.name, "");
    EEPROM.put(i, emptyFingerprint);
  }
  fingerprintCount = 0;
  EEPROM.commit();
  finger.emptyDatabase();
  Serial.println("Successfully delete all template");
}

void draw_part_event_FP(lv_event_t *e)
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
lv_obj_t *tableFP;
bool flagShowFP = false;
void FingerPrint::showList()
{
  readFingerprintFromEEPROM();
  tableFP = lv_table_create(ui_panelShowFP);
  int8_t countFP = 0;
  for (int i = 0; i < FINGERPRINT_COUNT; i++)
  {
    if (fingerprintData[i].id != 65535 && fingerprintData[i].id != 65534)
    {
      
      char str[5];  // 5 chữ số + ký tự kết thúc chuỗi ('\0')
      snprintf(str, sizeof(str), "%hu", fingerprintData[i].id);
      lv_table_set_cell_value(tableFP, countFP, 0, str);
      lv_table_set_cell_value(tableFP, countFP, 1, fingerprintData[i].name);
      countFP++;
    }
  }

  // lv_table_set_col_width(tableFP, 0, 60);
  // lv_table_set_col_width(tableFP, 1, 50);
  lv_obj_set_style_text_font(tableFP, &lv_font_montserrat_10, LV_PART_MAIN);
  lv_obj_set_style_text_color(tableFP, lv_color_hex(0x000000), LV_PART_MAIN);
  lv_obj_set_style_bg_color(tableFP, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
  lv_obj_set_style_text_align(tableFP, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);

  // lv_obj_set_size(table, 235, 220);
  lv_obj_set_height(tableFP, 230);
  lv_obj_center(tableFP);
  lv_obj_set_y(tableFP, -10);
  lv_obj_add_event_cb(tableFP, draw_part_event_FP, LV_EVENT_DRAW_PART_BEGIN, NULL);
  flagShowFP = true;
}

// void FingerPrint::showList()
// {
//   readFingerprintFromEEPROM();
//   // Serial.println(fingerprintCount);
//   // lv_textarea_set_text(ui_areaShowFP, "");
//   // lv_textarea_add_text(ui_areaShowFP, "Total fingerprint is ");
//   // convertNum(ui_areaShowFP, fingerprintCount);
//   // lv_textarea_add_text(ui_areaShowFP, "\n\n");
//   // for (int i = 0; i < FINGERPRINT_COUNT; i++)
//   // {
//   //   if (fingerprintData[i].id != 65535 && fingerprintData[i].id != 65534)
//   //   {
//   //     convertNum(ui_areaShowFP, fingerprintData[i].id);
//   //     lv_textarea_add_text(ui_areaShowFP, " : ");
//   //     lv_textarea_add_text(ui_areaShowFP, fingerprintData[i].name);
//   //     lv_textarea_add_text(ui_areaShowFP, "\n");
//   //     Serial.print(fingerprintData[i].id);
//   //     Serial.print(" :");
//   //     Serial.println(fingerprintData[i].name);
//   //   }
//   // }
// }

void FingerPrint::changeFingerprintAdmin()
{
  unEnroll("admin");
  enrollFingerprint();
}

void FingerPrint::queryFinger()
{
  // This medthod is used to query number of template
}

// std::vector<int> FingerPrint::getFPInUsed(){
//   // This method is used to get the current FP in use
//   std::vector<int> FPIndex(TotalFP + 1);
//   for (int i = StartAddrSaveFP; i < TotalFP; i++){
//     if (eeprom.read(i) != 0){
//       FPIndex[i]=eeprom.read(i);
//     }
//     else{
//       FPIndex[i]=0;
//     }
//   }

//   //Debug

//   // for (int j = 0; j < FPIndex.size(); j++)
//   // {
//   //   Serial.print("Index "); Serial.print(j); Serial.print(" :"); Serial.println(FPIndex[j]);
//   // }
//   return FPIndex;
// }