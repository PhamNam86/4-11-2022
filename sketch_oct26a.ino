const int TRIG_PIN = 16; // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int ECHO_PIN = 17; // Arduino pin connected to Ultrasonic Sensor's ECHO pin
float duration_us, distance_cm;

// Variable to store text message
String textMessage;
// Create a variable to store Lamp state
String lampState = "HIGH";
int command;
int led = 5;
 
void setup()
{
 
 Serial.begin(115200); 

 pinMode(TRIG_PIN, OUTPUT); // set arduino pin to output mode
 pinMode(ECHO_PIN, INPUT);  // set arduino pin to input mode

 pinMode(led, OUTPUT);
 digitalWrite(led, LOW);
}
/*
//text message
void control_speed()
{
   if(Serial.available()>0){
   textMessage = Serial.readString();
    Serial.println(textMessage);
    //updateSerial();    
    delay(10);
  } 
  if(textMessage.indexOf("TURN ON")>=0)
  {
    analogWrite(led, 255);
    }
  if(textMessage.indexOf("MEDIUM")>=0)
    {
      analogWrite(led, 200);
      }
      if(textMessage.indexOf("LOWEST")>=0)
    {
      analogWrite(led, 150);
      }
      if(textMessage.indexOf("TURN OFF")>=0)
    {
      analogWrite(led, 0);
      }
}
*/
void highest()
{
  analogWrite(led, 255);
  }
void medium()
{
  analogWrite(led, 200);
  }
void lowest()
{
  analogWrite(led, 150);
  }
  void stop_mos()
{
  analogWrite(led,0);
  }
void loop()
{
 if (Serial.available() > 0) { 
  command = Serial.read();
  
      if (command == 'O') highest();
      else if (command == 'M') medium();
      else if (command == 'C') lowest();
      else if (command == 'P') stop_mos();
  }
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN, HIGH);
  // calculate the distance
  distance_cm = 0.017 * duration_us;
  // print the value to Serial Monitor
  //Serial.print("distance: ");
  //Serial.print(distance_cm);
  //Serial.println(" cm");
  //Serial.println(a);
  delay(10);
  
  int sdata1 = digitalRead(19);        //IR SENSOR
  Serial.println(sdata1); 
  int sdata2 = round(distance_cm);    //ULTRASOUND SENSOR
  Serial.println(sdata2); 

  if((sdata1 == 1)  || (sdata2 <= 20) || ((sdata1 == 1)  && (sdata2 <= 20)))              
  {
      Serial.println("ON");  
  }
  else
  {
      Serial.println("OFF");
  }

   delay(1000); 

}

