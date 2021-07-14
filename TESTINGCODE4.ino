// Pin Definitions
  // Rows are connected to
const int row1 = 2;
const int row2 = 3;
const int row3 = 4;
const int row4 = 5;
const int row5 = 6;
const int row6 = 7;
const int row7 = 8;

  // Velocity Pedal
int velPot = A1;
//Velocity Var
int velRead = velPot;
int lastVel;
// Sustain pedal Input
int susPin = 12;

//Sustain State Var
int susRead;
// sustain last
int lastSus = LOW;

// variable definitions

int joyX = 0; //Pitch Bend
int lastX = 0; //last value for x axis
int joyY = 0; //CC1 und CC20
int lastY = 0; //last value for y axis


int channelSelect = 0;
int lastChannel;
int channelRead;

int pitchBend = 0;
int controllerWert = 0;

// The 74HC595 uses a serial communication 
// link which has three pins
const int clock = 9;
const int latch = 10;
const int data = 11;


/*
// The 74HC595 uses a serial communication 
// link which has three pins
const int clockTwo = 11;
const int latchTwo = 12;
const int dataTwo = 13;
*/



uint8_t keyToMidiMap[32];

boolean keyPressed[32];




uint8_t keyToMidiMapTwo[24];


boolean keyPressedTwo[24];




// use prepared bit vectors instead of shifting bit left everytime
int bits[] = { B11111110,
               B11111101, 
               B11111011, 
               B11110111,
               B11101111,
               B11011111,
               B10111111,
               B01111111
               };


int noteVelocity;


// use prepared bit vectors instead of shifting bit left everytime
int bitsTwo[] = { B11111110,
               B11111101, 
               B11111011, 
               B11110111,
               B11101111,
               B11011111,
               B10111111,
               B01111111
               };


int joyPin1 = A2; // slider variable connected to analog pin 0
int joyPin2 = A3; // slider variable connected to analog pin 1
/*int value1 = 0; // variable to read the value from analog pin 0
int value2 = 0; // variable to read the value from analog pin 1
*/
 

void scanColumn(int value)
{
  digitalWrite(latch, LOW);
     shiftOut(data, clock, MSBFIRST, B11111111); //right sr
     shiftOut(data, clock, MSBFIRST, value); //left sr
  digitalWrite(latch, HIGH);
}

void scanColumnTwo(int valueTwo) {
  digitalWrite(latch, LOW); //Pulls the chips latch low
      shiftOut(data, clock, MSBFIRST, valueTwo); //right sr
      shiftOut(data, clock, MSBFIRST, B11111111); //right sr
  digitalWrite(latch, HIGH); //Pulls the latch high displaying the data
}


/*

// 74HC595 shift to next column
void scanColumn(int value) {
  digitalWrite(latch, LOW); //Pulls the chips latch low
  shiftOut(data, clock, MSBFIRST, value); //Shifts out the 8 bits to the shift register
  digitalWrite(latch, HIGH); //Pulls the latch high displaying the data
}





// 74HC595 shift to next column
void scanColumnTwo(int valueTwo) {
  digitalWrite(latchTwo, LOW); //Pulls the chips latch low
  shiftOut(dataTwo, clockTwo, MSBFIRST, valueTwo); //Shifts out the 8 bits to the shift register
  digitalWrite(latchTwo, HIGH); //Pulls the latch high displaying the data
}

*/

