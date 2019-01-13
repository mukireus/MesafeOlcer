const int trigPin = 11;
const int echoPin = 12;
const int buzzerPin = 2;
long duration;
int distance;

int maximumRange = 50;
int minimumRange = 0;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  int olcum = mesafe(maximumRange, minimumRange);

  melodi(olcum*10); 
}

int mesafe(int maxrange, int minrange)
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  delay(50);
  Serial.print("Distance: ");
  Serial.println(distance);

  if(distance >= maxrange || distance <=minrange)
  return 0;
  return distance;
}

int melodi(int dly)
{
  tone(buzzerPin, 440);
  delay(dly);
  noTone(buzzerPin);
  delay(dly);
}
