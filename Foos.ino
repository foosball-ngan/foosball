#include <IRremote.h>
#include <IRremoteInt.h>

#include <IRremote2.h>
#include <IRremoteInt2.h>

#include "Button.h"

// Game
#define P1 0
#define P2 1

#define SCORE_DELAY 1500

byte p1_score = 0;
byte p2_score = 0;

// Seven Segment
byte seven_seg_pins[2][7] = {
  { 38, 36, 34, 32, 30, 40, 42 }, // top, top-right, bottom-right, bottom, bottom-left, top-left, middle
  { 41, 43, 31, 33, 35, 39, 37 },
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
IRsend irsend;  // pin 3 on uno, pin 9 on mega
IRsend2 irsend2; // pin 11 on mega
#define P1_PIN_DETECT 0
#define P2_PIN_DETECT 1

// Buttons
Button button_reset(50);
Button button_p1_increase(51);
Button button_p1_decrease(52);
Button button_p2_increase(53);
Button button_p2_decrease(22);

void setup() {
  // debug
  Serial.begin(9600);

  // IR
  pinMode(P1_PIN_DETECT, INPUT);
  pinMode(P2_PIN_DETECT, INPUT);
  irsend.enableIROut(38);
  irsend.mark(0);
  irsend2.enableIROut(38);
  irsend2.mark(0);

  // seven segment display
  for (byte player = 0; player < 2; ++player) {
    for (byte pin = 0; pin < 7; ++pin) {
      pinMode(seven_seg_pins[player][pin], OUTPUT);
    }
  }

  // reset scores
  p1_score = 0;
  p2_score = 0;
  displayScore(P1, p1_score);
  displayScore(P2, p2_score);
}

void debugScore() {
  Serial.print("Score: ");
  Serial.print(p1_score);
  Serial.print(" ");
  Serial.print(p2_score);
  Serial.println();
}

void displayScore(byte player, byte number) {
  debugScore();

  for (byte pin = 0; pin < 7; ++pin) {
    digitalWrite(seven_seg_pins[player][pin], seven_seg_digits[number][pin]);
  }
}

void loop() {
  // detect button presses
/*
  if (button_reset.pressed()) {
    p1_score = 0;
    p2_score = 0;
    displayScore(P1, p1_score);
    displayScore(P2, p2_score);
  }*/
/*
  if (button_p1_increase.pressed()) {
    ++p1_score;
    displayScore(P1, p1_score);
  }

  if (button_p1_decrease.pressed()) {
    --p1_score;
    displayScore(P1, p1_score);
  }

  if (button_p2_increase.pressed()) {
    ++p2_score;
    displayScore(P2, p2_score);
  }

  if (button_p2_decrease.pressed()) {
    --p2_score;
    displayScore(P2, p2_score);
  }
 */
/*
  // detect if any goals have been scored
  int p1_goal = analogRead(P2_PIN_DETECT);
  //Serial.println(p1_goal);
  if (p1_goal > 0) {
    ++p1_score;
    p1_score %= 10;
    displayScore(P1, p1_score);
    delay(SCORE_DELAY);
    //return;
  }
*/

  int p2_goal = analogRead(P1_PIN_DETECT);
  //Serial.println(p2_goal);
  if (p2_goal > 1000) {
    ++p2_score;
    p2_score %= 10;
    displayScore(P2, p2_score);
    delay(SCORE_DELAY);
    return;
  }


  int p1_goal = analogRead(P2_PIN_DETECT);
  //Serial.println(p1_goal);
  if (p1_goal > 1000) {
    ++p1_score;
    p1_score %= 10;
    displayScore(P1, p1_score);
    delay(SCORE_DELAY);
    return;
  }

  //delay(50);
}

