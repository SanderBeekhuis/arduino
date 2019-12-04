
#include <stdio.h>

#include <DS1302.h>

#include <Adafruit_NeoPixel.h>

// NeoPixel strand settings
#define STRAND_PIN 10
#define STRAND_LENGTH 120

// RTC Pins configured for position of RTC Over arduino board (shield-like)
#define RTC_VCC 7
#define RTC_GND 6
#define RTC_CLK 5
#define RTC_DAT 4
#define RTC_RST 3

//Operational constants
#define SLEEP 1000 * 60 //1 minuteu

// RTC Pins: RST,DAT,CLK
DS1302 rtc(RTC_RST, RTC_DAT, RTC_CLK);

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(STRAND_LENGTH, STRAND_PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

uint32_t BLACK = strip.Color(0, 0, 0);

void setup()
{
  Serial.begin(9600);
  Serial.println("My Sketch has started");

  pinMode(RTC_VCC, OUTPUT);
  digitalWrite(RTC_VCC, HIGH); // VCC
  pinMode(RTC_GND, OUTPUT);
  digitalWrite(RTC_GND, LOW); // GND

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop()
{
  check_alarm();
  delay(SLEEP);
}

void check_alarm()
{
  Time t = rtc.time();
  char buf[50];
  snprintf(buf, sizeof(buf), "%04d-%02d-%02d %02d:%02d:%02d",
           t.yr, t.mon, t.date,
           t.hr, t.min, t.sec);
  Serial.println(buf);

  if (t.hr == 6)
  {
    setColor(redToWhite(t.min));
  }
  else
  {
    setColor(BLACK);
  }
}

void setColor(uint32_t c)
{
  for (uint16_t i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, c);
  }
  strip.show();
}

// Returns white whith brigthness b between 0-255
uint32_t white(uint16_t b)
{
  return strip.Color(b, b, b);
}

// b can range from 0 to 255
// 0 is no liht
// 64 maxes red brightness
// 255 for full white
uint32_t redToWhite(byte b)
{
  byte red = min(4 * b, 255);
  byte green = min(2 * b, 255);
  byte blue = min(b, 255);
  return strip.Color(red, green, blue);
}
