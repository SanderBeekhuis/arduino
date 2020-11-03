// LM35_w_LCD.ino
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27 for a 16
// chars and 2 line display
float temp = 0;
long LM35val = 0;
void setup()
{
lcd.begin(); //initialize the lcd
lcd.backlight(); //open the backlight
}
void loop()
{ LM35val = analogRead(A0);
temp = (LM35val * 0.489);
lcd.setCursor(0,0); lcd.print("LM35 Temperature");
lcd.setCursor(1,1); lcd.print("Tem = ");
lcd.setCursor(7,1); lcd.print(temp, 1); // one decimal
lcd.print(" "); lcd.print(char(223)); lcd.print("C");
delay(200);
}