// HC595_shift_out.ino
int CLOCK = 12;
int LATCH = 11;
int DATA = 10;
int dataA[8] = {1,0,1,0,1,0,1,0};
int dataB[8] = {0,1,0,1,0,1,0,1};
void setup()
{ pinMode(LATCH, OUTPUT);
pinMode(CLOCK, OUTPUT);
pinMode(DATA, OUTPUT);
}
void loop ()
{ digitalWrite(LATCH, LOW);
for (int i=0; i<8; i++)
{ digitalWrite(CLOCK, LOW);
digitalWrite(DATA, dataA[i]);
digitalWrite(CLOCK, HIGH);
}
digitalWrite(LATCH, HIGH);
delay(300);
digitalWrite(LATCH, LOW);
for (int i=0; i<8; i++)
{ digitalWrite(CLOCK, LOW);
digitalWrite(DATA, dataB[i]);
digitalWrite(CLOCK, HIGH);
}
digitalWrite(LATCH, HIGH);
delay(300);
}