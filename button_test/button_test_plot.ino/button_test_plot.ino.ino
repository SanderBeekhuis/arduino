
int SWITCH = 3;
int n = 0;
int Toggle = 0;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
  pinMode(SWITCH, INPUT);
  digitalWrite(SWITCH, HIGH);
  Serial.println("Bouncing")  ;
}

// the loop function runs over and over again forever
void loop() {
  int state = digitalRead(SWITCH);
  Serial.println(state);
  digitalWrite(LED_BUILTIN, state);
}
