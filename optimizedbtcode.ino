#include <SoftwareSerial.h>

SoftwareSerial BTserial(12, 10); // RX | TX

// MOTOR PINS
const int MOTOR_A_ENA = 9;
const int MOTOR_A_IN1 = 8;
const int MOTOR_A_IN2 = 7;
const int MOTOR_B_ENB = 3;
const int MOTOR_B_IN3 = 6;
const int MOTOR_B_IN4 = 5;

void setup() {
  // setup serial communication with the HC-05 module
  BTserial.begin(9600);

  // setup pins for the motor driver
  pinMode(MOTOR_A_ENA, OUTPUT);
  pinMode(MOTOR_A_IN1, OUTPUT);
  pinMode(MOTOR_A_IN2, OUTPUT);
  pinMode(MOTOR_B_ENB, OUTPUT);
  pinMode(MOTOR_B_IN3, OUTPUT);
  pinMode(MOTOR_B_IN4, OUTPUT);

  // set initial state for the motors and LEDs
  digitalWrite(MOTOR_A_ENA, LOW);
  digitalWrite(MOTOR_A_IN1, LOW);
  digitalWrite(MOTOR_A_IN2, LOW);
  digitalWrite(MOTOR_B_ENB, LOW);
  digitalWrite(MOTOR_B_IN3, LOW);
  digitalWrite(MOTOR_B_IN4, LOW);
}

void forward(int speed) {
  analogWrite(MOTOR_A_ENA, speed);
  digitalWrite(MOTOR_A_IN1, HIGH);
  digitalWrite(MOTOR_A_IN2, LOW);
  analogWrite(MOTOR_B_ENB, speed);
  digitalWrite(MOTOR_B_IN3, LOW);
  digitalWrite(MOTOR_B_IN4, HIGH);
}

void turn_left(int speed) {
  analogWrite(MOTOR_A_ENA, 0);
  digitalWrite(MOTOR_A_IN1, HIGH);
  digitalWrite(MOTOR_A_IN2, LOW);
  analogWrite(MOTOR_B_ENB, speed);
  digitalWrite(MOTOR_B_IN3, LOW);
  digitalWrite(MOTOR_B_IN4, HIGH);
}

void turn_right(int speed) {
  analogWrite(MOTOR_A_ENA, speed);
  digitalWrite(MOTOR_A_IN1, HIGH);
  digitalWrite(MOTOR_A_IN2, LOW);
  analogWrite(MOTOR_B_ENB, 0);
  digitalWrite(MOTOR_B_IN3, LOW);
  digitalWrite(MOTOR_B_IN4, HIGH);
}

void backward(int speed) {
  analogWrite(MOTOR_A_ENA, speed);
  digitalWrite(MOTOR_A_IN1, LOW);
  digitalWrite(MOTOR_A_IN2, HIGH);
  analogWrite(MOTOR_B_ENB, speed);
  digitalWrite(MOTOR_B_IN3, HIGH);
  digitalWrite(MOTOR_B_IN4, LOW);
}

void forward_left(int speed) {
  analogWrite(MOTOR_A_ENA, speed * 0.8);
  digitalWrite(MOTOR_A_IN1, HIGH);
  digitalWrite(MOTOR_A_IN2, LOW);
  analogWrite(MOTOR_B_ENB, speed);
  digitalWrite(MOTOR_B_IN3, LOW);
  digitalWrite(MOTOR_B_IN4, HIGH);
}

void forward_right(int speed) {
  analogWrite(MOTOR_A_ENA, speed);
  digitalWrite(MOTOR_A_IN1, HIGH);
  digitalWrite(MOTOR_A_IN2, LOW);
  analogWrite(MOTOR_B_ENB, speed * 0.8);
  digitalWrite(MOTOR_B_IN3, LOW);
  digitalWrite(MOTOR_B_IN4, HIGH);
}

void backward_left(int speed) {
  analogWrite(MOTOR_A_ENA, speed * 0.8);
  digitalWrite(MOTOR_A_IN1, LOW);
  digitalWrite(MOTOR_A_IN2, HIGH);
  analogWrite(MOTOR_B_ENB, speed);
  digitalWrite(MOTOR_B_IN3, HIGH);
  digitalWrite(MOTOR_B_IN4, LOW);
}

void backward_right(int speed) {
  analogWrite(MOTOR_A_ENA, speed);
  digitalWrite(MOTOR_A_IN1, LOW);
  digitalWrite(MOTOR_A_IN2, HIGH);
  analogWrite(MOTOR_B_ENB, speed * 0.8);
  digitalWrite(MOTOR_B_IN3, HIGH);
  digitalWrite(MOTOR_B_IN4, LOW);
}

void stop() {
  digitalWrite(MOTOR_A_ENA, LOW);
  digitalWrite(MOTOR_A_IN1, LOW);
  digitalWrite(MOTOR_A_IN2, LOW);
  digitalWrite(MOTOR_B_ENB, LOW);
  digitalWrite(MOTOR_B_IN3, LOW);
  digitalWrite(MOTOR_B_IN4, LOW);
}

void loop() {
  if (BTserial.available()) {
    char cmd = BTserial.read();

    switch (cmd) {
      case 'F':
        forward(255);
        break;
      case 'B':
        backward(255);
        break;
      case 'L':
        turn_left(255);
        break;
      case 'R':
        turn_right(255);
        break;
      case 'G':
        forward_left(255);
        break;
      case 'I':
        forward_right(255);
        break;
      case 'H':
        backward_left(255);
        break;
      case 'J':
        backward_right(255);
        break;
      case 'S':
        stop();
        break;
    }
  }
}
