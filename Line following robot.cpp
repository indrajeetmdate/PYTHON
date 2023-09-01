// Pin configuration
const int leftMotor1 = 2;  // Left motor control pin 1
const int leftMotor2 = 3;  // Left motor control pin 2
const int rightMotor1 = 4; // Right motor control pin 1
const int rightMotor2 = 5; // Right motor control pin 2

const int leftSensor = A0;  // Analog pin for left sensor
const int rightSensor = A1; // Analog pin for right sensor

// Sensor threshold values (you may need to adjust these)
const int thresholdLeft = 500;  // Adjust this value based on sensor reading
const int thresholdRight = 500; // Adjust this value based on sensor reading

void setup() {
  // Motor control pins as outputs
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
}

void loop() {
  int leftValue = analogRead(leftSensor);
  int rightValue = analogRead(rightSensor);

  // Compare sensor values with thresholds
  if (leftValue < thresholdLeft && rightValue < thresholdRight) {
    // Both sensors detect the line - move forward
    forward();
  } else if (leftValue < thresholdLeft) {
    // Left sensor detects the line - turn right
    right();
  } else if (rightValue < thresholdRight) {
    // Right sensor detects the line - turn left
    left();
  } else {
    // Both sensors don't detect the line - stop
    stop();
  }
}

void forward() {
  // Move forward
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
}

void left() {
  // Turn left
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, HIGH);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
}

void right() {
  // Turn right
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, HIGH);
}

void stop() {
  // Stop
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, LOW);
}
