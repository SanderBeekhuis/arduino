// Dot_matrix_ICONS.ino
#include <FrequencyTimer2.h>
#define Heart {{0, 1, 0, 0, 0, 1, 0, 0}, \
{1, 0, 1, 0, 1, 0, 1, 0}, \
{1, 0, 0, 1, 0, 0, 1, 0}, \
{0, 1, 0, 0, 0, 1, 0, 0}, \
{0, 0, 1, 0, 1, 0, 0, 0}, \
{0, 0, 0, 1, 0, 0, 0, 0}, \
{0, 0, 0, 0, 0, 0, 0, 0}, \
{0, 0, 0, 0, 0, 0, 0, 0} \
}
#define Arrow {{0, 0, 0, 0, 1, 0, 0, 0}, \
{0, 0, 0, 0, 0, 1, 0, 0}, \
{0, 0, 0, 0, 0, 0, 1, 0}, \
{1, 1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1, 1}, \
{0, 0, 0, 0, 0, 0, 1, 0}, \
{0, 0, 0, 0, 0, 1, 0, 0}, \
{0, 0, 0, 0, 1, 0, 0, 0} \
}
#define Anchor {{0, 0, 0, 1, 1, 0, 0, 0}, \
{0, 0, 1, 1, 1, 1, 0, 0}, \
{0, 0, 0, 1, 1, 0, 0, 0}, \
{0, 0, 0, 1, 1, 0, 0, 0}, \
{1, 0, 0, 1, 1, 0, 0, 1}, \
{1, 0, 0, 1, 1, 0, 0, 1}, \
{0, 1, 0, 1, 1, 0, 1, 0}, \
{0, 0, 1, 1, 1, 1, 0, 0} \
}
#define Space {{0, 0, 0, 0, 0, 0, 0, 0}, \
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
byte patterns[1][8][8] = { Anchor }; //{ Heart, Arrow, Anchor };
void setup()
{ for (int i = 2; i <= 19; i++) pinMode(i, OUTPUT);
for (int i = 1; i <= 8; i++) digitalWrite(col[i - 1], HIGH);
for (int i = 1; i <= 8; i++) digitalWrite(row[i - 1], HIGH);
clearArray();
FrequencyTimer2::setPeriod(2000);
FrequencyTimer2::setOnOverflow(updateDisplay);
setPattern(0);
}
void loop()
{ setPattern(0);
}
void clearArray()
{ for (int i = 0; i < 8; i++)
{ for (int j = 0; j < 8; j++) LEDs[i][j] = 0;
}
}
void setPattern(int pattern)
{ for (int i = 0; i < 8; i++)
{ for (int j = 0; j < 8; j++) LEDs[i][j] = patterns[pattern][i][j];
}
}
void updateDisplay()
{ digitalWrite(col[column], HIGH);
column++;
if (column == 8) column = 0;
for (int r = 0; r < 8; r++)
{ if (LEDs[column][7 - r] == 1) digitalWrite(row[r], HIGH);
else digitalWrite(row[r], LOW);
}
digitalWrite(col[column], LOW);
}