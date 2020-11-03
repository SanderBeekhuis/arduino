// DS1302_read_time.ino
#include <stdio.h>
#include <DS1302.h>
// Pins: RST,DAT,CLK
DS1302 rtc(7, 6, 5);
String dayAsString(const Time::Day day) {
switch (day) {
case 1: return "Sonntag";
case 2: return "Montag";
case 3: return "Dienstag";
case 4: return "Mittwoch";
case 5: return "Donnerstag";
case 6: return "Freitag";
case 7: return "Samstag";
}
return "(ERROR)";
}
void printTime()
{ Time t = rtc.time();
const String day = dayAsString(t.day);
char buf[50];
snprintf(buf, sizeof(buf), "%s %04d-%02d-%02d %02d:%02d:%02d",
day.c_str(),
t.yr, t.mon, t.date,
t.hr, t.min, t.sec);
Serial.println(buf);
}
void setup()
{ Serial.begin(9600);
pinMode(3, OUTPUT); digitalWrite(3, HIGH); // VCC
pinMode(4, OUTPUT); digitalWrite(4, LOW); // GND
}
void loop() {
printTime();
delay(1000);
}