# Manage up to 4 Kato Turnouts

## Key Features
* 2 Arduino shields
* DCC shield contains the LED, BTN and DCC signal
  * top shield
  * DCC connector
    * horizontal terminal block 3.81mm 2 pins
  * DCC decoded input on Arduino Pin 2 and 3
  * Support 4 buttons to use in standalone
    * Arduino Pin D4 to D7
    * 1x vertical terminal block 3.81mm 2 pins
  * Support 2 leds per turnouts
    * 2x vertical terminal block 3.81mm 2 pins 
    * Arduino Pin D8 to D11
  * as top shield, receive the POWER ON LED and RESET BTN
* 12V DC shields contains the plug for 4 turnouts
  * intermediate shield
  * Arduino Pin D8 to D11 reuse for signal
  * OUT connector
    * horizontal terminal block 3.81mm 2 pins
    * Signal goes from 0V to 5V, generate a +12V on its OUT
    * Signal goes from 5V to 0V, generate a -12V on its OUT
    * Generate 100 ms impulsion of 12V
  * 12V jack barrel 5.5/2.1
* Receive information from
  * read DCC signal
  * read Serial TX/RX for JMRI message
  * BTN actions
* Send retroinformation to
  * JMRI using the Serial TX/RX
  * LED using the Arduino pin
* Use headers 3.81mm to connect LED, BTN, DCC, OUT for male screw terminal

## Layout

### 3D vision
![3D DCC occupancy](/Kato/Mimic-Panel/images/DCCturnout3D.png?raw=true)

### Pins
| Pin # | Function |
|---|---|
| D0 | JMRI RX |
| D1 | JMRI TX |
| D2 | DCC Signal RX to receive DCC info |
| D3 | DCC Signal TX to acknowledge |
| D4 | Turnout #4 BTN action |
| D5 | Turnout #3 BTN action |
| D6 | Turnout #2 BTN action |
| D7 | Turnout #1 BTN action |
| D8 | Turnout #1 LED and SIG action |
| D9 | Turnout #3 LED and SIG action |
| D10 | Turnout #2 LED and SIG action |
| D11 | Turnout #4 LED and SIG action |

## Gerber Files


## Code arduino

## Version
