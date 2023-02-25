// Motor pins
const int MOTOR_A_ENA = 2;
const int MOTOR_A_IN1 = 3;
const int MOTOR_A_IN2 = 4;
const int MOTOR_B_ENB = 7;
const int MOTOR_B_IN3 = 5;
const int MOTOR_B_IN4 = 6;

// LDR pins
const int LDR_CENTER_PIN = A0;
const int LDR_LEFT_PIN = A1;
const int LDR_RIGHT_PIN = A2;

// PID constants
const double Kp = 1.0;
const double Ki = 0.0;
const double Kd = 0.0;

// PID variables
double last_error = 0.0;
double integral = 0.0;
double setpoint = 500.0;

void setup() {
  pinMode(MOTOR_A_ENA, OUTPUT);
  pinMode(MOTOR_A_IN1, OUTPUT);
  pinMode(MOTOR_A_IN2, OUTPUT);
  pinMode(MOTOR_B_ENB, OUTPUT);
  pinMode(MOTOR_B_IN3, OUTPUT);
  pinMode(MOTOR_B_IN4, OUTPUT);

  pinMode(LDR_CENTER_PIN, INPUT);
  pinMode(LDR_LEFT_PIN, INPUT);
  pinMode(LDR_RIGHT_PIN, INPUT);

  Serial.begin(9600);
}

void loop() {
  int center_val = analogRead(LDR_CENTER_PIN);
  int left_val = analogRead(LDR_LEFT_PIN);
  int right_val = analogRead(LDR_RIGHT_PIN);

  double error = setpoint - center_val;
  integral += error;
  double derivative = error - last_error;
  last_error = error;

  double correction = (Kp * error) + (Ki * integral) + (Kd * derivative);

  int left_speed = 255 - correction;
  int right_speed = 255 + correction;

  analogWrite(MOTOR_A_ENA, left_speed);
  analogWrite(MOTOR_B_ENB, right_speed);

if (center_val > left_val && center_val > right_val) {
  forward(left_speed);
} else if (left_val > center_val && left_val > right_val) {
  turn_left(left_speed);
} else if (right_val > center_val && right_val > left_val) {
  turn_right(right_speed);
}


  delay(50); // adjust delay as necessary
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