# Pilot child card

## Objective
Replacing the YD8008/YD6940 by a Loconet motor driver to effectively pilot a Turnout.


## Specification
- This a Interface child card to put on top of it.
- Up to 4 motor driver TI DRV8256E per card.
- The card will use a CDU to inject current in the Kato turnout during few milliseconds and limit the current drain.

## Pin definition
> [!WARNING]  
> Pin D0 and D1 are used by Serial1 for the Loconet bus. A0 and A1 are used for the activity of RX and TX.

| Pin | Description |
|-----|-------------|
| D2  | Enable Motor #1 |
| D3  | Enable Motor #2 |
| D4  | Enable Motor #3 |
| D5  | Enable Motor #4 |
| D6  | Direction of rotation |
| D7  | receive the nSLEEP from the DRV8256E |
| D8  | receive the nFAULT from the DRV8256E |
| A2  | charge % of the CDU |
| A3  | input tension meter % |

## Firmware
The duration of the pulse is defined in the LNCV 1 of each device.
Only send a pulse at a time, each pulse can happen after a minimum of pulse delay added of 10 milliseconds of cooldown.

## Loconet operation
- on reception of OPC_SW_REQ, configure the motor and apply the configuration
- send OPC_SW_REP, when the pulse delay is elapsed

## Schematics
