#include <Shifty.h>

int totalBits = 40;
int latch = 7;
int clk = 8;
int data = 9;

Shifty shift;

// Define Class

class Word{
  public:
    bool segmented;
    int* firstSegment;
    int* invertedFirstSegment;
    int* shuffledFirstSegment;
    int firstSegmentLength;
    int* secondSegment;
    int* invertedSecondSegment;
    int* shuffledSecondSegment;
    int secondSegmentLength;

    void turnLightsOff(int interval){
      for (int i = 0 ; i <= totalBits; i++){
        shift.writeBit(i, HIGH);
      }
      delay(interval);
    }

    void cursor(){
      for(int i = 0; i < 2; i++){
        shift.writeBit(1,LOW);
        delay(300);
        shift.writeBit(1,HIGH);
        delay(300);
      }
    }

    void fromLeftToRight(int interval, int complete){
      if(segmented){
        for(int i = 0; i < firstSegmentLength; i++){
          shift.writeBit(firstSegment[i]-1, LOW);
          delay(interval);
        }
        delay(complete);
        turnLightsOff(70);
        cursor();
        for(int i = 0; i < secondSegmentLength; i++){
          shift.writeBit(secondSegment[i]-1, LOW);
          delay(interval);
        }
        delay(complete);
        turnLightsOff(70);
        cursor();
      }
      else{
        for(int i = 0; i < firstSegmentLength; i++){
          shift.writeBit(firstSegment[i]-1, LOW);
          delay(interval);
        }
        delay(complete);
        turnLightsOff(70);
        cursor();
      }
    } 

    void fromRightToLeft(int interval, int complete){
      if(segmented){
        for(int i = 0; i < firstSegmentLength; i++){
          shift.writeBit(invertedFirstSegment[i]-1, LOW);
          delay(interval);
        }
        delay(complete);
        turnLightsOff(70);
        cursor();
        for(int i = 0; i < secondSegmentLength; i++){
          shift.writeBit(invertedSecondSegment[i]-1, LOW);
          delay(interval);
        }
        delay(complete);
        turnLightsOff(70);
        cursor();
      }
      else{
        for(int i = 0; i < firstSegmentLength; i++){
          shift.writeBit(invertedFirstSegment[i]-1, LOW);
          delay(interval);
        }
        delay(complete);
        turnLightsOff(70);
        cursor();
      }
    }

    void randomOrder(int interval, int complete){
      if(segmented){
        for(int i = 0; i < firstSegmentLength; i++){
          shift.writeBit(shuffledFirstSegment[i]-1, LOW);
          delay(interval);
        }
        delay(complete);
        turnLightsOff(70);
        cursor();
        for(int i = 0; i < secondSegmentLength; i++){
          shift.writeBit(shuffledSecondSegment[i]-1, LOW);
          delay(interval);
        }
        delay(complete);
        turnLightsOff(70);
        cursor();
      }
      else{
        for(int i = 0; i < firstSegmentLength; i++){
          shift.writeBit(shuffledFirstSegment[i]-1, LOW);
          delay(interval);
        }
        delay(complete);
        turnLightsOff(70);
        cursor();
      }
    }

    void selectMode(int modeNumb, int intervalo, int complete){
      if(modeNumb == 0){
        fromLeftToRight(intervalo, complete);
      }
      else if (modeNumb == 1){
        fromRightToLeft(intervalo, complete);
      }
      else if (modeNumb == 2){
        randomOrder(intervalo, complete);
      }
    }
};

// count

const int wordCount = 10;
Word* words = new Word[wordCount];

// 1 animal

int ani[] = {17,20,22,24,25,28,30,31};
int aniI[] = {31,30,28,25,24,22,20,17};
int aniS[] = {25,30,31,24,17,28,22,20};
int aniL = 8;
int mal[] = {17,22,23,24,25,27,28,31,32};
int malI[] = {32,31,28,27,25,24,23,22,17};
int malS[] = {24,31,28,32,23,17,27,22,25};
int malL = 9;

// 2 central

int cen[] = {8,9,15,17,18,20,22,25,28,30};
int cenI[] = {30,28,25,22,20,18,17,15,9,8};
int cenS[] = {25,20,28,8,15,22,30,9,18,17};
int cenL = 10;
int tral[] = {4,5,8,11,12,14,17,20,22,24,25,26};
int tralI[] = {26,25,24,22,20,17,14,12,11,8,5,4};
int tralS[] = {25,26,24,14,22,11,4,5,12,20,8,17};
int tralL = 12;

// 3 Crisis

int cri[] = {8,9,15,17,19,20,21,25};
int criI[] = {25,21,20,19,17,15,9,8};
int criS[] = {21,20,19,9,15,8,17,25};
int criL = 8;
int sis[] = {10,12,13,18,22,23,26,28,29};
int sisI[] = {29,28,26,23,22,18,13,12,10};
int sisS[] = {26,23,13,18,22,28,29,12,10};
int sisL = 9;

// 4 Error

int errorA[] = {1,2,3,4,8,11,12,14,17,19,20,21,25,26,29,30,31,33,34,35,36};
int errorI[] = {36,35,34,33,31,30,29,26,25,21,20,19,17,14,12,11,8,4,3,2,1};
int errorS[] = {4,36,30,25,12,21,26,14,34,17,19,33,8,1,29,20,2,11,35,3,31};
int errorL = 21;

// 5 Grave

int graveA[] = {1,2,4,6,8,11,12,14,17,20,22,24,28,30,31,32,34,35};
int graveI[] = {35,34,32,31,30,28,24,22,20,17,14,12,11,8,6,4,2,1};
int graveS[] = {12,14,6,1,31,28,32,35,8,34,22,20,11,24,30,17,2,4};
int graveL = 18;

