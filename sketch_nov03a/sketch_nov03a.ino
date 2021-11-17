#include <TFT.h>
#include <SPI.h>
#include <ros.h>

#define cs 10
#define dc 9
#define rst 8

TFT LCDScreen = TFT(cs, dc, rst);
char printout[10];

String batt1 = "";
String batt2 = "";

const int R5 = A6;
const int R6 = A7;

void setup() {
  // put your setup code here, to run once:
  LCDScreen.begin();
  pinMode(R5, INPUT);
  pinMode(R6, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(batt1 != String(analogRead(R5)) || batt2 != String(analogRead(R6))) {
    batt1 = String(analogRead(R5));
    batt2 = String(analogRead(R6));
    LCDScreen.background(0, 0, 0);      // clear screen
  }
  
  LCDScreen.stroke(0, 255, 0);        // set to green
  
  LCDScreen.setTextSize(2);           // set text size
  LCDScreen.text("Battery 1", 0, 0);  // print at (0, 0) coordinate
  batt1.toCharArray(printout, 10);   // add to printout
  LCDScreen.setTextSize(5);           // set text size
  LCDScreen.text(printout, 0, 20);    // print printout array

  LCDScreen.setTextSize(2);
  LCDScreen.text("Battery 2", 0, 60);
  batt2.toCharArray(printout, 10);
  LCDScreen.setTextSize(5);
  LCDScreen.text(printout, 0, 80);

  Serial.println(analogRead(R6));
  delay(500);
}
