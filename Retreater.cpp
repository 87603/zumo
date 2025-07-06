#include "Retreater.h"

Retreater::Retreater() : measurer(), turner(), mode(0) {}


/*! Start met draaihoek en afstand, als mode 0 is
gaat hij draaien */
void Retreater::startRetreat(int t,  long s)
{
  afstand = s;  
  if (mode == 0) {
    // start draai en zet mode op 1
    turner.startTurn(t);
    mode = 1;
    Serial.println("mode 1");
  }

}


/*! Update voor draai- en rijstappen */
bool Retreater::update()
{
  if (mode == 1) {
    // draai actief, check of klaar
    if (turner.update()) {
      // starten met vooruitrijden
      measurer.driveForward(afstand);

      mode = 2;
    }
    return false;
  } else if (mode == 2) {
    // rijden actief
    measurer.update();
    return true;
  }
  return false;
}
