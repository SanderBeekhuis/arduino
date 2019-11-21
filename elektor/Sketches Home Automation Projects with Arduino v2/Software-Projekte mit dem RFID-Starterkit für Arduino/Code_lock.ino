// Code_lock.ino
#include <Password.h>
#include <Keypad.h>
#include <Servo.h>
Servo myservo;
Password password = Password( "123456" ); // change password here!
const byte ROWS = 4; // Four rows
const byte COLS = 4; // columns
char keys[ROWS][COLS] =
{ {'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};
byte rowPins[ROWS] = { 4, 5, 6, 7 };
byte colPins[COLS] = { 8, 9, 10, 11};
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
const byte LEDred = 12, LEDgreen = 13, ServoPin = 2;
const int openTime = 1000;
void setup()
{ Serial.begin(9600);
delay(200);
pinMode(LEDgreen, OUTPUT);
pinMode(LEDred, OUTPUT);
myservo.attach(ServoPin);
keypad.addEventListener(keypadEvent);
}
void loop()
{ keypad.getKey();
myservo.write(0);
}
void keypadEvent(KeypadEvent eKey)
{ switch (keypad.getState())
{ case PRESSED:
Serial.print("Enter: ");
Serial.println(eKey);
delay(10);
if(eKey == char('A'))
{ checkPassword(); delay(1);
}
else password.append(eKey); delay(1);
}
}
void checkPassword()
{ if (password.evaluate())
{ // password ok
Serial.println("Accepted"); delay(10);
myservo.write(90);
digitalWrite(LEDgreen, HIGH); delay(openTime);
digitalWrite(LEDgreen, LOW);
password.reset(); delay(1);
}
else
{ // password NOT ok
Serial.println("Denied"); delay(10);
myservo.write(0);
digitalWrite(LEDred, HIGH); delay(openTime);
digitalWrite(LEDred, LOW);
password.reset(); delay(1);
}
}