// LED bargraph demo code
// ...in which we provide a few functions to drive a 10-segment LED bargraph
// Mike Grusin, SparkFun Electronics
// This code is completely free to use for your purposes

// Hardware setup
// connect Arduino digital pins 0-9 to LED bargraph pins 1-10
// connect LED pins 11-20 via 330-Ohm resistors to ground

void setup() 
{
  int pin;
  
  // set pins 0 to 9 as outputs
  for (pin = 0; pin <= 9; pin++)
  {
    pinMode(pin,OUTPUT);
  }
}

void loop()
{
  int number;
  
// exercise lightOne() up and down

  for (number = 1; number <= 10; number++)
  {
    lightOne(number);
    delay(250);
  }
  
  for (number = 10; number >= 1; number--)
  {
    lightOne(number);
    delay(250);
  }

// exercise barGraph() up and down

  for (number = 1; number <= 10; number++)
  {
    barGraph(number);
    delay(250);
  }
  
  for (number = 10; number >= 1; number--)
  {
    barGraph(number);
    delay(250);
  }

// exercise binary() up and down

  for (number = 0; number <= 1023; number++)
  {
    binary(number);
    delay(10);
  }
  
  for (number = 1023; number >= 0; number--)
  {
    binary(number);
    delay(10);
  }
}

void lightOne(int number)
// input is a number from 0 to 10
// lights only that LED on the bargraph
// (0 lights no LEDs)
{
  int pin;

  for (pin = 0; pin <= 9; pin++)
  {
    if (number-1 == pin)
    {
      digitalWrite(pin,HIGH);
    }
    else
    {
      digitalWrite(pin,LOW);
    }
  }
}

void barGraph(int number)
// input is a number from 0 to 10
// lights that LED and below on the bargraph
// (0 lights no LEDs)
{
  int pin;

  for (pin = 0; pin <= 9; pin++)
  {
    if (number-1 >= pin)
    {
      digitalWrite(pin,HIGH);
    }
    else
    {
      digitalWrite(pin,LOW);
    }
  }
}

void binary(int number)
// input is a number from 0 to 1023 (10 bits)
// if a bit is '1' in that number, the corresponding LED is lit, otherwise it is off
{
  int pin;

  for (pin = 0; pin <= 9; pin++)
  {
    if (number & (1 << pin)) // check if bit position 'pin' in 'number' is a 1 or not
    {
      digitalWrite(pin,HIGH); // it's a 1!
    }
    else
    {
      digitalWrite(pin,LOW); // it's a 0!
    }
  }
}
