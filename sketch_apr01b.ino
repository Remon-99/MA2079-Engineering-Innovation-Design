const int solenoidPin = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(solenoidPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   digitalWrite(solenoidPin, LOW);
   delay(1000);
   digitalWrite(solenoidPin, HIGH);
   delay(1000); 
  }
