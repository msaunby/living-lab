#include <Servo.h>

Servo servos[4];  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(115200);
  servos[0].attach(9);  // attaches the servo on pin 9 to the servo object
  servos[1].attach(10); 
}

void loop() {
   while (Serial.available() > 0) {

    // look for the next valid integer in the incoming serial stream:
    int servo_num = Serial.parseInt();
    // do it again:
    int angle = Serial.parseInt();
    // look for the newline. That's the end of your
    // sentence:
    if (Serial.read() == '\n') {
      if(angle < 0) angle = 0;
      if(angle > 180) angle = 180;
      servos[ servo_num ].write( angle );
      delay(15);                       // waits 15ms for the servo to reach the position
    }
   }
}

