// Bouncing.ino
int SW1=3, LED=13;
int Toggle=0, n=0;
void setup()
{ Serial.begin(9600);
pinMode(SW1,INPUT);
digitalWrite(SW1,HIGH);
Serial.println("Bouncing");
pinMode(LED,OUTPUT);
}
void loop()
{ if(!digitalRead(SW1))
{ n++;
Serial.print("Switch pressed ");
Serial.print(n,DEC);
Serial.println(" times");
Toggle=!Toggle;
digitalWrite(LED,Toggle);
do {} while(!digitalRead(SW1));
}
}