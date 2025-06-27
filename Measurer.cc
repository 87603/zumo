/*
  De encoder telt 12 ticks (pulsen) per draai van de motoras.
  Omdat het wiel pas 1 keer ronddraait na ongeveer 75,81 motoras-draaiingen,
  geeft dat ongeveer 909 ticks per volledige wielomwenteling.

  Deze functie rijdt de robot vooruit totdat het gemiddelde aantal ticks
  een opgegeven doel (afstand in ticks) heeft bereikt.
  Onderweg wordt de afwijking tussen links en rechts gebruikt om bij te sturen.
*/

#include "Measurer.h"

Measurer::Measurer()
{
}

bool Measurer::driveForward(int d) 
{
  targetTicks = d;
  static bool started = false;

  if (!started) {
    encoders.getCountsAndResetLeft();
    encoders.getCountsAndResetRight();
    started = true;
  }

  int16_t countsLeft = encoders.getCountsLeft();
  int16_t countsRight = encoders.getCountsRight();



  int16_t averageTicks = (countsLeft + countsRight) / 2;


  if (averageTicks >= targetTicks) {
    motor->stop();
    Serial.print("Ticks links: ");
    Serial.println(countsLeft);
    Serial.print("Ticks rechts: ");
    Serial.println(countsRight);
    started = false;   
    return true;
  }


  motor->driveForward(200);

  return false;
}
