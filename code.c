// 1. Define motor pins
const int MotorL_pin1 = 2;
const int MotorL_pin2 = 3;
const int MotorR_pin1 = 4;
const int MotorR_pin2 = 5;


// 2. Define ultrasonic sensor pins
const int trig1 = 10;
const int echo1 = 9;
const int trig2 = 8;
const int echo2 = 7;
const int trig3 = 11;
const int echo3 = 12;


// 3. Variables for calculating distances
int distance1;
int distance2;
int distance3;
long duration;


// 4. Function to stop both motors
void Stop() {
  digitalWrite(MotorL_pin1, LOW);
  digitalWrite(MotorL_pin2, LOW);
  digitalWrite(MotorR_pin1, LOW);
  digitalWrite(MotorR_pin2, LOW);
}

// 5. Function to move both motors forward
void Forward() {
  digitalWrite(MotorL_pin1, HIGH);
  digitalWrite(MotorL_pin2, LOW);
  digitalWrite(MotorR_pin1, HIGH);
  digitalWrite(MotorR_pin2, LOW);
}

// 6. Function to turn left
void Left() {
  digitalWrite(MotorL_pin1, HIGH);
  digitalWrite(MotorL_pin2, LOW);
  digitalWrite(MotorR_pin1, LOW);
  digitalWrite(MotorR_pin2, LOW);
}

// 7. Function to turn right
void Right() {
  digitalWrite(MotorL_pin1, LOW);
  digitalWrite(MotorL_pin2, LOW);
  digitalWrite(MotorR_pin1, HIGH);
  digitalWrite(MotorR_pin2, LOW);
}


void setup() {
  Serial.begin(9600);
  
  // 8. Set motor pins as outputs
  pinMode(MotorL_pin1, OUTPUT);
  pinMode(MotorL_pin2, OUTPUT);
  pinMode(MotorR_pin1, OUTPUT);
  pinMode(MotorR_pin2, OUTPUT);


  // 9. Set ultrasonic sensor pins
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(trig3, OUTPUT);
  pinMode(echo3, INPUT);
}

void loop() {
  // 10. Ultrasonic sensor 1
  digitalWrite(trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);
  duration = pulseIn(echo1, HIGH);
  distance1 = duration * 0.034 / 2;

  // 11. Ultrasonic sensor 2
  digitalWrite(trig2, LOW);
  delayMicroseconds(2);
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);
  duration = pulseIn(echo2, HIGH);
  distance2 = duration * 0.034 / 2;

  // 12. Ultrasonic sensor 3
  digitalWrite(trig3, LOW);
  delayMicroseconds(2);
  digitalWrite(trig3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig3, LOW);
  duration = pulseIn(echo3, HIGH);
  distance3 = duration * 0.034 / 2;


  // 13. Print distances
   Serial.print("Distance1: "); Serial.println(distance1);
   Serial.print("Distance2: "); Serial.println(distance2);
   Serial.print("Distance3: "); Serial.println(distance3);


  // 14. Control movement based on distances
  if (distance1 < 4 || distance2 < 4 || distance3 < 4) {
    Stop(); // If any sensor detects an obstacle too close, stop.
  } else if (distance2 < 25 && distance3 < 25) {
    Forward(); // If object in front of sensor 2 and sensor 3, move forward.
  } else if (distance1 < 25) {
    Forward(); // If object in front, move forward.
  } else if (distance2 < 25) {
    Left(); // If object to the left, turn left.
  } else if (distance3 < 25) {
    Right(); // If object to the right, turn right.
  } else {
    Stop(); // Otherwise, stop (no object detected).
  }
}