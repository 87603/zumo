#include "Measurer.h"

Measurer::Measurer() : motor() 
{
  startTime = 0;
  isDriving = false;
}

/*! Start het voor- of achteruitrijden voor een opgegeven duur */
void Measurer::driveForward(/*int speed,*/ long duration) 
{
  if (duration > 0) {
    motor.driveForward(200);
  } else if (duration < 0) {
    motor.driveForward(-200);
  }
  startTime = millis(); //startijd
  driveDuration = abs(duration); // altijd positieve duur voor timer
  isDriving = true;

}

/*! Controleert of de rijtijd verstreken is en stopt indien nodig */
void Measurer::update() 
{
  if (isDriving) {
    unsigned  long currentTime = millis(); // unsigned long voor grote millisecondenwaarde
    if (currentTime - startTime >= driveDuration) {
      motor.stop();
      isDriving = false;
    }
  }
}
