#include <Shifty.h>

int totalBits = 40;
int latch = 7;
int clk = 8;
int data = 9;

Shifty shift;

// intervals between syllables and words
int lightsOn = 1000; // Time with lights on
int betweenSegments = 10; // Time between segments

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

void turnLightsOnObsolete(,int[],int,int); // Declare the function turnLightsOnObsolete

// Declare turnLightsOn function
// It has 3 arguments the two array lists (normal and shuffled), the array length,
// the minimum and the maximun time between segments.

void turnLightsOn(int[],int[],int,int,int);

void setup() {
  Serial.begin(9600); // Serial for console
  shift.setBitCount(totalBits); // Set total of bits (multiples of 8)
  shift.setPins(7,9,8); // Set Shift Register pins

  turnAllOff(); // Turn all lights off and wait 5 seconds
  delay(5000);

  // Starts the cicle of words

}

void loop(){
  
}

void turnAllOff(){
  for (int i = 0 ; i <= totalBits; i++){
    shift.writeBit(i, HIGH);
  }
}

void turnLightsOnObsolete(int b[], int bL, int t){
  for (int j = 0; j < bL; j++){
    shift.writeBit(b[j]-1,LOW); // Rest a digit because shift register starts on 0
    Serial.print(b[j]);
    Serial.print(",");
    delay(betweenSegments);
  }
  delay(t);
  Serial.println("next");
}

void turnLightsOn(int array[], int arrayS[], int arrayLength, int minTime, int maxTime){
  int randomNumber = random(3);
  int randomTime = random(minTime, maxTime);

  if(randomNumber == 0){
    Serial.println("programa1");
  } else if(randomNumber == 1) {
    Serial.println("programa2");
  } else if(randomNumber == 2) {
    Serial.println("programa3");
  }
}