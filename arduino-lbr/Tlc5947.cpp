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

/** \file
    Tlc5947 class functions. */

#include <avr/io.h>
#include <avr/interrupt.h>

#include "tlc_config.h"
#include "Tlc5947.h"

/** Pulses a pin - high then low. */
#define pulse_pin(port, pin)   port |= _BV(pin); port &= ~_BV(pin)

/** Some of the extened library will need to be called after a successful
    update. */
volatile void (*tlc_onUpdateFinished)(void);

/* for led matrices, counts the row being updated */
#if NUM_ROWS != 1
volatile uint8_t current_row = 0;
#endif

/** Packed grayscale data, 36 bytes (24 * 12 bits) per TLC.

    Format: Lets assume we have 2 TLCs, A and B, daisy-chained with the SOUT of
    A going into the SIN of B.
    - byte 0: upper 8 bits of B.15
    - byte 1: lower 4 bits of B.15 and upper 4 bits of B.14
    - byte 2: lower 8 bits of B.14
    - ...
    - byte 36: upper 8 bits of A.15
    - byte 37: lower 4 bits of A.15 and upper 4 bits of A.14
    - ...
    - byte 71: lower 8 bits of A.0

    \note Normally packing data like this is bad practice.  But in this
          situation, shifting the data out is really fast because the format of
          the array is the same as the format of the TLC's serial interface. */
uint8_t tlc_GSData[36 * NUM_ROWS];

#if NUM_ROWS != 1
ISR(TIMER2_COMPA_vect){
   BLANK_PORT |= _BV(BLANK_PIN);
   Tlc.setRow(current_row);
   Tlc.update(current_row);
   BLANK_PORT &= ~_BV(BLANK_PIN);
   current_row++;
   current_row %= NUM_ROWS;
}
#endif

/** \defgroup CoreFunctions Core Libary Functions
    These function are all prefixed with "Tlc." */
/* @{ */

/** Pin i/o and Timer setup.  The grayscale register will be reset to all
    zeros, or whatever initialValue is set to and the Timers will start.
    \param initialValue = 0, optional parameter specifing the inital startup
           value */
void Tlc5947::init(uint16_t initialValue)
{
    /* Pin Setup */
    XLAT_DDR |= _BV(XLAT_PIN);
    BLANK_DDR |= _BV(BLANK_PIN);
    BLANK_PORT |= _BV(BLANK_PIN); // leave blank high (until the timers start)
#if NUM_ROWS != 1
    A0_DDR |= _BV(A0_PIN);
    A1_DDR |= _BV(A1_PIN);
    A2_DDR |= _BV(A2_PIN);
#endif
    shift8_init();

    setAll(initialValue);
    update(0);

    /* Timer 1 setup for matrices */
#if NUM_ROWS != 1
    cli();//stop interrupts

/*
    //set timer1 interrupt at 350Hz
    TCCR1A = 0;// set entire TCCR1A register to 0
    TCCR1B = 0;// same for TCCR1B
    TCNT1  = 0;//initialize counter value to 0
    // set compare match register for 1hz increments
    OCR1A = 32000; //45713;// = (16*10^6) / 350 - 1 (must be <65536)
    // turn on CTC mode
    TCCR1B |= (1 << WGM12);
    // Set CS10 for no prescaler
    TCCR1B |= (1 << CS10);  
    // enable timer compare interrupt
    TIMSK1 |= (1 << OCIE1A);
*/
    //set timer2 interrupt at 500Hz
    TCCR2A = 0;// set entire TCCR1A register to 0
    TCCR2B = 0;// same for TCCR1B
    TCNT2  = 0;//initialize counter value to 0
    // set compare match register
    OCR2A = 30; //45713;// = (16*10^6) / 1024 / 500 - 1 (must be <256)
    // turn on CTC mode
    TCCR2A |= (1 << WGM21);
    // Set CS20, CS21 and CS22 for 1024 prescaler
    TCCR2B |= (1 << CS20);
    TCCR2B |= (1 << CS21);  
    TCCR2B |= (1 << CS22);
    // enable timer compare interrupt
    TIMSK2 |= (1 << OCIE2A);

    sei();//allow interrupts
#endif
}

