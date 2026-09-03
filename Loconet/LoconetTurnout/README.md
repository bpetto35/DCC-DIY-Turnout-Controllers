# Turnout Command for Loconet Follower

Redefine the bord use to command Kato and Fleischmann turnouts

## Description
Should be stack between the Arduino R4 and the Loconet Follower shield board.

Supports up to 4 inputs like momentary buttons
Supports up to 4 pairs of LED

- 1 input will be assoicted to a Loconet Turnout or Switch
- 1 pair of LED is also associated to a Loconet Turnout or Switch

Loconet operation behavior
- Send OPC_SW_REQ when input is pressed to toggle the associated Loconet Turnout or Switch state
- When receive OPC_SW_REP, set the pair of LEDs state

## Complements
Need 5 plugs to work properly
- one KF2EDGK-3.5-8P (LCSC reference: C440853)
- four KF2EDGK-3.5-4P (LCSC reference: C440849)

## Schematics
![LoconetTurnout Schematics](/Loconet/LoconetTurnout/images/Schematic_Loconet-Turnout-Command_2026-09-03.png?raw=true)