// Seven-segment_counter.ino
#include <TimerOne.h>
// pin connection - segments
int seg_a = 2; int seg_b = 3; int seg_c = 4; int seg_d = 5;
int seg_e = 6; int seg_f = 7; int seg_g = 8; int seg_dp = 9;
// pin connection - digits
int dig_1 = 13; int dig_2 = 12; int dig_3 = 11; int dig_4 = 10;
// display value: 0000 to 9999, digit-number: 1 to 4, counter variable
int number = 0, digit = 0, count = 0;
int timetune = 1; // fine tuning of display timing
void setup()
{ pinMode(dig_1, OUTPUT); pinMode(dig_2, OUTPUT);
pinMode(dig_3, OUTPUT); pinMode(dig_4, OUTPUT);
pinMode(seg_a, OUTPUT); pinMode(seg_b, OUTPUT);
pinMode(seg_c, OUTPUT); pinMode(seg_d, OUTPUT);
pinMode(seg_e, OUTPUT); pinMode(seg_f, OUTPUT);
pinMode(seg_g, OUTPUT); pinMode(seg_dp, OUTPUT);
Timer1.initialize(10000); // timer for 10000 µs = 10 ms = .01 s
Timer1.attachInterrupt( countUp ); // attach service routine countUp
}
void loop()
{ clrDigit(); Digit(0); Number((number/1000)); delay(timetune);
clrDigit(); Digit(1); Number((number%1000)/100); delay(timetune);
clrDigit(); Digit(2); Number(number%100/10); delay(timetune);
clrDigit(); Digit(3); Number(number%10); delay(timetune);
}
/**************************************/
void Digit(int digit)
{ digitalWrite(dig_1, HIGH); digitalWrite(dig_2, HIGH);
digitalWrite(dig_3, HIGH); digitalWrite(dig_4, HIGH);
switch(digit)
{ case 0: digitalWrite(dig_1, LOW); break;
case 1: digitalWrite(dig_2, LOW); break;
case 2: digitalWrite(dig_3, LOW); break;
case 3: digitalWrite(dig_4, LOW); break;
}
}
//display numbers
void Number(int digit)
{ switch(digit)
{ default: zero(); break;
case 1: one(); break;
case 2: two(); break;
case 3: three(); break;
case 4: four(); break;
case 5: five(); break;
case 6: six(); break;
case 7: seven(); break;
case 8: eight(); break;
case 9: nine(); break;
}
}
void clrDigit()
{ digitalWrite(seg_a, LOW); digitalWrite(seg_b, LOW);
digitalWrite(seg_c, LOW); digitalWrite(seg_d, LOW);
digitalWrite(seg_e, LOW); digitalWrite(seg_f, LOW);
digitalWrite(seg_g, LOW); digitalWrite(seg_dp, LOW);
}
void zero() // 0
{ digitalWrite(seg_a, HIGH); digitalWrite(seg_b, HIGH);
digitalWrite(seg_c, HIGH); digitalWrite(seg_d, HIGH);
digitalWrite(seg_e, HIGH); digitalWrite(seg_f, HIGH);
digitalWrite(seg_g, LOW);
}
void one() // 1
{ digitalWrite(seg_a, LOW); digitalWrite(seg_b, HIGH);
digitalWrite(seg_c, HIGH); digitalWrite(seg_d, LOW);
digitalWrite(seg_e, LOW); digitalWrite(seg_f, LOW);
digitalWrite(seg_g, LOW);
}
void two() // 2
{ digitalWrite(seg_a, HIGH); digitalWrite(seg_b, HIGH);
digitalWrite(seg_c, LOW); digitalWrite(seg_d, HIGH);
digitalWrite(seg_e, HIGH); digitalWrite(seg_f, LOW);
digitalWrite(seg_g, HIGH);
}
void three() // 3
{ digitalWrite(seg_a, HIGH); digitalWrite(seg_b, HIGH);
digitalWrite(seg_c, HIGH); digitalWrite(seg_d, HIGH);
digitalWrite(seg_e, LOW); digitalWrite(seg_f, LOW);
digitalWrite(seg_g, HIGH);
}
void four() // 4
{ digitalWrite(seg_a, LOW); digitalWrite(seg_b, HIGH);
digitalWrite(seg_c, HIGH); digitalWrite(seg_d, LOW);
digitalWrite(seg_e, LOW); digitalWrite(seg_f, HIGH);
digitalWrite(seg_g, HIGH);
}
void five() // 5
{ digitalWrite(seg_a, HIGH); digitalWrite(seg_b, LOW);
digitalWrite(seg_c, HIGH); digitalWrite(seg_d, HIGH);
digitalWrite(seg_e, LOW); digitalWrite(seg_f, HIGH);
digitalWrite(seg_g, HIGH);
}
void six() // 6
{ digitalWrite(seg_a, HIGH); digitalWrite(seg_b, LOW);
digitalWrite(seg_c, HIGH); digitalWrite(seg_d, HIGH);
digitalWrite(seg_e, HIGH); digitalWrite(seg_f, HIGH);
digitalWrite(seg_g, HIGH);
}
void seven() // 7
{ digitalWrite(seg_a, HIGH); digitalWrite(seg_b, HIGH);
digitalWrite(seg_c, HIGH); digitalWrite(seg_d, LOW);
digitalWrite(seg_e, LOW); digitalWrite(seg_f, LOW);
digitalWrite(seg_g, LOW);
}
void eight() // 8
{ digitalWrite(seg_a, HIGH); digitalWrite(seg_b, HIGH);
digitalWrite(seg_c, HIGH); digitalWrite(seg_d, HIGH);
digitalWrite(seg_e, HIGH); digitalWrite(seg_f, HIGH);
digitalWrite(seg_g, HIGH);
}
void nine() // 9
{ digitalWrite(seg_a, HIGH); digitalWrite(seg_b, HIGH);
digitalWrite(seg_c, HIGH); digitalWrite(seg_d, HIGH);
digitalWrite(seg_e, LOW); digitalWrite(seg_f, HIGH);
digitalWrite(seg_g, HIGH);
}
void countUp()
{ count ++;
if(count == 10)
{ count = 0;
number ++; if(number == 10000) number = 0;
}
}