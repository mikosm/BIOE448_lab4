const int trigPin = 11;
const int echoPin = 12;
long duration;
double distanceCm, distanceInch;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

  pinMode(3, OUTPUT); // red LED
  pinMode(4, OUTPUT); // green LED
  
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
  distanceCm = duration * 0.0343/2;
  distanceInch = duration * (0.0343 * 0.3937)/2;
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.print(" cm/");
  Serial.print(distanceInch);
  Serial.println(" in");

  if (distanceCm < 5){
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
  } else {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  delay(1000);
}
