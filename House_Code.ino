#define trigPin 10
#define echoPin 13
#include <LiquidCrystal.h> `
#include <Servo.h>
int LED = 8;


int seconds = 0;

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

Servo servo1;
Servo servo2;
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd_1.begin(16, 2);
  lcd_1.print("Hello World");
  lcd_1.clear();
  servo1.attach(6);
  servo2.attach(7);
  pinMode(LED,OUTPUT);
  //digitalWrite(LED,HIGH);
}

void loop() {
  float duration, distance;
  digitalWrite(trigPin, LOW); 	
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH);	
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0344;
  
  if (distance >= 400 || distance <= 2){
    Serial.print("Distance = ");
    Serial.println("Out of range");
  }
  else {
    Serial.print("Distance = ");
    Serial.print(distance);
    Serial.println(" cm");
    delay(500);
  }
  delay(500);
  
  if (distance < 4){
    lcd_1.setCursor(0, 0);
    lcd_1.print("Your Package");
    lcd_1.setCursor(0, 1);
    lcd_1.print(" has arrived");
     servo1.write(180);
     servo2.write(180);
     servo2.write(90);
     digitalWrite(LED,HIGH);
    
  }
}
