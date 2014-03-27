//**************************************************
/*
  Author: Malcolm Knapp
  Project: Stopwatch
  Date: 2/5/14
  Version: 1.0
  Description: This program is a for the Arduino stopwatch start code using non-blocking 
               timers. To extend this code into the full stopwatch use the Stopwatch Tutorial 1.0. 
               The complete code uses two button as inputs and an LCD as an output  
  Note: This source code is licensed under a Creative Commons License, CC-by-nc-sa.
        (attribution, non-commercial, share-alike)
   see http://creativecommons.org/licenses/by-nc-sa/3.0/ for details.
*/ 
//***************************************************
typedef unsigned char byte;
// included libraries
#include <LiquidCrystal.h>
#include <Button.h>

// pin definitions
#define START_BUTTON_PIN 6
//-7-

// variable initialize 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Button start_button = Button(START_BUTTON_PIN, BUTTON_PULLUP);
//-8-

unsigned long timerInterval = 1000; // duration variable in milliseconds
//-1-
unsigned long timerLastStart = 0;  // Last Start Time variable in milliseconds
//-2-
int secondCount1 = 0;
//-3-

//-5-

void setup () {
  Serial.begin (9600);
  Serial.println("Non Blocking Timer");
  Serial.println("Lets Begin");

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Timer: ");
  lcd.print(secondCount1);
  lcd.print ("s");
 
  //-6-
 
}

void loop () {
  
  if (start_button.uniquePress ()) {
  } 
  
  //-9-
  
  if(millis() - timerLastStart > timerInterval) {
    timerLastStart = millis();
    // event code
    secondCount1++;
    lcd.setCursor(0, 0);  
    lcd.print("Timer: ");
    lcd.print(secondCount1);
    lcd.print ("s");  
  }
  
  //-4-
  
}

