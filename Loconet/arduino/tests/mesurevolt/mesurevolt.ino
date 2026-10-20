void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(1, OUTPUT);
  pinMode(0, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(1, LOW);
  delay(3000);
  Serial.print("D1=LOW  -> D0="); Serial.println(digitalRead(0));
  digitalWrite(1, HIGH);
  delay(3000);
  Serial.print("D1=HIGH -> D0="); Serial.println(digitalRead(0));
}
