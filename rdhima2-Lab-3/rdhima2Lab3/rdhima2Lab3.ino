
// 1- FirstName:Roshan LastName-Dhimal - UIN - 661652338
// 2- Lab 3 : LCD
// 3- Description - Lab LCD requires to Print your first name,to the bottom row of the LCD,
//                  and your favorite quote to the top row. The quote should be longer than 16 characters, 
//                  so it does not fit on the screen. The quote should scroll across the top row so you can read the whole thing. 
//                  Only the quote should scroll, the bottom row with your name should stay in place, 
//                   but the name should be in the center of the LCD 
//                   with (as close as possible) equal spacing on each side.
// 4- Assumptions - The code used below should enable setup arduino display name and quote
// 5- References- https://docs.arduino.cc/learn/electronics/lcd-displays
        
//where did you find code snippets, ideas, inspirations? if no references are used say: "no references used" - failing to list the references you used can result in plagiarism
// 6- Demo - Neel Parikh  ; Time: 2 pm; lab 2; Date: 10/10/2022


// include the library code:
#include <LiquidCrystal.h>

// initializing the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


// set up the long character i.e is the quote
char *quote = "  The lab three of the computer class. here we go ";
// the index of the quote pos
int pos = 0; 
int curPos = 0;



// helper function to update the scroll
void resetDisplay(){
  int numLength = strlen(quote);
  lcd.setCursor(0,pos);
    // check to reset to start postion
  if (curPos == (numLength-1)){
    curPos = 0;    
  }
  // check to start postion if less then size of 16*2
  if (curPos < numLength - 16){
    for (int i = curPos; i < 16 + curPos; i++){
      lcd.print(quote[i]);
//printf(quote[i]);
//      lcd.scrollDisplayLeft(quote);      
    }
      
  }

  curPos++;
}

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // print in the middle of screen
  lcd.setCursor(4,1);
  // Print a message to the LCD.
  lcd.print("rdhimal");
}

void loop() {
  // call to scroll
  resetDisplay();
  delay(400);
  resetDisplay();
}