/** Clears the grayscale data array, #tlc_GSData, but does not shift in any
    data.  This call should be followed by update() if you are turning off
    all the outputs. */
void Tlc5947::clear(void)
{
    setAll(0);
}

/** Shifts in the data from the grayscale data array, #tlc_GSData.
    If data has already been shifted in this grayscale cycle, another call to
    update() will immediately return 1 without shifting in the new data.  To
    ensure that a call to update() does shift in new data, use
    \code while(Tlc.update()); \endcode
    or
    \code while(tlc_needXLAT); \endcode
    \returns 1 if there is data waiting to be latched, 0 if data was
             successfully shifted in */
uint8_t Tlc5947::update(uint8_t row)
{
    uint8_t *p = tlc_GSData + 36 * row;
    while (p < tlc_GSData + 36 * (row + 1)) {
        shift8(*p++);
        shift8(*p++);
        shift8(*p++);
    }
    

    //BLANK_PORT |= _BV(BLANK_PIN);
    pulse_pin(XLAT_PORT, XLAT_PIN);
    //pulse_pin(BLANK_PORT, BLANK_PIN);
    //BLANK_PORT &= ~_BV(BLANK_PIN);
    return 0;
}

/** Sets channel to value in the grayscale data array, #tlc_GSData.
    \param channel (0 to 23).  OUT0 of the first TLC is
           channel 0, OUT0 of the next TLC is channel 24, etc.
    \param value (0-4095).  The grayscale value, 4095 is maximum.
    \see get */
void Tlc5947::set(TLC_CHANNEL_TYPE channel, uint8_t row, uint16_t value)
{
    TLC_CHANNEL_TYPE index8 = 23 - channel;
    uint8_t *index12p = tlc_GSData + 36 * row + ((((uint16_t)index8) * 3) >> 1);
    if (index8 & 1) { // starts in the middle
                      // first 4 bits intact | 4 top bits of value
        *index12p = (*index12p & 0xF0) | (value >> 8);
                      // 8 lower bits of value
        *(++index12p) = value & 0xFF;
    } else { // starts clean
                      // 8 upper bits of value
        *(index12p++) = value >> 4;
                      // 4 lower bits of value | last 4 bits intact
        *index12p = ((uint8_t)(value << 4)) | (*index12p & 0xF);
    }
}


/** Gets the current grayscale value for a channel
    \param channel (0 to 23).  OUT0 of the first TLC is
           channel 0, OUT0 of the next TLC is channel 24, etc.
    \returns current grayscale value (0 - 4095) for channel
    \see set */
uint16_t Tlc5947::get(TLC_CHANNEL_TYPE channel, uint8_t row)
{
    TLC_CHANNEL_TYPE index8 = 23 - channel;
    uint8_t *index12p = tlc_GSData + 36 * row + ((((uint16_t)index8) * 3) >> 1);
    return (index8 & 1)? // starts in the middle
            (((uint16_t)(*index12p & 15)) << 8) | // upper 4 bits
            *(index12p + 1)                       // lower 8 bits
        : // starts clean
            (((uint16_t)(*index12p)) << 4) | // upper 8 bits
            ((*(index12p + 1) & 0xF0) >> 4); // lower 4 bits
    // that's probably the ugliest ternary operator I've ever created.
}

/** Sets all channels to value.
    \param value grayscale value (0 - 4095) */
void Tlc5947::setAll(uint16_t value)
{
    uint8_t row;
    uint8_t firstByte = value >> 4;
    uint8_t secondByte = (value << 4) | (value >> 8);
    uint8_t *p = tlc_GSData;
    for(row = 0; row < NUM_ROWS; row++)
    {
        p = tlc_GSData + 36 * row;
        while (p < tlc_GSData + 36 * (row + 1)) {
            *p++ = firstByte;
            *p++ = secondByte;
            *p++ = (uint8_t)value;
        }
    }
}

#if DATA_TRANSFER_MODE == TLC_BITBANG

/** Sets all the bit-bang pins to output */
void Tlc5947::shift8_init(void)
{
    SIN_DDR |= _BV(SIN_PIN);   // SIN as output
    SCLK_DDR |= _BV(SCLK_PIN); // SCLK as output
    SCLK_PORT &= ~_BV(SCLK_PIN);
}

