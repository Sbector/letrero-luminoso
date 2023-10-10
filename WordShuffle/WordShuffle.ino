// Declare a Word class

class Word{
  public:
    bool monoSyllabic;          // Monosyllabic means thar is displayed at once
    int* firstSyllable;
    int* shuffledFirstSyllable;
    int firstSyllableLength;
    int* secondSyllable;
    int* shuffledSecondSyllable;
    int secondSyllableLength;


    /// This function can be reused to turn lights on 
    void getInfo(){
      //
      if(!monoSyllabic){
        Serial.println("Not monosyllabic");
        Serial.println("List of first syllable segments");
        int i = 0;
        while(i < firstSyllableLength){
          Serial.println(firstSyllable[i]);
          i++;
        }
        Serial.println("Shuffled list of first syllable segments");
        int j = 0;
        while(j < firstSyllableLength){
          Serial.println(shuffledFirstSyllable[j]);
          j++;
        }
        Serial.println("List of second syllable segments");
        int a = 0;
        while(a < secondSyllableLength){
          Serial.println(secondSyllable[a]);
          a++;
        }
        Serial.println("Shuffled list of second syllable segments");
        int b = 0;
        while(b < secondSyllableLength){
          Serial.println(shuffledSecondSyllable[b]);
          b++;
        }
      } 
      else {
        Serial.println("Monosyllabic");
        Serial.println("List of word segments");
        int x = 0;
        while(x < firstSyllableLength){
          Serial.println(firstSyllable[x]);
          x++;
        }
        Serial.println("Shuffled list of word segments");
        int y = 0;
        while(y < firstSyllableLength){
          Serial.println(shuffledFirstSyllable[y]);
          y++;
        }
      }
    }
};

bool animalM = false;
int ani[] = {17,20,22,24,25,28,30,31};
int aniS[] = {25,30,31,24,17,28,22,20};
int aniL = 8;
int mal[] = {17,22,23,24,25,27,28,31,32};
int malS[] = {24,31,28,32,23,17,27,22,25};
int malL = 9;

bool errorM = true;
int errorList[] = {1,2,3,4,8,11,12,14,17,19,20,21,25,26,29,30,31,33,34,35,36};
int errorS[] = {4,36,30,25,12,21,26,14,34,17,19,33,8,1,29,20,2,11,35,3,31};
int errorL = 21;

Word animal;
Word error;


void setup() {
  Serial.begin(9600);
  animal.monoSyllabic = animalM;
  animal.firstSyllable = ani;
  animal.shuffledFirstSyllable = aniS;
  animal.firstSyllableLength = aniL;
  animal.secondSyllable = mal;
  animal.shuffledSecondSyllable = malS;
  animal.secondSyllableLength = malL;

  error.monoSyllabic = errorM;
  error.firstSyllable = errorList;
  error.shuffledFirstSyllable = errorS;
  error.firstSyllableLength = errorL;
  
  animal.getInfo();
  error.getInfo();

}

void loop() {
  // put your main code here, to run repeatedly:

}
