#include "IRsender.h"
#include <Arduino.h>

#define IR_FREQUENCY_KHZ (38)

void IRsender::enable_send_on_pin_11()
{
  // Disable timer interrupt
  TIMSK1 = _BV(OCIE1A);
  
  // Setup pins
  pinMode(11, OUTPUT);
  digitalWrite(11, LOW);     // When not sending PWM, we want it low

  // Setup frequency
  TCCR1A = _BV(WGM11);
  TCCR1B = _BV(WGM13) | _BV(CS10);
  ICR1 = F_CPU / 2000 / 38;
  OCR1A = F_CPU / 2000 / 38 / 3;
  
  // Enable PWM (i.e. GO!!)
  TCCR1A |= _BV(COM1A1);
}

void IRsender::enable_send_on_pin_9()
{
  // Disable timer interrupt
  TIMSK2 = 0;
  
  // Setup pins
  pinMode(9, OUTPUT);
  digitalWrite(9, LOW);     // When not sending PWM, we want it low

  // Setup frequency
  TCCR2A = _BV(WGM21);
  TCCR2B = _BV(CS21);
  OCR2A  = F_CPU * 50 / 1000000 / 8;
  TCNT2  = 0;
  
  // Enable PWM (i.e. GO!!)
  TCCR2A |= _BV(COM2B1);
}



