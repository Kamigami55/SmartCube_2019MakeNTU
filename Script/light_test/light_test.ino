int CDSPin = 17; // 光敏電阻接在A0接腳
float sensorValue = 0; // 設定初始光敏電阻值為0

void setup() {
  Serial.begin(9600);
}

void loop() { 
  sensorValue = analogRead(CDSPin);
  Serial.println(4095-sensorValue);  
  delay(2000); //每2s讀取一次       
}
