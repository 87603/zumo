#include "Retreater.h"

Retreater::Retreater() : measurer(), turner()
{
}

bool Retreater::startRetreat(int t, int s)
{
  //onthoud variabele tussen aanroepen
  static bool draaienKlaar = false;

  if (!draaienKlaar) {
    if (turner.startTurn(s)) {
      draaienKlaar = true;
    }
    if (draaienKlaar)
    return false;
  }

  // draaien is klaar
  bool rijdenKlaar = measurer.driveForward(t);
  if (rijdenKlaar) {
    draaienKlaar = false;  // reset voor volgende keer
    return true;
  }
  return false;
}

void Retreater::update(int s)
{

}