/** Shifts a byte out, MSB first */
void Tlc5947::shift8(uint8_t byte)
{
    for (uint8_t bit = 0x80; bit; bit >>= 1) {
        if (bit & byte) {
            SIN_PORT |= _BV(SIN_PIN);
        } else {
            SIN_PORT &= ~_BV(SIN_PIN);
        }
        pulse_pin(SCLK_PORT, SCLK_PIN);
    }
}

#elif DATA_TRANSFER_MODE == TLC_SPI

/** Initializes the SPI module to double speed (f_osc / 2) */
void Tlc5947::shift8_init(void)
{
    SIN_DDR    |= _BV(SIN_PIN);    // SPI MOSI as output
    SCLK_DDR   |= _BV(SCLK_PIN);   // SPI SCK as output
    TLC_SS_DDR |= _BV(TLC_SS_PIN); // SPI SS as output

    SCLK_PORT &= ~_BV(SCLK_PIN);

    SPSR = _BV(SPI2X); // double speed (f_osc / 2)
    SPCR = _BV(SPE)    // enable SPI
         | _BV(MSTR);  // master mode
}

/** Shifts out a byte, MSB first */
void Tlc5947::shift8(uint8_t byte)
{
    SPDR = byte; // starts transmission
    while (!(SPSR & _BV(SPIF)))
        ; // wait for transmission complete
}

#endif

#if NUM_ROWS != 1
void Tlc5947::setRow(uint8_t row)
{
  switch (row)
  {
    case 0:
      PORTD = (PORTD & ROW_MASK) | (3 << A0_PIN);
      break;
    case 1:
      PORTD = (PORTD & ROW_MASK) | (6 << A0_PIN);
      break;
    case 2:
      PORTD = (PORTD & ROW_MASK) | (5 << A0_PIN);
      break;
    case 3:
      PORTD = (PORTD & ROW_MASK) | (4 << A0_PIN);
      break;
    case 4:
      PORTD = (PORTD & ROW_MASK) | (7 << A0_PIN);
      break;
    case 5:
      PORTD = (PORTD & ROW_MASK) | (0 << A0_PIN);
      break;
    case 6:
      PORTD = (PORTD & ROW_MASK) | (1 << A0_PIN);
      break;
    case 7:
      PORTD = (PORTD & ROW_MASK) | (2 << A0_PIN);
      break;
  }
}

void Tlc5947::shiftLeft()
{
    uint8_t i, row;
    uint8_t temp_row[36];
    for (i = 0; i < 36; i++)
        temp_row[i] = tlc_GSData[i];
    for (row = 1; row < NUM_ROWS; row++)
        for (i = 0; i < 36; i++)
            tlc_GSData[(row - 1) * 36 + i] = tlc_GSData[row * 36 + i];
    for (i = 0; i < 36; i++)
        tlc_GSData[(NUM_ROWS - 1) * 36 + i] = temp_row[i];

}

void Tlc5947::shiftRight()
{
    uint8_t i, row;
    uint8_t temp_row[36];
    for (i = 0; i < 36; i++)
        temp_row[i] = tlc_GSData[(NUM_ROWS - 1) * 36 + i];
    for (row = NUM_ROWS - 1; row > 0; row--)
        for (i = 0; i < 36; i++)
            tlc_GSData[row * 36 + i] = tlc_GSData[(row - 1) * 36 + i];
    for (i = 0; i < 36; i++)
        tlc_GSData[i] = temp_row[i];

}

void Tlc5947::setLED(uint8_t lednum, uint8_t row, uint16_t r, uint16_t g, uint16_t b) {
    set(lednum, row, r);
    set(23 - lednum, row, g);
    set(lednum + 8, row, b);
}

void Tlc5947::setAllLED(uint16_t r, uint16_t g, uint16_t b) {
    for(uint8_t row = 0; row < NUM_ROWS; row++)
    {
        for(uint8_t lednum = 0; lednum < 8; lednum++)
        {
            set(lednum, row, r);
            set(23 - lednum, row, g);
            set(lednum + 8, row, b);
        }
    }
}
#endif

