/*
  "The Imperial March (Darth Vader's Theme)" by John Williams 
 
 Was created using:
    Arduino Tone Library: https://code.google.com/p/rogue-code/wiki/ToneLibraryDocumentation 
    Arduino Cookbook by Michael Margolis with Nick Weldin (O’Reilly). Copyright 2011 Michael Margolis and Nicholas Weldin, 9780596802479.
*/

#include <Tone.h>

#define PAUSE 0

Tone tone1; 

int score[] = {NOTE_G4, NOTE_G4, NOTE_G4, NOTE_DS4, NOTE_AS4,
               NOTE_G4, NOTE_DS4, NOTE_AS4, NOTE_G4, PAUSE,
               NOTE_D5, NOTE_D5, NOTE_D5, NOTE_DS5, NOTE_AS4,
               NOTE_FS4, NOTE_DS4, NOTE_AS4, NOTE_G4,
               NOTE_G5, NOTE_G4, NOTE_G4, NOTE_G5, NOTE_FS5, NOTE_F5,
               NOTE_E5, NOTE_DS5, NOTE_E5, PAUSE, NOTE_GS4, NOTE_CS5, NOTE_C5, NOTE_B4,
               NOTE_AS4, NOTE_A4, NOTE_AS4, PAUSE, NOTE_DS4, NOTE_FS4, NOTE_DS4, NOTE_F4,
               NOTE_AS4, NOTE_G4, NOTE_AS4, NOTE_D5,
               NOTE_G5, NOTE_G4, NOTE_G4, NOTE_G5, NOTE_FS5, NOTE_F5,
               NOTE_E5, NOTE_DS5, NOTE_E5, PAUSE, NOTE_GS4, NOTE_CS5, NOTE_C5, NOTE_B4,
               NOTE_AS4, NOTE_A4, NOTE_AS4, PAUSE, NOTE_DS4, NOTE_FS4, NOTE_DS4, NOTE_AS4,
               NOTE_G4, NOTE_DS4, NOTE_AS4, NOTE_G4};
               
const byte scoreLen = sizeof(score)/2; //wtf

byte beats[scoreLen] = {4, 4, 4, 3, 1,
                        4, 3, 1, 4, 4,
                        4, 4, 4, 3, 1,
                        4, 3, 1, 8,
                        4, 3, 1, 4, 3, 1,
                        1, 1, 2, 2, 2, 4, 3, 1,
                        1, 1, 2, 2, 2, 4, 3, 1,
                        4, 3, 1, 8,
                        4, 3, 1, 4, 3, 1,
                        1, 1, 2, 2, 2, 4, 3, 1,
                        1, 1, 2, 2, 2, 4, 3, 1,
                        4, 3, 1, 8};

unsigned int speed = 200; // the time in ms for one beat

void setup() {
    pinMode(13, OUTPUT); //add red LED on pin 13 for epicness
    tone1.begin(3); //prepare pin 3 for playing a tone
    for (int i = 0; i<scoreLen; i++){
     int duration = beats[i] * speed;
     digitalWrite(13, HIGH);
     tone1.play(score[i], duration);
     delay(duration/2);
     digitalWrite(13, LOW); 
     delay(duration/2+10);
    }
}

void loop() {}
 
