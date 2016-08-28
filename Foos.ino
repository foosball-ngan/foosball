// Game
#define P1 0
#define P2 1

byte p1_score = 0;
byte p2_score = 0;

// Seven Segment
byte seven_seg_pins[2][7] = {
  { 2, 3, 4, 5, 6, 7, 8 },
  { 39, 37, 31, 33, 35, 41, 43 },
};

byte seven_seg_digits[10][7] = {
  { 1, 1, 1, 1, 1, 1, 0 },  // = 0
  { 0, 1, 1, 0, 0, 0, 0 },  // = 1
  { 1, 1, 0, 1, 1, 0, 1 },  // = 2
  { 1, 1, 1, 1, 0, 0, 1 },  // = 3
  { 0, 1, 1, 0, 0, 1, 1 },  // = 4
  { 1, 0, 1, 1, 0, 1, 1 },  // = 5
  { 1, 0, 1, 1, 1, 1, 1 },  // = 6
  { 1, 1, 1, 0, 0, 0, 0 },  // = 7
  { 1, 1, 1, 1, 1, 1, 1 },  // = 8
  { 1, 1, 1, 0, 0, 1, 1 },  // = 9
};


// IR
uint8_t ir_pins[2][2] = {
  { 2, 0 },
  { 3, 1 },
};

#define P1_PIN_IR 2
#define P1_PIN_DETECT 0

#define P2_PIN_IR 3
#define P2_PIN_DETECT 2
#define P2_PIN_STATUS 13

// Buttons
#define PIN_RESET 57
#define PIN_POWER 58

#define P1_PIN_INCREASE 53
#define P1_PIN_DECREASE 54

#define P2_PIN_INCREASE 55
#define P2_PIN_DECREASE 56

void setup() {
  // debug
  Serial.begin(9600);

  // IR
  pinMode(P1_PIN_IR, OUTPUT);
  pinMode(P1_PIN_DETECT, INPUT);
  digitalWrite(P1_PIN_IR, 1); // led always on

/*
  // IR
  for (byte player = 0; player < 2; ++player) {
    pinMode(ir_pins[player][1], INPUT);
    pinMode(ir_pins[player][0], OUTPUT);
    digitalWrite(ir_pins[player][0], 1); // led always on
  }
*/
/*
  // seven segment display
  for (byte player = 0; player < 2; ++player) {
    for (byte pin = 0; pin < 7; ++pin) {
      pinMode(seven_seg_pins[player][pin], OUTPUT);
    }
  }
*/
  // Buttons
  pinMode(P1_PIN_INCREASE, INPUT);
  pinMode(P1_PIN_DECREASE, INPUT);
}

void displayScore(byte player, byte number) {
  for (byte pin = 0; pin < 7; ++pin) {
    digitalWrite(seven_seg_pins[player][pin], seven_seg_digits[number][pin]);
  }
}

void debugScore() {
  Serial.print("Score: ");
  Serial.print(p1_score);
  Serial.print(" ");
  Serial.print(p2_score);
  Serial.println();
}

void loop() {
  // detect button presses
  byte p1_increase = digitalRead(P1_PIN_INCREASE);
  if (p1_increase) {
    ++p1_score;
    debugScore();
    //displayScore(P1, p1_score);
    delay(500);
  }

  // detect if any goals have been scored
  int p2_goal = analogRead(P1_PIN_DETECT);
  Serial.println(p2_goal);
/*
  if (p2_goal == 0) {
    ++p2_score;
    debugScore();
    delay(1500);
  }
*/
  delay(100);
}

