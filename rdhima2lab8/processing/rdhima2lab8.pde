
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




import processing.serial.*;

  Serial myPort;        // The serial port
  int xPos = 1;         // horizontal position of the graph
  float inByte = 0;
  
  float potenti0 = 0;
  float photoCell = 0;


  void setup () {
    // set the window size:
    size(900, 500);

    // List all the available serial ports
    // if using Processing 2.1 or later, use Serial.printArray()
    println(Serial.list());

   
    // Arduino, at first in Serial.list()[0].
    myPort = new Serial(this, Serial.list()[0], 9600);

    // don't generate a serialEvent() unless you get a newline character:
    myPort.bufferUntil('\n');

    // set initial background:
    background(0);
  }

  void draw () {
    // draw the line:

    // at the edge of the screen, go back to the beginning:

      stroke(127, 34, #8dd9cc);
      line(xPos, height/2, xPos, height/2 - photoCell);
 
       stroke(127, 66, 255);
       //line(xPos, height, xPos, height- photoCell);
       line(xPos, height, xPos, height - potenti0);

       
        
    if (xPos >= width) { 
      xPos = 0;
      background(0);
    } else {
      // increment the horizontal position:
     xPos++;
    }
  }

  void serialEvent (Serial myPort) {
    // get the ASCII string:
    String inString = myPort.readStringUntil('\n');
    String[] midinputSlplit = inString.split(" ");
    String photoIn = midinputSlplit[0];
    String ptoentio = midinputSlplit[1];

    if (inString != null) {
      // trim off any whitespace:
      inString = trim(inString);
      photoIn = trim(photoIn);
      ptoentio = trim(ptoentio);
      
      // convert to an int and map to the screen height:
      inByte = float(inString);
      potenti0 = float(photoIn);
      photoCell = float(ptoentio);
      // debug the thing
      println(inByte);
      println(potenti0);
      println(photoCell);
      
      //put the map
      //inByte = map(inByte, 0, 1023, 0, height);
      potenti0 = map(potenti0, 0, 1023,0, height/2);
      
      photoCell = map(photoCell, 0, 1023,0, height);
    }
  }
