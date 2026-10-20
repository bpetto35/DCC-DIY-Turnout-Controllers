// Plug a leader board onto the arduino and check all patterns are ok

const unsigned long BAUD = 16666;
const uint8_t patterns[] = {0x55, 0xAA, 0x00, 0xFF, 0x81, 0x7E, 0x01, 0x47, 0x64, 0xCC};

void setup() {
  Serial.begin(115200);
  while (!Serial) {}
  Serial1.begin(BAUD);          // 8N1
}

void loop() {
  uint32_t ok = 0, missing = 0, wrong = 0;
  for (int i = 0; i < 600; i++) {
    uint8_t tx = patterns[i % 10];
    while (Serial1.available()) Serial1.read();   // vide le tampon
    Serial1.write(tx);
    Serial1.flush();
    unsigned long t0 = micros();
    while (!Serial1.available() && micros() - t0 < 3000) {}
    if (!Serial1.available())      missing++;
    else if (Serial1.read() == tx) ok++;
    else                           wrong++;
    delay(2);
  }
  Serial.print("ok=");      Serial.print(ok);
  Serial.print(" missing="); Serial.print(missing);
  Serial.print(" wrong=");   Serial.println(wrong);
  delay(2000);
}