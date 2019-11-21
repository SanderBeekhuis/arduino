// Clapping_Switch.ino
#define LED1 2 // 1x clapp - 1. LED
#define LED2 3 // 2x clapp - 2. LED
#define LED3 4 // 3x clapp - 3. LED or relais etc
#define SW1 8 // Input for clap signal
#define T1 10 // delay
#define T2 100 // ON-Time of 3. LED
#define T3 10 // reset-delay
#define C1 300 // loop constant
void setup()
{ pinMode(SW1,INPUT);
digitalWrite(SW1,HIGH); // activate internal pull-up
pinMode(LED1,OUTPUT); pinMode(LED2,OUTPUT); pinMode(LED3,OUTPUT);
}
void loop()
{ if(digitalRead(SW1))
{ digitalWrite(LED1, HIGH);
delay(T1);
for(int n=0; n<C1; n++)
{ if(digitalRead(SW1))
{ digitalWrite(LED2, HIGH);
delay(T1);
for(int m=0; m<C1; m++)
{ if(digitalRead(SW1))
{ digitalWrite(LED3, HIGH);
for(int q=0; q<10; q++)
delay(T2);
}
delay(T3);
}
delay(T3);
}
delay(T3);
}
digitalWrite(LED1, LOW);
digitalWrite(LED2, LOW);
digitalWrite(LED3, LOW);
}
}