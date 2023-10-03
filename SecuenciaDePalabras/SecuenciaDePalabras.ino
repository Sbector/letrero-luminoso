#include <Shifty.h>

int totalBits = 40;
int latch = 7;
int clk = 8;
int data = 9;

Shifty shift;

// intervals between syllables and words
int lightsOnSyllables = 200; // Time with lights on for ssllables
int lightsOnWords = 400; // Time with lights on for ssllables
int betweenSyllables = 200; // Time off between syllables
int betweenWords = 1000;  // Time off between words

// list of words and syllables with their respective array length

int ani[] = {17,20,22,24,25,28,30,31};
int aniL = 8;
int mal[] = {17,22,23,24,25,27,28,31,32};
int malL = 9;

int cen[] = {8,9,14,17,18,20,22,25,28,30};
int cenL = 9;
int tral[] = {4,5,8,11,12,14,17,20,22,24,25,26};
int tralL = 12;

int cri[] = {8,9,14,17,19,20,21,25};
int criL = 8;
int sis[] = {10,12,13,18,22,23,26,28,29};
int sisL = 9;

int error[] = {1,2,3,4,8,11,12,14,17,19,20,21,25,26,29,30,31,33,34,35,36};
int errorL = 21;

int grave[] = {1,2,4,6,8,11,12,14,17,20,22,24,28,30,31,32,34,35};
int graveL = 18;

int idea[] = {2,4,5,8,10,14,17,18,20,22,25,27,28};
int ideaL = 13;

int ideal[] = {2,4,5,8,10,14,17,18,20,22,25,27,28,31,32};
int idealL = 15;

int metal[] = {1,4,5,6,7,8,9,12,15,22,23,25,27,28,31,32};
int metalL = 16;

int motor[] = {1,4,5,6,7,8,9,15,16,22,23,25,26,29,30,31,33,34,35,36};
int motorL = 20;

int uni[] = {17,18,24,25,28,30,31};
int uniL = 7;
int on[] = {17,18,22,24,25,28,30};
int onL = 7;

// Declare turnLightsOn function
void turnLightsOn(int[], int, int);

void setup() {
  Serial.begin(9600); // Inicia serial
  shift.setBitCount(totalBits); // Define total de bits (múltiplos de 8)
  shift.setPins(7,9,8); // Define los pines del Shift Register

  turnAllOff(); // Turn all lights off and wait 5 seconds
  delay(5000);

  // Starts the cicle of words

  wordsList();
  
}

void loop() {
  
}


// Turn All lights off

void turnAllOff(){
  for (int i = 0 ; i <= totalBits; i++){
    shift.writeBit(i, HIGH);
  }
}

// Turn lights on (int b[] is the word, int bL is the lenght of the array)
void turnLightsOn(int b[], int bL, int t){
  for (int j = 0; j < bL; j++){
    shift.writeBit(b[j]-1,LOW); // Rest a digit because shift register starts on 0
    Serial.println(b[j]);
  }
  delay(t);
}

void wordsList(){

  // 1 animal
  turnLightsOn(ani,aniL,lightsOnSyllables);
  turnAllOff();
  delay(betweenSyllables);
  turnLightsOn(mal,malL,lightsOnSyllables);
  turnAllOff();
  delay(betweenWords);

  // 2 central
  turnLightsOn(cen,cenL,lightsOnSyllables);
  turnAllOff();
  delay(betweenSyllables);
  turnLightsOn(tral,tralL,lightsOnSyllables);
  turnAllOff();
  delay(betweenWords);

  // 3 crisis
  turnLightsOn(cri,criL,lightsOnSyllables);
  turnAllOff();
  delay(betweenSyllables);
  turnLightsOn(sis,sisL,lightsOnSyllables);
  turnAllOff();
  delay(betweenWords);

  // 4 error
  turnLightsOn(error,errorL,lightsOnWords);
  turnAllOff();
  delay(betweenWords);

  // 5 grave
  turnLightsOn(grave,graveL,lightsOnWords);
  turnAllOff();
  delay(betweenWords);

  // 6 idea
  turnLightsOn(idea,ideaL,lightsOnWords);
  turnAllOff();
  delay(betweenWords);

  // 7 ideal
  turnLightsOn(ideal,idealL,lightsOnWords);
  turnAllOff();
  delay(betweenWords);

  // 8 metal
  turnLightsOn(metal,metalL,lightsOnWords);
  turnAllOff();
  delay(betweenWords);

  // 9 motor
  turnLightsOn(motor,motorL,lightsOnWords);
  turnAllOff();
  delay(betweenWords);

  // 10 union
  turnLightsOn(uni,uniL,lightsOnSyllables);
  turnAllOff();
  delay(betweenSyllables);
  turnLightsOn(on,onL,lightsOnSyllables);
  turnAllOff();
  delay(betweenWords);
}
