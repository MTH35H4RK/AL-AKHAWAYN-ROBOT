#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial BTserial(12, 10); // RX | TX

Servo topservo;  // create servo object to control a the top servo
Servo bottomservo;  // create servo object to control a servo
Servo shoulderservo;  // create servo object to control a servo
Servo baseservo;  // create servo object to control a servo

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

  //attach every servo to his pin
  topservo.attach(50);
  bottomservo.attach(48);
  shoulderservo.attach(46);
  baseservo.attach(44);

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
void topopen() {
  topservo.write(120);
}
void topclose() {
  topservo.write(0);
}

void bottomopen() {
  bottomservo.write(120);
}
void bottomclose() {
  bottomservo.write(0);
}

void shoulderu90() {
  shoulderservo.write(90);
}
void shoulderd0() {
  shoulderservo.write(0);
}
void shoulderu180() {
  shoulderservo.write(180);
}
void shoulderd90() {
  shoulderservo.write(90);
}
void base0() {
  baseservo.write(0);
}
void base20() {
  baseservo.write(20);
}
void base35() {
  baseservo.write(35);
}
void base50() {
  baseservo.write(50);
}
void base70() {
  baseservo.write(70);
}
void base85() {
  baseservo.write(85);
}
void base100() {
  baseservo.write(100);
}
void base120() {
  baseservo.write(120);
}
void base140() {
  baseservo.write(140);
}
void base160() {
  baseservo.write(160);
}
void base180() {
  baseservo.write(180);
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
      case 'W':
        topopen();
        break;
      case 'w':
        topclose();
        break;
      case 'U':
        bottomopen();
        break;
      case 'u':
        bottomclose();
        break;
      case 'V':
        shoulderu90();
        break;
      case 'v':
        shoulderd0();
        break;
      case 'X':
        shoulderu180();
        break;
      case 'x':
        shoulderd90();
        break;
      case '0':
        base0();
        break;
      case '1':
        base20();
        break;
      case '2':
        base35();
        break;
      case '3':
        base50();
        break;
      case '4':
        base70();
        break;
      case '5':
        base85();
        break;
      case '6':
        base100();
        break;
      case '7':
        base120();
        break;
      case '8':
        base140();
        break;
      case '9':
        base160();
        break;
      case 'q':
        base180();
        break;
      case 'S':
        stop();
        break;
    }
  }
}