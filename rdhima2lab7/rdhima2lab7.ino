// 1- FirstName:Roshan LastName-Dhimal - UIN - 661652338
// 2- Lab 7 : LCD interrupt
// 3- Description -Information about how to tell the system to call your Interrupt Service Routine (ISR) can be found at: http://arduino.cc/en/Reference/attachInterrupt 
//                  Write a program for the arduino that utilizes interrupts. When no button has been pressed your 16x2 display should say "Waiting for X seconds", where X will be updated as time goes on.
// 4- Assumptions - LCD screens interrupts and time to zero when its is iterripted
// 5- References-  http://arduino.cc/en/Reference/attachInterrupt
//               https://www.arduino.cc/en/Reference/Millis
// demo = Amir, time 3:30 pm
        
//where did you find code snippets, ideas, inspirations? if no references are used say: "no references used" - failing to list the references you used can result in plagiarism
// 6- Demo -   ; Time: 2 pm; lab 2; Date: 10/10/2022
#include <LiquidCrystal.h>
const int rs = 7, en = 6, d4 = 9, d5 = 8, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const byte interruptPin1 = 2;
unsigned long myTime;
const byte interruptPin2 = 3;
bool look = false;
bool look2 = false;


void setup() {
  
   pinMode(interruptPin1, INPUT_PULLUP);
   pinMode(interruptPin2, INPUT_PULLUP);
   
   attachInterrupt(digitalPinToInterrupt(interruptPin1), interruptText, CHANGE );
   attachInterrupt(digitalPinToInterrupt(interruptPin2), resetT, CHANGE );

  
  
}

void loop() {
    
    lcd.begin(16, 2);
    if (look == true){
        lcd.print("Interupted");
    }


    else{
     // myTime = millis()/1000;     
      lcd.print("Waiting for ");
      lcd.print((millis() - myTime) / 1000);
    }
    delay(1000);

}

void interruptText()
{
    look = true;
}

void resetT(){
  if (look == true){
  look = false;
  myTime = millis();
  }
  
}
