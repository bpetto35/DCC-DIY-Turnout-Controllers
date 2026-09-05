// leader Loconet implementation
/**
 * Use a LocoNetStreamUnoR4 to read and write loconet messages on the UART serial
 * Use the Serial to read and write loconet messages over the USB
 * 
 * The "onPacket" callback allow to send over the USB the message received by the LocoNetBus
 * 
 * The loop will run the process and callback for the LocoNetBus and, if any data present
 * on the Serial, broadcast them over the LocoNetBus
 */
#include <LocoNet2.h>
#include <LocoNetStreamUnoR4.h>

LocoNetMessageBuffer lnSerialSend;

LocoNetBus locoBus;
LocoNetDispatcher locoParser(&locoBus);
LocoNetStreamUnoR4 locoSerial(&Serial1, &locoBus);

void setup() {
    Serial.begin(LOCONET_BAUD);
    locoSerial.start();
    locoParser.onPacket(CALLBACK_FOR_ALL_OPCODES, [] (const lnMsg *rxPacket)
    {
        uint8_t msgLen = rxPacket->length();
        for (uint8_t x = 0; x < msgLen; x++)
            Serial.write(rxPacket->data[x]);
    });
}

void loop() {
    locoSerial.process();

    if (Serial.available()) {
        uint8_t newByte = Serial.read() & 0xFF; 
        LnMsg * rxPacket = lnSerialSend.addByte (newByte);
        if (rxPacket != nullptr) {
            locoBus.broadcast (*rxPacket);
        }
    }
}