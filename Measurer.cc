/*
  De encoder telt 12 ticks (pulsen) per draai van de motoras.
  Omdat het wiel pas 1 keer ronddraait na ongeveer 75,81 motoras-draaiingen,
  geeft dat ongeveer 909 ticks per volledige wielomwenteling.

  Deze functie rijdt de robot vooruit totdat het gemiddelde aantal ticks
  een opgegeven doel (afstand in ticks) heeft bereikt.
  Onderweg wordt de afwijking tussen links en rechts gebruikt om bij te sturen.
*/

#include "Measurer.h"

Measurer::Measurer() : motor()
{
  int16_t countsLeft = 0;
  int16_t countsRight = 0;
  targetTicks = 0;
}

bool Measurer::driveForward(float d) 
{
  //reken afstand om naar ticks

  /*! bereken target ticks, gebruik gegeven afstand, deel door pi keer diameter wiel en keer 909. 
  909 is aantalticks van volledige rotatoei van het wiel. 409 om te stoppen
  wanneer de bumper het doel heeft bereikt. 
  */
  targetTicks = (d / (3.14159 * 2.5)) * 909;
  encoders.getCountsAndResetLeft();
  encoders.getCountsAndResetRight();

return update();
}

/*! update is een bool die telt de ticks, berekent het gemiddelde omdat er een klein 
verschil tussen left en right zit en kijkt of averageticks groter is dan targetTicks is
Als groter dan true, zo niet false.  */
bool Measurer::update() {

  int countsLeft = encoders.getCountsLeft();
  int countsRight = encoders.getCountsRight();

  int averageTicks = (countsLeft + countsRight) / 2;

  int afgelegdeAfstand = (averageTicks / 909.0) * 3.14159 * 2.5;
  
  if (targetTicks > 0) {
    if (averageTicks < targetTicks) {
      motor.forwardTurn(200, (countsLeft-countsRight));
      return false;
    } else {
      motor.stop();
      }
      return true;
  } else {
    if (averageTicks > targetTicks) {
      motor.forwardTurn(-200, (countsRight-countsLeft));
      return false;
    } else {
      motor.stop();
      return true;
    }

    return true;
  }

  return false;
}