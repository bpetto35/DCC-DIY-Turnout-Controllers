# Manage up to 4 Turnouts using CMRInet of JMRI

Reuse the first design for Fleischmann turnout PCB

## Key Features
* USB loop from JRMI
* Support 4 buttons to use in standalone
  * Arduino Pin D4 to D7
* Support 2 leds per turnouts
  * 4 pins
  * Arduino Pin D8 to D11
* Inform JMRI when a button is pressed
* Read LED status from JMRI

## Layout

### Turnouts
| Turnout # | Button Pin | LED and Relay Pin |
|---|---|---|
| 1 | D7 | D9 |
| 2 | D6 | D10 |
| 3 | D5 | D8 |
| 4 | D4 | D11 |


## Gerber Files
* [Gerber File 2.0](/Mimic-Panel/gerber/Gerber_Mimic-Panel_PCB_Mimic-Panel_2025-11-19_v2.zip)

## Version
### 2.x
* initial and tested version
* ![MimicPanelPCB 2.0](/Fleischmann/Mimic-Panel/images/PCB_PCB_Mimic-Panel_2025-11-19.png?raw=true)
