#define c 262
#define d 294
#define e 330
#define f 349
#define g 392
#define a 440
#define b 494
#define C 523
#define D 587
#define E 659
#define F 698
#define G 784
#define A 880
#define B 988
#define H 1047

int arr[15] = {c, d, e, f, g, a, b, C, D, E, F, G, A, B, H};

void setup() {
  pinMode(15, OUTPUT);
}

void loop() {

  {
    tone(15, arr[7], 500);    delay(250); 
    tone(15, arr[6], 500);     delay(250); 
    tone(15, arr[5], 500);     delay(500); 
    tone(15, arr[9], 500);    delay(1000); 
    tone(15, arr[7], 500);    delay(250); 
    tone(15, arr[5], 500);     delay(250); 
    tone(15, arr[6], 500);     delay(500); 
    tone(15, arr[10], 500);    delay(500); 
    tone(15, arr[9], 500);    delay(250); 
    tone(15, arr[8], 500);    delay(750); 

    tone(15, arr[7], 500);    delay(250); 
    tone(15, arr[8], 500);    delay(250); 
    tone(15, arr[7], 500);    delay(250); 
    tone(15, arr[8], 500);    delay(250); 
    tone(15, arr[9], 500);    delay(500); 
    tone(15, arr[7], 500);    delay(250); 
    tone(15, arr[6], 500);     delay(250); 
    tone(15, arr[5], 500);     delay(500);  
    tone(15, arr[8], 500);    delay(500); 
    tone(15, arr[7], 500);    delay(250); 
    tone(15, arr[6], 500);     delay(750); 
  
  }
  delay(2000);
}
