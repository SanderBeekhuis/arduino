// Dot_Matrix_Jumping_dot.ino
// Row Col 1 2 3 4 5 6 7 8
// 1 o o o o o o o o
// 2 o o o o o o o o
// 3 o o o o o o o o
// 4 o o o o o o o o
// 5 o o o o o o o o
// 6 o o o o o o o o
// 7 o o o o o o o o
// 8 o o o o o o o o
// define row and column pins
int col[8] = {16, 12, 18, 13, 5, 19, 7, 2}; // definition of pin out rows
int row[8] = {6, 11, 10, 3, 17, 4, 8, 9}; // definition of pin out
// columns
void setup()
{ for (int i = 0; i < 8; i++) // initialize columns 1..8
{pinMode(col[i], OUTPUT);
digitalWrite(col[i], LOW);
}
for (int i = 0; i < 8; i++) // initialize row 1..8
{pinMode(row[i], OUTPUT);
digitalWrite(row[i], HIGH);
}
}
void loop()
{ for (int x = 0; x < 8; x++) // select columns 1..8
{ digitalWrite(col[x], HIGH);
for (int y = 0; y < 8; y++) // clear rows 1..8
digitalWrite(row[y], HIGH);
for (int y = 0; y < 8; y++) // set dot @ rows 1..8
{ digitalWrite(row[y], LOW);
delay(50);
digitalWrite(row[y], HIGH);
}
digitalWrite(col[x], LOW);
}
}