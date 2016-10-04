/*
 * Relevant parts were stolen from the arduino IRremote library
 */

#ifndef IRsender_h
#define IRsender_h

class IRsender
{
 public:
  IRsender() { }

  void enable_send_on_pin_11(void);
  void enable_send_on_pin_9(void);
};

#endif
