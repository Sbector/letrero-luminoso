#include <Shifty.h>

int totalBits = 40;
int latch = 7;
int clk = 8;
int data = 9;

Shifty shift;

// Declare a Word class

class Word{
  public:
    bool segmented;          // segmented means thar is displayed at once
    int* firstSyllable;
    int* shuffledFirstSyllable;
    int firstSyllableLength;
    int* secondSyllable;
    int* shuffledSecondSyllable;
    int secondSyllableLength;


    /// This function turns all the lights off 
    
    void turnAllOff(){
      for (int i = 0 ; i <= totalBits; i++){
          shift.writeBit(i, HIGH);
        }
      }

    // LeftToRight method

    void leftToRight(int interval){
      if(segmented){
        int i = 0;
        while(i<firstSyllableLength){
          shift.writeBit(firstSyllable[i]-1, LOW);
          delay(interval);
          i++;
        }
        delay(interval);
        turnAllOff();
        delay(500);
        int j = 0;
        while(j<secondSyllableLength){
          shift.writeBit(secondSyllable[j]-1, LOW);
          delay(interval);
          j++;
        }
        delay(interval);
        turnAllOff();
      }
      else {
        int a = 0;
        while(a<firstSyllableLength){
          shift.writeBit(firstSyllable[a]-1, LOW);
          delay(interval);
          a++;
        }
        delay(interval);
        turnAllOff();
        delay(500);
      }    
    }

    // Rigth to left method
    void rightToLeft(int interval){
      if(segmented){
        for(int b = firstSyllableLength; b > 0; b--){
          shift.writeBit(firstSyllable[b]-1, LOW);
          delay(interval);
        }
        delay(interval);
        turnAllOff();
        delay(500);
        for(int c = secondSyllableLength; c > 0; c--){
          shift.writeBit(firstSyllable[c]-1, LOW);
          delay(interval);
        }
        delay(interval);
        turnAllOff();
      }
      else {
        int a = firstSyllableLength;
        while(a<=0){
          shift.writeBit(firstSyllable[a]-1, LOW);
          delay(interval);
          a--;
        }
        delay(interval);
        turnAllOff();
        delay(500);
      }
    }
};

bool animalM = true;
int ani[] = {17,20,22,24,25,28,30,31};
int aniS[] = {25,30,31,24,17,28,22,20};
int aniL = 8;
int mal[] = {17,22,23,24,25,27,28,31,32};
int malS[] = {24,31,28,32,23,17,27,22,25};
int malL = 9;

bool errorM = false;
int errorList[] = {1,2,3,4,8,11,12,14,17,19,20,21,25,26,29,30,31,33,34,35,36};
int errorS[] = {4,36,30,25,12,21,26,14,34,17,19,33,8,1,29,20,2,11,35,3,31};
int errorL = 21;

Word animal;
Word error;


void setup() {
  Serial.begin(9600);
  shift.setBitCount(totalBits); // Set total of bits (multiples of 8)
  shift.setPins(7,9,8); // Set Shift Register pins

  animal.segmented = animalM;
  animal.firstSyllable = ani;
  animal.shuffledFirstSyllable = aniS;
  animal.firstSyllableLength = aniL;
  animal.secondSyllable = mal;
  animal.shuffledSecondSyllable = malS;
  animal.secondSyllableLength = malL;

  error.segmented = errorM;
  error.firstSyllable = errorList;
  error.shuffledFirstSyllable = errorS;
  error.firstSyllableLength = errorL;
  
  turnAllOff();
  Serial.println("all lights off");
}

void loop() {
  // put your main code here, to run repeatedly:
  animal.leftToRight(120);
  turnAllOff();
  delay(1000);
  error.leftToRight(120);
  turnAllOff();
  delay(1000);

  animal.rightToLeft(120);
  turnAllOff();
  delay(1000);
  error.rightToLeft(120);
  turnAllOff();
  delay(1000);
}

void turnAllOff(){
  for (int i = 0 ; i <= totalBits; i++){
    shift.writeBit(i, HIGH);
  }
}
