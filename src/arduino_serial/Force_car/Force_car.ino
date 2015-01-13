 // January 12, 2014
 // Sruti Modekurty

 //This program feeds high and low values to the pins that are 
 // connected to the forward, back, left, and right buttons on the
 // remote control
 //1 - forward, 2 - reverse, 3 - left, 4 - right,
// 5 - forward left, 6 - forward right, 7 - back left (right), 8 - back right (left)
 
 

 void setup() {
   
   pinMode(13, OUTPUT); //forward
   pinMode(12, OUTPUT); //backward
   pinMode(11, OUTPUT); //left
   pinMode(10, OUTPUT); //right
   Serial.begin(9600);
   Serial.println("Ready");
   
 }
 
 void loop() {
   
   char command = ' ';
   if (Serial.available()) {
     char command = Serial.read();
     Serial.println(command);
   }
   delay(100);
   switch (command){
     case 0:    
       digitalWrite(13, HIGH);
       digitalWrite(12, HIGH);
       digitalWrite(11, HIGH);
       digitalWrite(10, HIGH);
       delay(1000);
       break;
     case 1:    
       digitalWrite(13, LOW);
       break;
     case 2:
       digitalWrite(12, LOW);
       break;
     case 3:
       digitalWrite(11, LOW);
       break;    
     case 4:
       digitalWrite(10, LOW);
       break;
     case 5:
       digitalWrite(13, LOW);
       digitalWrite(11, LOW);
       break;
     case 6:
       digitalWrite(13, LOW);
       digitalWrite(10, LOW);
       break;
     case 7:
       digitalWrite(12, LOW);
       digitalWrite(10, LOW);
       break;
     case 8: 
       digitalWrite(12, LOW);
       digitalWrite(11, LOW);
       break;
     default: 
       digitalWrite(13, HIGH);
       digitalWrite(12, HIGH);
       digitalWrite(11, HIGH);
       digitalWrite(10, HIGH);
   }
     delay(250);

 }
   
   
//   //forward
//   digitalWrite(13, LOW);
//   delay(250);
//   //forward left
//   digitalWrite(11, LOW);
//   delay(250);
//   //stop
//   digitalWrite(13, HIGH);
//   digitalWrite(12, HIGH);
//   digitalWrite(11, HIGH);
//   digitalWrite(10, HIGH);
//   delay(1000);
//   //backward
//   digitalWrite(12, LOW);
//   delay(250);
//   //backward right
//   digitalWrite(10, LOW);
//   delay(250);
//   //stop
//   digitalWrite(12, HIGH);
//   digitalWrite(13, HIGH);
//   digitalWrite(11, HIGH);
//   digitalWrite(10, HIGH);
//   delay(1000);
//   
//   //forward
//   digitalWrite(13, LOW);
//   delay(250);
//   //forward right
//   digitalWrite(10, LOW);
//   delay(250);
//   //stop
//   digitalWrite(13, HIGH);
//   digitalWrite(12, HIGH);
//   digitalWrite(11, HIGH);
//   digitalWrite(10, HIGH);
//   delay(1000);
//   //backward
//   digitalWrite(12, LOW);
//   delay(250);
//   //backward left
//   digitalWrite(11, LOW);
//   delay(250);
//   //stop
//   digitalWrite(12, HIGH);
//   digitalWrite(13, HIGH);
//   digitalWrite(11, HIGH);
//   digitalWrite(10, HIGH);
//   delay(1000); 
// }
   
    
 
