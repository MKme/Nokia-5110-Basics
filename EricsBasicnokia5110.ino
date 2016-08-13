/*


This is a work in progress but hopefully it will help someone else by providing
a base to start and work from.
Please check out my Youtube videos here and consider a thumbs up if this helped you!
Youtube : http://www.youtube.com/mkmeorg
Website, Forum and store are at http://mkme.org

Pin 11 for PWM LCD backlight on the Nokia 5110
pin 7 - Serial clock out (SCLK)
pin 6 - Serial data out (DIN)
pin 5 - Data/Command select (D/C)
pin 4 - LCD chip select (CS)
pin 3 - LCD reset (RST)
*/


#include "Adafruit_GFX.h"
#include "Adafruit_PCD8544.h"
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);//4 and 3 are reversed on the cheap eBay models

void setup() {
  
  Serial.begin(9600);
  analogWrite(11,220);// PWM of LCD backlight but ebay unit is backwards- 
  //must go high + cycle to dim 
  //Very Dim=230
  Serial.println("Running..."); 
  display.begin();//Display code
  display.setContrast(60);//Nokia 5110 works best around 50- change to suit your unit
  delay(1000);
  display.clearDisplay();     // clears the screen and buffer
  display.setTextSize(1);     // set text size
  display.setTextColor(BLACK);
  //delay(1000);
  // Splash Screen- taken from example code
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);//set cursor top left
  display.println("   Eric's");//Prints the first line then a line break- leave off the ln characters to continue on the same line!
  display.println("");
  display.println("   Gizmos");
  display.println("   DooDad");
  display.println("   Thingy");
  display.display();//this command writes all the preceeding info to the lcd
  delay(2000);//wait 2 seconds
  display.clearDisplay();     // clears the screen and buffer
 
}

void loop() {
 
LCDDisplay();

}

void LCDDisplay(){
  display.clearDisplay();              // clears the screen and buffer
  display.setCursor(0,0);
  display.println(" Analog Pin 0");
  //display.setCursor(5, 1);
  display.println ("");
  int sensorValue = analogRead(A0);
  display.setTextSize(2);     // set text sizebigger
  display.println(sensorValue);//print the pin value driectly
  display.setTextSize(1); //set text size back smaller
  display.println("Raw Value");
  display.display();
  //delay(2000);
}
    
  
   
