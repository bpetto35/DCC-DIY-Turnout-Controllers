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

// please define in the file LocoNet2.h #define DEBUG_OUTPUT
#include <LocoNet2.h>
#include <LocoNetStreamUnoR4.h>

void log_printf (const char * format, ...)
{
    char buffer[256];
    va_list args;
    va_start (args, format);
    vsprintf (buffer,format, args);
    Serial.print (buffer);
    va_end (args);
}

LocoNetMessageBuffer lnSerialSend;

LocoNetBus locoBus;
LocoNetDispatcher locoParser(&locoBus);
LocoNetStreamUnoR4 locoSerial(&Serial1, &locoBus);

void setup() {
    Serial.begin(115200);
    locoSerial.start();
    locoParser.onPacket(CALLBACK_FOR_ALL_OPCODES, [] (const lnMsg *rxPacket)
    {
        uint8_t msgLen = rxPacket->length();
        for (uint8_t x = 0; x < msgLen; x++)
            Serial.write(rxPacket->data[x]);
        Serial.println();
    });
}

void loop() {
    locoSerial.process();

    // Generate a Loconet message over Serial1 every 2 seconds
    static unsigned long lastSend = 0;
    if (millis() - lastSend > 2000) {
        lastSend = millis();


        lnMsg msg = makeMsg (OPC_SW_REQ, 1, 0);

        Serial.print(">> TX: ");
        for (uint8_t i = 0; i < msg.length(); i++) {
            Serial.print(msg.data[i], HEX);
            Serial.print(" ");
        }
        Serial.println();

        locoBus.broadcast(msg);
    }
}
