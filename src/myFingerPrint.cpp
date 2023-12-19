#include "myFingerPrint.hpp"
#include <TFT_eSPI.h>
#include "realtime.hpp"
#include "utils.hpp"
#include "historyHandler.hpp"
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
    criticalTaskHandler(ui_AreaPopup, "Unknown", 5000, -1, false); //-1 value means do not consider for adminFP to enter setting mode
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
    for (int8_t i = 0; i < fingerprintData.size(); i++)
    {
      if (fingerprintData[i].id == finger.fingerID)
      {
        printName = fingerprintData[i].name.c_str();
      }
    }

    const char *mess = "Hello ";
    uint8_t totalMess = strlen(mess) + strlen(printName) + 1;
    char notify[totalMess];
    strcpy(notify, mess);
    strcat(notify, printName);
    Serial.println(notify);
    // _ui_flag_modify(ui_KeyboardPWHome, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    _ui_flag_modify(ui_AreaPWHome, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);

    criticalTaskHandler(ui_AreaPopup, "Unlock", 5000, finger.fingerID, true);
    String log = removeSpaces(String(printName)) + "-" + "FP" + "-" + realtime.getTimeLog();
    // Serial.println(log);
    history.updateHistory(log);
    return;
  }
}
int8_t FingerPrint::getID()
{
  int8_t dataSize = fingerprintData.size();
  int8_t id = -1;
  for (int i = 1; i <= FINGERPRINT_COUNT; i++)
  {
    bool found = (std::find_if(fingerprintData.begin(), fingerprintData.end(),
                               [i](const DataFingerprint &data)
                               { return data.id == i; }) != fingerprintData.end());
    if (!found)
    {
      id = i;
      return (id <= FINGERPRINT_COUNT) ? id : -1;
    }
  }
  return -1;
}
bool compareById(const DataFingerprint& a, const DataFingerprint& b){
    return a.id < b.id;
  }
