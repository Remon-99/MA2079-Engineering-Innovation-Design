const int switchPin = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int switchState = digitalRead(switchPin);
  Serial.print(switchState);
}
