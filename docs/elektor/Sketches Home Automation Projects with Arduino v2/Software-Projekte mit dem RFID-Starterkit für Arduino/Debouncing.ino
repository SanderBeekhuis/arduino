// Debouncing.ino
byte n=0;
int SW1=3;
int LED=13;
int Toggle=0;
byte value_1, value_2=0;
void setup()
{ Serial.begin(9600);
pinMode(SW1,INPUT);
digitalWrite(SW1,HIGH);
pinMode(LED,OUTPUT);
Serial.println("Debounce");
}
void loop()
{ value_1=digitalRead(SW1);
if(!value_1)
{ delay(50);
value_2=digitalRead(SW1);
if(!value_2)
{ n++;
Serial.print("Switch was pressed ");
Serial.print(n,DEC);
Serial.println(" times");
Toggle=!Toggle;
digitalWrite(LED,Toggle);
do{}while(!digitalRead(SW1));
}
}
}