// DS1302_set_time.ino
#include <stdio.h>
#include <DS1302.h>
namespace {
  

const int kCePin = 7;   // Chip Enable
const int kIoPin = 6;   // Input/Output
const int kSclkPin = 5; // Serial Clock

// Create a DS1302 object.
DS1302 rtc(kCePin, kIoPin, kSclkPin);

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

} //namespace

void setup()
{
    Serial.begin(9600);
    pinMode(3, OUTPUT);
    digitalWrite(3, HIGH); // VCC
    pinMode(4, OUTPUT);
    digitalWrite(4, LOW); // GND
    rtc.writeProtect(false);
    rtc.halt(false);
    // Donnerstag, 1. September, 10:00:00
    Time t(2016, 9, 1, 10, 0, 0, Time::kTuesday);
    rtc.time(t);
}

// Loop and print the time every second.
void loop()
{
    printTime();
    delay(1000);
}
