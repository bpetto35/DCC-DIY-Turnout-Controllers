# Arduino LocoNet Shields

I will present 2 shields in this part.
- Loconet Leader (from **[arduino-loconetshield](https://github.com/lucadentella/arduino-loconetshield)**)
- Turnout Loconet

## Loconet Leader
### Attribution/Licence
This project is largely inspired by the project **[arduino-loconetshield](https://github.com/lucadentella/arduino-loconetshield)** by [lucadentella](https://github.com/lucadentella), under **[CC BY 4.0](https://creativecommons.org/licenses/by/4.0/)** license.
It largely use the data and electronic schematics.

The Arduino ino sketch is original and use the mrrwa/Loconet2 lib.

### Features
- read from Serial1 or USB Loconet messages
- write to USB or Serial1 Loconet messages
- Serial1 connect to a RJ12 connector (pin 3 and pin 4)
- Send the 12V DC in pin 1 and pin 6 and GND to pin 2 and pin 5 to emulate a Loconet T

### What change
- in Arduino shield form factor
- use **SMD** components instead of **through-hole**
- reuse the loconet schematics for
  - read/write
  - consume few milli amps
  - 12V barrel
- remove the 12V header and just keep the barrel

## Loconet Follower
### Attribution/Licence
This project is largely inspired by the project **[arduino-loconetshield](https://github.com/lucadentella/arduino-loconetshield)** by [lucadentella](https://github.com/lucadentella), under **[CC BY 4.0](https://creativecommons.org/licenses/by/4.0/)** license.
It largely use the data and electronic schematics.

### Features
- 2 RJ12 connectors
- read from and write to Serial1 Loconet messages
- Serial1 connect to two RJ12 connectors (pin 3 and pin 4)

### What change
- in Arduino shield form factor
- use **SMD** components instead of **through-hole**
- only reuse the read/write

## Turnout Command
This shield is fully original and based on my previous work for Fleischmann or Kato Arduino shields.
The Arduino ino sketch is original and use the mrrwa/Loconet2 lib.
This shield need to be stack with a Loconet Follower to be fully functional.

### Features
- support 4 turnouts per shield
- a turnout is composed of 1 momentary button and 2 LEDs
- read button state and send a message onto the Loconet bus
- from Loconet message, write the output to light one of the 2 LEDs
- allow LNCV to configure addresses
