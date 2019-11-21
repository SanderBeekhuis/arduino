// Dot_matrix_LIVE.ino
#include <FrequencyTimer2.h>
byte const MATRIX_SIZE = 8, start_density = 40;
int matPin[16]= {13, 12, 11, 10, 16, 17, 18, 19, 2, 3, 4, 5, 6, 7, 8, 9};
int col[MATRIX_SIZE] = {matPin[12], matPin[2], matPin[3], matPin[9],
matPin[5], matPin[10], matPin[14], matPin[15]};
int row[MATRIX_SIZE] = {matPin[8], matPin[13], matPin[7], matPin[11],
matPin[0], matPin[6], matPin[1], matPin[4]};
// default start condition
byte state[MATRIX_SIZE][MATRIX_SIZE][2] =
{ 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0,
0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0,
1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0,
0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0,
1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0,
0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0,
0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0,
};
byte cells[MATRIX_SIZE][MATRIX_SIZE], cl = 0;
void setup()
{ // initailize and reset matrix
for (int i = 0; i < 2*MATRIX_SIZE; i++) pinMode(matPin[i], OUTPUT);
for (int i = 0; i < MATRIX_SIZE; i++)
{ digitalWrite(col[i], HIGH);
digitalWrite(row[i], HIGH);
}
// reset display
for (int i = 0; i < 8; i++)
for (int j = 0; j < 8; j++) cells[i][j] = 0;
FrequencyTimer2::setPeriod(2000);
FrequencyTimer2::setOnOverflow(display);
/*
// random start condition
randomSeed(analogRead(0));
for (int i = 0; i < MATRIX_SIZE; i++)
{ for (int j = 0; j < MATRIX_SIZE; j++)
{ if (random(100) < start_density) state[i][j][0] = 1;
else state[i][j][0] = 0;
state[i][j][1] = 0;
}
}
*/
}
void loop() {
// show state
for (int i = 0; i < MATRIX_SIZE; i++)
for (int j = 0; j < MATRIX_SIZE; j++) cells[i][j] = state[i][j][0];
delay(80);
// cycles
for (int x = 0; x < MATRIX_SIZE; x++)
{ for (int y = 0; y < MATRIX_SIZE; y++)
{ state[x][y][1] = state[x][y][0];
int count = neighbours(x, y);
if (count == 3 && state[x][y][0] == 0) state[x][y][1] = 1; // cell is
// born
if ((count < 2 || count > 3) && state[x][y][0] == 1) state[x][y][1] =
0; // cell dies
}
}
// next generation
for (int x = 0; x < MATRIX_SIZE; x++)
for (int y = 0; y < MATRIX_SIZE; y++) state[x][y][0] = state[x][y][1];
}
int neighbours(int x, int y)
{ return state[(x + MATRIX_SIZE - 1) % MATRIX_SIZE][(y + MATRIX_SIZE - 1) %
MATRIX_SIZE][0] +
state[(x + 1) % MATRIX_SIZE][y][0] + state[x][(y + 1) % MATRIX_
SIZE][0] +
state[(x + MATRIX_SIZE - 1) % MATRIX_SIZE][(y + 1) % MATRIX_SIZE]
[0] +
state[(x + 1) % MATRIX_SIZE][(y + MATRIX_SIZE - 1) % MATRIX_SIZE]
[0]+
state[(x + 1) % MATRIX_SIZE][(y + 1) % MATRIX_SIZE][0] + state[(x
+ MATRIX_SIZE - 1) % MATRIX_SIZE][y][0] +
state[x][(y + MATRIX_SIZE - 1) % MATRIX_SIZE][0];
}
void display() // display refresh
{ digitalWrite(col[cl], HIGH);
cl++;
if (cl == MATRIX_SIZE) cl = 0;
for (int rw = 0; rw < MATRIX_SIZE; rw++)
{ if (cells[cl][MATRIX_SIZE - 1 - rw] == 1) digitalWrite(row[rw], HIGH);
else digitalWrite(row[rw], LOW);
}
digitalWrite(col[cl], LOW);
}