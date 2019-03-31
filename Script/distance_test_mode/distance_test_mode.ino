int trigPin = 3;                  //Trig Pin
int echoPin = 4;                  //Echo Pin
long duration, cm;
int mode;
 
void setup() {
  Serial.begin (9600);             // Serial Port begin
  pinMode(trigPin, OUTPUT);        //Define inputs and outputs 
  pinMode(echoPin, INPUT);
}
void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);     // 給 Trig 高電位，持續 10微秒
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);             // 讀取 echo 的電位
  duration = pulseIn(echoPin, HIGH);   // 收到高電位時的時間
  cm = (duration/2) / 29.1;         // 將時間換算成距離 cm  

  if (cm<10){
    mode = 0;
    }
  else if  (cm<20){
    mode = 1;
    }
  else if  (cm<30){
    mode = 2;
    }
  else {
    mode = 3;
    }
  Serial.print(cm);
  Serial.print("cm, ");
  Serial.print("mode ");
  Serial.print(mode); 
  Serial.println();
  
  delay(2000);
}
