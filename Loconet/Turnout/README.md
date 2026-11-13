# Turnout Child for Loconet Interface

Redefine the board use to command Kato and Fleischmann turnouts

## Description
This a Interface child card to put on top of it.

Supports up to 4 inputs like momentary buttons
Supports up to 4 pairs of LED

- 1 input will be associated to a Loconet Turnout
- 1 pair of LED is also associated to a Loconet Turnout

## Pin usage
> [!WARNING]  
> Pin D0 and D1 are used by Serial1 for the Loconet bus. A0 and A1 are used for the activity of RX and TX.

| Pin  | Function |
| ------------- | ------------- |
| D4  | Button Turnout #1  |
| D5  | Button Turnout #2  |
| D6  | Button Turnout #3  |
| D7  | Button Turnout #4  |
| D8  | LED state Turnout #1  |
| D9  | LED state Turnout #2  |
| D10  | LED state Turnout #3  |
| D11  | LED state Turnout #4  |

## Loconet operation
- Send OPC_SW_REQ when input is pressed to toggle the associated Loconet Turnout or Switch state
- When receive OPC_SW_REP, set the pair of LEDs state

## Complements
Need 6 plugs KF2EDGK-3.5-4P ([LCSC reference: C440849](https://www.lcsc.com/product-detail/C440849.html?s_z=n_q_C440849&globalKeyword=C440849)) to work properly

## Schematics
![Turnout Schematics](/Loconet/Turnout/images/?raw=true)
