#include "realtime.hpp"
DateTime now;
void realTime::begin()
{
    if (!rtc.begin())
    {
        Serial.println("RTC module is NOT found");
    }
    if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    
  }
}

String realTime::getTimeLog()
{
    // now = rtc.now();

    String time = String(now.year()) + "-" + String(now.month()) + "-" +
                  String(now.day()) + "-" + String(now.hour()) + "-" + String(now.minute());
    return time;
}

void realTime::updateTimer()
{
    now = rtc.now();
}
