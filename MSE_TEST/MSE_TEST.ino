//MSE 2202 Test
//Ajanthan Pathmanathan - 251127801

// Pot Setup
int potPin = 36;
unsigned long potVal = 0;

// Ultrasonic Setup
int trigPin = 32;
int echoPin = 34;
long duration;
long distance;
long safetyDistance;

void setup() {
  // put your setup code here, to run once:
  pinMode(36, INPUT_PULLUP);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  duration = pulseIn(echoPin, HIGH);

  distance = duration*0.034/2;
  
  
}
