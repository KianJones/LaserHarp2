/* Photocell simple testing sketch. 
 
Connect one end of the photocell to 5V, the other end to Analog 0.
Then connect one end of a 10K resistor from Analog 0 to ground
 
For more information see http://learn.adafruit.com/photocells */
 
int photoR = 7;     // the cell and 10K pulldown are connected to a0
int photoY = 6;
int photoG = 5;
int R_reading;     // the analog reading from the analog resistor divider
int Y_reading;
int G_reading;
int REDpin = 11;
int YELpin = 10;
int GRNpin = 9;
int LEDbrightness;
 
void setup(void) {
  // We'll send debugging information via the Serial monitor
  Serial.begin(9600);
   pinMode(REDpin, OUTPUT);
   pinMode(YELpin,OUTPUT);
   pinMode(GRNpin,OUTPUT);
   pinMode(photoR, INPUT);
   pinMode(photoY, INPUT);
   pinMode(photoG, INPUT);
}
 
void flash(int pin){
  digitalWrite(pin,HIGH);
  delay(10);
  digitalWrite(pin,LOW);
} 
 
void loop(void) {
  R_reading = digitalRead(photoR);  
  Y_reading = digitalRead(photoY);  
  G_reading = digitalRead(photoG);    
 
  /*Serial.print("red reading = ");
  Serial.print(R_reading);     // the raw analog reading
  Serial.print(", yellow reading = ");
  Serial.print(Y_reading);
  Serial.print(", green reading = ");
  Serial.print(G_reading);
  Serial.println();*/
 
  // We'll have a few threshholds, qualitatively determined
  /*if (photocellReading < 10) {
    Serial.println(" - Dark");
  } else if (photocellReading < 200) {
    Serial.println(" - Dim");
  } else if (photocellReading < 500) {
    Serial.println(" - Light");
    flash(LEDpin);
  } else if (photocellReading < 800) {
    Serial.println(" - Bright");
    flash(LEDpin);
  } else {
    Serial.println(" - Very bright");
  }*/
  if(R_reading == 0){
    //Serial.println("off");
  }else{
    //Serial.println("on");
    Serial.print("r");
    flash(REDpin);
  }
  
  if(Y_reading == 0){
    //Serial.println("off");
  }else{
    Serial.print("y");
    flash(YELpin);
  }
  
  if(G_reading == 0){
    //Serial.println("off");
  }else{
    Serial.print("g");
    flash(GRNpin);
  }
  Serial.println();
  //delay(1000);
}
