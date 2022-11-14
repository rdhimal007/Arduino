
// Assignment = Lab 8 - Graphing Sensor Data on a PC
// 1- FirstName:Roshan LastName-Dhimal - UIN - 661652338
// 3- Description - in this lab we are getting the hardware input or reading from the arduino like the phtocell potentiometer
// to produce a graph in the processing software, and this is carried out by communicating or making communication from arduino to PC
// we use split to differentiate the two input reading and trim it to maka series of input 
// 4- Assumptions - We assume that the input from the analog reading goes to PC to produce graph
// 5- References-https://processing.org/reference/line_.html
// https://docs.arduino.cc/built-in-examples/communication/Graph
//https://learn.sparkfun.com/tutorials/connecting-arduino-to-processing#introduction
//   https://processing.org/reference/split_.html            
// 6- Demo - Micheal  ; Time: 2:46; lab 8; Date: 11/14/2022


// variables for the input hardware
int valInput;
int valInput2;

void setup() {
 // initalize 
 Serial.begin(9600);

 // photocell 
 pinMode(A3, INPUT);
 // potentiometer
 pinMode(A0, INPUT);
}


// Graphing Sensor Data on a PC
void loop() {
  // this is photocell
  valInput = analogRead(A3);
// this is potentiometer
  valInput2 = analogRead(A0);
  Serial.println(String(valInput)+ " " +String(valInput2)); 
  delay(100);
}
