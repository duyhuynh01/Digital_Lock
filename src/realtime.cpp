#include "realtime.hpp"

void realTime::begin()
{
    if (!rtc.begin())
    {
        Serial.println("RTC module is NOT found");
    }
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void realTime::updateTimer()
{
    DateTime now = rtc.now();
    Serial.print(daysOfWeek[now.dayOfTheWeek()]);
    Serial.print("\t");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.print("\t");
    Serial.print(now.day(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.println(now.year(), DEC);
    
    
    
    delay(2000);
}
