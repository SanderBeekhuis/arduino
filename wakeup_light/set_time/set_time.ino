// DS1302_set_time.ino
#include <stdio.h>
#include <DS1302.h>
namespace {
  

// RTC Pins configured for position of RTC Over arduino board (shield-like)
#define RTC_VCC 7
#define RTC_GND 6
#define RTC_CLK 5
#define RTC_DAT 4
#define RTC_RST 3

const int kCePin = RTC_RST;   // Chip Enable
const int kIoPin = RTC_DAT;   // Input/Output
const int kSclkPin = RTC_CLK; // Serial Clock

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
    pinMode(RTC_VCC, OUTPUT);
    digitalWrite(RTC_VCC, HIGH); // VCC
    pinMode(RTC_GND, OUTPUT);
    digitalWrite(RTC_GND, LOW); // GND
    rtc.writeProtect(false);
    rtc.halt(false);
    // Donnerstag, 1. September, 10:00:00
    Time t(2021, 12, 5, 21, 55, 0, Time::kWednesday);
    rtc.time(t);
}

// Loop and print the time every second.
void loop()
{
    printTime();
    delay(1000);
}
