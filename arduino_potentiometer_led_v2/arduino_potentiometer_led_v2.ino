// Control the Intensity of an LED using a Potentiometer
int ledPin = 9;
int potMeter = 0;
int potReading = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  pinMode(potMeter,INPUT);
}

void loop()
{
  potReading = analogRead(potMeter);
  potReading = map(potReading,0,1023,0,255);
  Serial.println(potReading);

  digitalWrite(ledPin, HIGH);
  delay(potReading);
 
  digitalWrite(ledPin, LOW);
  delay(potReading);
 }
