// the number of beams
int BEAMCOUNT = 8;
//digital i/o pins
int pin_array[] = {2,3,4,5,6,7,8,9};

// start out with the states the same
boolean old_state[] = {true,true,true,true,true,true,true,true};
boolean new_state[] = {true,true,true,true,true,true,true,true};

void setup() {
  //all of the pins are inputs from the photoresistors
  for(int i = 0; i < BEAMCOUNT; i++){
      pinMode(pin_array[i], INPUT);
  }
}

void loop() {
  // loop over the beams
  for(int i = 0; i < BEAMCOUNT; i++){
    
    // if the laser is broken, show that that pin changed state
    // or rather, that it changed resistance from the last time 
    // it was checked.
    if(digitalRead(pin_array[i]) == 1)
      new_state[i] = false;
    else
      new_state[i] = true;
    
    // if the state that it is currently in is different than the
    // one it was in the last time it was checked
    if(old_state[i] != new_state[i]){
      
      // check for true, so that only gets the change from laser
      // to no laser.
      // print the sensor number for now
      // later will play sound
      if(old_state[i] == true)
        Serial.println(pin_array[i]);
      
      // changes the old state to what the new state is
      old_state[i] = !old_state[i];
    }
    
  }
}
