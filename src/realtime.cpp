#include "realtime.hpp"

void realTime::begin()
{
    if (!rtc.begin())
    {
        Serial.println("RTC module is NOT found");
    }
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

String realTime::getTimeLog()
{
    DateTime now = rtc.now();

    String time = String(now.year()) + "-" + String(now.month()) + "-" +
                  String(now.day()) + "-" + String(now.hour()) + "-" + String(now.minute());
    return time;
}
