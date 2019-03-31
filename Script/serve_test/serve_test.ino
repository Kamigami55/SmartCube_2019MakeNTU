#include <Servo.h> 

Servo myservo;

void setup() 
{ 

  myservo.attach(4, 500, 2400); // 修正脈衝寬度範圍
  myservo.write(90); // 一開始先置中90度
  delay(3000);
} 

void loop() {
    myservo.write(105); 
    delay(1000);
    myservo.write(90); 
    delay(2000);
    myservo.write(70); 
    delay(1000);    
    myservo.write(90); 
    delay(2000);
}
