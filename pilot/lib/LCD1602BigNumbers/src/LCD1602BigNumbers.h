/*
  LCD1602BigNumbers.h - Library for displaying large numbers on LCD1602 displays.
  LCD1602BigNumbers.cpp - Library for displaying large numbers on LCD1602 displays.
  @author Robert W.B. Linn @ www.rwblinn.de
  @since 20170130
*/

#ifndef LCD1602BigNumbers_h
#define LCD1602BigNumbers_h

#include "Arduino.h"
#include "LiquidCrystal.h"

class LCD1602BigNumbers
{
  public:
    LCD1602BigNumbers(LiquidCrystal*);
  	void begin();
		void writeBigNumber(int num, byte col,byte max);
  private:
    LiquidCrystal* _lcd;
};

#endif
