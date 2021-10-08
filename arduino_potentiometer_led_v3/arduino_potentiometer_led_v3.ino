// Breathing LED  controlled using Poteniometer

int led_pins[4] = {3,5,6};
int jj = 1; // 0 = red, 1 = green, 2 = blue
int potMeter = 0;
int potReading = 0;
float smoothness_pts = 500;//larger=slower change in brightness  

float gamma = 0.14; // affects the width of peak (more or less darkness)
float beta = 0.5; // shifts the gaussian to be symmetric

void setup() {
  Serial.begin(9600);
  for (int ii = 0;ii<sizeof(led_pins)/sizeof(int);ii++){
    pinMode(led_pins[ii],OUTPUT);
    pinMode(potMeter,INPUT);
  }
}

void loop() {
 
  potReading = analogRead(potMeter);
  potReading = map(potReading,0,1023,0,255);
  Serial.println(potReading);
 
  for (int ii=0;ii<smoothness_pts;ii++){
    float pwm_val = potReading*(exp(-(pow(((ii/smoothness_pts)-beta)/gamma,2.0))/2.0));
    analogWrite(led_pins[jj],int(pwm_val));
    delay(5);
    Serial.println(int(pwm_val));
  }

 
}