// 6 Idea

int ideaA[] = {2,4,5,8,10,14,17,18,20,22,25,27,28};
int ideaI[] = {28,27,25,22,20,18,17,14,10,8,5,4,2};
int ideaS[] = {18,10,25,27,28,20,22,4,14,17,8,2,5};
int ideaL = 13;

// 7 Ideal

int idealA[] = {2,4,5,8,10,14,17,18,20,22,25,27,28,31,32};
int idealI[] = {32,31,28,27,25,22,20,18,17,14,10,8,5,4,2};
int idealS[] = {20,27,5,14,8,25,32,10,31,17,2,22,18,28,4};
int idealL = 15;

// 8 Metal

int metalA[] = {1,4,5,6,7,8,9,12,15,22,23,25,27,28,31,32};
int metalI[] = {32,31,28,27,25,23,22,15,12,9,8,7,6,5,4,1};
int metalS[] = {6,27,5,7,12,8,1,15,28,4,32,9,23,25,31,22};
int metalL = 16;

// 9 Motor

int motorA[] = {1,4,5,6,7,8,9,15,16,22,23,25,26,29,30,31,33,34,35,36};
int motorI[] = {36,35,34,33,31,30,29,26,25,23,22,16,15,9,8,7,6,5,4,1};
int motorS[] = {8,9,7,30,35,33,36,31,6,26,16,34,23,29,15,4,5,1,25,22};
int motorL = 20;

// 10 Union

int uni[] = {17,18,24,25,28,30,31};
int uniI[] = {31,30,28,25,24,18,17};
int uniS[] = {24,17,18,28,25,30,31};
int uniL = 7;
int on[] = {17,18,22,24,25,28,30};
int onI[] = {30,28,25,24,22,18,17};
int onS[] = {17,18,22,24,25,28,30};
int onL = 7;

void setup() {
  Serial.begin(9600);
  shift.setBitCount(totalBits); // Set total of bits (multiples of 8)
  shift.setPins(7,9,8); // Set Shift Register pins
  
  randomSeed(analogRead(0));

  words[0].segmented = true;
  words[0].firstSegment = ani;
  words[0].invertedFirstSegment = aniI;
  words[0].shuffledFirstSegment = aniS;
  words[0].firstSegmentLength = aniL;
  words[0].secondSegment = mal;
  words[0].invertedSecondSegment = malI;
  words[0].shuffledSecondSegment = malS;
  words[0].secondSegmentLength = malL;

  words[1].segmented = true;
  words[1].firstSegment = cen;
  words[1].invertedFirstSegment = cenI;
  words[1].shuffledFirstSegment = cenS;
  words[1].firstSegmentLength = cenL;
  words[1].secondSegment = tral;
  words[1].invertedSecondSegment = tralI;
  words[1].shuffledSecondSegment = tralS;
  words[1].secondSegmentLength = tralL;

  words[2].segmented = true;
  words[2].firstSegment = cri;
  words[2].invertedFirstSegment = criI;
  words[2].shuffledFirstSegment = criS;
  words[2].firstSegmentLength = criL;
  words[2].secondSegment = sis;
  words[2].invertedSecondSegment = sisI;
  words[2].shuffledSecondSegment = sisS;
  words[2].secondSegmentLength = sisL;

  words[3].segmented = false;
  words[3].firstSegment = errorA;
  words[3].invertedFirstSegment = errorI;
  words[3].shuffledFirstSegment = errorS;
  words[3].firstSegmentLength = errorL;

  words[4].segmented = false;
  words[4].firstSegment = graveA;
  words[4].invertedFirstSegment = graveI;
  words[4].shuffledFirstSegment = graveS;
  words[4].firstSegmentLength = graveL;

  words[5].segmented = false;
  words[5].firstSegment = ideaA;
  words[5].invertedFirstSegment = ideaI;
  words[5].shuffledFirstSegment = ideaS;
  words[5].firstSegmentLength = ideaL;

  words[6].segmented = false;
  words[6].firstSegment = idealA;
  words[6].invertedFirstSegment = idealI;
  words[6].shuffledFirstSegment = idealS;
  words[6].firstSegmentLength = idealL;

  words[7].segmented = false;
  words[7].firstSegment = metalA;
  words[7].invertedFirstSegment = metalI;
  words[7].shuffledFirstSegment = metalS;
  words[7].firstSegmentLength = metalL;

  words[8].segmented = false;
  words[8].firstSegment = motorA;
  words[8].invertedFirstSegment = motorI;
  words[8].shuffledFirstSegment = motorS;
  words[8].firstSegmentLength = motorL;

  words[9].segmented = true;
  words[9].firstSegment = uni;
  words[9].invertedFirstSegment = uniI;
  words[9].shuffledFirstSegment = uniS;
  words[9].firstSegmentLength = uniL;
  words[9].secondSegment = on;
  words[9].invertedSecondSegment = onI;
  words[9].shuffledSecondSegment = onS;
  words[9].secondSegmentLength = onL;

  
  
  turnAllOff(5000);
  
}

void loop() {
  for(int i = 0; i < wordCount; i++){
    words[i].selectMode(random(3),5, 500);
  }
  for(int i = 0; i < wordCount; i++){
    words[random(10)].selectMode(random(3),5, 500);
  }
}

void turnAllOff(int interval){
  for (int i = 0 ; i <= totalBits; i++){
    shift.writeBit(i, HIGH);
  }
  delay(interval);
}
