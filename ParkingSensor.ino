//Proximity sensor for parking wall
//Developed by: Ian Maralhas

#include <Ultrasonic.h>
 
#define pino_trigger 6
#define pino_echo 7
#define pinoRele 9
 
//Initialize the sensor on the pins defined above
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup()
{
  pinMode( pinoRele, OUTPUT);
}
 
void loop()
{
 
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);

  if (cmMsec <= 15){
    digitalWrite( pinoRele, LOW );
    delay (1000);   
  }
  else {
    digitalWrite( pinoRele, HIGH );
    delay (1000);
  }
   
}
