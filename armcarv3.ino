#include <SoftwareSerial.h>
#include <Servo.h>

// Motor pins
const int MOTOR_A_ENA = 2;
const int MOTOR_A_IN1 = 3;
const int MOTOR_A_IN2 = 4;
const int MOTOR_B_ENB = 7;
const int MOTOR_B_IN3 = 5;
const int MOTOR_B_IN4 = 6;

// Servo pins
const int TOP_SERVO_PIN = 11;
const int BOTTOM_SERVO_PIN = 10;
const int SHOULDER_SERVO_PIN = 9;
const int BASE_SERVO_PIN = 8;

// Servo angles
const int TOP_OPEN_ANGLE = 85;
const int TOP_CLOSE_ANGLE = 0;
const int BOTTOM_OPEN_ANGLE = 120;
const int BOTTOM_CLOSE_ANGLE = 0;

const int SHOULDER_ANGLES[] = {18, 37, 44, 51, 58, 65, 72, 79, 86, 93, 101, 108};
const int BASE_ANGLES[] = {0, 20, 35, 50, 70, 85, 90, 100, 120, 140, 160, 180};


SoftwareSerial BTserial(12, 13);

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

}

void setServoAngle(Servo& servo, const int angle) {
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

void setShoulderAngle(const int index) {
  setServoAngle(shoulderServo, SHOULDER_ANGLES[index]);
}

void setBaseAngle(const int index) {
  setServoAngle(baseServo, BASE_ANGLES[index]);
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
    int command = BTserial.read();
    Serial.println(command);
    switch (command) {
      //HADO CONTROLE DYAL CAR
      case 70:
        forward(255);
        break;
      case 66:
        backward(255);
        break;
      case 82:
        turn_left(255);
        break;
      case 76:
        turn_right(255);
        break;
      //HADA KAYW99F MOTOR
      case 83:
        stopMotors();
        break;
      // HADO BACH TCSSD W T7L CONTENAIRE
      case 86:
        topOpen();
        break;
      case 84:
        topClose();
        break;
      case 67:
        bottomOpen();
        break;
      case 65:
        bottomClose();
        break;
      //HADO DYAL SHOULDER MN 12 L 9
      case 12:
        setShoulderAngle(0);
        break;
      case 13:
        setShoulderAngle(1);
        break;
      case 14:
        setShoulderAngle(2);
        break;
      case 15:
        setShoulderAngle(3);
        break;
      case 16:
        setShoulderAngle(4);
        break;
      case 17:
        setShoulderAngle(5);
        break;
      case 18:
        setShoulderAngle(6);
        break;
      case 19:
        setShoulderAngle(7);
        break;
      case 20:
        setShoulderAngle(8);
        break;
      case 21:
        setShoulderAngle(9);
        break;
      case 22:
        setShoulderAngle(10);
        break;
      case 23:
        setShoulderAngle(11);
        break;

      // HADO DYAL BASE MN 0 L 11
      case 24:
        setBaseAngle(0);
        break;
      case 25:
        setBaseAngle(1);
        break;
      case 26:
        setBaseAngle(2);
        break;
      case 27:
        setBaseAngle(3);
        break;
      case 28:
        setBaseAngle(4);
        break;
      case 29:
        setBaseAngle(5);
        break;
      case 30:
        setBaseAngle(6);
        break;
      case 31:
        setBaseAngle(7);
        break;
      case 32:
        setBaseAngle(8);
        break;
      case 33:
        setBaseAngle(9);
        break;
      case 34:
        setBaseAngle(10);
        break;
      case 35:
        setBaseAngle(11);
        break;

    }
  }
}