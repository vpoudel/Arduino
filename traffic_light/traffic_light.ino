//Coded by: Vision Poudel
//R-number: R11596332
//Subject: CS-4331-001 (Embedded Systems)
//Assignment 2: Traffic Light Controller with Arduio

//the pins representing LEDS on North
const int LEDRED1= 2;
const int LEDGREEN1= 3;
const int LEDYELLOW1= 4;

//the pins representing LEDS on East
const int LEDRED2= 13;
const int LEDGREEN2= 12;
const int LEDYELLOW2= 11;

//pedestrian buttons
const int PED1= 7;
const int PED2= 8;

//delay time for green light to yellow
const long delay_time = 4000;
//variables holding time values
unsigned long newtime;
unsigned long oldtime;

void setup() {
  //traffic lights LEDs set as output
  pinMode(LEDRED1,OUTPUT);
  pinMode(LEDGREEN1,OUTPUT);
  pinMode(LEDYELLOW1,OUTPUT);
  pinMode(LEDRED2,OUTPUT);
  pinMode(LEDGREEN2,OUTPUT);
  pinMode(LEDYELLOW2,OUTPUT);
  Serial.begin(9600);
  //pedestrian buttons as inputs
  pinMode(PED1,INPUT);
  pinMode(PED2,INPUT);
}

void loop() {
    digitalWrite(LEDRED1, HIGH);
    digitalWrite(LEDGREEN2, HIGH);
    //records current time
    newtime = millis(); 
    oldtime = millis();
    
    //the loop runs while the difference is below or equal to delay time=4000 ms
    while ( (newtime-oldtime) <= delay_time){  
      newtime = millis();
      Serial.print("Difference in time is: ");  //just checking the output
      Serial.println(newtime-oldtime);
      if (digitalRead(PED2) == LOW){  //if the button is pressed get out of loop
        break;
      }
    }
    digitalWrite(LEDGREEN2, LOW);
    digitalWrite(LEDYELLOW2, HIGH);
    delay(1000);
    digitalWrite(LEDYELLOW2, LOW);
    digitalWrite(LEDRED1, LOW);
    digitalWrite(LEDRED2, HIGH);
    digitalWrite(LEDGREEN1, HIGH);
    //update values of time
    newtime = millis();
    oldtime = millis();
    
    while ( (newtime-oldtime) <= delay_time){
      newtime = millis();
      Serial.print("Difference in time is: ");
      Serial.println(newtime-oldtime);
      if (digitalRead(PED1) == LOW){
        break;
      }
    }
    digitalWrite(LEDGREEN1, LOW);
    digitalWrite(LEDYELLOW1, HIGH);
    delay(1000); 
    digitalWrite(LEDYELLOW1, LOW);
    digitalWrite(LEDRED2, LOW);
}
