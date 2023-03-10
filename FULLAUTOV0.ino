#include <Servo.h>
// Motor pins
const int MOTOR_A_ENA = 2;
const int MOTOR_A_IN1 = 3;
const int MOTOR_A_IN2 = 4;
const int MOTOR_B_ENB = 7;
const int MOTOR_B_IN3 = 5;
const int MOTOR_B_IN4 = 6;

// Servo angles
const int TOP_OPEN_ANGLE_LEFT = 180;
const int TOP_OPEN_ANGLE_RIGHT = 0;
const int TOP_CLOSE_ANGLE = 90;
const int BOTTOM_OPEN_ANGLE = 100;
const int BOTTOM_CLOSE_ANGLE = 0;


// LDR pins
const int LDR_CENTER_PIN = A4;
const int LDR_LEFT_PIN = A1;
const int LDR_RIGHT_PIN = A2;
const int LDR_B1_PIN = A3;
const int LDR_B2_PIN = A0;
const int LDR_B3_PIN = A5;

// PID constants
const double Kp = 5;
const double Ki = 2.5;
const double Kd = 2.5;

// PID variables
double last_error = 0.0;
double integral = 0.0;
double setpoint = 500.0;

// Servo pins
const int TOP_SERVO_PIN = 8;
const int BOTTOM_SERVO_PIN = 11;
const int SHOULDER_SERVO_PIN = 9;
const int BASE_SERVO_PIN = 10;
const int TRAIN_SERVO_PIN = 24;


int i = 1;
int m0 = 1;
int m1 = 0;
int m2 = 0;
int m3 = 0;
int m4 = 0;

int pos;
Servo topServo;
Servo bottomServo;
Servo shoulderServo;
Servo baseServo;
Servo trainServo;

void setServoAngle(Servo& servo, const int angle) {
  servo.write(angle);
  }
  void forward(int speed) {
    analogWrite(MOTOR_A_ENA, speed);
      digitalWrite(MOTOR_A_IN1, LOW);
        digitalWrite(MOTOR_A_IN2, HIGH);
	  analogWrite(MOTOR_B_ENB, speed);
	    digitalWrite(MOTOR_B_IN3, HIGH);
	      digitalWrite(MOTOR_B_IN4, LOW);
	      }
	      void backward(int speed) {
	        analogWrite(MOTOR_A_ENA, speed);
		  digitalWrite(MOTOR_A_IN1, HIGH);
		    digitalWrite(MOTOR_A_IN2, LOW);
		      analogWrite(MOTOR_B_ENB, speed);
		        digitalWrite(MOTOR_B_IN3, LOW);
			  digitalWrite(MOTOR_B_IN4, HIGH);
			  }
			  void stoprobot () {
			    analogWrite(MOTOR_A_ENA, 0);
			      digitalWrite(MOTOR_A_IN1, LOW);
			        digitalWrite(MOTOR_A_IN2, LOW);
				  analogWrite(MOTOR_B_ENB, 0);
				    digitalWrite(MOTOR_B_IN3, LOW);
				      digitalWrite(MOTOR_B_IN4, LOW);
				      }

void turn_left(int speed) {
  analogWrite(MOTOR_A_ENA, 30);
    digitalWrite(MOTOR_A_IN1, LOW);
      digitalWrite(MOTOR_A_IN2, HIGH);
        analogWrite(MOTOR_B_ENB, speed);
	  digitalWrite(MOTOR_B_IN3, HIGH);
	    digitalWrite(MOTOR_B_IN4, LOW);
	    }

void turn_right(int speed) {
  analogWrite(MOTOR_A_ENA, speed);
    digitalWrite(MOTOR_A_IN1, LOW);
      digitalWrite(MOTOR_A_IN2, HIGH);
        analogWrite(MOTOR_B_ENB, 30);
	  digitalWrite(MOTOR_B_IN3, HIGH);
	    digitalWrite(MOTOR_B_IN4, LOW);
	    }


