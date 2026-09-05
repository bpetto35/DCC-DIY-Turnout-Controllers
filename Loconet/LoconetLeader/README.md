# Loconet Leader

## Attribution/Licence
This project is largely inspired by the project **[arduino-loconetshield](https://github.com/lucadentella/arduino-loconetshield)** by [lucadentella](https://github.com/lucadentella), under **[CC BY 4.0](https://creativecommons.org/licenses/by/4.0/)** license.
It largely use the data and electronic schematics.

## Features
### Loconet Header
- receive the RJ12 connector
- send/receive Loconet messages over pin 3 and 4
- pin 2 and 5 are set to the ground
- pin 1 and 6 are set to the DC12V

### Loconet Master
- header H1 allow to set/unset the loconet master as indicated in **[arduino-loconetshield](https://github.com/lucadentella/arduino-loconetshield)** by [lucadentella](https://github.com/lucadentella)
- the R3 and R4 generate 13mA of consumption with the DC 12V

### Loconet Read/Write
- signal LNET can be the write from D1 or a value to read in D0
- it is the same schematics I have copied from **[arduino-loconetshield](https://github.com/lucadentella/arduino-loconetshield)** by [lucadentella](https://github.com/lucadentella)

### DC12 Header
- a simple DC barrel with some condensators to smooth the voltage

### Power LED and Reset
- the LED is ON when Arduino is ON on the USB or own DC barrel
- the reset allow to restart the sketch

## What change
- Master loconet in Arduino shield form factor
- Use **SMD** components instead of **through-hole**
- Remove the 12V header and just keep the barrel

## Arduino code
- bridge between the Serial/USB and the Serial1/UART of the Arduino Uno R4 Minima
- Serial/USB can be connected to a PC with JMRI
- Serial1/UART will be connected to the RJ12 and loconet bus

## Schematics
![LoconetLeader Schematics](/Loconet/LoconetLeader/images/Schematic_Loconet-Master-Shield_2026-09-03.png?raw=true)