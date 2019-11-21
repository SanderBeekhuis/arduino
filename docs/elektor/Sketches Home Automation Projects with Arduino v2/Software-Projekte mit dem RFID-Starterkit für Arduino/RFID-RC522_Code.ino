// RFID-RC522_Code.ino
#include <SPI.h>
#include <MFRC522.h>
// RC522 Arduino UNO
// Pin Pin
// ---------------------------------------
// RST 9
// SDA(SS) 10
// MOSI 11
// MISO 12
// SCK 13
#define RST_PIN 9
#define SS_PIN 10
MFRC522 mfrc522(SS_PIN, RST_PIN);
long code = 0;
long validCode = 123456; // enter valid code
int activePin = 7;
void setup()
{ pinMode (activePin, OUTPUT);
Serial.begin(9600);
SPI.begin();
mfrc522.PCD_Init();
Serial.println("Place RFID TAG in range!");
delay(300);
}
void loop()
{ // Card present?
if ( ! mfrc522.PICC_IsNewCardPresent())
{ return;
}
// Select card
if ( ! mfrc522.PICC_ReadCardSerial())
{ return;
}
Serial.print("UID of RFID TAGS: ");
for (byte i = 0; i < mfrc522.uid.size; i++)
{ Serial.print(mfrc522.uid.uidByte[i], HEX);
Serial.print(" ");
}
Serial.println();
long code=0;
for (byte i = 0; i < mfrc522.uid.size; i++)
{code=((code+mfrc522.uid.uidByte[i])*10);
}
Serial.print("Code is: ");
Serial.println(code);
if (code == validCode)
{ // valid card detected
Serial.println("Valid ID detected - activate lock!");
Serial.println();
digitalWrite (activePin, HIGH);
delay (3000);
digitalWrite (activePin, LOW);
}
}