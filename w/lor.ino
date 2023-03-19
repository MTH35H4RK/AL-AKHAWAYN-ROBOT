#include <Servo.h>
#include <Ultrasonic.h>

const int Shoulder_Down_MIN = 140 ;
const int Shoulder_Down_MAX = 100 ;

const int BASE_MIDDLE = 65;

const int BASE_BALL_1 = 40 ;
const int BASE_RIGHT = 0 ;


const int BASE_BALL_2 = 88 ;
const int BASE_LEFT = 135 ;
const int BASE_BALL_3 = 67;

Ultrasonic ultrasonic1(48, 46);

// Motor pins
const int MOTOR_A_ENA = 2;
const int MOTOR_A_IN1 = 3;
const int MOTOR_A_IN2 = 4;
const int MOTOR_B_ENB = 7;
const int MOTOR_B_IN3 = 5;
const int MOTOR_B_IN4 = 6;

// Servo angles
const int TOP_OPEN = 100;
const int TOP_CLOSE_ANGLE = 0;
const int BOTTOM_OPEN_ANGLE = 100;
const int BOTTOM_CLOSE_ANGLE = 0;


// LDR pins
const int LDR_CENTER_PIN = A3;
const int LDR_LEFT_PIN = A1;
const int LDR_RIGHT_PIN = A2;
const int LDR_B1_PIN = A0;  // CENTER
const int LDR_B2_PIN = A5;  // RIGHT
const int LDR_B3_PIN = A4;  // LEFT



// Servo pins
const int TOP_SERVO_PIN = 8;
const int BOTTOM_SERVO_PIN = 28;
const int SHOULDER_SERVO_PIN = 9;
const int BASE_SERVO_PIN = 10;
const int TRAIN_SERVO_PIN = 24;

const int valeur_max = 700;
const int valeur2_max = 800;

//VAL MOTORS
int moins;
int val_center;
int val_right;
int val_left;

int i = 1;
int m0 = 1;
int m1 = 0;
int m2 = 0;
int m3 = 0;
int m4 = 0;

Servo topServo;
Servo bottomServo;
Servo shoulderServo;
Servo baseServo;
Servo trainServo;



void base_ghadi(int Mnax, int Talax) {
  for (int Pas = Mnax; Pas <= Talax; Pas += 1) {
    baseServo.write(Pas);
    delay(50);
  }
}
void base_jay (int manax, int talax) {
  for (int pas = manax; pas >= talax; pas -= 1) {
    baseServo.write(pas);
    delay(50);
  }
}

void Shoulder_Down() {

  for (int Sh_M = 100; Sh_M <= 145; Sh_M += 1) {
    shoulderServo.write(Sh_M);
    delay(50);
    Serial.println("Shoulder_Down");
  }
}
void Shoulder_BALL_3() {

  for (int Sh_UP = 145; Sh_UP >= 130; Sh_UP -= 1) {
    shoulderServo.write(Sh_UP);
    delay(50);
  }
}

void Shoulder_UP() {
  Serial.println("Shoulder_UP");
  for (int Sh_UP = 145; Sh_UP >= 100; Sh_UP -= 1) {
    shoulderServo.write(Sh_UP);
    delay(50);
  }
}

void Shoulder_BLUP() {
  Serial.println("Shoulder_BLUP");
  for (int ShLUP = 130; ShLUP >= 100; ShLUP -= 1) {
    shoulderServo.write(ShLUP);
    delay(50);
  }
}



void topOpen() {
  Serial.println("topopen");
  setServoAngle(topServo, TOP_OPEN);
}

void setServoAngle(Servo& servo, const int angle) {
  servo.write(angle);
}


void topClose() {
  Serial.println("topclose");
  setServoAngle(topServo, TOP_CLOSE_ANGLE);
}

void bottomOpen() {
  Serial.println("BT_open");
  setServoAngle(bottomServo, BOTTOM_OPEN_ANGLE);
  delay(1000);
}

void bottomClose() {
  Serial.println("BT_close");
  setServoAngle(bottomServo, BOTTOM_CLOSE_ANGLE);
}

