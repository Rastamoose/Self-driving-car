#include <unordered_map>


#define enA 10
#define in1 4
#define in2 5
#define enB 11
#define in3 6
#define in4 7
#define b1 1
#define b2 2
#define b3 3

int motorSpeedA = 0;    // 0-255
int motorSpeedB = 0;
int bA = 0;     // button A
int bB = 0;
int bC = 0;
bool aOn = false;
bool bOn = false;
bool cOn = false;

void setup() {
  // set motor A,B + motor control 1-4
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);
}

void updateButtons(){
  // get button states
  bA = digitalRead(b1);
  bB = digitalRead(b2);
  bC = digitalRead(b3);
  // toggle buttons
  if (bA==1){
    if (aOn==false){
    aOn = true;
    bOn = false;
    cOn = false;
    }else {
      aOn = false;
    }
  }else if (bB==1){
    if (bOn==false){
    aOn = false;
    bOn = true;
    cOn = false;
    }else {
      bOn = false;
    }
  }else if (bC==1){
    if (cOn==false){
    aOn = false;
    bOn = false;
    cOn = true;
    }else {
      cOn = false;
    }
  }
}

void updateA(){
  motorSpeedA = 255;
  motorSpeedB = 255; 
  analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
  analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
}

void updateB(){
  motorSpeedA = 255;
  motorSpeedB = 0;
  analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
  analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
  delay(3500);
  motorSpeedA = 0;
  motorSpeedB = 255;
  analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
  analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
  delay(3500);
}

void updateC(){
  motorSpeedA = 255;
  motorSpeedB = 120;
  analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
  analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
  delay(600);
  motorSpeedA = 120;
  motorSpeedB = 255;
  analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
  analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
  delay(600);
}

void loop() {
  updateButtons();

  // Set Motor A forward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // Set Motor en forward
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  if (aOn){
    updateA();
  } else if (bOn){
    updateB();
  } else if (cOn){
    updateC();
  }
}