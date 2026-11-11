# Turnout Child for Loconet Interface

Redefine the board use to command Kato and Fleischmann turnouts

## Description
Should be stack on top of Interface shield board.

Supports up to 4 inputs like momentary buttons
Supports up to 4 pairs of LED

- 1 input will be assoicted to a Loconet Turnout or Switch
- 1 pair of LED is also associated to a Loconet Turnout or Switch

Loconet operation behavior
- Send OPC_SW_REQ when input is pressed to toggle the associated Loconet Turnout or Switch state
- When receive OPC_SW_REP, set the pair of LEDs state

## Complements
Need 6 plugs KF2EDGK-3.5-4P ([LCSC reference: C440849](https://www.lcsc.com/product-detail/C440849.html?s_z=n_q_C440849&globalKeyword=C440849)) to work properly

## Schematics
![Turnout Schematics](/Loconet/Turnout/images/?raw=true)
