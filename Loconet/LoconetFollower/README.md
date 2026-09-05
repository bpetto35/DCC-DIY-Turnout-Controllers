# Loconet Follower

No Arduino sketch in this part, the usage is in the user shield.
This should be a top shield and with the U shape, it shoudl allow intermediate shield to be accessible.

## Attribution/Licence
This project is largely inspired by the project **[arduino-loconetshield](https://github.com/lucadentella/arduino-loconetshield)** by [lucadentella](https://github.com/lucadentella), under **[CC BY 4.0](https://creativecommons.org/licenses/by/4.0/)** license.
It largely use the data and electronic schematics.

## Features
### Loconet Header
- allow 2 RJ12 connector to cascade Loconet device
- send/receive Loconet messages over pin 3 and 4
- pin 2 and 5 not used
- pin 1 and 6 not used

Both RJ12 can receive and send messages

### Loconet Read/Write
- signal LNET can be the write from D1 or a value to read in D0
- it is the same schematics I have copied from **[arduino-loconetshield](https://github.com/lucadentella/arduino-loconetshield)** by [lucadentella](https://github.com/lucadentella)

### Power LED and Reset
- the LED is ON when Arduino is ON on the USB or own DC barrel
- the reset allow to restart the sketch

### LNCV programmation indicator
- [2026/09/05] add a LED on pin D13 (LED_BUILTIN) to indicate when the device is in LoconetCV programmation mode

## Schematics
![LoconetFollower Schematics](/Loconet/LoconetFollower/images/Schematic_Loconet-Turnout-Shield_2026-09-05.png?raw=true)