// Name = roshan dhimal
// Assignment = lab-1-get started with Arduino
// 1- FirstName:Roshan LastName-Dhimal - UIN - 661652338
// 2- Lab 1 - 1-3 way blink
// 3- Description - So the code below would turn on onboard high then red then green seqentially
// 4- Assumptions - the code taken millis second time as refrence as delay would to blink sequentially
// 5- References - https://docs.arduino.cc/built-in-examples/digital/BlinkWithoutDelay
//             https://docs.arduino.cc/built-in-examples/basics/Blink
//             https://www.arduino.cc/reference/en/
//where did you find code snippets, ideas, inspirations? if no references are used say: "no references used" - failing to list the references you used can result in plagiarism 
// 6- Demo - Neel Parikh Time: 2 pm lab; Date: 9/12/2022


// variables of led pinMode In the Arduino board and the state
int led = LOW;  // buitin Led
int led2 = LOW;  // red led 
int led3 = HIGH;  // green led turn on high at first 

// store last time LED for the millis as it holds hige time
unsigned long prevMillis = 0;

 //constant interval for which the led blink ( in milliseconds)
const long constIinterval = 1000; 

void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);

}


void loop() {
  unsigned long currMillis = millis();
   if (currMillis - prevMillis >= constIinterval) {
    prevMillis = currMillis;  

    // if onboard on turn un red light
    if (led == HIGH){
    led = LOW;
    led2 = HIGH;   
    
    }
    // if red light on turn on green 
    else if (led2 == HIGH){
      led2 = LOW;
      led3 = HIGH;
      
    }
    // if green on turn onboard light
   else if(led3 == HIGH){
    led3 = LOW;
    led = HIGH; 

   }
    digitalWrite(LED_BUILTIN, led); 
    digitalWrite(12, led2);
    digitalWrite(11, led3); 
  }
}
