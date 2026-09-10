# Loconet Leader

## Attribution/Licence
This project is largely inspired by the project **[arduino-loconetshield](https://github.com/lucadentella/arduino-loconetshield)** by [lucadentella](https://github.com/lucadentella), under **[CC BY 4.0](https://creativecommons.org/licenses/by/4.0/)** license.
It largely use the data and electronic schematics.

## Features

### Changelogs
2026/09/10: Add support to 2 modes
- BRIDGE: used with an Arduino board
- INJECTOR: used standalone, BRIDGE jumper off
- add DV12 protection with a Thermal Fuse

### Bridge mode
- BRIDGE jumper can be set to enable Loconet Master
- Arduino must be present
- can be chained

### Injector mode
- BRIDGE jumper can be set to enable Loconet Master (**but only one card on the bus can be**)
- Arduino must be absent
- must be chained
- use to provide the DC12V over the Loconet Bus to third part Loconet user like YD6016LNCS

### Loconet Header
- receive the RJ12 connector
- send/receive Loconet messages over pin 3 and 4
- pin 2 and 5 are set to the ground
- pin 1 and 6 are set to the DC12V

### Loconet Header Supp (2026/09/10)
- RJ12 connector to chain the Loconet Bus

### Loconet Master
- header BRIDGE allow to set/unset the loconet master as indicated in **[arduino-loconetshield](https://github.com/lucadentella/arduino-loconetshield)** by [lucadentella](https://github.com/lucadentella)
- the R3 and R4 generate 13mA of consumption with the DC 12V
- need to command in addition the BOM a Shunts 2.54mm like [LCSC C5305](https://www.lcsc.com/product-detail/C5305.html?s_z=s_q_p_HEADER%25201X2&spm=wm.ssy.bg.0.stp&lcsc_vid=FFBXVlIAEgVbBgAFEgJcVlZWE1FcBVJTTgcMAVVeRAAxVlNeT1hWVlJVRldcVjsOAxUeFF5JWBYZEEoKFBINSQcJGk4eFQsCAgIaSgADAwAHC0slQVFbUldVTk8GEwkK)

### Loconet Read/Write
- signal LNET can be the write from D1 or a value to read in D0
- it is the same schematics I have copied from **[arduino-loconetshield](https://github.com/lucadentella/arduino-loconetshield)** by [lucadentella](https://github.com/lucadentella)

### DC12 Header
- a simple DC barrel with some condensators to smooth the voltage
- (2026/09/10) add a Thermal Fuse (500mA, 24V) to protect the RJ12 cable
- (2026/09/10) add a TVS diode (24V) to protect the RJ12 cable

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
- in loop, read byte per byte until a Loconet message is reconstructed or no data on Serial

## Schematics
![LoconetLeader Schematics](/Loconet/LoconetLeader/images/Schematic_Loconet-Master-Shield_2026-09-10.pdf?raw=true)
