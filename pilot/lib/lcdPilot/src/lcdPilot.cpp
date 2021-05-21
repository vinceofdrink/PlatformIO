/*
  LCD1602BigNumbers.cpp - Library for displaying large numbers on LCD1602 displays.
  @author Robert W.B. Linn @ www.rwblinn.de
  @since 20170130
*/

#include "lcdPilot.h"

byte lcdPilot_custchar[8][8] = {
    {
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00100,
        B00100
    }, {
        B10000,
        B10000,
        B10000,
        B10000,
        B10000,
        B10000,
        B00100,
        B00100
    }, {
        B00100,
        B00100,
        B00100,
        B00100,
        B00100,
        B00100,
        B00100,
        B00100
    }, {
        B00001,
        B00001,
        B00001,
        B00001,
        B00001,
        B00001,
        B00100,
        B00100
    }, {
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00100,
        B00100
    }, {
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000
    }, {
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000
    }, {
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000
    }
};


// Creates the LCD1602BigNumbers object
// LiquidCrystal* lcd: LiquidCrystal object to use
lcdPilot::lcdPilot(LiquidCrystal* lcd)
{
  _lcd = lcd;
}

// Loads the custom characters used to build big numbers
void lcdPilot::begin()
{
	for (int i = 0; i < 8; i++)
		_lcd->createChar(i, lcdPilot_custchar[i]);
    _lcd->home();
     _lcd->setCursor(1,0);
    for(byte i=0;i<20;i++) {
    }
}

// Writes a number 0 - 9 at position col & row
// number - the number to display
// col - column of upper left corner of first large character
void lcdPilot::set(int num) {
            _lcd->setCursor(0,0);
            byte fontnum = num%3 +1;


            for(byte i=0;i<20;i++) {
               
                    _lcd->write(fontnum);
                }
                
            
            

    
            // _lcd->setCursor(0,0);
            // for(byte i=0;i<20;i++) {
            //     switch  ( num - (i*3) )
            //     {
            //     case 0:
            //          _lcd->write(1);
            //          break;
            //     case 1:
            //         _lcd->write(2);
            //          break;
            //     case 2:
            //         _lcd->write(3);
            //          break;

            //     default:
            //         _lcd->write((int)0);
            //     }
                
            // }
            
            
            
}


