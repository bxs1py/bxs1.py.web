
#include <AFMotor.h>

#define Speed 255

AF_DCMotor M1(1);
AF_DCMotor M2(2);
AF_DCMotor M3(3);
AF_DCMotor M4(4);
char value;

int val = 0 ;
void setup()
{
    Serial.begin(9600);
    pinMode(5,INPUT);  // Rain sensor output pin connected
    pinMode(6,OUTPUT); // Relay
    pinMode(7,OUTPUT); // BuzZer 

    digitalWrite(6,HIGH); // Relay
    M1.setSpeed(Speed);
    M2.setSpeed(Speed);
    M3.setSpeed(Speed);
    M4.setSpeed(Speed);
}
void loop() 
{
   Bluetoothcontrol();
   val = digitalRead(5);  //  Rain sensor output pin connected
   Serial.println(val);   // see the value in serial monitor in Arduino IDE
   delay(100);
   
  if(val == 0 )
  {
    digitalWrite(6,LOW); // Relay
    digitalWrite(7,HIGH); // Buzzer
  }
   if(val == 1 )
  {
    digitalWrite(6,HIGH); // Relay
    digitalWrite(7,LOW); // Buzzer
  }
  }

  void Bluetoothcontrol() {
  if (Serial.available() > 0) {
    value = Serial.read();
    Serial.println(value);
  }

  switch (value) {
    case 'F': forward(); break;
    case 'B': backward(); break;
    case 'L': left(); break;
    case 'R': right(); break;
    case 'S': Stop(); break;
    default: break;
  }
}

void forward() {
  M1.run(FORWARD);
  M2.run(FORWARD);
  M3.run(FORWARD);
  M4.run(FORWARD);
}

void backward() {
  M1.run(BACKWARD);
  M2.run(BACKWARD);
  M3.run(BACKWARD);
  M4.run(BACKWARD);
}

void right() {
  M1.run(BACKWARD);
  M2.run(BACKWARD);
  M3.run(FORWARD);
  M4.run(FORWARD);
}

void left() {
  M1.run(FORWARD);
  M2.run(FORWARD);
  M3.run(BACKWARD);
  M4.run(BACKWARD);
}

void Stop() {
  M1.run(RELEASE);
  M2.run(RELEASE);
  M3.run(RELEASE);
  M4.run(RELEASE);
}
