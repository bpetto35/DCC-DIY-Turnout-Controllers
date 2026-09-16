# Loconet Interface shield

## Description
Merge the capabilities of the shield boards Leader and Follower in one design Arduino Uno footprint.

Inspired from the schematic **[arduino-loconetshield](https://github.com/lucadentella/arduino-loconetshield)** by [lucadentella](https://github.com/lucadentella), under **[CC BY 4.0](https://creativecommons.org/licenses/by/4.0/)** license.

Loconet read and write are provided by the **[Loconet lib v2](https://github.com/mrrwa/LocoNet2)** with some adaptation to the Uno R4 UART (Serial1).


## Features
Allow to work in 3 modes:
| Mode   | ARDUINO | TERM  | VIN   |
| ------ | ------- | ----- | ----- |
| BRIGDE | YES     | YES   | CAN   |
| INJECT | NO      | NO    | NO    |
| NODE   | YES     | NO    | CAN   |

### BRIDGE
In that mode, we need an Arduino R4 Uno to support the code. The basic behavior is to copy the data from and to Serial1 UART to and from the USB. It support one or both RJ12 Loconet signal.

Must activate the TERM jumper to enable the Loconet Terminaison of 13.6mA consumption on the bus.

By enabling the VIN jumper, the Arduino can receive power from the Jack Barrel of the board.

### INJECT
In that mode, it is fully standalone and no Arduino is needed.

This mode is present to re-inject 12V power on the loconet bus in case modules like YD6016-LNCS need more juice. Loconet signal is just copied from one RJ-12 to another and its RJ12 must be connected to keep the bus continuous.

### NODE
In that mode, it is the equivalent of the Follower board. This mode need to an Arduino R4 Uno to work properly.

By enabling the VIN jumper, the Arduino can receive power from the Jack Barrel of the board.


## Changelogs

## Add-on top shield
Dimension in mil of inch
- x in 450 -> 2700 -> 57.17mm
- y in 0 -> 2100 -> 53.34mm

a cut at y 450 to 1050 and in x at 2550 => H=15.24mm W=3.81mm

Keep the Ardiono headers

