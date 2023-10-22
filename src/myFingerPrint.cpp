#include "myFingerPrint.hpp"
DataFingerprint fingerprintData[FINGERPRINT_COUNT];
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
    return;
  }
  else if (status == FINGERPRINT_OK)
  {
    Serial.print("Found ID #");
    Serial.print(finger.fingerID);
    Serial.print(" with confidence of ");
    Serial.println(finger.confidence);
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
  // for (int i = 0; i < FINGERPRINT_COUNT; i++)
  // {
  //   Serial.println(fingerprintData[i].id);
  //   if (fingerprintData[i].id != 65535)
  //   {
  //     // Serial.println(fingerprintData[i].id);
  //     fingerprintCount++;
  //   }

  // }
  // Serial.print("fingeradd: ");
  // Serial.println(fingerprintCount);
  // fingerprintCount = 0;
  for (int i = 0; i < FINGERPRINT_COUNT; i++)
  {
    // Serial.println(fingerprintData[i].id);
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
      return 0;
    }
  }
  // check if timeout
  if (status == FINGERPRINT_NOFINGER)
  {
    Serial.println("Timeout to scan fingerprint");
    return false;
  }

  // first stage: convert image
  status = finger.image2Tz(1);
  if (status != FINGERPRINT_OK)
  {
    Serial.print("Your FingerPrint module has an issue at first stage of enroll (convert image) , issue code: 0x0");
    Serial.println(status);
    return false;
  }

  status = 0;
  delay(1000);
  while (status != FINGERPRINT_NOFINGER)
  {
    Serial.println("Remove your finger");
    status = finger.getImage();
  }
  delay(1000);

  // second stage: get image
  startTime = millis();
  Serial.println("Place your same finger on sensor again");
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
    return false;
  }

  // second stage: convert image
  status = finger.image2Tz(2);
  if (status != FINGERPRINT_OK)
  {
    Serial.print("Your FingerPrint module has an issue at second stage of enroll (convert image) , issue code: 0x0");
    Serial.println(status);
    return false;
  }

  // third stage:create model

  Serial.print("Creating model for #");
  Serial.println(id);
  status = finger.createModel();
  if (status == FINGERPRINT_ENROLLMISMATCH)
  {
    Serial.println("Failed to add new finger because your two fingers do not match");
    return false;
  }
  else if (status != FINGERPRINT_OK)
  {
    Serial.print("Your FingerPrint module has an issue at third stage of enroll (create model) , issue code: 0x0");
    Serial.println(status);
    return false;
  }

  // third stage: save model
  Serial.print("Saving model for #");
  Serial.println(id);
  status = finger.storeModel(id);
  if (status != FINGERPRINT_OK)
  {
    Serial.print("Your FingerPrint module has an issue at third stage of enroll (save model) , issue code: 0x0");
    Serial.println(status);
    return false;
  }
  return true;
}
/*--------------------Enroll Fingerprint-----------------*/
bool FingerPrint::enrollFingerprint()
{

  readFingerprintFromEEPROM();
  if (fingerprintCount >= FINGERPRINT_COUNT)
  {
    Serial.println("FingerPrint list is fulled");
    return false;
  }
  uint16_t id = 1000;
  char name[8];
  int8_t position = findDeletedPosition();
  id = position + 1;
  if (position >= 0)
  {
    if(id == 1)
    {
      strcpy(name, "Admin");
    }
    else
    {
      snprintf(name, sizeof(name), "User%d", id);
    }
    padNameWithSpaces(name);
    fingerprintData[position].id = id;
    strcpy(fingerprintData[position].name, name);
    fingerprintCount++;
  }
  else
  {
    id = fingerprintCount + 1;
    if(id == 1)
    {
      strcpy(name, "Admin");
    }
    else
    {
      snprintf(name, sizeof(name), "User%d", id);
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
  }
  Serial.println("saved succcessfull!");
  return true;
}

/*-------------------Delete Fingerprint-----------------*/
bool FingerPrint::unEnroll(const char* admin)
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
      return false;
    }

    Serial.print("Model # ");
    Serial.print(id);
    Serial.println(" has been deleted");
  }
  else
  {
    Serial.println("Name not found!");
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

void FingerPrint::showList()
{
  readFingerprintFromEEPROM();
  // Serial.println(fingerprintCount);
  for (int i = 0; i < FINGERPRINT_COUNT; i++)
  {
    if (fingerprintData[i].id != 65535)
    {
      Serial.print(fingerprintData[i].id);
      Serial.print(" :");
      Serial.println(fingerprintData[i].name);
    }
  }
}

void FingerPrint::changeFingerprintAdmin()
{
  unEnroll("Admin");
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