 // January 12, 2014
 // Sruti Modekurty

 //This program feeds high and low values to the pins that are 
 // connected to the forward, back, left, and right buttons on the
 // remote control

 void setup() {
   
   pinMode(13, OUTPUT);
   pinMode(12, OUTPUT);
   pinMode(11, OUTPUT);
   pinMode(10, OUTPUT);
 }
 
 void loop() {
  
   //forward
   digitalWrite(13, LOW);
   delay(250);
   //forward left
   digitalWrite(11, LOW);
   delay(250);
   //stop
   digitalWrite(13, HIGH);
   digitalWrite(12, HIGH);
   digitalWrite(11, HIGH);
   digitalWrite(10, HIGH);
   delay(1000);
   //backward
   digitalWrite(12, LOW);
   delay(250);
   //backward right
   digitalWrite(10, LOW);
   delay(250);
   //stop
   digitalWrite(12, HIGH);
   digitalWrite(13, HIGH);
   digitalWrite(11, HIGH);
   digitalWrite(10, HIGH);
   delay(1000);
   
   //forward
   digitalWrite(13, LOW);
   delay(250);
   //forward right
   digitalWrite(10, LOW);
   delay(250);
   //stop
   digitalWrite(13, HIGH);
   digitalWrite(12, HIGH);
   digitalWrite(11, HIGH);
   digitalWrite(10, HIGH);
   delay(1000);
   //backward
   digitalWrite(12, LOW);
   delay(250);
   //backward left
   digitalWrite(11, LOW);
   delay(250);
   //stop
   digitalWrite(12, HIGH);
   digitalWrite(13, HIGH);
   digitalWrite(11, HIGH);
   digitalWrite(10, HIGH);
   delay(1000); 
 }   
 
