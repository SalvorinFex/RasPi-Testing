/*
Lesson Six: connect the rotational brick to analogue pin 5, the
LDR brick to analogue pin 1, and the push button brick to digital pin
8.
*/
void setup()
{
Serial.begin(9600); // opens serial port, sets data rate
// to 9600 bps
}
int rotational = 0; // this stores the value from the
// rotational brick
int ldr = 0; // this stores the value from the LDR brick
void loop()
{
rotational = analogRead(5); // store value of rotational
// brick
ldr = analogRead(1); // store value of LDR brick
delay (100); // wait for 100 milliseconds
Serial.print("Rotational = "); // send information to the
// serial port
Serial.print(rotational);
Serial.print(" - LDR = ");
Serial.println(ldr);
delay(500); // wait half a second
}