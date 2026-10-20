// Include EEPROM
#include <EEPROM.h>
// Include Loconet interface
#include <LocoNet2.h>
#include <LocoNetStreamUnoR4.h>
#include <ln_opc.h>


// constant
#define BUTTON_THRESHOLD 1000

// PIN assign
// Turnout #1 input and output
#define T1_BUTTON_PIN 7
#define T1_LED_PIN 8
// Turnout #2 input and output
#define T2_BUTTON_PIN 6
#define T2_LED_PIN 9
// Turnout #3 input and output
#define T3_BUTTON_PIN 5
#define T3_LED_PIN 10
// Turnout #4 input and output
#define T4_BUTTON_PIN 4
#define T4_LED_PIN 11


#define EEPROM_ID_SIGN 0x004F4354UL



// Turnout structure
struct Turnout {
  uint8_t buttonPin;
  uint8_t ledPin;
  int buttonState;
  int swState;
  unsigned long timestamp;
};

// Default and starting values of the turnouts
Turnout turnouts[4] = {
  { T1_BUTTON_PIN, T1_LED_PIN, HIGH, LOW, 0 },
  { T2_BUTTON_PIN, T2_LED_PIN, HIGH, LOW, 0 },
  { T3_BUTTON_PIN, T3_LED_PIN, HIGH, LOW, 0 },
  { T4_BUTTON_PIN, T4_LED_PIN, HIGH, LOW, 0 },
};

struct DEVICE_INFO {
  uint32_t tag;
  uint32_t version;
  uint32_t deviceId;
  uint16_t turnoutAddresses[4]; 
};

DEVICE_INFO deviceInfo;

LocoNetBus locoBus;
LocoNetDispatcher locoParser(&locoBus);
LocoNetStreamUnoR4 locoDevice(&Serial1, &locoBus);

/*
LNCV work:
First receive a discovery with a single ArticleNumber/DeviceClass
-> should answer 4 times (one per turnout) with a small delay between each answer (do not bind the discovery callback)
-> when prog is on, it selects an LNCV #0 addr (prog is on, if LNCV #0 addr match one of the turnout)
-> all successive write or read apply only on the selected turnout
-> stop to write/read after the prog is off
*/


void setup() {
  // put your setup code here, to run once:
  deviceInfo.deviceId = 1;
  // read eeprom for JMRI info
  if (EEPROM.length() ) {
    // read data
    EEPROM.get(0, deviceInfo);
    if (deviceInfo.tag != EEPROM_ID_SIGN) {
      deviceInfo.deviceId = 1;
      deviceInfo.turnoutAddresses[0] = 1;
      deviceInfo.turnoutAddresses[1] = 2;
      deviceInfo.turnoutAddresses[2] = 3;
      deviceInfo.turnoutAddresses[3] = 4;
    } 
  }

  // init serial
  Serial.begin(115200);
  uint8_t maxWaitLoops = 255;
  while(!Serial && maxWaitLoops--)
    delay(20);

  Serial.println("Init Loconet Uno R4 device");
  //locoDevice.setAddress(deviceInfo.deviceId);
  locoDevice.start();

  // init the callbacks
  locoParser.onPacket(CALLBACK_FOR_ALL_OPCODES, [] (const lnMsg *rxPacket)
    {
        char tmp[100];
        formatMsg(*rxPacket, tmp, sizeof (tmp));
        Serial.print("onPacket: ");
        Serial.println(tmp);
    });
  locoParser.onSwitchRequest([] (uint16_t address, bool output, bool direction)
    {
        Serial.print("Switch Request: ");
        Serial.print(address, DEC);
        Serial.print(':');
        Serial.print(direction ? "Closed" : "Thrown");
        Serial.print(" - ");
        Serial.println(output ? "On" : "Off");
    });
  locoParser.onSwitchReport([] (uint16_t address, bool state, bool sensor)
    {
        Serial.print("Switch/Sensor Report: ");
        Serial.print(address, DEC);
        Serial.print(':');
        Serial.print(sensor ? "Switch" : "Aux");
        Serial.print(" - ");
        Serial.println(state ? "Active" : "Inactive");
    });
  locoParser.onSensorChange([] (uint16_t address, bool state)
    {
        Serial.print("Sensor: ");
        Serial.print(address, DEC);
        Serial.print(" - ");
        Serial.println(state ? "Active" : "Inactive");
    });

  // init the pin for each turnout
  for (int turnoutIdx=0; turnoutIdx<4; turnoutIdx++) {
    pinMode(turnouts[turnoutIdx].buttonPin, INPUT);
    digitalWrite(turnouts[turnoutIdx].buttonPin, HIGH); // Write the button is HIGH when released, make test the LOW in the loop() for pressed
    pinMode(turnouts[turnoutIdx].ledPin, OUTPUT);
    reportSwitch(&locoBus, deviceInfo.turnoutAddresses[turnoutIdx]);
  }

  Serial.println("Init done");
}

void loop() {
  unsigned long now = millis();
  locoDevice.process();

  // for each turnout, read the button
  for (int turnoutIdx=0; turnoutIdx<4; turnoutIdx++) {

    if (turnouts[turnoutIdx].timestamp + BUTTON_THRESHOLD < now) {
      turnouts[turnoutIdx].buttonState = digitalRead(turnouts[turnoutIdx].buttonPin);
      if (turnouts[turnoutIdx].buttonState == LOW) {
        // change the state of the relay and the led
        turnouts[turnoutIdx].timestamp = now;
        Serial.print(turnoutIdx);
        Serial.println(" -- Turnout toggling");
        turnouts[turnoutIdx].swState = (turnouts[turnoutIdx].swState == LOW) ? HIGH : LOW;
        //digitalWrite(turnouts[turnoutIdx].relayLedPin, turnouts[turnoutIdx].relayState);
        locoParser.send(OPC_SW_REQ, deviceInfo.turnoutAddresses[turnoutIdx], turnouts[turnoutIdx].swState == HIGH);
      }
    }
  }
}

