#include <RTClib.h>

class realTime
{
    RTC_DS3231 rtc;
    char daysOfWeek[7][12] = {
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday"};
public:
    realTime() : rtc() {};
    void begin();
    String getTimeLog();
    void updateTimer();
};
