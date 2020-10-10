#include <Servo.h>
Servo myservo; // create servo object
int servoPos = 0; // servo position
int analogIn = A1;  // sensor input pin
int sensorValue = 0;  //initial sensor value

void setup()
{
  myservo.attach(9); // attaches the servo on pin 9
  Serial.begin(9600); // baud rate
}

void loop() {
  sensorValue = analogRead(analogIn); //light sensor value
  
  Serial.print("Analog sensor value = "); //print the sensor value
  Serial.println(sensorValue);
  delay(50);
  
  if (sensorValue < 20) { //lowest angle for the servo
    servoPos = 0;
    myservo.write(servoPos);
    delay(10);
  }
  else if (sensorValue > 500) { // higesht angle for the servo
    servoPos = 180;
    myservo.write(servoPos);
    delay(2000);   // wait 2 seconds after getting to 180 degree and go back to 0 degree
    servoPos = 0;
    myservo.write(servoPos);
    delay(10);
  }
  else {
    servoPos = map (sensorValue, 20, 500, 0, 180); // sensor values mapped to servo positions in angle 
    myservo.write(servoPos);
    delay(10);
  }

  Serial.print("Servo Position = "); // print the servo position
  Serial.println(servoPos);
   delay(100);
}
