
// 1- FirstName:Roshan LastName-Dhimal - UIN - 661652338
// 2- Lab 4 : Multiple Inputs and Outputs
// 3- Description -
// 5- References- https://create.arduino.cc/projecthub/DCamino/ambient-light-sensor-using-photo-resistor-and-led-lights-9b7f39

//where did you find code snippets, ideas, inspirations? if no references are used say: "no references used" - failing to list the references you used can result in plagiarism
// 6- Demo - Micheal  ; Time: 3:30 pm; lab 2; Date: 10/10/2022

// variable
//int Led0 = low; led1 = low; led2 = low; led3 = low;
int buzzerPin = 9;
int light = 0;
int photoPin = A3;
int voltPin = A2;
int toneNum = 0;


void setup() {
  // setup
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
//  pinMode(buzzerPin, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(A3, INPUT);
  pinMode(A2, INPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
   light = analogRead(photoPin);
   toneNum = analogRead(voltPin);
//   Serial.println(light);
//    Serial.println(toneNum);
    tone(9, toneNum);
   
   if(light > 500) { 
//        Serial.println("light!");
        digitalWrite(2,LOW);
        digitalWrite(3,LOW); 
        digitalWrite(4,LOW);
        digitalWrite(7,LOW); 
    }
    else if(light > 229 && light < 280) {
//        Serial.println("It is 1 light!");
        digitalWrite(2,HIGH);
        digitalWrite(3,LOW); 
        digitalWrite(4,LOW);
        digitalWrite(7,LOW); 
    }
    else if(light > 229 && light < 250) {
//        Serial.println("It is low light!");
        digitalWrite(2,HIGH);
        digitalWrite(3,LOW); 
        digitalWrite(4,LOW);
        digitalWrite(7,LOW); 
    }
    else if(light > 229 && light < 350) {
//        Serial.println("It is average light!");
        digitalWrite(2,HIGH);
        digitalWrite(3,HIGH); 
        digitalWrite(4,LOW);
        digitalWrite(7,LOW); 
    }

    else if(light > 229 && light < 451) {
//        Serial.println("It is 3rd light!");
        digitalWrite(2,HIGH);
        digitalWrite(3,HIGH); 
        digitalWrite(4,HIGH);
        digitalWrite(7,LOW); 
    }
    else { // If it's dark...
//        Serial.println("It is pretty dark!");
        digitalWrite(2,HIGH);
        digitalWrite(3,HIGH); 
        digitalWrite(4,HIGH);
        digitalWrite(7,HIGH); 
    }
    delay(1000); // don't spam the computer!

}
