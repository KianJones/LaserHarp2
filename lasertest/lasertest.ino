int BEAMCOUNT = 8;
int pin_array[] = {2,3,4,5,6,7,8,9};


void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < BEAMCOUNT; i++){
      pinMode(pin_array[i], INPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly: 
  for(int i = 0; i < BEAMCOUNT; i++){
    if(digitalRead(pin_array[i]) == 1){
      //Serial.print("off: ");
      Serial.print(pin_array[i]);
      Serial.println();
    }
  }
  Serial.println();
  //delay(100);
}
