#include "BTS7960.h"

BTS7960 m1(0, 3, 5);
BTS7960 m2(1, 9, 10);
BTS7960 m3(2, 11, 13);




void setup_act(){
pinMode(A4, INPUT_PULLUP);
  
TCCR3B = (TCCR3B & 0b11111000) | 0x01;  // Configura prescaler para 1

// Alterar a frequência PWM do pino 9 e 10 (Timer 1) para 18 kHz
TCCR1B = (TCCR1B & 0b11111000) | 0x01;  // Configura prescaler para 1

// Alterar a frequência PWM do pino 3 e 11 (Timer 0) para 18 kHz
TCCR0B = (TCCR0B & 0b11111000) | 0x01;  // Configura prescaler para 1

// Alterar a frequência PWM do pino 6 (Timer 4) para 18 kHz
TCCR4B = (TCCR4B & 0b11111000) | 0x01;  // Configura prescaler para 1
}
void loop_act(){


  if (digitalRead(A4) == LOW) {
    m1.Enable();
    m2.Enable();
    m3.Enable();
  } else {
    m1.Disable();
    m2.Disable();
    m3.Disable();
  }

  
}

void go_act(int xx, int yy, int zz) {
  xx = map(xx, -100, 100, -255, 255);
  
  if (xx >= 0) {
    m1.TurnRight(xx);
  } else {
    m1.TurnLeft(xx);
  }

  yy = map(yy, -100, 100, -255, 255);
  if (yy >= 0) {
    m2.TurnRight(yy);
  } else {
    m2.TurnLeft(yy);
  }

  zz = map(zz, -100, 100, -255, 255);
  if (zz >= 0) {
    m3.TurnRight(zz);
  } else {
    m3.TurnLeft(zz);
  }
}