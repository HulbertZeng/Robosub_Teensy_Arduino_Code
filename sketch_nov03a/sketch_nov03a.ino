#include <TFT.h>
#include <SPI.h>
#include <ros.h>

#define cs 10
#define dc 9
#define rst 8

TFT LCDScreen = TFT(cs, dc, rst);

float num = 0;
String number = "";
char printout[10];

const int R5 = 6;
const int R6 = 7;

void setup() {
  // put your setup code here, to run once:
  LCDScreen.begin();
  pinMode(R5, OUTPUT);
  pinMode(R6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  String batt1 = String(digitalRead(R5));
  String batt2 = String(digitalRead(R5));

  LCDScreen.background(0, 0, 0);      // clear screen
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
  delay(500);
}
