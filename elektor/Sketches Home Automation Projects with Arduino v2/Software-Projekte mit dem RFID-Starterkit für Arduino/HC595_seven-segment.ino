// HC595_seven-segment.ino
const int latchPin = 11;//Pin connected to ST_CP of 74HC595
const int clockPin = 12;//Pin connected to SH_CP of 74HC595
const int dataPin = 10; //Pin connected to DS of 74HC595
// display 0,1,2,3,4,5,6,7,8,9,A,b,C,d,E,F
int datArray[16] = {252, 96, 218, 242, 102, 182, 190, 224, 254, 246, 238,
62, 156, 122, 158, 142};
void setup ()
{ pinMode(latchPin,OUTPUT);
pinMode(clockPin,OUTPUT);
pinMode(dataPin,OUTPUT);
}
void loop()
{ for(int num = 0; num < 16; num++)
{ digitalWrite(latchPin,LOW);
shiftOut(dataPin,clockPin,MSBFIRST,datArray[num]);
digitalWrite(latchPin,HIGH); //set latch to save data
delay(1000);
}
}