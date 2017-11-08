Backpack for 8x8 RGB LED matrix
==============================

This is a simple breakout board for 8x8 RGB matrices like the [GTM2088ARGB](http://www.ebay.com/itm/5mm-8x8-Matrix-RGB-LED-Common-Anode-Full-Colour-60-60mm-/370699782315)  
It uses a [TLC5947](http://www.ti.com/product/tlc5947) that provides 24 12 bit current sink PWM channels, and a 74HC138 3 to 8 line decoder followed by P-channel MOSFETs to drive the rows.  

![schematic](prints/schematic.png)

The needed Eagle libraries are in `eagle-lbr/`  
The whole thing fits on a single layer PCB.  
The matrix is controlled through the 9-pin header with this pinout:

Pin number	| Label	| Description
----------	| -----	| -----------
1			| A2	| row higher bit
2			| A1	| row middle bit
3			| A0	| row lower bit
4			| SIN	| TLC data (24x12 bit = 36 bytes)
5			| SCLK	| TLC clock
6			| BLANK	| TLC blank columns and reset PWM timer
7			| GND	| Ground
8			| VCC	| +5V
9			| XLAT	| TLC latch data

To get everything to fit on a single sided board, I had to make weird column and row assignments:

A0	| A1	| A2	| Row Number
--- | ---	| ---	| ----------
0	| 0		| 0		| 2
0	| 0		| 1		| 1
0	| 1		| 0		| 0
0	| 1		| 1		| 7
1	| 0		| 0		| 4
1	| 0		| 1		| 5
1	| 1		| 0		| 6
1	| 1		| 1		| 3

TLC channel	| Columns
----------  | ------
0-7			| Red 0-7
8-15		| Blue 0-7
16-23		| Green 7-0 (inverted order)

The `arduino-lbr/` directory contatins a modified version of the Tlc5940 library by Alex Leone, named Tlc5947. Like its counterpart, it can use arduino hardware spi to speed things up to an acceptable refresh rate. The basic bitbang code flickers quite a bit, even with direct port manipulation.

The `arduino/` directory contains a demo arduino sketch using that library.

![layers](prints/layers.gif)
