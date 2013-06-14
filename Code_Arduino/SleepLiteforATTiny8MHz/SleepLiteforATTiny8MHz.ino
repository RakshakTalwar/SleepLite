/*
  Fades an LED at rate of human heart. Note: values are different as this
  is for ATTiny85 @ 8MHz.
  Instructions for ATTiny85 with Arduino Bootloader
  http://hlt.media.mit.edu/?p=1695
*/

#define lightSensor 2 //connect to pin 3 of ATTiny85 
#define led 1 //Connect to pin 6 of ATTiny85
int lightReading; //value of ambient light being received
float time = 1900.0; //time interval, sets frequency

void setup() 
{
  pinMode(led, OUTPUT); //Tells the ATTiny85 that the pin we're connecting the 
                         //LED to is an output
}

void loop() 
{
 
  lightReading = analogRead(lightSensor);
  
  if(lightReading <= 261)// if light level is low enough start SleepLite                                         
  {
    for(int i=0; i<=255; i++) //Gently fades in the LED
    {
    analogWrite(led, i);
    delayMicroseconds(time);
    }
    for(int i=255; i>=0; i--) //Gently fades out the LED
    {
    analogWrite(led, i); 
    delayMicroseconds(time);
    }
    if(time<(2600.0)) 
    time+=1.5; //rate at which the flashing slows (higher number = slower)
  }
  else //if too much ambient light keep SleepLite off 
    {
     analogWrite(led, 0); //turns off LED
     time = 1900.0; //resets frequency to 1Hz
     delay(1); //gives ATTiny85 a break
    }
}
