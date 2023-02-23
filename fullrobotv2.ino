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
enum ServoAngle {
  TOP_OPEN_ANGLE = 85,
  TOP_CLOSE_ANGLE = 0,
  BOTTOM_OPEN_ANGLE = 120,
  BOTTOM_CLOSE_ANGLE = 0,
  SHOULDER_U90_ANGLE = 90,

  SHOULDER_30_ANGLE = 30,
  SHOULDER_37_ANGLE = 37,
  SHOULDER_44_ANGLE = 44,
  SHOULDER_51_ANGLE = 51,
  SHOULDER_58_ANGLE = 58,
  SHOULDER_65_ANGLE = 65,
  SHOULDER_72_ANGLE = 72,
  SHOULDER_79_ANGLE = 79,
  SHOULDER_86_ANGLE = 86,
  SHOULDER_93_ANGLE = 93,
  SHOULDER_101_ANGLE = 101,
  SHOULDER_108_ANGLE = 108,
  BASE_0_ANGLE = 0,
  BASE_20_ANGLE = 20,
  BASE_35_ANGLE = 35,
  BASE_50_ANGLE = 50,
  BASE_70_ANGLE = 70,
  BASE_85_ANGLE = 85,
  BASE_90_ANGLE = 90,
  BASE_100_ANGLE = 100,
  BASE_120_ANGLE = 120,
  BASE_140_ANGLE = 140,
  BASE_160_ANGLE = 160,
  BASE_180_ANGLE = 180,
};

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

void shoulder30() {
  setServoAngle(shoulderServo, SHOULDER_30_ANGLE);
}

void shoulder37() {
  setServoAngle(shoulderServo, SHOULDER_30_ANGLE);
}

void shoulder44() {
  setServoAngle(shoulderServo, SHOULDER_30_ANGLE);
}

void shoulder51() {
  setServoAngle(shoulderServo, SHOULDER_51_ANGLE);
}

void shoulder58() {
  setServoAngle(shoulderServo, SHOULDER_58_ANGLE);
}

void shoulder65() {
  setServoAngle(shoulderServo, SHOULDER_65_ANGLE);
}

void shoulder72() {
  setServoAngle(shoulderServo, SHOULDER_72_ANGLE);
}

void shoulder79() {
  setServoAngle(shoulderServo, SHOULDER_79_ANGLE);
}

void shoulder86() {
  setServoAngle(shoulderServo, SHOULDER_86_ANGLE);
}
void shoulder93() {
  setServoAngle(shoulderServo, SHOULDER_93_ANGLE);
}
void shoulder101() {
  setServoAngle(shoulderServo, SHOULDER_101_ANGLE);
}
void shoulder108() {
  setServoAngle(shoulderServo, SHOULDER_108_ANGLE);
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
void base90() {
  setServoAngle(baseServo, BASE_90_ANGLE);
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
        shoulder30();
        break;
      case 13:
        shoulder37();
        break;
      case 14:
        shoulder44();
        break;
      case 15:
        shoulder51();
        break;
      case 16:
        shoulder58();
        break;
      case 17:
        shoulder65();
        break;
      case 18:
        shoulder72();
        break;
      case 19:
        shoulder79();
        break;
      case 20:
        shoulder86();
        break;
      case 21:
        shoulder93();
        break;
      case 22:
        shoulder101();
        break;
      case 23:
        shoulder108();
        break;

      // HADO DYAL BASE MN 0 L 11
      case 0:
        base0();
        break;
      case 1:
        base20();
        break;
      case 2:
        base35();
        break;
      case 3:
        base50();
        break;
      case 4:
        base70();
        break;
      case 5:
        base85();
        break;
      case 6:
        base90();
        break;
      case 7:
        base100();
        break;
      case 8:
        base120();
        break;
      case 9:
        base140();
        break;
      case 10:
        base160();
        break;
      case 11:
        base180();
        break;

    }
  }
}