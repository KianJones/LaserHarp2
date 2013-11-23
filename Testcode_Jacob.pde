
//imports minim for processing
import ddf.minim.*;
import ddf.minim.signals.*;
import ddf.minim.analysis.*;
import ddf.minim.effects.*;
//imports arduino for processing
import processing.serial.*;
import cc.arduino.*;

//Definitions: modify these to change the loopdelay or the beamcount
final int BEAMCOUNT = 8;
final int loopdelay = 200;

Arduino arduino; //arduino class
Minim minim; //minim class
AudioOutput[] audioout = new AudioOutput[BEAMCOUNT]; //audio output
AudioPlayer[] piano = new AudioPlayer[BEAMCOUNT]; //audio player



int pinarray[] = {2,3,4,5,6,7,8,9}; //analog array for the beam sensors.
boolean playarrayold[] = {false,false,false,false,false,false,false,false}; 
boolean playarraynew[] = {false,false,false,false,false,false,false,false};
int[] cal = new int[BEAMCOUNT]; //stores the calibration data.

void setup() {
  size(512, 200);
  minim = new Minim(this); //sets up the minim class
  arduino = new Arduino(this, Arduino.list()[0], 57600); //sets up the arduino
  for (int i = 0; i<BEAMCOUNT; i++) {
    piano[i] = minim.loadFile("clarinet.pp." + (i+1) + ".aiff", 2048);
    arduino.pinMode(pinarray[i], arduino.INPUT); //loads the specific file needed. Stored in the TEST folder
  }
}

//loops infinitely, checks to see if laser is broken, if so plays note. as soon as the note is not held, dies quickly.
void draw() 
{
  for (int i = 0; i<BEAMCOUNT; i++) 
  {
    if (ReadPhoto(pinarray[i]) == 1) // 0 = off 1 = on
      playarraynew[i] = true; // 
    else
      playarraynew[i] = false;
    if (playarraynew[i] != playarrayold[i])
    {
      if (playarrayold[i] == true)
      {
        piano[i].shiftGain(piano[i].getGain(), 0, 6000);
      }
      else
      {
        if (pinarray[i] == 3 || pinarray[i] == 5 || pinarray[i] == 6) 
        {
          piano[i].play(150); // 150
          piano[i].setGain(6.0);
        }
        else
        {
          piano[i].setGain(6.0);
          piano[i].play(325); // 325
          //piano[i].pause();
        }
        println("piano gain " + piano[i] + " " + piano[i].getGain());
        println(ReadPhoto(pinarray[i]));
      }
    playarrayold[i] = !playarrayold[i]; // !playarrayold[i]
    }
  }
  delay(loopdelay); 
}
//checks the photosensor for its value with respect to the calibration value
int ReadPhoto(int port)
{
  return arduino.digitalRead(port);
}
//used to successfully close out the processing code, DO NOT CHANGE THIS. 
void stop()
{
  for (int i=0; i<BEAMCOUNT; i++) 
  {
    audioout[i].close();
    piano[i].close();
  }
  minim.stop(); 
  super.stop();
}

