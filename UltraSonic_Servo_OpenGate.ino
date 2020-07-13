// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 5; 
// Create a servo object 
Servo Servo1; 

#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
bool isOpen=false;

void setup() { 
   // We need to attach the servo to the used pin number 
   Servo1.attach(servoPin); 

   pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
  
  Servo1.write(95); 
}


void loop() {
  
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  if(distance < 20)
  {
    opengate();
  }
  else
  {
    closeGate();
  }
  
delay(2000);
}

void closeGate()
{
   if(isOpen) {
   Servo1.write(95); 
   isOpen=false;
 }
}


void opengate(){ 
   // Make servo go to 0 degrees 
  if(!isOpen) {
    // Make servo go to 90 degrees 
    Servo1.write(0); 
  }

   isOpen=true;
   delay(2000);
  
    
}