void br(int speed) {
  analogWrite(MOTOR_A_ENA, 10);
    digitalWrite(MOTOR_A_IN1, HIGH);
      digitalWrite(MOTOR_A_IN2, LOW);
        analogWrite(MOTOR_B_ENB, speed);
	  digitalWrite(MOTOR_B_IN3, LOW);
	    digitalWrite(MOTOR_B_IN4, HIGH);
	    }
	    void bl(int speed) {
	      analogWrite(MOTOR_A_ENA, speed);
	        digitalWrite(MOTOR_A_IN1, HIGH);
		  digitalWrite(MOTOR_A_IN2, LOW);
		    analogWrite(MOTOR_B_ENB, 10);
		      digitalWrite(MOTOR_B_IN3, LOW);
		        digitalWrite(MOTOR_B_IN4, HIGH);
			}
			void nichan() {
			  int center_val = analogRead(LDR_CENTER_PIN);
			    int left_val = analogRead(LDR_LEFT_PIN)  ;
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

  if (center_val > 900)
    {
        stoprobot();

    m0 = 0;
      }
        else {
	    if (center_val > left_val && center_val > right_val) {
	          forward(left_speed);
		      } else if (left_val > center_val && left_val > right_val) {
		            turn_left(left_speed);
			        } else if (right_val > center_val && right_val > left_val) {
				      turn_right(right_speed);
				          }
					      //  Serial.print("Fmoyen:  ");
					          //  Serial.print(Fmoyen);
						      Serial.print("center_val:  ");
						          Serial.print(center_val);
							      Serial.print("  ");
							          Serial.print("left_val:  ");
								      Serial.print(left_val);
								          Serial.print("   ");
									      Serial.print("right_val:  ");
									          Serial.println(right_val);

  }
  }
  void lor() {
    int B1_center_val = analogRead(LDR_B1_PIN);
      int B2_right_val = analogRead(LDR_B2_PIN);
        int B3_left_val = analogRead(LDR_B3_PIN) + 30;

  double error = setpoint - B1_center_val;
    integral += error;
      double derivative = error - last_error;
        last_error = error;

  double correction = (Kp * error) + (Ki * integral) + (Kd * derivative);

  int left_speed = 255 - correction;
    int right_speed = 255 + correction;

  analogWrite(MOTOR_A_ENA, right_speed);
    analogWrite(MOTOR_B_ENB, left_speed);

  if (B1_center_val > B3_left_val && B1_center_val > B2_right_val) {
      backward(B3_left_val);
        } else if (B3_left_val > B1_center_val && B3_left_val > B2_right_val) {
	    bl(left_speed);
	      } else if (B2_right_val > B1_center_val && B2_right_val > B3_left_val) {
	          br(right_speed);
		    }

  Serial.print("  B1:  ");
    Serial.print(B1_center_val);
      Serial.print("    ");
        Serial.print("B2:  ");
	  Serial.print(B2_right_val);
	    Serial.print("    ");
	      Serial.print("B3:  ");
	        Serial.println(B3_left_val);


}
void Shoulder_UP() {
  int pos1;
    for (pos1 = 165; pos1 <= 133; pos1 -= 1) {
        shoulderServo.write(pos1);
	    delay(15);
	      }
	      }


void Base_Middle() {
  baseServo.write(65);
    delay(15);
    }
    void Base_LEFT() {
      for (pos = 65; pos <= 135; pos += 1) {
          baseServo.write(pos);
	      delay(15);
	        }
		}


void Base_RIGHT() {
  for (pos = 65; pos >= 0; pos -= 1) {
      baseServo.write(pos);
          delay(15);
	    }
	    }


void Base_Ball_1() {
  for (pos = 65; pos >= 45; pos -= 1) {
      baseServo.write(pos);
          delay(15);
	    }
	    }


void Base_Ball_2() {
  for (pos = 65; pos <= 100; pos += 1) {
      baseServo.write(pos);
          delay(15);
	    }
	    }

void topOpenLeft() {
  setServoAngle(topServo, TOP_OPEN_ANGLE_LEFT);
  }
  void topOpenRight() {
    setServoAngle(topServo, TOP_OPEN_ANGLE_RIGHT);
    }

