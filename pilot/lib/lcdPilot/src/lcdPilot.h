/*
  LCD1602BigNumbers.h - Library for displaying large numbers on LCD1602 displays.
  LCD1602BigNumbers.cpp - Library for displaying large numbers on LCD1602 displays.
  @author Robert W.B. Linn @ www.rwblinn.de
  @since 20170130
*/

#ifndef lcdPilot_h
#define lcdPilot_h

#include "Arduino.h"
#include "LiquidCrystal.h"

class lcdPilot
{
  public:
    lcdPilot(LiquidCrystal*);
  	void begin();
		void set(int num);
  private:
    LiquidCrystal* _lcd;
};

#endif
