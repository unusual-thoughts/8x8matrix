/*  Copyright (c) 2009 by Alex Leone <acleone ~AT~ gmail.com>

    This file is part of the Arduino TLC5947 Library.

    The Arduino TLC5947 Library is free software: you can redistribute it
    and/or modify it under the terms of the GNU General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    The Arduino TLC5947 Library is distributed in the hope that it will be
    useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with The Arduino TLC5947 Library.  If not, see
    <http://www.gnu.org/licenses/>. */

#ifndef TLC5947_H
#define TLC5947_H

/** \file
    Tlc5947 library header file. */

#include <stdint.h>
#include "tlc_config.h"

extern volatile void (*tlc_onUpdateFinished)(void);
extern uint8_t tlc_GSData[8 * 36];
#if NUM_ROWS != 1
extern volatile uint8_t current_row;
#endif


/** The main Tlc5947 class for the entire library.  An instance of this class
    will be preinstantiated as Tlc. */
class Tlc5947
{
  public:
    void init(uint16_t initialValue = 0);
    void clear(void);
    uint8_t update(uint8_t row);
    void set(TLC_CHANNEL_TYPE channel, uint8_t row, uint16_t value);
    uint16_t get(TLC_CHANNEL_TYPE channel, uint8_t row);
    void setAll(uint16_t value);
    void shift8_init(void);
    void shift8(uint8_t byte);
#if NUM_ROWS != 1
    void setRow(uint8_t row);
    void shiftLeft();
    void shiftRight();
    void setLED(uint8_t lednum, uint8_t row, uint16_t r, uint16_t g, uint16_t b);
    void setAllLED(uint16_t r, uint16_t g, uint16_t b);
#endif
};

//void tlc_shift8_init(void);
//void tlc_shift8(uint8_t byte);

// for the preinstantiated Tlc variable.
extern Tlc5947 Tlc;

#endif

