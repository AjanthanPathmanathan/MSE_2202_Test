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
long safetyDistance = 100;

// Motor
int motorPin = 23;

// LED PINS
int ledGreen = 15;
int ledRed = 4;
int ledYellow = 2;

// Extortion Level
unsigned long extortion;
unsigned long extortionPercent;

void setup() {
  // put your setup code here, to run once:
  pinMode(5, INPUT_PULLUP);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Start Up using Button
  int switchState = digitalRead(5);
  
  if (swtichState == HIGH) {
    // Initializes the Ultrasonic Sensor
    duration = pulseIn(echoPin, HIGH);
    distance = duration*0.034/2;
  
    // Setup Extrotion Value
    potVal = digitalRead(potPin);
    extortion = potVal;
    extortionPercent = extortion/10 + extortion;
  
    if (distance > safetyDistance){
      ledcWrite(motorPin, 0);
    }
    else if (distance <= safetyDistance) {
      ledcWrite(motorPin, extortion);
      
      if (extortion > extortionPercent)
      {
        digitalWrite(redLed, HIGH);
        digitalWrite(yellowLed, LOW);
        digitalWrite(greenLed, LOW);
      } else if (extortion < extortionPercent) {
        digitalWrite(redLed, LOW);
        digitalWrite(yellowLed, HIGH);
        digitalWrite(greenLed, LOW);
      } else {
        digitalWrite(redLed, LOW);
        digitalWrite(yellowLed, LOW);
        digitalWrite(greenLed, HIGH);
      }
      
    } else {
      ledcWrite(motorPin, 0);
    }
    
  }
  
}
