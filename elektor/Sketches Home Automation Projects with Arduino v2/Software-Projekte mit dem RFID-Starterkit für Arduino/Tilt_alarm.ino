// Tilt_alarm.ino
int speaker = 9;
void setup()
{ pinMode(speaker, OUTPUT);
pinMode(2, INPUT_PULLUP);
}
void loop()
{ if(digitalRead(2) == LOW)
{ tone(speaker,1000,100);
}
delay(300);
}