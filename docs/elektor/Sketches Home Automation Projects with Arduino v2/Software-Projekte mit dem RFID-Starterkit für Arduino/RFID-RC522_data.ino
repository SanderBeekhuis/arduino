// RFID-RC522_data.ino
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
void setup()
{ Serial.begin(9600);
SPI.begin(); // Start SPI bus
mfrc522.PCD_Init(); // Init MFRC522 Reader
mfrc522.PCD_DumpVersionToSerial(); // Show RC522 details
Serial.println("Place RFID TAG in range!");
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
// Send data to serial
mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}