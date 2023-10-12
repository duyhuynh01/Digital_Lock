#ifndef PASSWORD_HPP
#define PASSWORD_HPP

#include <EEPROM.h>
#include "funcUi.hpp"
#define ADMIN_PASSWORD_ADDRESS 0
#define USER_PASSWORD_ADDRESS 10
#define PASSWORD_SIZE 6

extern char InputAdminPassword[];
extern char InputUserPassword[];
extern char adminPassword[];
extern char userPassword[];

void createPasswords();
bool checkPasswordUnlock();
bool checkUserPassword();
bool checkAdminPassword();
bool passwordExists();
void readPasswordFromEEPROM();
void updateAdminPasswordInEEPROM(char *newPassword);
void updateUserPasswordInEEPROM(char *newPassword);
#endif