/*
  Motor.h - Library for working with the Cytron SPG30E-30K or other DC motor with quadrant encoder.
  Created by Vinay Lanka, January 27, 2021.
  
  Update - Dingo 21 November 2021
  + en_a and en_b updated to enc_a and enc_b to avoid confusion with "Enable A and Enable B on the L293D motor driver (which is not used)
  + comments update with details
*/
#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor {
  public:
    //Constructor for Motor - 'Plus' and 'Minus' are the Motor pins to connect the output to / enc_a and enc_b are the encoder inputs
    Motor(int plus, int minus, int enc_a, int enc_b);
    
    //Rotate motor shaft based on a percentage value
    void rotate(int value);
    
    //Motor Outputs - plus is one direction and minus is the other
    int plus;
    int minus;
    
    //Encoder Inputs
    int enc_a;
    int enc_b;
};

#endif