void train(int val, int DELAY) {
  if (i == 1) {
    Serial.println("train_more");
    trainServo.write(val);
    delay(DELAY);

    trainServo.write(90);
    i = 0;
  }
}





void forward(int speeda, int speedb) {
  analogWrite(MOTOR_A_ENA, speeda);
  digitalWrite(MOTOR_A_IN1, LOW);
  digitalWrite(MOTOR_A_IN2, HIGH);
  analogWrite(MOTOR_B_ENB, speedb);
  digitalWrite(MOTOR_B_IN3, HIGH);
  digitalWrite(MOTOR_B_IN4, LOW);
}

void back (int speedleft, int speedright) {
  analogWrite(MOTOR_A_ENA, speedleft);
  digitalWrite(MOTOR_A_IN1, HIGH);
  digitalWrite(MOTOR_A_IN2, LOW);
  analogWrite(MOTOR_B_ENB, speedright);
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

int getMAX(int a, int b, int c) {
  int max = a;
  if (b > max) {
    max = b;
  }
  if (c > max) {
    max = c;
  }
  return max;
}




void turn_left(int speed) {
  analogWrite(MOTOR_A_ENA, 0);
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
  analogWrite(MOTOR_B_ENB, 0);
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
  int val_CENTER = analogRead(LDR_CENTER_PIN);
  int val_LEFT = analogRead(LDR_LEFT_PIN);
  int val_RIGHT = analogRead(LDR_RIGHT_PIN);
  int valmax = getMAX(val_center, val_left, val_right);

  int sonic = ultrasonic1.read();
  Serial.print("Sensor: ");
  Serial.print(sonic);
  Serial.println("cm");

  val_center = map(val_CENTER, 0, 1016, 0, 255);
  val_right = map(val_RIGHT, 0, 1016, 0, 255);
  val_left = map(val_LEFT, 0, 1016, 0, 255);

  if (sonic < 18) {

    if (val_CENTER > valeur_max || val_RIGHT > valeur_max || val_LEFT > valeur_max) {
      //      Serial.print("Sensor: ");
      //      Serial.print(sonic);
      //      Serial.println("cm");
//      Serial.print("center_val:  ");
//      Serial.print(val_CENTER);
//      Serial.print("  ");
//      Serial.print("left_val:  ");
//      Serial.print(val_LEFT);
//      Serial.print("   ");
//      Serial.print("right_val:  ");
//      Serial.println(val_RIGHT);

      if (val_CENTER > val_RIGHT && val_CENTER > val_LEFT) {
        back(0, 0);
        m0 = 0;
        m1 = 1;
      }
      else if (val_RIGHT > val_CENTER && val_LEFT < val_RIGHT) {
        back(100, 140);
      }
      else if (val_RIGHT > val_CENTER && val_LEFT < val_RIGHT) {
        back(140, 90);
      }
    }
  }

  else if (val_right == valmax && val_right < valeur_max) {
    forward(150 - moins, 45 - moins);
    if (valmax > 160) {
      moins = 35;
    }
    else {
      moins = 0;
    }
  }




  else if (val_left == valmax && val_right < valeur_max) {
    forward(35 - moins, 170 - moins);
    if (valmax > 160) {
      moins = 35;
    }
    else {
      moins = 0;

    }
  }

  else if (val_center == valmax && val_right < valeur_max) {
    forward(60 - moins , 145 - moins );
    if (valmax > 160) {
      moins = 25;
    }
    else {
      moins = 0;
    }

  }
}
void lor() {

  int B1_center_val = analogRead(LDR_B1_PIN);
  int B2_right_val = analogRead(LDR_B2_PIN);
  int B3_left_val = analogRead(LDR_B3_PIN) ;
  int valmax = getMAX(B1_center_val, B3_left_val, B2_right_val);
//
//  Serial.print("  B1:  ");
//  Serial.print(B1_center_val);
//  Serial.print("    ");
//  Serial.print("B2:  ");
//  Serial.print(B2_right_val);
//  Serial.print("    ");
//  Serial.print("B3:  ");
//  Serial.println(B3_left_val);

  if (B1_center_val > valeur2_max || B2_right_val > valeur2_max || B3_left_val > valeur2_max) {


    if (B1_center_val > B2_right_val && B1_center_val > B3_left_val ) {
      back(0, 0);
      m4 = 0;

    }

  }


  else if (B2_right_val == valmax && B2_right_val < valeur_max) {
    back(45 - moins , 150 - moins);   //CHANGED
    if (valmax > 160) {
      moins = 35;
    }
    else {
      moins = 0;
    }
  }




  else if (B3_left_val == valmax && B2_right_val < valeur_max) {
    back(170 - moins, 35 - moins); //CHANGED
    if (valmax > 160) {
      moins = 35;
    }
    else {
      moins = 0;

    }
  }

  else if (B1_center_val == valmax && B2_right_val < valeur_max) {
    back( 145 - moins, 60 - moins);  //CHANGED
    if (valmax > 160) {
      moins = 25;
    }
    else {
      moins = 0;
    }

  }



}

void mission0() {
  Serial.println("mission0");
  nichan();
  bottomClose();



}
void mission1() {


  Shoulder_Down();
  delay(600);

  topOpen();
  delay(600);

  base_jay(BASE_MIDDLE, BASE_BALL_1);
  delay(600);

  Shoulder_UP();
  delay(600);

  topClose();
  delay(600);

  Shoulder_Down();
  delay(600);

  Shoulder_UP();
  delay(600);

  base_jay(BASE_BALL_1 , BASE_RIGHT);
  delay(600);

  i = 1;
  train(100, 2000);
  delay(600);
  topOpen();
  bottomOpen();
  delay(1000);

  topClose();
  bottomClose();
  delay(600);

  i = 1;
  train(0, 1900);
  delay(600);

  base_ghadi(BASE_RIGHT, BASE_BALL_1);
  delay(600);

  Shoulder_Down();
  delay(600);

  base_ghadi(BASE_BALL_1 , BASE_MIDDLE);
  delay(600);

  base_jay(BASE_MIDDLE, BASE_BALL_2);
  m1 = 0;
  m2 = 1;

}
void mission2() {

  bottomClose();
  delay(600);

  Shoulder_Down();
  delay(600);

  base_ghadi(BASE_BALL_2, BASE_BALL_2);
  delay(600);

  topOpen();
  delay(600);

  Shoulder_UP();
  delay(600);

  topClose();
  delay(600);

  Shoulder_Down();
  delay(600);

  Shoulder_UP();
  delay(600);

  base_ghadi(BASE_BALL_2 , BASE_LEFT);
  delay(600);

  i = 1;
  train(100, 2000);
  delay(600);

  bottomOpen();
  delay(1000);

  bottomClose();
  delay(600);

  i = 1;
  train(0, 1900);
  delay(600);

  base_jay(BASE_LEFT, BASE_BALL_2);
  delay(600);

  Shoulder_Down();
  delay(600);

  base_jay(BASE_BALL_2, BASE_BALL_3);


  m2 = 0;
  m3 = 1;

}
void mission3() {

  Shoulder_BALL_3();
  delay(600);

  i = 1;
  train(100, 1400);
  delay(200);

  topOpen();
  delay(500);

  Shoulder_BLUP();
  delay(600);

  topClose();
  delay(600);

  Shoulder_Down();
  delay(600);

  Shoulder_UP();
  delay(600);

  base_jay(BASE_BALL_3, BASE_RIGHT);
  delay(600);

  i = 1;
  train(100, 300);
  delay(200);

  topOpen();
  bottomOpen();
  delay(1000);

  topClose();
  bottomClose();
  delay(600);

  i = 1;
  train(0, 1700);
  delay(200);
  base_ghadi(BASE_RIGHT , BASE_MIDDLE);


  m3 = 0;
  m4 = 1;
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

  train(90, 0);

  Shoulder_UP();
  baseServo.write(65);
  topServo.write(0);
  bottomServo.write(0);

  pinMode(30, INPUT);
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

//    while (digitalRead(30)) {
//    }
//    while (!digitalRead(30)) {
//    }
  while (m0 == 1) {
    mission0();
  }

  delay(1500);
  mission1();
  delay(1500);
  mission2();
  delay(1500);
  mission3();
  delay(1500);
  while (m4 == 1) {
    mission4();
  }

}