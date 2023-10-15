#include "Password.hpp"

extern const char *PasswordUnlock;
Password::Password()
{
}

const char *Password::getAdminPassword() const
{
  return adminPassword;
}
void Password::createPasswords()
{
  strcpy(adminPassword, INITIALIZE_ADMIN_PASSWORD);
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
  if (strcmp(adminPassword, PasswordUnlock) == 0)
    return true;
  else
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
