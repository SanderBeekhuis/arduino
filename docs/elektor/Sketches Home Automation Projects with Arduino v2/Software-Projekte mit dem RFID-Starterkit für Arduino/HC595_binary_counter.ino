// HC595_binary_counter.ino
int CLOCK = 12;
int LATCH = 11;
int DATA = 10;
int counter = 1;
void setup()
{ //set pins to output so you can control the shift register
pinMode(LATCH, OUTPUT);
pinMode(CLOCK, OUTPUT);
pinMode(DATA, OUTPUT);
}
void loop()
{ digitalWrite(LATCH, LOW);
shiftOut(DATA, CLOCK, MSBFIRST, counter);
digitalWrite(LATCH, HIGH);
delay(100);
counter++;
if (counter >= 256) counter=1;
}