#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

int quiz();
void einde();
int stopfunctie();

SoftwareSerial mySoftwareSerial(10,11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

unsigned long startMillis;
unsigned long currentMillis;
const unsigned long period = 5000;  //the value is a number of milliseconds, ie 1 second

const int buttonPinA = 2;
const int buttonPinB = 4;
const int buttonPinC = 7;
const int buttonPinD = 8;
const int buttonPinE = 12; 

// variables will change:
int buttonStateA = 0;
int buttonStateB = 0;
int buttonStateC = 0;
int buttonStateD = 0;
int buttonStateE = 0;

int vragen;
int aantal; 

void setup() 
{
  pinMode(buttonPinA, INPUT);
  pinMode(buttonPinB, INPUT);
  pinMode(buttonPinC, INPUT);
  pinMode(buttonPinD, INPUT);
  pinMode(buttonPinE, INPUT);
  Serial.begin(9600);
  
  pinMode(buttonPinA, INPUT); // buttons als input aangeven
  mySoftwareSerial.begin(9600);
  if (!myDFPlayer.begin(mySoftwareSerial)) 
  { 
    while(true)
    {
      delay(0); // Code to compatible with ESP8266 watch dog.
    }
  }
  myDFPlayer.volume(30);
  myDFPlayer.play(1);
}

void loop() 
{ 
  buttonStateD = digitalRead(buttonPinD);
  if (buttonStateD == HIGH)
  {
    quiz();
  }
  
}
int quiz()
{ 
  for (vragen = 0; vragen < 5; vragen++)
  {
    buttonStateE = digitalRead(buttonPinE);// hoelang heb je de tijd om het aan te zetten? Wat gebeurd er als je in een case zit en je drukt op deze knop? Wat gebeurd er als je na je case op deze knop drukt? 
    while (buttonStateE != HIGH)
    {
     // hier moet ook constant gechecked worden, maar hoe? 
      myDFPlayer.volume(30);
      buttonStateA = digitalRead(buttonPinA);
      buttonStateB = digitalRead(buttonPinB);
      buttonStateC = digitalRead(buttonPinC);
      switch (vragen) 
      {
        case 0:
          Serial.println("ik ben nu in case 0");
          myDFPlayer.play(14); // vraag 1
          while ((buttonStateA == LOW) && (buttonStateB == LOW) && (buttonStateC == LOW))
          {
            buttonStateA = digitalRead(buttonPinA);
            buttonStateB = digitalRead(buttonPinB);
            buttonStateC = digitalRead(buttonPinC);
          }
          if (buttonStateA == HIGH)
          {
            myDFPlayer.play(9); // antwoord is goed geluid
            aantal = aantal +1;
            Serial.println("Ik heb antwoord A gekozen / juiste antwoord");
            buttonStateA = LOW;
          }
          if (buttonStateB == HIGH || buttonStateC == HIGH)
          {
            myDFPlayer.play(8);// antwoord is fout geluid
            buttonStateB = LOW;
            buttonStateC = LOW;
            Serial.println("Ik heb antwoord B of C gekozen / foute antwoord");
          }
          if (buttonStateE == HIGH)
          {
            buttonStateE = HIGH;
          }
          delay(5000);
          break;
        case 1:
          Serial.println("ik ben nu in case 1");
          myDFPlayer.play(13); // vraag 2
           while ((buttonStateA == LOW) && (buttonStateB == LOW) && (buttonStateC == LOW))
           {
             buttonStateA = digitalRead(buttonPinA);
             buttonStateB = digitalRead(buttonPinB);
             buttonStateC = digitalRead(buttonPinC);
           }
           if (buttonStateA == HIGH)
           {
             myDFPlayer.play(9); // goed geluid
             aantal = aantal +1;
             buttonStateA = LOW;
             Serial.println("ik heb antwoord A gekozen / juiste antwoord)");
           }
           if (buttonStateB == HIGH || buttonStateC == HIGH)
           {
             myDFPlayer.play(8); // fout geluid
             buttonStateB = LOW;
             buttonStateC = LOW;
             Serial.println("Ik heb antwoord B of C gekozen / foute antwoord");
           }
           if (buttonStateE == HIGH)
           {
             buttonStateE = HIGH;
           }
           delay(5000);
           break;
         case 2:
           Serial.println("ik ben nu in case 2");
           myDFPlayer.play(12); // vraag 3
           while ((buttonStateA == LOW) && (buttonStateB == LOW) && (buttonStateC == LOW))
            {
              buttonStateA = digitalRead(buttonPinA);
              buttonStateB = digitalRead(buttonPinB);
              buttonStateC = digitalRead(buttonPinC);
            }
           if (buttonStateC == HIGH)
           {
              myDFPlayer.play(9); // goed geluid
              aantal = aantal +1;
              buttonStateC = LOW;
              Serial.println(" Ik heb antwoord C gekozen / juiste antwoord");
           }
           if (buttonStateA == HIGH || buttonStateB == HIGH)
           {
              myDFPlayer.play(8); // fout geluid
              buttonStateB = LOW;
              buttonStateA = LOW;
              Serial.println("Ik heb antwoord A of B gekozen / foute antwoord");
           }
           if (buttonStateE == HIGH)
           {
              buttonStateE = HIGH;
           }
           delay(5000);
           break;
         case 3:
           Serial.println("ik ben nu in case 3");
           myDFPlayer.play(11); // vraag 4
           while ((buttonStateA == LOW) && (buttonStateB == LOW) && (buttonStateC == LOW))
           {
             buttonStateA = digitalRead(buttonPinA);
             buttonStateB = digitalRead(buttonPinB);
             buttonStateC = digitalRead(buttonPinC);
           }
           if (buttonStateB == HIGH)
           {
             myDFPlayer.play(9); // goed geluid
             aantal = aantal + 1;
             buttonStateB = LOW;
             Serial.println("Ik heb antwoord B gekozen / juiste antwoord");
           }
           if (buttonStateA == HIGH | buttonStateC == HIGH)
           {
               myDFPlayer.play(8); // fout geluid
               buttonStateA = LOW;
               buttonStateC = LOW;
               Serial.println("ik heb antwoord A of C gekozen / foute antwoord");
           }
           delay(5000);
           break;
         case 4:
           Serial.println("ik ben nu in case 4");
           myDFPlayer.play(10); // vraag 5
           while ((buttonStateA == LOW) && (buttonStateB == LOW) && (buttonStateC == LOW))
           {
             buttonStateA = digitalRead(buttonPinA);
             buttonStateB = digitalRead(buttonPinB);
             buttonStateC = digitalRead(buttonPinC);
           }
           if (buttonStateA == HIGH)
           {
             myDFPlayer.play(9); // goed geluid
             aantal = aantal + 1;
             buttonStateA = LOW;
             Serial.println("Ik heb antwoord A gekozen / juiste antwoord");
           }
           if (buttonStateB == HIGH || buttonStateC == HIGH) //
           {
             myDFPlayer.play(8); // fout geluid
             buttonStateB = LOW;
             buttonStateC = LOW;
             Serial.println("ik heb antwoord B of C gekozen / foute antwoord");
           }
           if (buttonStateE == HIGH)
           {
             buttonStateE = HIGH;
           }
           delay(5000);
           break;
       }
    }
    if (buttonStateE == HIGH)
    {
      Serial.println("Je hebt op stop gedrukt");
      stopfunctie(); // iets met prototypes bovenaan.
    }
  einde();
}

void einde()
{
  switch (aantal)
    {
      case 0:
        myDFPlayer.play(7); // Je hebt 0 vragen goed, het spel is afgelopen.
        Serial.println("Je hebt 0 vragen goed");
        break; 
      case 1: 
        myDFPlayer.play(6); // Je hebt 1 vraag goed, het spel is afgelopen.
        Serial.println("Je hebt 1 vraag goed");
        break;
      case 2: 
        myDFPlayer.play(5); // Je hebt 2 vragen goed, het spel is afgelopen.
        Serial.println("Je hebt 2 vragen goed");
        break;
      case 3: 
        myDFPlayer.play(4); // Je hebt 3 vragen goed, het spel is afgelopen.
        Serial.println("Je hebt 3 vragen goed");
        break;
      case 4: 
        myDFPlayer.play(3); // Je hebt 4 vragen goed, het spel is afgelopen.
        Serial.println("Je hebt 4 vragen goed");
        break;
      case 5: 
        myDFPlayer.play(2); // Je hebt 5 vragen goed, het spel is afgelopen.
        Serial.println("Je hebt 5 vragen goed");
        break;
    }
}


int stopfunctie()
{
  myDFPlayer.play(15); // weet je zeker dat je wilt stoppen? Klik nog een keer op stop om definitief te stoppen. Als je verder wilt gaan, wacht 5 seconden. 
  buttonStateE = LOW;
  startMillis = millis();
  buttonStateE = digitalRead(buttonPinE); // is deze overbodig? 
  while (buttonStateE == LOW)
  {
    currentMillis = millis();
    buttonStateE = digitalRead(buttonPinE); // is deze overbodig? 
    if ((currentMillis - startMillis >= period) && (buttonStateE == LOW))
    {
      quiz();
    }
  }
  buttonStateE = digitalRead(buttonPinE); // is deze overbodig? 
  if (buttonStateE == HIGH)
  {
    einde(); //
  }
}