void FingerPrint::LoadFPFromMem()
{
  fingerprintData.clear(); // clear all buffer
  File file = SPIFFS.open("/fplist.txt", "r");
  if (!file)
  {
    Serial.println("Failed to open fplist file for reading");
    return;
  }
  while (file.available())
  {
    DataFingerprint FP;
    String line = file.readStringUntil('\n');
    int hyphenPos = line.indexOf('-');
    // Extract the ID part
    String idStr = line.substring(0, hyphenPos);
    FP.id = idStr.toInt();
    String tempName= line.substring(hyphenPos + 1);
    for (char c : tempName){
      if(!isspace(c)){
        FP.name+=c;
      }
    }
    fingerprintData.push_back(FP);
  }
  //sort 
  std::sort(fingerprintData.begin(), fingerprintData.end(), compareById);
}
bool FingerPrint::storeFPToBuffer(String name, int8_t id)
{
  DataFingerprint newFP;
  newFP.id = id;
  newFP.name = name;
  // save to local vector
  fingerprintData.push_back(newFP);
  return true;
}
bool FingerPrint::enroll()
{
  // get ID for enroll
  int8_t id = getID();
  if (id == -1)
  {
    Serial.println("Fingerprint list is full.");
    showPopup(ui_areaPopupFP, "Fingerprint list is full.", TIME_POPUP);
    _ui_screen_change(&ui_SceenFinger, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_SceenFinger_screen_init);
    lv_refr_now(NULL);
    return false;
  }

  int status = -1;
  // first stage: get image
  unsigned int startTime = millis();
  Serial.println("Place your finger on sensor");
  // lv_textarea_set_text(ui_areaNotyfyAddFP, "Place your finger on sensor");
  // lv_refr_now(NULL);
  showPopup(ui_areaPopupFP, "Place your finger on sensor", TIME_POPUP);
  while (status != FINGERPRINT_OK && (millis() - startTime) < ScanTimeoutMillis)
  {
    resetOnScreenTimer();
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
      showPopup(ui_areaPopupFP, "Failed to add new fingerprint due to issues", TIME_POPUP);
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
    showPopup(ui_areaPopupFP, "No fingerprint detected", TIME_POPUP);
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
    showPopup(ui_areaPopupFP, "Failed to add new fingerprint due to issues", TIME_POPUP);
    return false;
  }

  status = 0;
  delay(1000);
  while (status != FINGERPRINT_NOFINGER)
  {
    Serial.println("Remove your finger");
    // lv_textarea_set_text(ui_areaNotyfyAddFP, "Remove your finger");
    // lv_refr_now(NULL);
    showPopup(ui_areaPopupFP, "Remove your finger", TIME_POPUP);
    status = finger.getImage();
  }
  delay(1000);

  // second stage: get image
  startTime = millis();
  Serial.println("Place your same finger on sensor again");
  // lv_textarea_set_text(ui_areaNotyfyAddFP, "Place your same finger on sensor again");
  // lv_refr_now(NULL);
  showPopup(ui_areaPopupFP, "Place your same finger on sensor again", TIME_POPUP);
  while (status != FINGERPRINT_OK && (millis() - startTime) < ScanTimeoutMillis)
  {
    resetOnScreenTimer();
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
    showPopup(ui_areaPopupFP, "No fingerprint detected", TIME_POPUP);
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
    showPopup(ui_areaPopupFP, "Failed to add new fingerprint due to issues", TIME_POPUP);
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
    showPopup(ui_areaPopupFP, "Failed to add new fingerprint due to your two fingerprints do not match", TIME_POPUP);
    return false;
  }
  else if (status != FINGERPRINT_OK)
  {
    Serial.print("Your FingerPrint module has an issue at third stage of enroll (create model) , issue code: 0x0");
    Serial.println(status);
    // lv_textarea_set_text(ui_areaEnterNameFP, "Failed to add new fingerprint due to issues");
    // lv_refr_now(NULL);
    // delay(2000);
    showPopup(ui_areaPopupFP, "Failed to add new fingerprint due to issues", TIME_POPUP);
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
    showPopup(ui_areaPopupFP, "Failed to add new fingerprint due to issues", TIME_POPUP);
    return false;
  }
  String name = "user";
  name += String(id);
  if (id == 1)
  {
    if (!storeFPToBuffer("admin", 1))
      return false;
  }
  else
  {
    if (!storeFPToBuffer(name, id))
      return false;
  }
  showPopup(ui_areaPopupFP, "Successful", TIME_POPUP);
  storeFPToMem();
  LoadFPFromMem();
  return true;
}
const char *FingerPrint::getNameByID(int8_t ID)
{
  for (int i = 0; i < fingerprintData.size(); i++)
  {
    if (fingerprintData[i].id == ID){
      return fingerprintData[i].name.c_str();
    }
      
  }
  return "unknown";
}
void FingerPrint::storeFPToMem()
{
  File file = SPIFFS.open("/fplist.txt", "w");
  if (!file)
  {
    Serial.println("Failed to open FPList file for writing");
    return;
  }
  for (int i = 0; i < fingerprintData.size(); ++i)
  {
    file.print(fingerprintData[i].id);
    file.print("-");
    file.println(fingerprintData[i].name);
  }
  file.close();
}
/*-------------------Delete Fingerprint-----------------*/
bool FingerPrint::unEnroll(int8_t DelID)
{
  const char *DelName = getNameByID(DelID);
  if (!strcmp(DelName, "unknown")){
    showPopup(ui_areaNotyfyDeleteFP, "ID not found!", TIME_POPUP);
    lv_timer_handler();
    lv_refr_now(NULL);
    Serial.println("ID not found!");
    return false;
  }
  uint8_t status = -1;
  status = finger.deleteModel(DelID);
  Serial.print("Deleteting model #");
  Serial.println(DelID);
  if (status != FINGERPRINT_OK)
  {
    Serial.println("Failed to delete model");
    showPopup(ui_areaNotyfyDeleteFP, "Failed to delete!", TIME_POPUP);
    return false;
  }


  Serial.print("Model # ");
  Serial.print(DelID);
  Serial.println(" has been deleted");
  Serial.println(DelName);
  String notify = "Deleted " + String(DelName) +"'s FP";
  showPopup(ui_areaNotyfyDeleteFP, notify.c_str(), TIME_POPUP);
  lv_timer_handler();
  lv_refr_now(NULL);
  
  //remove FP in vector
  fingerprintData.erase(std::remove_if(fingerprintData.begin(), fingerprintData.end(),
                        [DelID](const DataFingerprint& data) { return data.id == DelID; }),
                        fingerprintData.end());

  storeFPToMem();  //update to memory
  LoadFPFromMem();
  return true;
}
void FingerPrint::restore()
{
  // This method is used to delete all template (both eeprom and sensor)
  finger.emptyDatabase();
  File file = SPIFFS.open("/fplist.txt", "w");
  if (!file)
  {
    Serial.println("Failed to open fplist file for clearing");
    return;
  }
  LoadFPFromMem();
  file.close();
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
  tableFP = lv_table_create(ui_panelShowFP);
  int8_t countFP = 0;
  for (int i = 0; i < fingerprintData.size(); i++)
  {
    char str[5]; // 5 chữ số + ký tự kết thúc chuỗi ('\0')
    snprintf(str, sizeof(str), "%hu", fingerprintData[i].id);
    lv_table_set_cell_value(tableFP, countFP, 0, str);
    lv_table_set_cell_value(tableFP, countFP, 1, fingerprintData[i].name.c_str());
    countFP++;
  }

  // lv_table_set_col_width(tableFP, 0, 60);
  // lv_table_set_col_width(tableFP, 1, 50);
  lv_obj_set_style_text_font(tableFP, &lv_font_montserrat_10, LV_PART_MAIN);
  lv_obj_set_style_text_color(tableFP, lv_color_hex(0x000000), LV_PART_MAIN);
  lv_obj_set_style_bg_color(tableFP, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
  lv_obj_set_style_text_align(tableFP, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(tableFP, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

  // lv_obj_set_size(table, 235, 220);
  lv_obj_set_height(tableFP, 230);
  lv_obj_center(tableFP);
  lv_obj_set_y(tableFP, -10);
  lv_obj_add_event_cb(tableFP, draw_part_event_FP, LV_EVENT_DRAW_PART_BEGIN, NULL);
  flagShowFP = true;
}

