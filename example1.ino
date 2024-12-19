
int data;
#include <AFMotor.h>

AF_DCMotor motor(3); 
AF_DCMotor motor2(4);

void setup() {
   Serial.begin(9600);
  motor.setSpeed(255);
  motor2.setSpeed(255);
}

void loop() {
  bluetooth();
}
void bluetooth() {
  if (Serial.available() > 0) { // check if there's any serial buffer in the terminal
    data = Serial.read(); // read the buffer and store it in the variable data
    Serial.println(data); // print the data (buffer) in the terminal (monitor) with a line break

    if (data == 'F') {
      moveForward();
    } else if (data == 'B') {
      moveBackward();
    } else if (data == 'R') {
      moveRight();
    } else if (data == 'L') {
      moveLeft();
    }
  }
}
void moveForward() {
  motor.run(FORWARD);
  motor2.run(FORWARD);
}

void moveBackward() {
  motor.run(BACKWARD);
  motor2.run(BACKWARD);
}
void moveRight() {
  motor.run(BACKWARD);
  motor2.run(FORWARD);
}
void moveLeft() {
  motor.run(FORWARD);
  motor2.run(BACKWARD);
}
