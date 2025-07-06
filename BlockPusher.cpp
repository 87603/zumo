/**
 * @file BlockPusher.cpp
 * @brief Bevat de implementatie van de BlockPusher klasse voor het duwen van blokken.
 */

#include "BlockPusher.h"

#define MAXSNELHEID 300  /**< Maximale motorsnelheid */
#define maxRamtijd 2000  /**< Maximale ramtijd in milliseconden */

/** Constructor, initialiseert de BlockPusher. 
 * 
*/
BlockPusher::BlockPusher() :
  state(INIT), middenUitgevoerd(false), rammenStartTijd(0) {}

/** Initialiseer communicatie, sensoren en wacht op startknop. 
 
*/
void BlockPusher::setup() {
  Serial1.begin(9600);
  finder.setup();
  lineSensors.initFiveSensors();

  Serial1.print(F("Druk op knop A om te starten..."));
  buttonA.waitForButton();

  motors.setSpeeds(MAXSNELHEID, MAXSNELHEID);
  delay(1000);
  motors.setSpeeds(0, 0);
}

/** Laat de robot vooruit rijden. 
 * 
*/
void BlockPusher::vooruit() {
  motors.setSpeeds(MAXSNELHEID, MAXSNELHEID);
}

/** Stop de robot. 
 * 
*/
void BlockPusher::stop() {
  motors.setSpeeds(0, 0);
}

/** Rijd met lage snelheid naar het midden. 
 * 
*/
void BlockPusher::gaNaarMidden() {
  motors.setSpeeds(100, 100);
  delay(600);
  motors.setSpeeds(0, 0);
}

/** Controleer of de robot gestopt is. 
 * 
*/
bool BlockPusher::isGestopt() const {
  return state == STOPPEN;
}

/** Hoofdloop die de robot aanstuurt afhankelijk van de status. 
 * 
*/
void BlockPusher::loop() {
  switch (state) {
    case INIT:
      if (!middenUitgevoerd) {
        gaNaarMidden();
        middenUitgevoerd = true;
      }
      finder.update();
      if (finder.isBlokGevonden()) {
        vooruit();
        delay(150);
        rammenStartTijd = millis();
        state = RAMMEN;
      }
      break;

    case RAMMEN:
      vooruit();
      lineSensors.read(lineSensorValues);
      if (lineSensorValues[0] > 1000 || lineSensorValues[4] > 1000) {
        stop();
        state = STOPPEN;
      }
      if (millis() - rammenStartTijd > maxRamtijd) {
        stop();
        state = STOPPEN;
      }
      break;

    case STOPPEN:
      break;
  }
}
