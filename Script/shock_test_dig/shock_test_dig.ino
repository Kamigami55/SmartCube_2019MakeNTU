int Shock=13;
int val;
void setup()
{ 
Serial.begin(9600);
}
void loop()
{
 pinMode(Shock,INPUT);
 val=digitalRead(Shock);
 Serial.print(val);
 delay(20);
}
