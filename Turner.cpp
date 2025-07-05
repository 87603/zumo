#include "Turner.h"

Turner::Turner() : motor()
{
  encoders.getCountsAndResetLeft();
  encoders.getCountsAndResetRight();
}


/*! Berekent benodigde ticks en stelt richting in */
void Turner::startTurn(int degrees)
{
  // Gebruik het teken van degrees om richting te bepalen
  int deg = abs(degrees);
  float afstand = (3.14159 * 9.7 * deg) / (2 * 360.0); // pi * wheelbase
  float omtrek = 3.14159 * 2.5; // pi * wiel diameter

  ticksNeeded = (afstand / omtrek) * 909;
  turnDirection = (degrees >= 0);  // true = rechtsom, false = linksom

  encoders.getCountsAndResetLeft();
  encoders.getCountsAndResetRight();
}

/*! Voert de draai uit en controleert of doel bereikt is */
bool Turner::update()
{
  //abs want de wielen draaien tegenovergesteld, met abs wordt alleen afstand gemeten
  int left = abs(encoders.getCountsLeft());
  int right = abs(encoders.getCountsRight());
  int gemiddeldeTicks  = (left + right) / 2;

  if (turnDirection) {
    motor.tankTurn(300);
  } else {
    motor.tankTurn(-300);
  }

  if (gemiddeldeTicks >= ticksNeeded) {
    motor.stop();
    Serial.print("Gemiddelde ticks: ");
    Serial.println(gemiddeldeTicks);
    Serial.println();

    return true;
  }
    return false;
}
