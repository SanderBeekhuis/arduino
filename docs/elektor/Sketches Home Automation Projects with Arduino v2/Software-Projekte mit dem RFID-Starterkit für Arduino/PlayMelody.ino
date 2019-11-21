// PlayMelody.ino
int duration = 300, silence = 200;
int speakerPin=9;
// tone frequencies
int A = 440, H = 494;
int C = 523, d = 587, e = 659, f = 698;
int g = 784, a = 880, h = 988, c = 1047;
void setup()
{ pinMode(speakerPin, OUTPUT);
}
void loop()
{ tone(speakerPin,C,duration); delay(silence);
tone(speakerPin,d,duration); delay(silence);
tone(speakerPin,e,duration); delay(silence);
tone(speakerPin,f,duration); delay(silence);
tone(speakerPin,g,duration); delay(silence);
tone(speakerPin,e,duration); delay(silence);
tone(speakerPin,e,duration); delay(silence);
tone(speakerPin,f,duration); delay(silence);
tone(speakerPin,C,duration); delay(silence);
tone(speakerPin,C,duration); delay(silence);
delay(3*silence);
}