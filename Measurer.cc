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

  Serial.print("Ticks links: ");
  Serial.println(countsLeft);
  Serial.print("Ticks rechts: ");
  Serial.println(countsRight);

  int16_t averageTicks = (countsLeft + countsRight) / 2;
  float afstand = (averageTicks / 909.0) * 3.14159 * 2.52;


  if (averageTicks >= targetTicks) {
    motor.stop();
    Serial.print("Afstand (cm): ");
    Serial.println(afstand);
    started = false;   
    return true;
  }

  int16_t verschil = countsLeft - countsRight;

  // if (verschil > 2 || verschil < -2) {
  //   motor.forwardTurn(100, verschil);
  // } else {
  //   motor.driveForward(100);
  // }
    motor.tankTurn(100);

  return false;
}
