// Dot matrix control.ino
// Dot matric control via joystick
const int row[8] = { 2, 7, 19, 5, 13, 18, 12, 16 };
const int col[8] = { 6, 11, 10, 3, 17, 4, 8, 9 };
int pixels[8][8];
int x = 5, y = 5;
void setup()
{ for (int i = 0; i < 8; i++)
{ pinMode(col[i], OUTPUT);
pinMode(row[i], OUTPUT);
digitalWrite(col[i], HIGH);
}
// initialize matrix
for (int x = 0; x < 8; x++)
{ for (int y = 0; y < 8; y++)
{ pixels[x][y] = HIGH; }
}
}
void loop()
{ // turn off the last position:
pixels[x][y] = HIGH;
// read joystick position
x = map(analogRead(A0), 0, 1023, 0, 7);
y = map(analogRead(A1), 0, 1023, 0, 7);
pixels[x][y] = LOW;
refreshMatrix();
}
void refreshMatrix() {
for (int i = 0; i < 8; i++)
{ digitalWrite(row[i], HIGH);
for (int j = 0; j < 8; j++)
{ // pixel on
int thisPixel = pixels[i][j];
digitalWrite(col[j], thisPixel);
// pixel off
if (thisPixel == LOW) {
digitalWrite(col[j], HIGH);
}
}
// clear row:
digitalWrite(row[i], LOW);
}
}