void topClose() {
  setServoAngle(topServo, TOP_CLOSE_ANGLE);
  }

void bottomOpen() {
  setServoAngle(bottomServo, BOTTOM_OPEN_ANGLE);
    delay(1000);
    }

void bottomClose() {
  setServoAngle(bottomServo, BOTTOM_CLOSE_ANGLE);
  }

void train_more() {
  if (i == 1) {

    trainServo.write(100);
        delay(1000);

    trainServo.write(90);
        i = 0;
	  }
	  }

void train_less() {
  if (i == 1) {
      trainServo.write(0);
          delay(1000);
	      trainServo.write(90);
	          i = 0;
		    }
		    }

void Shoulder_Down() {
  int pos2;
    for (pos2 = 133; pos2 <= 165; pos2 += 1) {
        shoulderServo.write(pos2);
	    delay(15);
	      }
	      }


void mission0() {
  nichan();



}
void mission1() {

  Shoulder_Down();
    delay(800);
      Base_Ball_1();
        delay(800);
	  topOpenLeft();
	    delay(800);
	      Shoulder_UP();
	        delay(800);

  topClose();
    delay(800);

  Base_RIGHT();
    delay(800);

  train_more();
    delay(800);
      bottomOpen();
        delay(800);
	  bottomClose();
	    i = 1;
	      delay(800);
	        train_less();
		  delay(800);
		    Base_Ball_1();
		      delay(800);
		        Shoulder_Down();
			  delay(800);
			    Base_Middle();



}
void mission2() {
  Base_Ball_2();
    topOpenRight();
      Shoulder_UP();
        topClose();
	  Base_LEFT();
	    i = 1;
	      train_more();
	        bottomOpen();
		  bottomClose();
		    i = 1;
		      train_less();
		        Base_Ball_2();
			  Shoulder_Down();
			    Base_Middle();

}
void mission3() {
  i = 1;
    train_more();
      topOpenRight();
        Shoulder_UP();
	  topClose();
	    Base_RIGHT();
	      bottomOpen();
	        bottomClose();
		  i = 1;
		    train_less();
		      Base_Ball_1();
		        Base_Middle();

}

void mission4() {
  lor();
  }
  void setup() {
    topServo.attach(TOP_SERVO_PIN);
      bottomServo.attach(BOTTOM_SERVO_PIN);
        shoulderServo.attach(SHOULDER_SERVO_PIN);
	  baseServo.attach(BASE_SERVO_PIN);
	    trainServo.attach(TRAIN_SERVO_PIN);
	      train_less();



  pinMode(MOTOR_A_ENA, OUTPUT);
    pinMode(MOTOR_A_IN1, OUTPUT);
      pinMode(MOTOR_A_IN2, OUTPUT);
        pinMode(MOTOR_B_ENB, OUTPUT);
	  pinMode(MOTOR_B_IN3, OUTPUT);
	    pinMode(MOTOR_B_IN4, OUTPUT);

  pinMode(LDR_CENTER_PIN, INPUT);
    pinMode(LDR_LEFT_PIN, INPUT);
      pinMode(LDR_RIGHT_PIN, INPUT);
        pinMode(LDR_B1_PIN, INPUT);
	  pinMode(LDR_B2_PIN, INPUT);
	    pinMode(LDR_B3_PIN, INPUT);
	      Serial.begin(9600);


}


void loop() {



  if (m0 == 1) {
      mission0();

    m1 = 1;
      }
          if (m1 == 1) {
	        mission1();
		      m1 = 0;
		            m2 = 1;
			        }
				//    if (m2 == 1) {
				//      mission2();
				//      m2 = 0;
				//      m3 = 1;
				//    }
				//    if (m3 == 1) {
				//      mission3();
				//      m3 = 0;
				//      m4 = 1;
				//    }
				//    if (m4 == 1) {
				//      mission1();
				//      m4 = 0;
				//  }
				}