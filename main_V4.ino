//LED Output
const int redLEDPin = 11;
const int greenLEDPin = 12;
//Motor Output
const int motorPin1 = 5;
const int motorPin2 = 6;
//UltraSound Input/Output
const int echoPin = 2;
const int trigPin = 3;
//Define variables
long duration;
int distance;

void setup() 
{
  //Begin Printing
  Serial.begin(9600);
  //Declaring Modes
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin2, OUTPUT);
}

void loop() {
  digitalWrite(redLEDPin, LOW);
  digitalWrite(greenLEDPin, HIGH);
  delay(1000);
  //Reading distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance(Start): ");
  Serial.print(distance);
  Serial.print(" cm");
  Serial.print("\n");
  //Programme
  if (distance > 50) {
    digitalWrite(redLEDPin, HIGH);
    digitalWrite(greenLEDPin, LOW);
    delay(1000);
    digitalWrite(motorPin1, HIGH);
    Serial.print("Motor 1 ON");
    Serial.print("\n");
    digitalWrite(motorPin2, HIGH);
    Serial.print("Motor 2 ON");
    Serial.print("\n");
    delay(5000);
    digitalWrite(motorPin1, LOW);
    Serial.print("Motor 1 OFF");
    Serial.print("\n");
    digitalWrite(motorPin2, LOW);
    Serial.print("Motor 2 OFF");
    Serial.print("\n");
    delay(1000);
    digitalWrite(redLEDPin, LOW);
    digitalWrite(greenLEDPin, HIGH);
    while (distance > 20){
      delay(1000);
      //Reading distance
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      distance = duration * 0.034 / 2;
      Serial.print("Distance(Waiting): ");
      Serial.print(distance);
      Serial.print("\n");
    }
    if (distance <= 20){
      delay(3000);
      return;
    }
  }
  else if (distance <= 50){
    digitalWrite(redLEDPin, LOW);
    digitalWrite(greenLEDPin, HIGH);
  } 
}
