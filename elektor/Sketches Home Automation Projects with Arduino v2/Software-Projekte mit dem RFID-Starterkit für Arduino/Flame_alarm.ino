// Flame_alarm.ino
// Rv = 10 k
#define AlarmLED 13
#define speaker 9
int ADC_value;
int ADC_0=0;
int threshold = 300;
void setup()
{ Serial.begin(9600);
pinMode(AlarmLED, OUTPUT);
}
void loop()
{ ADC_value=analogRead(ADC_0);
Serial.println(ADC_value);
if(ADC_value > threshold)
{ digitalWrite(AlarmLED,HIGH);
tone(speaker,1000,100);
Serial.println("Flame alert!");
}
else digitalWrite(AlarmLED,LOW);
delay(300);
}