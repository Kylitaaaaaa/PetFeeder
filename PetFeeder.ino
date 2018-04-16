#include <TimeLib.h>  
#include <Servo.h> 

//https://playground.arduino.cc/Code/Time

int setDay;
boolean hadLunch = false;
boolean hadDinner = false;

//lunch : 12:00nn
int lunchHr = 12;
int lunchMin = 0;

//dinner : 6:00pm
int dinnerHr = 18;
int dinnerMin = 0;

//Servo
Servo myservo;

void setup()  {
 Serial.begin(9600);
 int hr = 11;
 int min = 59;
 int sec = 59;
 int day = 2;
 int month = 1;
 int yr = 2018;
 setDay = day;
 setTime(hr,min,sec,day,month,yr);

 //setup Servo
  myservo.attach(9);
  myservo.write(90);  // set servo to mid-point
 
 delay(1000);
}

void loop()
{
  time_t t = now();      

  int currSec = second(t);
  int currMin = minute(t);
  int currHr = hour(t);
  int currDay = day(t);

  Serial.print("min: ");
  Serial.println(currMin);
  
  Serial.print("sec: ");
  Serial.println(currSec);

  Serial.print("lunch: ");
  Serial.println(hadLunch);
  

  if(currDay != setDay){
    hadLunch = false;
    hadDinner = false;
  }

  if(currMin == lunchMin &&
      currHr == lunchHr &&
      !hadLunch){
        hadLunch = true;
        Serial.print("Lunch Time!");
        Serial.println(hadLunch);
      }
  else if(currMin == dinnerMin &&
      currHr == dinnerHr &&
      !hadDinner){
        Serial.println(currMin);
        Serial.println(currSec);
        Serial.println("Dinner Time!");
        hadDinner = true;
      }

  Serial.println();
      
  delay(1000);
}

