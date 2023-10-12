#include "Password.hpp"

char adminPassword[PASSWORD_SIZE + 1];
char userPassword[PASSWORD_SIZE + 1];
char InputAdminPassword[PASSWORD_SIZE + 1];
char InputUserPassword[PASSWORD_SIZE + 1];
/*hàm tạo password*/
void createPasswords()
{
    strcpy(adminPassword, "123456");
    strcpy(userPassword, "012345");

    for (int i = 0; i < PASSWORD_SIZE; i++)
    {
        EEPROM.write(ADMIN_PASSWORD_ADDRESS + i, adminPassword[i]);
    }

    for (int i = 0; i < PASSWORD_SIZE; i++)
    {
        EEPROM.write(USER_PASSWORD_ADDRESS + i, userPassword[i]);
    }

    EEPROM.commit();
}



/*hàm kiểm tra password tồn tại trong eeprom chưa*/
bool passwordExists()
{
    for (int i = 0; i < PASSWORD_SIZE; i++)
    {
        adminPassword[i] = EEPROM.read(ADMIN_PASSWORD_ADDRESS + i);
        userPassword[i] = EEPROM.read(USER_PASSWORD_ADDRESS + i);
    }
    adminPassword[PASSWORD_SIZE] = '\0';
    userPassword[PASSWORD_SIZE] = '\0';

    return (strcmp(adminPassword, "") != 0 && strcmp(userPassword, "") != 0);
}



/*hàm đọc pass từ eeprom*/
void readPasswordFromEEPROM()
{
  for (int i = 0; i < PASSWORD_SIZE; i++)
  {
    InputAdminPassword[i] = EEPROM.read(ADMIN_PASSWORD_ADDRESS + i);
    InputUserPassword[i] = EEPROM.read(USER_PASSWORD_ADDRESS + i);
  }
  InputAdminPassword[PASSWORD_SIZE] = '\0';
  InputUserPassword[PASSWORD_SIZE] = '\0';
}


/*hàm kiểm tra mật khẩu admin*/
bool checkAdminPassword()
{
    if (strcmp(adminPassword, PasswordUnlock) == 0)
        return true;
    else
        return false;
}

/*hàm kiểm tra mật khẩu user*/
bool checkUserPassword()
{
    if (strcmp(userPassword, PasswordUnlock) == 0)
        return true;
    else
        return false;
}

/*hàm kiểm tra mật khẩu user và admin*/
bool checkPasswordUnlock()
{
  if((strcmp(adminPassword, PasswordUnlock) == 0) || (strcmp(userPassword, PasswordUnlock) == 0))
    return true;
  else  
    return false;
}

/*hàm cập nhật mật khẩu admin mới vào EEPROM*/
void updateAdminPasswordInEEPROM(char *newPassword)
{
  for (int i = 0; i < PASSWORD_SIZE; i++)
  {
    EEPROM.write(ADMIN_PASSWORD_ADDRESS + i, newPassword[i]);
  }
  strcpy(adminPassword, newPassword);
  EEPROM.commit();
}

/*hàm cập nhật mật khẩu user mới vào EEPROM*/
void updateUserPasswordInEEPROM(char *newPassword)
{
  for (int i = 0; i < PASSWORD_SIZE; i++)
  {
    EEPROM.write(USER_PASSWORD_ADDRESS + i, newPassword[i]);
  }
  strcpy(userPassword, newPassword);
  EEPROM.commit();
}

