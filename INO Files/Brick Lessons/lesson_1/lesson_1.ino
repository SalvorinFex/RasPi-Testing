/*
Lesson One
*/
void setup()
{
pinMode (12, OUTPUT); // set the socket D12 as an output
pinMode (8, INPUT); // set the socket D8 as an input
}
void loop()
{
if (digitalRead(8) == HIGH) // if the button has been
// pressed
{
digitalWrite(12, HIGH); // turn on the LED
delay(100);
}
digitalWrite(12,LOW); // turn off the LED
}
