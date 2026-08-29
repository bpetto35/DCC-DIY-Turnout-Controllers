// Include EEPROM
#include <EEPROM.h>
// Include CMRInet interface
#include <CMRI.h>

// constant
#define RELAI_THRESHOLD 1000

// PIN assign
// Turnout #1 input and output
#define T1_BUTTON_PIN 7
#define T1_LED_RELAY_PIN 8
// Turnout #2 input and output
#define T2_BUTTON_PIN 6
#define T2_LED_RELAY_PIN 9
// Turnout #3 input and output
#define T3_BUTTON_PIN 5
#define T3_LED_RELAY_PIN 10
// Turnout #4 input and output
#define T4_BUTTON_PIN 4
#define T4_LED_RELAY_PIN 11
// JMRI input
#define JMRI_INPUT_PIN 2

#define CMRI_ID_SIGN 0x54434F00UL



// Turnout structure
struct Turnout {
  uint8_t buttonPin;
  uint8_t relayLedPin;
  int buttonState;
  int relayState;
  unsigned long timestamp;
};

// Default and starting values of the turnouts
Turnout turnouts[4] = {
  { T1_BUTTON_PIN, T1_LED_RELAY_PIN, HIGH, LOW, 0 },
  { T2_BUTTON_PIN, T2_LED_RELAY_PIN, HIGH, LOW, 0 },
  { T3_BUTTON_PIN, T3_LED_RELAY_PIN, HIGH, LOW, 0 },
  { T4_BUTTON_PIN, T4_LED_RELAY_PIN, HIGH, LOW, 0 },
};

struct CMRI_ID{
  uint32_t tag;
  uint32_t vers;
  uint32_t cmriId;
};

CMRI cmri;


void setup() {
  // put your setup code here, to run once:
  CMRI_ID cmriId;
  cmriId.cmriId = 0;
  // read eeprom for JMRI info
  if (EEPROM.length() ) {
    // read data
    EEPROM.get(0, cmriId);
    if (cmriId.tag != CMRI_ID_SIGN)
      cmriId.cmriId = 0;
  }
  cmri.set_address(cmriId.cmriId);
  // init serial
  //Serial.begin(115200);
  //uint8_t maxWaitLoops = 255;
  //while(!Serial && maxWaitLoops--)
  //  delay(20);

  // init the pin for each turnout
  for (int turnoutIdx=0; turnoutIdx<4; turnoutIdx++) {
    pinMode(turnouts[turnoutIdx].buttonPin, INPUT);
    digitalWrite(turnouts[turnoutIdx].buttonPin, HIGH); // Write the button is HIGH when released, make test the LOW in the loop() for pressed
    pinMode(turnouts[turnoutIdx].relayLedPin, OUTPUT);
  }

  //Serial.println("Init done");
}

void loop() {
  unsigned long now = millis();
  cmri.process();

  // for each turnout, read the button
  for (int turnoutIdx=0; turnoutIdx<4; turnoutIdx++) {
    digitalWrite(turnouts[turnoutIdx].relayLedPin, cmri.get_bit(turnoutIdx));
    turnouts[turnoutIdx].buttonState = digitalRead(turnouts[turnoutIdx].buttonPin);
    cmri.set_bit(turnoutIdx, !turnouts[turnoutIdx].buttonState);

//    if (turnouts[turnoutIdx].timestamp + RELAI_THRESHOLD < now) {
//      turnouts[turnoutIdx].buttonState = digitalRead(turnouts[turnoutIdx].buttonPin);
//      if (turnouts[turnoutIdx].buttonState == LOW) {
        // change the state of the relay and the led
//        turnouts[turnoutIdx].timestamp = now;
        //Serial.print(turnoutIdx);
        //Serial.println(" -- Turnout toggling");
//        turnouts[turnoutIdx].relayState = (turnouts[turnoutIdx].relayState == LOW) ? HIGH : LOW;
        //digitalWrite(turnouts[turnoutIdx].relayLedPin, turnouts[turnoutIdx].relayState);
//      }
//    }
  }
}

