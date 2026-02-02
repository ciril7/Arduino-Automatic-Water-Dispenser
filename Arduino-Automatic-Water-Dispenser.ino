#define TRIG 9
#define ECHO 8
#define PUMP 12
#define LED 13
long duration;
int distance;
int threshold = 10; // Distance in cm
void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(PUMP, OUTPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  if (distance < threshold) {
    digitalWrite(PUMP, HIGH);
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(PUMP, LOW);
    digitalWrite(LED, LOW);
  }
  delay(200);
}