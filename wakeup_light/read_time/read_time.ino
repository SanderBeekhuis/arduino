// DS1302_read_time.ino
#include <stdio.h>
#include <DS1302.h>

// Pins: RST,DAT,CLK
DS1302 rtc(7, 6, 5);

String dayAsString(const Time::Day day) {
  switch (day) {
    case Time::kSunday: return "Sunday";
    case Time::kMonday: return "Monday";
    case Time::kTuesday: return "Tuesday";
    case Time::kWednesday: return "Wednesday";
    case Time::kThursday: return "Thursday";
    case Time::kFriday: return "Friday";
    case Time::kSaturday: return "Saturday";
  }
  return "(unknown day)";
}

void printTime()
{
    Time t = rtc.time();
    const String day = dayAsString(t.day);
    char buf[50];
    snprintf(buf, sizeof(buf), "%s %04d-%02d-%02d %02d:%02d:%02d",
             day.c_str(),
             t.yr, t.mon, t.date,
             t.hr, t.min, t.sec);
    Serial.println(buf);
}

void setup()
{
    Serial.begin(9600);
    pinMode(3, OUTPUT);
    digitalWrite(3, HIGH); // VCC
    pinMode(4, OUTPUT);
    digitalWrite(4, LOW); // GND
}

void loop()
{
    printTime();
    delay(1000);
}
