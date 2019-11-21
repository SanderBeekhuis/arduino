// Alarm_signal.ino
int speakerPin=9;
int fstart = 100, fend = 2000;
void setup()
{ pinMode(speakerPin, OUTPUT);
}
void loop()
{ for(int i = fstart; i<= fend; i++)
{ tone(speakerPin,i,10);
}
}