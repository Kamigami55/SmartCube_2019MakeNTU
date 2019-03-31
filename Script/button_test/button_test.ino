void setup()
{
  pinMode(2, INPUT);
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  if (HIGH == digitalRead(2)) {
    Serial.println("按鈕按下");
    digitalWrite(LED_BUILTIN, HIGH);

  } else {
    Serial.println("按鈕放開");
    digitalWrite(LED_BUILTIN, LOW);
  }

  delay(100);
}
