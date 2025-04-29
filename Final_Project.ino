//Piano
#include <CapacitiveSensor.h>
#include "pitches.h"
#include <Adafruit_NeoPixel.h>

#define TONE_DURATION 250
#define FAIL_TONE_DURATION 400
#define FAIL_TONE_DURATION 400
#define MID_NOTE_DURATION 600
#define LAST_NOTE_DURATION 700

unsigned long startTime;
unsigned long currentTime;
int interval = 2000;
int RL = 13;
int BL = 12;
int GL = 11;


// 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired// To add more sensors...
//CapacitiveSensor   cs_4_6 = CapacitiveSensor(4,6);
// 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil
//CapacitiveSensor   cs_4_8 = CapacitiveSensor(4,8);
// 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foilvoidsetup()

//2 reads
//other number gives
CapacitiveSensor cs_2_3 = CapacitiveSensor(2, 3);
CapacitiveSensor cs_2_4 = CapacitiveSensor(2, 4);
CapacitiveSensor cs_2_5 = CapacitiveSensor(2, 5);  // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor cs_2_6 = CapacitiveSensor(2, 6);
CapacitiveSensor cs_2_7 = CapacitiveSensor(2, 7);
CapacitiveSensor cs_2_8 = CapacitiveSensor(2, 8);
CapacitiveSensor cs_2_10 = CapacitiveSensor(2, 10);

//5 sensors for 5 buttons



unsigned long currMillis = 0;
unsigned long prevMillis = 0;
unsigned long noteStartMillis = 0;
int BUZZER = 9;
int butpin = 12;
int butpin2 = 13;
int thresh1 = 400;
int thresh2 = 500;
int thresh3 = 100;
int threshHuh = 0;
bool buttState = false;
bool prevState = false;
bool octa = false;



void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  cs_2_3.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_2_4.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_2_5.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_2_6.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_2_7.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_2_8.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_2_10.set_CS_AutocaL_Millis(0xFFFFFFFF);



  pinMode(BUZZER, OUTPUT);
  pinMode(RL, OUTPUT);
  pinMode(BL, OUTPUT);
  pinMode(GL, OUTPUT);

  startTime = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  //for one

  long total1 = cs_2_3.capacitiveSensor(30);
  long total2 = cs_2_4.capacitiveSensor(30);
  long total3 = cs_2_5.capacitiveSensor(30);
  long total4 = cs_2_6.capacitiveSensor(30);
  long total5 = cs_2_7.capacitiveSensor(30);
  long total6 = cs_2_8.capacitiveSensor(30);  //octa
  long total7 = cs_2_10.capacitiveSensor(30);


  Serial.println(total5);
  //  Serial.println("2: " + total2);
  // Serial.println("3: " + total3);
  // Serial.println("4: " + total4);
  // Serial.println("5: " + total5);

  prevState = buttState;
  if (total6 > thresh1) {
    buttState = true;
  }else
 
    buttState = false;

  if (buttState && prevState == 0) {  //octave control
    octa = !octa;
  }

  /*
digitalWrite(RL, HIGH);
digitalWrite(BL, HIGH);
digitalWrite(GL, HIGH);
*/
  //Lower
  if ((total7 > thresh1) & octa) {  //

    digitalWrite(RL, HIGH);
    digitalWrite(GL, HIGH);
    tone(BUZZER, NOTE_C4);
  } else if ((total1 > thresh1) & octa) {  //

    digitalWrite(RL, HIGH);
    tone(BUZZER, NOTE_A4);
  } else

    // noTone(BUZZER);
    // delay(50);

    if ((total2 > thresh1) & octa) {  //

      digitalWrite(BL, HIGH);
      tone(BUZZER, NOTE_G4);
    } else
      //  noTone(BUZZER);
      // delay(50);

      if ((total3 > thresh1) & octa) {  //
        digitalWrite(GL, HIGH);
        tone(BUZZER, NOTE_F4);
      } else
        //  noTone(BUZZER);
        //delay(50);

        if ((total4 > thresh1) & octa) {  //
          digitalWrite(RL, HIGH);
          digitalWrite(BL, HIGH);
          tone(BUZZER, NOTE_E4);
        } else
          //  noTone(BUZZER);
          // delay(50);

          if ((total5 > thresh1) & octa) {  //

            digitalWrite(BL, HIGH);
            digitalWrite(GL, HIGH);
            tone(BUZZER, NOTE_D4);
          } else
            //Normal
            if ((total7 > thresh1) & !octa) {  //

              digitalWrite(RL, HIGH);
              digitalWrite(GL, HIGH);
              tone(BUZZER, NOTE_A4);
            } else 
            if ((total1 > thresh1) & !octa) {  //

              digitalWrite(RL, HIGH);
              tone(BUZZER, NOTE_F5);
            } else
              // noTone(BUZZER);
              // delay(50);

              if ((total2 > thresh1) & !octa) {  //

                digitalWrite(BL, HIGH);
                tone(BUZZER, NOTE_E5);
              } else
                //  noTone(BUZZER);
                // delay(50);

                if ((total3 > thresh1) & !octa) {  //
                  digitalWrite(GL, HIGH);
                  tone(BUZZER, NOTE_D5);
                } else
                  //  noTone(BUZZER);
                  //delay(50);

                  if ((total4 > thresh1) & !octa) {  //
                    digitalWrite(RL, HIGH);
                    digitalWrite(BL, HIGH);
                    tone(BUZZER, NOTE_C5);
                  } else
                    //  noTone(BUZZER);
                    // delay(50);

                    if ((total5 > thresh1) & !octa) {  //

                      digitalWrite(BL, HIGH);
                      digitalWrite(GL, HIGH);
                      tone(BUZZER, NOTE_AS4);
                    } else
                      noTone(BUZZER);
  digitalWrite(RL, LOW);
  digitalWrite(BL, LOW);
  digitalWrite(GL, LOW);

  delay(10);
}
//ADD A BUTTON TO CHANGE OCTAVES
