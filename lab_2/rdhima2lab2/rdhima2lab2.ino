
// Assignment = Lab 2 - Input and Output
// 1- FirstName:Roshan LastName-Dhimal - UIN - 661652338
// 2- Lab 2 : Input and Output
// 3- Description - So the code below would turn on onboard uses three pushbutton switch that will light the 4 led and turn off using the concept of the 4bit binary counter and the two button used will increment or decrement the counter that will determine the state of the led
// 4- Assumptions - The code used below should enable setup arduino to turn on light of led until less than 15 and other button should turn off led following
//// 5- References- https://docs.arduino.cc/built-in-examples/digital/Button
//                  https://makeabilitylab.github.io/physcomp/arduino/switch_2.html
//                  http://www.ladyada.net/learn/arduino/lesson5.html
//                  https://www.arduino.cc/reference/en/language/functions/communication/serial/
//where did you find code snippets, ideas, inspirations? if no references are used say: "no references used" - failing to list the references you used can result in plagiarism
// 6- Demo - Karan Jogi ; Time: 2 pm; lab 2; Date: 9/19/2022

// declare variables for the arduino
int switch_1 = LOW, switch_2 = LOW, led_0 = LOW, led_1 = LOW, led_2 = LOW, led_3 = LOW, count = 0;
bool switchState_1 = true, switchState_2 = true;

void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
}

void loop () {
  // inserting pushbutton at 4 and 5 respectively
  switch_1 = digitalRead(4);
  switch_2 = digitalRead(5);

  // condtion to check if pushbutton is turned on and high then count until 15
  if (switch_1 == HIGH && switchState_1 == true && count < 15) {
    ++count;
  }

  // condtion to check if pushbutton 2 is turned on and high then count if greter then 0 and less then 15
  if (switch_2 == HIGH && switchState_2 == true && count > 0) {
    --count;
  }

  // if case: for the pushbutton to turn state false when turned on
  if (switch_1 == HIGH){
     switchState_1 = false;
   }
   else {
     switchState_1 = true;
   }
  if (switch_2 == HIGH) {
    switchState_2 = false;
  } else {
    switchState_2 = true;
  }

  // if case: For the LEDs to read the bits of the count i.e the number
  // if count  x equal to the designated bitread(x, n) number n then turn high
  if(bitRead(count, 0)){
    led_0 = HIGH;
  }  else {
    led_0= LOW;
  }
  if(bitRead(count, 1)){
    led_1 = HIGH;
  }  else {
    led_1 = LOW;
  }
    if(bitRead(count, 2)){
    led_2 = HIGH;
  }  else {
    led_2 = LOW;
  }
    if(bitRead(count, 3)){
    led_3 = HIGH;
  }  else {
    led_3 = LOW;
  }

  Serial.print(count);
  Serial.print("\n");
  digitalWrite(9, led_0);
  digitalWrite(10, led_1);
  digitalWrite(11, led_2);
  digitalWrite(12, led_3);
}
