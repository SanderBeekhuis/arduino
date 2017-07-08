
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define WAIT 1000 //wait of 1000 for normal operation
#define UNITTIME 1 //600 for 10 Minutes
#define TIMESTARTLED 1
#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(29, PIN, NEO_GRB + NEO_KHZ800);

uint32_t RED = strip.Color(128,0,0);



int SWITCH = 3;
int n = 0;
int Toggle = 0;
int seconds = 0;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
  pinMode(SWITCH, INPUT);
  digitalWrite(SWITCH, HIGH);
  Serial.println("Bouncing");
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

// the loop function runs over and over again forever
void loop() {  
  // state light
  int state = digitalRead(SWITCH);
  Serial.println(state);
  digitalWrite(LED_BUILTIN, state);
  strip.setPixelColor(0, stateToColor(state));
  
  
  //time
  seconds++;
  showTime(seconds);
  
  strip.show();
  delay(WAIT);
}

uint32_t stateToColor(int state) {
  if (state == 1){
    return strip.Color(65, 65, 65);
  }
  else{
    return strip.Color(0, 0, 0);
  };
};

void showTime(int seconds){
    int units = seconds / UNITTIME;
    int i;
    for (int i=TIMESTARTLED; i<units; i++){
        strip.setPixelColor(i, RED);
    }
};


// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}


