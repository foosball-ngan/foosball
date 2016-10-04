/*
 * Relevant parts were stolen from the arduino IRremote library
 */

#ifndef IRsend_h
#define IRsend_h

class IRsend
{
 public:
  IRsend () { }

  void enable_send_on_pin_11(void);
  void enable_send_on_pin_9(void);
};

#endif
