/*
 Lesson Seven
*/
void setup()
{
 Serial.begin(9600); // opens serial port, sets data rate
//to 9600 bps
}
float temperature = 0; // this stores the value from the
 // temperature sensor brick
void loop()
{
 temperature = analogRead(5); // store value of temp brick
 temperature = temperature +252-500; // some maths to
 temperature = temperature / 10; // convert to Celsius
 delay (100); // wait for 100 milliseconds
 Serial.print("Temperature = ");
 Serial.print(temperature);
 Serial.println(" degrees Celsius.");
 delay(500); // wait half a second
}

