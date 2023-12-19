#include "Password.hpp"

extern const char *PasswordUnlock;
Password::Password()
{
}

void Password::begin()
{
   if (!passwordExists())
    {
        createPasswords(INITIALIZE_ADMIN_PASSWORD);
        Serial.println("--Created password!---");
    }
    else
    {
        Serial.println("Created password!");
    }
}
const char *Password::getAdminPassword() const
{
  return adminPassword;
}
void Password::createPasswords(const char* newPassword)
{
  strcpy(adminPassword, newPassword);
  for (int i = 0; i < PASSWORD_SIZE; i++)
  {
    EEPROM.write(ADMIN_PASSWORD_ADDRESS + i, adminPassword[i]);
  }
  EEPROM.commit();
}

/*hàm kiểm tra password tồn tại trong eeprom chưa*/
bool Password::passwordExists()
{
  for (int i = 0; i < PASSWORD_SIZE; i++)
  {
    adminPassword[i] = EEPROM.read(ADMIN_PASSWORD_ADDRESS + i);
  }
  adminPassword[PASSWORD_SIZE] = '\0';
  return (strcmp(adminPassword, "") != 0);
}

/*hàm đọc pass từ eeprom*/
void Password::readPasswordFromEEPROM()
{
  for (int i = 0; i < PASSWORD_SIZE; i++)
  {
    InputAdminPassword[i] = EEPROM.read(ADMIN_PASSWORD_ADDRESS + i);
  }
  InputAdminPassword[PASSWORD_SIZE] = '\0';
}

/*hàm kiểm tra mật khẩu admin*/
bool Password::checkAdminPassword()
{
  uint8_t passwordLength = strlen(adminPassword);
  uint8_t inputPasswordLength = strlen(PasswordUnlock);
  for(int i = 0; i <= inputPasswordLength - passwordLength; i ++)
  {
    if(strncmp(PasswordUnlock + i, adminPassword, passwordLength) == 0)
    {
      return true;
    }
  }
  return false;
}

/*hàm cập nhật mật khẩu admin mới vào EEPROM*/
void Password::updateAdminPasswordInEEPROM(char *newPassword)
{
  for (int i = 0; i < PASSWORD_SIZE; i++)
  {
    EEPROM.write(ADMIN_PASSWORD_ADDRESS + i, newPassword[i]);
  }
  strcpy(adminPassword, newPassword);
  EEPROM.commit();
}


void Password::changePassword(const char *currentPassword, const char *newPassword, const char *confirmPassword)
{
  if(strcmp(currentPassword, adminPassword) == 0)
  {
    if(strcmp(newPassword, confirmPassword) == 0)
    {
      strcpy(adminPassword, confirmPassword);
      createPasswords(adminPassword);
      showPopup(ui_areaNotifyChangePW, "Successful", TIME_POPUP);
      Serial.println("Changed password successfully");
    }
    else
    {
      showPopup(ui_areaNotifyChangePW, "New passcodes not match", TIME_POPUP);
      Serial.println("New password and confirm password do not match");
    }
  }
  else
  {
    showPopup(ui_areaNotifyChangePW, "Incorrect old passcode", TIME_POPUP);
    Serial.println("Incorrect current password");
  }

}