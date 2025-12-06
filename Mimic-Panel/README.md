# Manage up to 4 Fleischmann Turnouts

## Key Features
* DCC decoded input on Arduino Pin 2
* Support 4 buttons to use in standalone
  * Arduino Pin D4 to D7
* Support 2 leds per turnouts
  * 4 pins
  * Arduino Pin D8 to D11
* Signal up to 4 5V relay like SONGLE SRD-05VDC-SL-C
  * use the same Arduino output pin than the LED
* [v3.x] support DCC input/output directly without a DCC-Decoder module

## Layout

### Turnouts
| Turnout # | Button Pin | LED and Relay Pin |
|---|---|---|
| 1 | D7 | D9 |
| 2 | D6 | D10 |
| 3 | D5 | D8 |
| 4 | D4 | D11 |

### DCC in (Version 2.0)
see DCC decoder information in its directory

| Pin # | Function |
|---|---|
| 1 | 5V DC to power the DCC decoder |
| 2 | Signal RX to receive DCC info |
| 3 | GND to align the DCC decoder |

## Gerber Files
* [Gerber File 2.0](/Mimic-Panel/gerber/Gerber_Mimic-Panel_PCB_Mimic-Panel_2025-11-19_v2.zip)
* [Gerber File 3.1](/Mimic-Panel/gerber/Gerber_Mimic-Panel_PCB_Mimic-Panel_2025-12-06_v3.1.zip)


## Code arduino
Only store the code for the version 2 but it is ready for the verrsion 3.x. To unlock the support of version 3.x, you will need to uncomment the control of the D3 output pin and acknowledge code.

## Version
### 3.x (WIP -- not tested)
* add a DCC decoder/encoder
* add support to programmable DCC address
* ![MimicPanelPCB 3.1](/Mimic-Panel/images/PCB_PCB_Mimic-Panel_2025-12-06.png?raw=true)

### 2.x
* initial and tested version
* ![MimicPanelPCB 2.0](/Mimic-Panel/images/PCB_PCB_Mimic-Panel_2025-11-19.png?raw=true)