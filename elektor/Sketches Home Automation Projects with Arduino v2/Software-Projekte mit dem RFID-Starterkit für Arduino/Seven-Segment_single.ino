// Seven-Segment_single.ino
const int a=4; const int b=5;
const int dp=6; const int c=7;
const int d=8; const int e=9;
const int f=10; const int g=11;
int timeDelay = 300;
void setup()
{ for(int thisPin = 4; thisPin <= 11; thisPin++)
{ pinMode(thisPin,OUTPUT);
}
}
void loop()
{ digital_0(); delay(timeDelay);
digital_1(); delay(timeDelay);
digital_2(); delay(timeDelay);
digital_3(); delay(timeDelay);
digital_4(); delay(timeDelay);
digital_5(); delay(timeDelay);
digital_6(); delay(timeDelay);
digital_7(); delay(timeDelay);
digital_8(); delay(timeDelay);
digital_9(); delay(timeDelay);
}
void digital_0(void) // zero
{ digitalWrite(a,HIGH); digitalWrite(b,HIGH);
digitalWrite(c,HIGH); digitalWrite(d,HIGH);
digitalWrite(e,HIGH); digitalWrite(f,HIGH);
digitalWrite(g,LOW); digitalWrite(dp,LOW);
}
void digital_1(void) // one
{ digitalWrite(a,LOW); digitalWrite(b,HIGH);
digitalWrite(c,HIGH); digitalWrite(d,LOW);
digitalWrite(e,LOW); digitalWrite(f,LOW);
digitalWrite(g,LOW); digitalWrite(dp,LOW);
}
void digital_2(void) // two
{ digitalWrite(a,HIGH); digitalWrite(b,HIGH);
digitalWrite(c,LOW); digitalWrite(d,HIGH);
digitalWrite(e,HIGH); digitalWrite(f,LOW);
digitalWrite(g,HIGH); digitalWrite(dp,LOW);
}
void digital_3(void) // three
{ digitalWrite(a,HIGH); digitalWrite(b,HIGH);
digitalWrite(c,HIGH); digitalWrite(d,HIGH);
digitalWrite(e,LOW); digitalWrite(f,LOW);
digitalWrite(g,HIGH); digitalWrite(dp,LOW);
}
void digital_4(void) // four
{ digitalWrite(a,LOW); digitalWrite(b,HIGH);
digitalWrite(c,HIGH); digitalWrite(d,LOW);
digitalWrite(e,LOW); digitalWrite(f,HIGH);
digitalWrite(g,HIGH); digitalWrite(dp,LOW);
}
void digital_5(void) // five
{ digitalWrite(a,HIGH); digitalWrite(b,LOW);
digitalWrite(c,HIGH); digitalWrite(d,HIGH);
digitalWrite(e,LOW); digitalWrite(f,HIGH);
digitalWrite(g,HIGH); digitalWrite(dp,LOW);
}
void digital_6(void) // six
{ digitalWrite(a,HIGH); digitalWrite(b,LOW);
digitalWrite(c,HIGH); digitalWrite(d,HIGH);
digitalWrite(e,HIGH); digitalWrite(f,HIGH);
digitalWrite(g,HIGH); digitalWrite(dp,LOW);
}
void digital_7(void) // seven
{ digitalWrite(a,HIGH); digitalWrite(b,HIGH);
digitalWrite(c,HIGH); digitalWrite(d,LOW);
digitalWrite(e,LOW); digitalWrite(f,LOW);
digitalWrite(g,LOW); digitalWrite(dp,LOW);

}
void digital_8(void) // eight
{ digitalWrite(a,HIGH); digitalWrite(b,HIGH);
digitalWrite(c,HIGH); digitalWrite(d,HIGH);
digitalWrite(e,HIGH); digitalWrite(f,HIGH);
digitalWrite(g,HIGH); digitalWrite(dp,LOW);
}
void digital_9(void) // nine
{ digitalWrite(a,HIGH); digitalWrite(b,HIGH);
digitalWrite(c,HIGH); digitalWrite(d,HIGH);
digitalWrite(e,LOW); digitalWrite(f,HIGH);
digitalWrite(g,HIGH); digitalWrite(dp,LOW);
}