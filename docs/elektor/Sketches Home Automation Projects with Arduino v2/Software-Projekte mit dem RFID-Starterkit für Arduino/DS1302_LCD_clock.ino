// DS1302_LCD_clock.ino
#include <stdio.h>
#include <DS1302.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
// Pins: RST,DAT,CLK
DS1302 rtc(7, 6, 5);
String dayAsString(const Time::Day day)
{ switch (day)
{ case 1: return "So"; case 2: return "Mo";
case 3: return "Di"; case 4: return "Mi";
case 5: return "Do"; case 6: return "Fr";
case 7: return "Sa";
}
return "(ERROR)";
}
void setup()
{ // initialize the LCD
lcd.begin();
// Turn on the blacklight and print start message
lcd.backlight();
lcd.print("Starting Clock!");
delay(3000);
pinMode(3, OUTPUT); digitalWrite(3, HIGH); // VCC
pinMode(4, OUTPUT); digitalWrite(4, LOW); // GND
}
void loop()
{ Time t = rtc.time();
const String day = dayAsString(t.day);
char buf1[16];
snprintf(buf1, sizeof(buf1), " %s, %02d.%02d.%04d", day.c_str(), t.date,
t.mon, t.yr);
char buf2[16];
snprintf(buf2, sizeof(buf2), " %02d:%02d:%02d", t.hr, t.min, t.sec);
lcd.setCursor(0, 0); lcd.println(buf1);
lcd.setCursor(15, 0); lcd.println(" ");
lcd.setCursor(0, 1); lcd.println(buf2);
lcd.setCursor(12, 1); lcd.println(" ");
delay(1000);
}