void setup() {
  
  // Map scan matrix buttons/keys to actual Midi note number. Lowest num 41 corresponds to F MIDI note.
  keyToMidiMap[0] = 41;
  keyToMidiMap[1] = 42;
  keyToMidiMap[2] = 43;
  keyToMidiMap[3] = 44;
  keyToMidiMap[4] = 45;
  keyToMidiMap[5] = 46;
  keyToMidiMap[6] = 47;
  keyToMidiMap[7] = 48;
  
  keyToMidiMap[8] = 49;
  keyToMidiMap[1 + 8] = 50;
  keyToMidiMap[2 + 8] = 51;
  keyToMidiMap[3 + 8] = 52;
  keyToMidiMap[4 + 8] = 53;
  keyToMidiMap[5 + 8] = 54;
  keyToMidiMap[6 + 8] = 55;
  keyToMidiMap[7 + 8] = 56;
 
  keyToMidiMap[16] = 57;
  keyToMidiMap[1 + 16] = 58;
  keyToMidiMap[2 + 16] = 59;
  keyToMidiMap[3 + 16] = 60;
  keyToMidiMap[4 + 16] = 61;
  keyToMidiMap[5 + 16] = 62;
  keyToMidiMap[6 + 16] = 63;
  keyToMidiMap[7 + 16] = 64;
  
  keyToMidiMap[24] = 65;
  keyToMidiMap[1 + 24] = 66;
  keyToMidiMap[2 + 24] = 67;
  keyToMidiMap[3 + 24] = 68;
  keyToMidiMap[4 + 24] = 69;
  keyToMidiMap[5 + 24] = 70;
  keyToMidiMap[6 + 24] = 71;
  keyToMidiMap[7 + 24] = 72;




  // Map scan matrix buttons/keys to actual Midi note number. Lowest num 41 corresponds to F MIDI note.
  keyToMidiMapTwo[0] = 6;
  keyToMidiMapTwo[1] = 7;
  keyToMidiMapTwo[2] = 8;
  keyToMidiMapTwo[3] = 9;
  keyToMidiMapTwo[4] = 10;
  keyToMidiMapTwo[5] = 3;
  keyToMidiMapTwo[6] = 0;
  keyToMidiMapTwo[7] = 4;
  
  keyToMidiMapTwo[8] = 11;
  keyToMidiMapTwo[1 + 8] = 12;
  keyToMidiMapTwo[2 + 8] = 13;
  keyToMidiMapTwo[3 + 8] = 14;
  keyToMidiMapTwo[4 + 8] = 15;
  keyToMidiMapTwo[5 + 8] = 5;
  keyToMidiMapTwo[6 + 8] = 2;
  keyToMidiMapTwo[7 + 8] = 52;
 
  keyToMidiMapTwo[16] = 27;
  keyToMidiMapTwo[1 + 16] = 26;
  keyToMidiMapTwo[2 + 16] = 25;
  keyToMidiMapTwo[3 + 16] = 24;
  keyToMidiMapTwo[4 + 16] = 23;
  keyToMidiMapTwo[5 + 16] = 22;
  keyToMidiMapTwo[6 + 16] = 21;
  keyToMidiMapTwo[7 + 16] = 1;



  // setup pins output/input mode
  pinMode(data, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(latch, OUTPUT);

  pinMode(row1, INPUT);
  pinMode(row2, INPUT);
  pinMode(row3, INPUT);
  pinMode(row4, INPUT);


/*

   // setup pins output/input mode
  pinMode(dataTwo, OUTPUT);
  pinMode(clockTwo, OUTPUT);
  pinMode(latchTwo, OUTPUT);


*/


  pinMode(row5, INPUT);
  pinMode(row6, INPUT);
  pinMode(row7, INPUT);



  

  pinMode(susPin, INPUT);

  pinMode(velPot, INPUT);

  pinMode(joyPin1, INPUT);

  pinMode(joyPin2, INPUT);
   
    Serial.begin(31250);

  

}

void loop() {

//read the channel

 
  lastChannel = channelSelect;



 
  //read the velocity
   velRead = analogRead(A1);   // Divide by 8 to get range of 0-127 for midi
   
   if (velRead != lastVel) {
   
      if (velRead < 40) {
      velRead = 0 ;
      }


      if (velRead > 40 && velRead < 995) {
      velRead = map(velRead,40,995,0,127); 
       
      }
      
      else if (velRead > 995) {
      velRead = 127 ;
      }



                    
lastVel = velRead ; 
      
   }
  lastVel = velRead ; 

/*
      susRead = digitalRead(susPin);

    
    if (susRead != lastSus){
        if (susRead = HIGH) {
       sendeMIDI(176 + channelSelect,64,127); 
         lastSus = susRead;
       
        }
       else if ((susRead = LOW) && (lastSus = HIGH)) {
       sendeMIDI(176 + channelSelect,64,0); 
      lastSus = susRead;
       
        }
  

     }
  

*/


  //read the Sustain Pedal 
        susRead = digitalRead(susPin);
    if (susRead != lastSus){
       
       if (susRead = LOW); {
      sendeMIDI(176,64,0);
      lastSus = susRead;
      delay(10);  
        }
      
     }

         susRead = digitalRead(susPin);
    
    if (susRead != lastSus){
        if (susRead = HIGH) {
       sendeMIDI(176,64,127); 
       lastSus = susRead;
       delay(10);
        }

     }

 
  for (int col = 0; col < 8; col++) {
    
    // shift scan matrix to following column
    scanColumn(bits[col]);

    // check if any keys were pressed - rows will have HIGH output in this case corresponding
    int groupValue1 = !digitalRead(row1);
    int groupValue2 = !digitalRead(row2);
    int groupValue3 = !digitalRead(row3);
    int groupValue4 = !digitalRead(row4);

    // process if any combination of keys pressed
    if (groupValue1 != 0 || groupValue2 != 0 || groupValue3 != 0 || groupValue4 != 0) {

      if (groupValue1 != 0 && !keyPressed[col]) {
        keyPressed[col] = true;
        noteOn(144 + lastChannel, keyToMidiMap[col], velRead);
      }

      if (groupValue2 != 0 && !keyPressed[col + 8]) {
        keyPressed[col + 8] = true;
        noteOn(144 + lastChannel, keyToMidiMap[col + 8], velRead);
      }

      if (groupValue3 != 0 && !keyPressed[col + 16]) {
        keyPressed[col + 16] = true;
        noteOn(144 + lastChannel, keyToMidiMap[col + 16], velRead);
      }

      if (groupValue4 != 0 && !keyPressed[col + 24]) {
        keyPressed[col + 24] = true;
        noteOn(144 + lastChannel, keyToMidiMap[col + 24], velRead);
      }

     

    }

    //  process if any combination of keys released
    if (groupValue1 == 0 && keyPressed[col]) {
      keyPressed[col] = false;
      noteOn(144 + lastChannel, keyToMidiMap[col], 0);
    }

    if (groupValue2 == 0 && keyPressed[col + 8]) {
      keyPressed[col + 8] = false;
      noteOn(144 + lastChannel, keyToMidiMap[col + 8], 0);
    }

    if (groupValue3 == 0 && keyPressed[col + 16]) {
      keyPressed[col + 16] = false;
      noteOn(144 + lastChannel, keyToMidiMap[col + 16], 0);
    }

    if (groupValue4 == 0 && keyPressed[col + 24]) {
      keyPressed[col + 24] = false;
      noteOn(144 + lastChannel, keyToMidiMap[col + 24], 0);
    }

    

  }





for (int colTwo = 0; colTwo < 8; colTwo++) {


     // shift scan matrix to following column
    scanColumnTwo(bitsTwo[colTwo]);

    // check if any keys were pressed - rows will have HIGH output in this case corresponding
    int groupValue5 = !digitalRead(row5);
    int groupValue6 = !digitalRead(row6);
    int groupValue7 = !digitalRead(row7);
   
    

    // process if any combination of keys pressed
    if (groupValue5 != 0 || groupValue6 != 0 || groupValue7 != 0) {

      if (groupValue5 != 0 && !keyPressedTwo[colTwo]) {
        keyPressedTwo[colTwo] = true;
        channelSelect = keyToMidiMapTwo[colTwo];
        lastChannel = channelSelect;
      }

      if (groupValue6 != 0 && !keyPressedTwo[colTwo + 8] && (colTwo != 7)) {
        keyPressedTwo[colTwo + 8] = true;
        channelSelect = keyToMidiMapTwo[colTwo + 8];
        lastChannel = channelSelect;
      }

      
      if (groupValue6 != 0 && !keyPressedTwo[colTwo + 8] && (colTwo == 7)) {
        keyPressedTwo[colTwo + 8] = true;
        ctrCh(176 + 6,keyToMidiMapTwo[colTwo + 8],127);
      }

      if (groupValue7 != 0 && !keyPressedTwo[colTwo + 16] && (colTwo != 7)) {
        keyPressedTwo[colTwo + 16] = true;
        ctrCh(176 + 6,keyToMidiMapTwo[colTwo + 16],127);
      }

      if (groupValue7 != 0 && !keyPressedTwo[colTwo + 16] && (colTwo == 7)) {
        keyPressedTwo[colTwo + 16] = true;
        channelSelect = keyToMidiMapTwo[colTwo + 16];
        lastChannel = channelSelect;
      }

      
           

    }

        //  process if any combination of keys released
    if (groupValue5 == 0 && keyPressedTwo[colTwo]) {
        keyPressedTwo[colTwo] = false;
        channelSelect = keyToMidiMapTwo[colTwo];
        lastChannel = channelSelect;
    }

    if (groupValue6 == 0 && keyPressedTwo[colTwo + 8] && (colTwo != 7)) {
        keyPressedTwo[colTwo + 8] = false;
        channelSelect = keyToMidiMapTwo[colTwo + 8];
        lastChannel = channelSelect;
    }
    
    if (groupValue7 == 0 && keyPressedTwo[colTwo + 16] && (colTwo != 7)) {
        keyPressedTwo[colTwo + 16] = false;
        ctrCh(176 + 6,keyToMidiMapTwo[colTwo + 16],0);
    }
    if (groupValue7 == 0 && keyPressedTwo[colTwo + 16] && (colTwo == 7)) {
        keyPressedTwo[colTwo + 16] = false;
        channelSelect = keyToMidiMapTwo[colTwo + 16];
        lastChannel = channelSelect;
    }






    
  }








  

  //Read the joystick

  joyX = analogRead(A2);
 if (joyX != lastX) {
   
 
 if (joyX > 580) {
 pitchBend = map(joyX,580,1020,65,127);
 sendeMIDI(224 + lastChannel,0,pitchBend);
 }
 if (joyX < 460) {
 pitchBend = map(joyX,0,460,0,63);
 sendeMIDI(224 + lastChannel,0,pitchBend);
 }
 else if ((joyX > 460 && joyX < 580) && pitchBend != 64) {
 pitchBend = 64;
 sendeMIDI(224 + lastChannel,0,pitchBend);
 }

 lastX = joyX;

}

joyY = analogRead(A3);
if (joyY != lastY) {
 

 if (joyY > 580) {
 controllerWert = map(joyY,580,1020,0,127);
 sendeMIDI(176 + lastChannel,1,controllerWert);
 }
 if (joyY < 460) {
 controllerWert = map(joyY,460,0,0,127);
 sendeMIDI(176 + lastChannel,1,controllerWert);
 }

  else if ((joyY > 460 && joyY < 580) && controllerWert != 0) {
  controllerWert = 0;
  sendeMIDI(176 + lastChannel,1,controllerWert);
  }



  lastY = joyY;

 } 
 

/*


// reads the value of the pot on analog pin joyPin1
value1 = analogRead(joyPin1);
Serial.print("value1="); Serial.println(value1); Serial.print("\n");
// this small pause is needed between reading and to make display easier
// analog pins, otherwise we get the same value twice
delay(1000); //1000ms delay
// reads the value of the pot on analog pin joyPin2
value2 = analogRead(joyPin2);
Serial.print("value2="); Serial.println(value2);
delay(1000); //1000ms delay


*/


}

void sendeMIDI(int statusByte, int dataByte1, int dataByte2) {
 Serial.write(statusByte);
 Serial.write(dataByte1);
 Serial.write(dataByte2);
}


void noteOn(int cmd, int pitch, int velocity) {
    Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}

void ctrCh(int cmd, int cc, int velocity) {
    Serial.write(cmd);
  Serial.write(cc);
  Serial.write(velocity);
}
