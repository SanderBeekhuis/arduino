// DHT11_w_LCD_display.ino
#include <dht.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27 for a 16
// chars and 2 line display
dht DHT;
const int DHT11_PIN= 4;
void setup()
{ lcd.begin(); //initialize the lcd
lcd.backlight(); //open the backlight
}
void loop()
{ DHT.read11(DHT11_PIN);
lcd.setCursor(0, 0); lcd.print("Temp: ");
lcd.print(DHT.temperature,0);
lcd.print(char(223));//print the unit" oC "
lcd.print("C");
lcd.setCursor(0, 1);
lcd.print("Humidity: ");
lcd.print(DHT.humidity,0); lcd.print(" %");
delay(200);
}