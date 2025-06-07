USB printer emulator
====================

A simple device emulating a parallel printer and passing the data over USB using CDC-ACM serial port. Can be implemented on a cheap CH552 development board with a 7400 chip and an optional pull-up resistor.
 
Based on USB-CDC to I2C Bridge by Stefan Wagner (https://github.com/wagiminator/CH552-USB-OLED).

Distributed under Creative Commons Attribution-ShareAlike 3.0 Unported License (http://creativecommons.org/licenses/by-sa/3.0/).

Schematic:
```
                 4k7
           +----#####------------ VCC
           |
BUSY ---------------------+
______     |     ___      |
STROBE ----+----|   \     |
                |    o----+------ P3.4
           +----|___/     |
           |_____   ______|
                 \ /
                  X
            _____/ \______
           |     ___      |
           +----|   \     |
                |    o----+
           +----|___/
___        |
ACK -------+--------------------- P1.1

D0 ------------------------------ P3.0
D1 ------------------------------ P3.1
D2 ------------------------------ P3.2
D3 ------------------------------ P3.3
D4 ------------------------------ P1.4
D5 ------------------------------ P1.5
D6 ------------------------------ P1.6
D7 ------------------------------ P1.7
```
