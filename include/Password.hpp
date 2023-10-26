#ifndef PASSWORD_HPP
#define PASSWORD_HPP

#include <EEPROM.h>
#include "funcUi.hpp"
#define ADMIN_PASSWORD_ADDRESS 0
#define PASSWORD_SIZE 6
#define INITIALIZE_ADMIN_PASSWORD "123456"
class Password
{
private:
    char adminPassword[PASSWORD_SIZE + 1];
    char userPassword[PASSWORD_SIZE + 1];
    char InputAdminPassword[PASSWORD_SIZE + 1];
    char InputUserPassword[PASSWORD_SIZE + 1];

public:
    Password();
    void begin();
    void createPasswords(const char* newPassword);
    bool checkAdminPassword();
    bool passwordExists();
    void readPasswordFromEEPROM();
    void updateAdminPasswordInEEPROM(char *newPassword);
    const char *getAdminPassword() const;
    void changePassword(const char *currentPassword, const char *newPassword, const char *confirmPassword);
};

#endif