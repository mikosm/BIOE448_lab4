const int trigPin = 11;
const int echoPin = 12;
long duration;
int distanceCm, distanceInch;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // calculating the duration
  duration = pulseIn(echoPin, HIGH);
  Serial.print("Duration: ");
  Serial.print(duration);
    Serial.print(" micros/");


  // using the duration to calculate the sensor
  distanceCm = duration / 1000 *  34,300;
  distanceInch = duration / 1000 * 34,300 * 0.3937;
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.print(" cm/");
  Serial.print(distanceInch);
  Serial.println(" in");
  delay(1000);
}
