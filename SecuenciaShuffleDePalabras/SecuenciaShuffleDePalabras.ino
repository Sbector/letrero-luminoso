#include <Shifty.h>

int totalBits = 40;
int latch = 7;
int clk = 8;
int data = 9;

Shifty shift;

// intervals between syllables and words
int lightsOnSyllables = 1000; // Time with lights on for syllables
int lightsOnWords = 1600; // Time with lights on for ssllables
int betweenSyllables = 200; // Time off between syllables
int betweenWords = 1000;  // Time off between words
int betweenSegments = 200;
int minDelay = 70;

// list of words and syllables with their respective array length

int ani[] = {17,20,22,24,25,28,30,31};
int aniS[] = {25,30,31,24,17,28,22,20};
int aniL = 8;
int mal[] = {17,22,23,24,25,27,28,31,32};
int malS[] = {24,31,28,32,23,17,27,22,25};
int malL = 9;

int cen[] = {8,9,15,17,18,20,22,25,28,30};
int cenS[] = {25,20,28,8,15,22,30,9,18,17};
int cenL = 10;
int tral[] = {4,5,8,11,12,14,17,20,22,24,25,26};
int tralS[] = {25,26,24,14,22,11,4,5,12,20,8,17};
int tralL = 12;

int cri[] = {8,9,14,17,19,20,21,25};
int criS[] = {21,20,19,9,14,8,17,25};
int criL = 8;
int sis[] = {10,12,13,18,22,23,26,28,29};
int sisS[] = {26,23,13,18,22,28,29,12,10};
int sisL = 9;

int error[] = {1,2,3,4,8,11,12,14,17,19,20,21,25,26,29,30,31,33,34,35,36};
int errorS[] = {4,36,30,25,12,21,26,14,34,17,19,33,8,1,29,20,2,11,35,3,31};
int errorL = 21;

int grave[] = {1,2,4,6,8,11,12,14,17,20,22,24,28,30,31,32,34,35};
int graveS[] = {12,14,6,1,31,28,32,35,8,34,22,20,11,24,30,17,2,4};
int graveL = 18;

int idea[] = {2,4,5,8,10,14,17,18,20,22,25,27,28};
int ideaS[] = {18,10,25,27,28,20,22,4,14,17,8,2,5};
int ideaL = 13;

int ideal[] = {2,4,5,8,10,14,17,18,20,22,25,27,28,31,32};
int idealS[] = {20,27,5,14,8,25,32,10,31,17,2,22,18,28,4};
int idealL = 15;

int metal[] = {1,4,5,6,7,8,9,12,15,22,23,25,27,28,31,32};
int metalS[] = {6,27,5,7,12,8,1,15,28,4,32,9,23,25,31,22};
int metalL = 16;

int motor[] = {1,4,5,6,7,8,9,15,16,22,23,25,26,29,30,31,33,34,35,36};
int motorS[] = {8,9,7,30,35,33,36,31,6,26,16,34,23,29,15,4,5,1,25,22};
int motorL = 20;

int uni[] = {17,18,24,25,28,30,31};
int uniS[] = {24,17,18,28,25,30,31};
int uniL = 7;
int on[] = {17,18,22,24,25,28,30};
int onS[] = {17,18,22,24,25,28,30};
int onL = 7;

// Declare turnLightsOn function
void turnLightsOn(int[], int, int);
// Declare turnShuffleLightsOn function
void turnShuffleLightsOn(int[], int, int, int);

void setup() {
  Serial.begin(9600); // Serial for console
  shift.setBitCount(totalBits); // Set total of bits (multiples of 8)
  shift.setPins(7,9,8); // Set Shift Register pins

  turnAllOff(); // Turn all lights off and wait 5 seconds
  delay(5000);

  // Starts the cicle of words

  wordsList();
  wordsListShuffle();
  
}

void loop() {
  //test();
  //delay(5000);
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
    Serial.print(b[j]);
    Serial.print(",");
    delay(minDelay);
  }
  delay(t);
  Serial.println("next");
}

// Turn lights on (int b[] is the word, int bL is the lenght of the array)
void turnShuffleLightsOn(int b[], int bL, int t, int tS){
  for (int j = 0; j < bL; j++){
    shift.writeBit(b[j]-1,LOW); // Rest a digit because shift register starts on 0
    delay(tS); // Tiempo entre segmentos
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

void wordsListShuffle(){

  // 1 animal
  turnShuffleLightsOn(aniS,aniL,lightsOnSyllables,betweenSegments);
  turnAllOff();
  delay(betweenSyllables);
  turnShuffleLightsOn(malS,malL,lightsOnSyllables,betweenSegments);
  turnAllOff();
  delay(betweenWords);

  // 2 central
  turnShuffleLightsOn(cenS,cenL,lightsOnSyllables,betweenSegments);
  turnAllOff();
  delay(betweenSyllables);
  turnShuffleLightsOn(tralS,tralL,lightsOnSyllables,betweenSegments);
  turnAllOff();
  delay(betweenWords);

  // 3 crisis
  turnShuffleLightsOn(criS,criL,lightsOnSyllables,betweenSegments);
  turnAllOff();
  delay(betweenSyllables);
  turnShuffleLightsOn(sisS,sisL,lightsOnSyllables,betweenSegments);
  turnAllOff();
  delay(betweenWords);

  // 4 error
  turnShuffleLightsOn(errorS,errorL,lightsOnWords, betweenSegments);
  turnAllOff();
  delay(betweenWords);

  // 5 grave
  turnShuffleLightsOn(graveS,graveL,lightsOnWords, betweenSegments);
  turnAllOff();
  delay(betweenWords);

  // 6 idea
  turnShuffleLightsOn(ideaS,ideaL,lightsOnWords, betweenSegments);
  turnAllOff();
  delay(betweenWords);

  // 7 ideal
  turnShuffleLightsOn(idealS,idealL,lightsOnWords, betweenSegments);
  turnAllOff();
  delay(betweenWords);

  // 8 metal
  turnShuffleLightsOn(metalS,metalL,lightsOnWords, betweenSegments);
  turnAllOff();
  delay(betweenWords);

  // 9 motor
  turnShuffleLightsOn(motorS,motorL,lightsOnWords, betweenSegments);
  turnAllOff();
  delay(betweenWords);

  // 10 union
  turnShuffleLightsOn(uniS,uniL,lightsOnSyllables,betweenSegments);
  turnAllOff();
  delay(betweenSyllables);
  turnShuffleLightsOn(onS,onL,lightsOnSyllables,betweenSegments);
  turnAllOff();
  delay(betweenWords);
}

void test(){

  // 1 animal
  turnShuffleLightsOn(aniS,aniL,lightsOnSyllables,betweenSegments);
  turnAllOff();
  delay(betweenSyllables);
  turnShuffleLightsOn(malS,malL,lightsOnSyllables,betweenSegments);
  turnAllOff();
  delay(betweenWords);
}
