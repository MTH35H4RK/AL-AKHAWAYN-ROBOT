// Motor pins
const int MOTOR_A_ENA = 2;
const int MOTOR_A_IN1 = 3;
const int MOTOR_A_IN2 = 4;
const int MOTOR_B_ENB = 7;
const int MOTOR_B_IN3 = 5;
const int MOTOR_B_IN4 = 6;



int ldr1center = A0;

int ldr2left = A1;

int ldr3right = A2;

void setup() {

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

  pinMode(ldr1center, INPUT);

  pinMode(ldr2left, INPUT);

  pinMode(ldr3right, INPUT);

  delay(2000);

  Serial.begin(9600);

}

void loop() {

  int value1 = analogRead(ldr1center);

  int value2 = analogRead(ldr2left);

  int value3 = analogRead(ldr3right);

  if (value1 > value2 && value1 > value3) {

    forward(255);

    delay(1000);

    Serial.println("straight");

  }

  else if (value2 > value1 && value2 > value3) {

    turn_left(255);

    Serial.println("left");

    delay(600);

  }

  else if (value3 > value1 && value3 > value2) {

    turn_right(255);

    delay(600);

    Serial.println("right");

  }

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