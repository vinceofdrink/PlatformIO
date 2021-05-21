/*
  LCD1602BigNumbers.cpp - Library for displaying large numbers on LCD1602 displays.
  @author Robert W.B. Linn @ www.rwblinn.de
  @since 20170130
*/

#include "LCD1602BigNumbers.h"

byte custchar[8][8] = {
    {
        B11111,
        B11111,
        B11111,
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
        B11111,
        B11111,
        B11111
    }, {
        B11111,
        B11111,
        B11111,
        B00000,
        B00000,
        B11111,
        B11111,
        B11111
    }, {
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B01110,
        B01110,
        B01110
    }, {
        B00000,
        B00000,
        B00000,
        B01110,
        B01110,
        B01110,
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

byte bignumbers[10][2][3] = {
    {
        {255, 0, 255},
        {255, 1, 255}
    }, {
        {0, 255, 254},
        {1, 255, 1}
    }, {
        {2, 2, 255},
        {255, 1, 1}
    }, {
        {0, 2, 255},
        {1, 1, 255}
    }, {
        {255, 1, 255},
        {254, 254, 255}
    }, {
        {255, 2, 2},
        {1, 1, 255}
    }, {
        {255, 2, 2},
        {255, 1, 255}
    }, {
        {0, 0, 255},
        {254, 255, 254}
    }, {
        {255, 2, 255},
        {255, 1, 255}
    }, {
        {255, 2, 255},
        {254, 254, 255}
    }
};

// Creates the LCD1602BigNumbers object
// LiquidCrystal* lcd: LiquidCrystal object to use
LCD1602BigNumbers::LCD1602BigNumbers(LiquidCrystal* lcd)
{
  _lcd = lcd;
}

// Loads the custom characters used to build big numbers
void LCD1602BigNumbers::begin()
{
	for (int i = 0; i < 8; i++)
		_lcd->createChar(i, custchar[i]);
    _lcd->home();
}

// Writes a number 0 - 9 at position col & row
// number - the number to display
// col - column of upper left corner of first large character
void LCD1602BigNumbers::writeBigNumber(int num, byte col, byte max) {
    byte slice;
    while(max!=0) {
        max--;
        if(num>9) {
            slice=num%10;
            num=num/10;
        } else {
            if (num == 0 ) {
                 slice=11;
            } else { 
                slice=num;
                num=0;
            }
        }

		byte row = 0;
        for (int i = 0; i < 2; i++) {
            _lcd->setCursor(col, row + i);
            for (int j = 0; j < 3; j++) {
                if(slice == 11) {
                     _lcd->write(254);
                } else {
                _lcd->write(bignumbers[slice][i][j]);
                }
            }
       
           
    }
    col=col-4;
    }
}


