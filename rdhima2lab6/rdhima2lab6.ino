
// Assignment = Lab 6 - Serial Communication
// 1- FirstName:Roshan LastName-Dhimal - UIN - 661652338
// 3- Description -  There are two different options for this lab. You may complete this lab by yourself using one Arduino, or with a partner using two Arduinos. If you complete this lab with a partner, make sure to add them to your submission on gradescope. Both group members should be present for the lab demo. If you a
// 4- Assumptions - serial cnection fromboth ends
//// 5- References-
//where did you find code snippets, ideas, inspirations? if no references are used say: "no references used" - failing to list the references you used can result in plagiarism
// 6- Demo - Micheal  ; Time: 3:39pm; lab 6; Date: 10/31/2022

#include <SoftwareSerial.h>
//int RX;
//int TX;
bool switchSt = false;bool switchSt2 = false;
int counter = 0;
int counter2 = 0;
SoftwareSerial mySerial(9,10);



void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  
  // buttons
  pinMode(12,INPUT);
  pinMode(11,INPUT);
  // ledfs
  pinMode(6,OUTPUT);  
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
}

void loop() {
   switchSt = digitalRead(12);
   switchSt2 = digitalRead(11);

  if (switchSt == true){
      Serial.write('D');
      delay(500);
      counter += 1;
  }

    if (switchSt2 == true){
      mySerial.write('E');
      delay(500);
      counter2 += 1;
  }
  if (mySerial.available()){
    mySerial.read();
  
    if (bitRead(counter,0)){
       digitalWrite(6,HIGH);

    }
    else{
      digitalWrite(6,LOW);
    }
    if (bitRead(counter,1)){
       digitalWrite(5,HIGH);

    }
    else{
      digitalWrite(5,LOW);
    }

  }

  // next portion of the button whennavailable
  if (Serial.available()){
    Serial.read();
    if (bitRead(counter2,0)){
       digitalWrite(3,HIGH);

    }
    else{
      digitalWrite(3,LOW);
    }
    if (bitRead(counter2,1)){
       digitalWrite(2,HIGH);

    }
    else{
      digitalWrite(2,LOW);
    }

  }
}
