import g4p_controls.*;
import processing.serial.*;
Serial mySerial;
import java.awt.Font;
PrintWriter output;
PFont font;
int downloadFlag = 0;
String value;
boolean firstContact = false;

void setup() {
  size(820, 420, JAVA2D);
  background(200);
  font = createFont ("Serif",height);
  textFont (font);
  fill(229,20,0);
  textSize(35);
   mySerial = new Serial( this, Serial.list()[0], 9600 );
   output = createWriter( "Data.csv" );
   createGUI();
   customGUI();
}

void draw() {
    //String val = mySerial.readString();
    //while(val != "x");
    if (mySerial.available() > 0 ) {
            value = mySerial.readString();
         if ( value != null ) {
              //mySerial.write('x');
              output.print( value );
          }
    }
}

void keyPressed() {
    output.flush();  // Writes the remaining data to the file
    output.close();  // Finishes the file
    exit();  // Stops the program
}

public void customGUI(){

}