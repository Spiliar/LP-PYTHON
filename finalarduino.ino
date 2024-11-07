#include <Servo.h>

const int trigPin = 11;
const int echoPin = 10;
long duration;
int distance;
Servo myServo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);  
  myServo.attach(3);   
}

void loop() {
  for (int i = 15; i <= 165; i++) {
    myServo.write(i);
    delay(30);  
    distance = calculateDistance();  
    
    
    if (distance == -1 || distance > 400) {
      distance = 0;  
    }

    Serial.print("Angle: ");
    Serial.print(i);
    Serial.print(", Distance: ");
    Serial.println(distance);
  }

  for (int i = 165; i > 15; i--) {
    myServo.write(i);
    delay(30);  
    distance = calculateDistance(); 

    
    if (distance == -1 || distance > 400) {
      distance = 0;  
    }

    Serial.print("Angle: ");
    Serial.print(i);
    Serial.print(", Distance: ");
    Serial.println(distance);
  }
}

int calculateDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  
 
  if (duration == 0) {
    return -1;  
  }

  
  distance = duration * 0.034 / 2;
  
  
  if (distance > 400) {
    return -1;  
  }

  return distance;
}
