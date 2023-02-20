#include <SoftwareSerial.h>
#include <Servo.h>

// Motor pins
const int MOTOR_A_ENA = 8;
const int MOTOR_A_IN1 = 9;
const int MOTOR_A_IN2 = 13;
const int MOTOR_B_ENB = 11;
const int MOTOR_B_IN3 = 24;
const int MOTOR_B_IN4 = 22;

// Servo pins
const int TOP_SERVO_PIN = 4;
const int BOTTOM_SERVO_PIN = 5;
const int SHOULDER_SERVO_PIN = 3;
const int BASE_SERVO_PIN = 2;

// Servo angles
enum ServoAngle {
  TOP_OPEN_ANGLE = 85,
  TOP_CLOSE_ANGLE = 0,
  BOTTOM_OPEN_ANGLE = 120,
  BOTTOM_CLOSE_ANGLE = 0,
  SHOULDER_U90_ANGLE = 90,
  SHOULDER_D0_ANGLE = 30,
  SHOULDER_U180_ANGLE = 180,
  SHOULDER_D90_ANGLE = 90,
  BASE_0_ANGLE = 0,
  BASE_20_ANGLE = 20,
  BASE_35_ANGLE = 35,
  BASE_50_ANGLE = 50,
  BASE_70_ANGLE = 70,
  BASE_85_ANGLE = 85,
  BASE_100_ANGLE = 100,
  BASE_120_ANGLE = 120,
  BASE_140_ANGLE = 140,
  BASE_160_ANGLE = 160,
  BASE_180_ANGLE = 180,
};

SoftwareSerial BTserial(12, 10);

Servo topServo;
Servo bottomServo;
Servo shoulderServo;
Servo baseServo;

void setup() {
  BTserial.begin(9600);
  Serial.begin(9600);
  topServo.attach(TOP_SERVO_PIN);
  bottomServo.attach(BOTTOM_SERVO_PIN);
  shoulderServo.attach(SHOULDER_SERVO_PIN);
  baseServo.attach(BASE_SERVO_PIN);

  pinMode(MOTOR_A_ENA, OUTPUT);
  pinMode(MOTOR_A_IN1, OUTPUT);
  pinMode(MOTOR_A_IN2, OUTPUT);
  pinMode(MOTOR_B_ENB, OUTPUT);
  pinMode(MOTOR_B_IN3, OUTPUT);
  pinMode(MOTOR_B_IN4, OUTPUT);

  digitalWrite(MOTOR_A_ENA, LOW);
  digitalWrite(MOTOR_A_IN1, LOW);
  digitalWrite(MOTOR_A_IN2, LOW);
  digitalWrite(MOTOR_B_ENB, LOW);
  digitalWrite(MOTOR_B_IN3, LOW);
  digitalWrite(MOTOR_B_IN4, LOW);
}

void setServoAngle(Servo& servo, ServoAngle angle) {
  servo.write(angle);
}

void topOpen() {
  setServoAngle(topServo, TOP_OPEN_ANGLE);
}

void topClose() {
  setServoAngle(topServo, TOP_CLOSE_ANGLE);
}

void bottomOpen() {
  setServoAngle(bottomServo, BOTTOM_OPEN_ANGLE);
}

void bottomClose() {
  setServoAngle(bottomServo, BOTTOM_CLOSE_ANGLE);
}

void shoulderUp90() {
  setServoAngle(shoulderServo, SHOULDER_U90_ANGLE);
}

void shoulderDown0() {
  setServoAngle(shoulderServo, SHOULDER_D0_ANGLE);
}

void shoulderUp180() {
  setServoAngle(shoulderServo, SHOULDER_U180_ANGLE);
}

void shoulderDown90() {
  setServoAngle(shoulderServo, SHOULDER_D90_ANGLE);
}

void base0() {
  setServoAngle(baseServo, BASE_0_ANGLE);
}

void base20() {
  setServoAngle(baseServo, BASE_20_ANGLE);
}

void base35() {
  setServoAngle(baseServo, BASE_35_ANGLE);
}

void base50() {
  setServoAngle(baseServo, BASE_50_ANGLE);
}

void base70() {
  setServoAngle(baseServo, BASE_70_ANGLE);
}

void base85() {
  setServoAngle(baseServo, BASE_85_ANGLE);
}

void base100() {
  setServoAngle(baseServo, BASE_100_ANGLE);
}

void base120() {
  setServoAngle(baseServo, BASE_120_ANGLE);
}

void base140() {
  setServoAngle(baseServo, BASE_140_ANGLE);
}

void base160() {
  setServoAngle(baseServo, BASE_160_ANGLE);
}

void base180() {
  setServoAngle(baseServo, BASE_180_ANGLE);
}

void stopMotors() {
  digitalWrite(MOTOR_A_ENA, LOW);
  digitalWrite(MOTOR_B_ENB, LOW);
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

void loop() {
  if (BTserial.available()) {
    char command = BTserial.read();
    Serial.println(command);
    switch (command) {
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
        stopMotors();
        break;
      case 'W':
        topOpen();
        break;
      case 'w':
        topClose();
        break;
      case 'U':
        bottomOpen();
        break;
      case 'u':
        bottomClose();
        break;
      case 'V':
        shoulderUp90();
        break;
      case 'v':
        shoulderDown0();
        break;
      case 'X':
        shoulderUp180();
        break;
      case 'x':
        shoulderDown90();
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
    }
  }
}