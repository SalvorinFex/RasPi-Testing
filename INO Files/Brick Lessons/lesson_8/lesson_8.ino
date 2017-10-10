/*
Lesson Eight
*/
#include <LiquidCrystal.h>
// we need this library for the LCD commands
LiquidCrystal lcd(10,11,12,13,14,15,16);
/* tells Arduino which pins the LCD is connected to;
in this case 10~16, which match the pinouts on chassis
BUS2 socket
*/
void setup()
{
lcd.begin(16, 2); // tells Arduino the LCD dimensions
lcd.setCursor(0,0);
lcd.print("Hello electropus!");
// print text and move cursor to start of next line
lcd.setCursor(0,1);
lcd.print("Please wait...");
delay(2000);
lcd.clear(); // clear LCD screen
lcd.setCursor(0,0);
lcd.print("Temperature is ");
}
float temperature = 0; // this stores the value for temperature
void loop()
{
temperature = analogRead(5); // store value from temp brick
temperature = temperature +252-500;
temperature = temperature / 10;
// maths to convert reading to temperature in Celsius.
// may need calibrating, by comparing with real thermometer
// and adjusting value of -500
delay (100); // wait for 100 milliseconds
lcd.print(" Temperature is ");
lcd.setCursor(0,1);
// move cursor to first character of second line
lcd.print(temperature);
lcd.println(" deg. C. ");
delay(1000); // wait a second
}