/** Preinstantiated Tlc variable. */
Tlc5947 Tlc;

/** \defgroup ExtendedFunctions Extended Library Functions
    These functions require an include statement at the top of the sketch. */
/* @{ */ /* @} */

/** \mainpage
    The <a href="http://www.ti.com/lit/gpn/TLC5947">Texas Instruments TLC5947
    </a> is a 16-channel, constant-current sink LED driver.  Each channel has
    an individually adjustable 4096-step grayscale PWM brightness control and
    a 64-step, constant-current sink (no LED resistors needed!).  This chip
    is a current sink, so be sure to use common anode RGB LEDs.

    Check the <a href="http://code.google.com/p/tlc5940arduino/">tlc5940arduino
    project</a> on Google Code for updates.  To install, unzip the "Tlc5947"
    folder to &lt;Arduino Folder&gt;/hardware/libraries/

    &nbsp;

    \section hardwaresetup Hardware Setup
    The basic hardware setup is explained at the top of the Examples.  A good
    place to start would be the BasicUse Example.  (The examples are in
    File->Sketchbook->Examples->Library-Tlc5947).

    All the options for the library are located in tlc_config.h, including
    #NUM_TLCS, what pins to use, and the PWM period.  After changing
    tlc_config.h, be sure to delete the Tlc5947.o file in the library folder
    to save the changes.

    &nbsp;

    \section libref Library Reference
    \ref CoreFunctions "Core Functions" (see the BasicUse Example and Tlc5947):
    - \link Tlc5947::init Tlc.init(int initialValue (0-4095))\endlink - Call this is
            to setup the timers before using any other Tlc functions.
            initialValue defaults to zero (all channels off).
    - \link Tlc5947::clear Tlc.clear()\endlink - Turns off all channels
            (Needs Tlc.update())
    - \link Tlc5947::set Tlc.set(uint8_t channel (0-(NUM_TLCS * 16 - 1)),
            int value (0-4095))\endlink - sets the grayscale data for channel.
            (Needs Tlc.update())
    - \link Tlc5947::setAll Tlc.setAll(int value(0-4095))\endlink - sets all
            channels to value. (Needs Tlc.update())
    - \link Tlc5947::get uint16_t Tlc.get(uint8_t channel)\endlink - returns
            the grayscale data for channel (see set).
    - \link Tlc5947::update Tlc.update()\endlink - Sends the changes from any
            Tlc.clear's, Tlc.set's, or Tlc.setAll's.

    \ref ExtendedFunctions "Extended Functions".  These require an include
    statement at the top of the sketch to use.

    \ref ReqVPRG_ENABLED "Functions that require VPRG_ENABLED".  These
    require VPRG_ENABLED == 1 in tlc_config.h

    &nbsp;

    \section expansion Expanding the Library
    Lets say we wanted to add a function like "tlc_goCrazy(...)".  The first
    thing to do is to create a source file in the library folder,
    "tlc_my_crazy_functions.h".
    A template for this .h file is
    \code
// Explination for my crazy function extension

#ifndef TLC_MY_CRAZY_FUNCTIONS_H
#define TLC_MY_CRAZY_FUNCTIONS_H

#include "tlc_config.h"
#include "Tlc5947.h"

void tlc_goCrazy(void);

void tlc_goCrazy(void)
{
    uint16_t crazyFactor = 4000;
    Tlc.clear();
    for (uint8_t channel = 4; channel < 9; channel++) {
        Tlc.set(channel, crazyFactor);
    }
    Tlc.update();
}

#endif
 * \endcode
 * Now to use your library in a sketch, just add
 * \code
#include "tlc_my_crazy_functions.h"

// ...

tlc_goCrazy();
    \endcode
    If you would like to share your extended functions for others to use,
    email me (acleone ~AT~ gmail.com) with the file and an example and I'll
    include them in the library.

    &nbsp;

    \section bugs Contact
    If you found a bug in the library, email me so I can fix it!
    My email is acleone ~AT~ gmail.com

    &nbsp;

    \section license License - GPLv3
    Copyright (c) 2009 by Alex Leone <acleone ~AT~ gmail.com>

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

