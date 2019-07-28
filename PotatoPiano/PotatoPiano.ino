/*Arduino speaker song tutorial
 * This program will play the theme song of the Malayalam movie
 * 'Ennu Ninte Moideen'. The song is 'Mukkathe Penne'.
 * The song is played on the speaker connected to pin 3 and GND.
 * 
 * Created 26 Oct 2015
 * by Akshay James
 * Video at https://www.youtube.com/watch?v=LgtcUxe8fmA
 */

#include"pitches.h"

// notes in the song 'Mukkathe Penne'
int melody[] = {
  NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_A4,
  NOTE_G4, NOTE_C5, NOTE_AS4, NOTE_A4,                   
  NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_FS4, NOTE_DS4, NOTE_D4,
  NOTE_C4, NOTE_D4,0,                                 
  
  NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_A4,
  NOTE_G4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4,      //29               //8
  NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_FS4, NOTE_DS4, NOTE_D4,
  NOTE_C4, NOTE_D4,0,                                       
  
  NOTE_D4, NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_DS5, NOTE_D5,
  NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_C5,
  NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_FS4, NOTE_D5, NOTE_C5,
  NOTE_AS4, NOTE_A4, NOTE_C5, NOTE_AS4,             //58
  
  NOTE_D4, NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_DS5, NOTE_D5,
  NOTE_C5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_C5, NOTE_G4,
  NOTE_A4, 0, NOTE_AS4, NOTE_A4, 0, NOTE_G4,
  NOTE_G4, NOTE_A4, NOTE_G4, NOTE_FS4, 0,
  
  NOTE_C4, NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_DS4,
  NOTE_C4, NOTE_D4, 0,
  NOTE_C4, NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_DS4,
  NOTE_C4, NOTE_D4, END
  
};

// note durations: 8 = quarter note, 4 = 8th note, etc.
int noteDurations[] = {       //duration of the notes
  8,4,8,4,
  4,4,4,12,
  4,4,4,4,4,4,
  4,16,4,
  
  8,4,8,4,
  4,2,1,1,2,1,1,12,
  4,4,4,4,4,4,
  4,16,4,
  
  4,4,4,4,4,4,
  4,4,4,12,
  4,4,4,4,4,4,
  4,4,4,12,
  
  4,4,4,4,4,4,
  2,1,1,2,1,1,4,8,4,
  2,6,4,2,6,4,
  2,1,1,16,4,
  
  4,8,4,4,4,
  4,16,4,
  4,8,4,4,4,
  4,20,
};

#include <Wire.h>
#include "Adafruit_MPR121.h"

Adafruit_MPR121 cap = Adafruit_MPR121();

int speed=90;  //higher value, slower notes
void setup() {

  Serial.begin(9600);
  cap.begin(0x5A);
  
/*  for (int thisNote = 0; melody[thisNote]!=-1; thisNote++) {

    int noteDuration = speed*noteDurations[thisNote];
    tone(8, melody[thisNote],noteDuration*.95);
    Serial.println(melody[thisNote]);

    delay(noteDuration);

    noTone(8);
  }*/
}

void loop() {
  uint16_t val = cap.touched();
  int thisNote = -1;
  if (val != 0) {
    String label = "";
    if (val & 0x01) {
      label += "One ";
      thisNote = 1;
    }
    if (val & 0x02) {
      label += "Two ";
      thisNote = 2;
    }
    if (val & 0x800) {
      label += "Potato ";
      thisNote = 3;
    }
    Serial.println("Daddy stop touching me: " + String(val) + " " + label);
    int noteDuration = speed*noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration*.95);
    delay(noteDuration);
    noTone(8);
  }
}
