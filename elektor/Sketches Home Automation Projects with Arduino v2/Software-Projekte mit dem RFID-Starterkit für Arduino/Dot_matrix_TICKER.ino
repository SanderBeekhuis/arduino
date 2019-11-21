// Dot_matrix_TICKER.ino
#include <FrequencyTimer2.h>
#define H { \
{0, 1, 1, 0, 0, 1, 1, 0}, \
{0, 1, 1, 0, 0, 1, 1, 0}, \
{0, 1, 1, 0, 0, 1, 1, 0}, \
{0, 1, 1, 1, 1, 1, 1, 0}, \
{0, 1, 1, 1, 1, 1, 1, 0}, \
{0, 1, 1, 0, 0, 1, 1, 0}, \
{0, 1, 1, 0, 0, 1, 1, 0}, \
{0, 1, 1, 0, 0, 1, 1, 0} \
}
#define A { \
{0, 1, 1, 1, 1, 1, 1, 0}, \
{0, 1, 1, 1, 1, 1, 1, 0}, \
{0, 1, 1, 0, 0, 1, 1, 0}, \
{0, 1, 1, 0, 0, 1, 1, 0}, \
{0, 1, 1, 1, 1, 1, 1, 0}, \
{0, 1, 1, 1, 1, 1, 1, 0}, \
{0, 1, 1, 0, 0, 1, 1, 0}, \
{0, 1, 1, 0, 0, 1, 1, 0} \
}
#define L { \
{0, 1, 1, 0, 0, 0, 0, 0}, \
{0, 1, 1, 0, 0, 0, 0, 0}, \
{0, 1, 1, 0, 0, 0, 0, 0}, \
{0, 1, 1, 0, 0, 0, 0, 0}, \
{0, 1, 1, 0, 0, 0, 0, 0}, \
{0, 1, 1, 0, 0, 0, 0, 0}, \
{0, 1, 1, 1, 1, 1, 1, 0}, \
{0, 1, 1, 1, 1, 1, 1, 0} \
}
#define O { \
{0, 0, 0, 1, 1, 0, 0, 0}, \
{0, 0, 1, 1, 1, 1, 0, 0}, \
{0, 1, 1, 0, 0, 1, 1, 0}, \
{0, 1, 1, 0, 0, 1, 1, 0}, \
{0, 1, 1, 0, 0, 1, 1, 0}, \
{0, 1, 1, 0, 0, 1, 1, 0}, \
{0, 0, 1, 1, 1, 1, 0, 0}, \
{0, 0, 0, 1, 1, 0, 0, 0} \
}
#define SPACE { \
{0, 0, 0, 0, 0, 0, 0, 0}, \
{0, 0, 0, 0, 0, 0, 0, 0}, \
{0, 0, 0, 0, 0, 0, 0, 0}, \
{0, 0, 0, 0, 0, 0, 0, 0}, \
{0, 0, 0, 0, 0, 0, 0, 0}, \
{0, 0, 0, 0, 0, 0, 0, 0}, \
{0, 0, 0, 0, 0, 0, 0, 0}, \
{0, 0, 0, 0, 0, 0, 0, 0} \
}
byte column = 0;
byte LEDs[8][8];
int col[8] = {6, 11, 10, 3, 17, 4, 8, 9};
int row[8] = {2, 7, 19, 5, 13, 18, 12, 16};
const int numPatterns = 6;
byte patterns[numPatterns][8][8] = { H,A,L,L,O, SPACE };
int pattern = 0;
void setup() {
// sets the pins as output
for (int i = 2; i <= 19; i++)
{ pinMode(i, OUTPUT);
}
// set up cols and rows
for (int i = 1; i <= 8; i++)
{ digitalWrite(col[i - 1], HIGH);
}
for (int i = 1; i <= 8; i++)
{ digitalWrite(row[i - 1], HIGH);
}
clearLEDs();
// Turn off toggling of pin 11
FrequencyTimer2::disable();
// Set refresh rate (interrupt timeout period)
FrequencyTimer2::setPeriod(2000);
// Set interrupt routine to be called
FrequencyTimer2::setOnOverflow(display);
setPattern(pattern);
}
void loop() {
pattern = ++pattern % numPatterns;
slidePattern(pattern, 100);
}
void clearLEDs() {
// Clear display array
for (int i = 0; i < 8; i++) {
for (int j = 0; j < 8; j++) {
LEDs[i][j] = 0;
}
}
}
void setPattern(int pattern) {
for (int i = 0; i < 8; i++) {
for (int j = 0; j < 8; j++) {
LEDs[i][j] = patterns[pattern][i][j];
}
}
}
void slidePattern(int pattern, int del) {
for (int l = 0; l < 8; l++) {
for (int i = 0; i < 7; i++) {
for (int j = 0; j < 8; j++) {
LEDs[j][i] = LEDs[j][i+1];
}
}
for (int j = 0; j < 8; j++) {
LEDs[j][7] = patterns[pattern][j][0 + l];
}
delay(del);
}
}
// Interrupt routine
void display() {
digitalWrite(col[column], HIGH); // Turn whole previous column off
column++;
if (column == 8) {
column = 0;
}
for (int r = 0; r < 8; r++) {
if (LEDs[column][7 - r] == 1) {
digitalWrite(row[r], HIGH); // Turn on this LED
}
else {
digitalWrite(row[r], LOW); // Turn off this LED
}
}
digitalWrite(col[column], LOW); // Turn whole column on at once (for equal
// lighting times)
}