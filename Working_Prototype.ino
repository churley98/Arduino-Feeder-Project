#include <Servo.h>

//Create a new servo object
Servo servoT;
//Musical Note Definitions
#define NOTE_0  0 
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
 
#define melodyPin 8
#define NO_SOUND 0 // make the rests in music

//array of notes
int melody[18] = {NOTE_A3,NOTE_A3,NOTE_A3,NOTE_F3,NOTE_C4,NOTE_A3,NOTE_F3,NOTE_C4,NOTE_A3,NOTE_E4,NOTE_E4,NOTE_E4,NOTE_F4,NOTE_C4,NOTE_GS3,NOTE_F3,NOTE_C4,NOTE_A3,
 
};

// note duration: 1 = whole note, 2 = half note, 4 = quarter note, 8 = eighth note, etc.
int noteDurations[18] = {6,6,6,8,11,6,8,11,2,6,6,6,8,11,6,8,11,2,
 
};

int pace = 3450; // change pace of music("speedy")

//END OF MUSIC DEFINITIONS

int potpin = A0;
int angle;
int buzz = 8;

double lightValue = 0;

int led3 = 12;
int delayTimer = 0;

// the setup routine runs once when you press reset:
void setup() {
  pinMode(led3, OUTPUT);
  servoT.attach(9);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
 /*
  int val = analogRead(potpin);
  float volt = 5.*val/1023;
*/
  digitalWrite(led3, LOW);
  
  //Controls checks in time
  Serial.println(delayTimer);
  delay(6000);
  delayTimer++;
  

  if(delayTimer++ > 2)
  {
    delay(1000 * 30);
    delayTimer = 0;
  }

  if (delayTimer < 3){
      lightValue = CheckLight();
      CloseLid();

      if(lightValue < 3.0){
          PlayMusic();
        } else {
          Serial.println("Bowl Still Full");
          }
    }
  /*
  if (volt <= 5.0 && volt > 3.8)
  {
    angle = 180;
    
    servoT.write(angle);
    digitalWrite(led3, HIGH);
  }

  if(volt <= 5.0 && volt
  
  //Light
  if (volt < 3.0)
  {
    angle = 0;
    servoT.write(angle);
    digitalWrite(led3, LOW);
  }
  */
 

}

double CheckLight(){
    
    int val = 0;
    float volt = 0.0;
    double lightVal = 0;
    
    angle = 180;
    servoT.write(angle);
    
    digitalWrite(led3, HIGH);
  for(int i = 0; i < 100; i++){
     val = analogRead(potpin);
     volt = 5.*val/1023;
    Serial.print(angle);
    Serial.print("\t");
    Serial.print(val);
    Serial.print("\t");
    Serial.print(volt, 2);
    Serial.println("v");
    
    lightVal = volt;
  }
    return lightVal;
 }

void CloseLid(){
    angle = 0;
    servoT.write(angle);
    digitalWrite(led3, LOW);
  }

 void PlayMusic(){
      for (int Note = 0; Note <18; Note++) {//counter of Notes (54 limit the array)
    int duration = pace/noteDurations[Note];//Adjust duration with the pace of music
    tone(8, melody[Note],duration); //Play note

    // to distinguish the notes, set a minimum time between them.
    delay(duration*1.1);
  }
  }
