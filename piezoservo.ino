#include <Servo.h>


#define PIEZO1_PIN 34 
#define PIEZO2_PIN 35 
#define SERVO1_PIN 18
#define SERVO2_PIN 19


Servo servo1;
Servo servo2;


void setup() {
  Serial.begin(115200);

  
  servo1.attach(SERVO1_PIN);
  servo2.attach(SERVO2_PIN);

}

void loop() {

  int piezo1Value = analogRead(PIEZO1_PIN);
  int piezo2Value = analogRead(PIEZO2_PIN);

  int servo1Angle = map(piezo1Value, 0, 4095, 0, 180);
  int servo2Angle = map(piezo2Value, 0, 4095, 0, 180);


  int combinedValue = (piezo1Value + piezo2Value) / 2;
  int servo3Angle = map(combinedValue, 0, 4095, 0, 180);


  servo1.write(servo1Angle);
  servo2.write(servo2Angle);
  servo3.write(servo3Angle);




  delay(50); 
}
