/*
Lesson Four
*/
void setup()
{
pinMode (12, OUTPUT); // set the socket D12 as an output
pinMode (11, OUTPUT); // set the socket D11 as an output
}
int del = 0; // this stores the value from the rotational
// brick, it will be used as the delay value
// for the flashing LEDs
void loop()
{
del = analogRead(1); // put the analog result from the
// rotation brick into the variable del
digitalWrite(12,HIGH); // turn on the green LED
digitalWrite(11,LOW); // turn off the red LED
delay (del); // wait for the period of time specified by
// the rotation brick;
digitalWrite(12,LOW); // turn on the green LED
digitalWrite(11,HIGH); // turn off the red LED
delay (del); // wait for the period of time specified by
// the rotation brick;
}
