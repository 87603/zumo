/**
 * @file zumo.ino
 * @brief Hoofdprogramma voor de Zumo-robot met BlockPusher en Retreater.
 */

#include "Measurer.h"
#include "Turner.h"
#include "Retreater.h"
#include "BlockPusher.h"

/** Motoren van de robot. */
// Motors motors;

/** Klasse voor afstanden meten. */
Measurer measurer;

/** Klasse voor draaien. */
Turner turner;

/** Klasse voor terugtrekken. */
Retreater retreater;

/** Klasse voor blok duwen. */
BlockPusher blockPusher;

/** Knop A van de Zumo. */
Zumo32U4ButtonA buttonA;

/** Status of BlockPusher gestart is. */
bool blockPusherGestart = false;

/** Status of Retreater gestart is. */
bool retreatGestart = false;

/*! afstand voor rijden */
int afstand = 100;

/** Initialiseer seriële communicatie en BlockPusher. */
void setup() {
  Serial.begin(9600);
  blockPusher.setup();
}

/** Hoofdprogramma met statusafhandeling voor BlockPusher en Retreater. */
void loop() {
  if (!blockPusherGestart) {
    Serial.println(F("Wacht op knop A..."));
    buttonA.waitForButton();
    blockPusherGestart = true;
    Serial.println(F("BlockPusher gestart!"));
  }

  if (blockPusherGestart && !retreatGestart) {
    blockPusher.loop();

    if (blockPusher.isGestopt()) {
      retreater.startRetreat(180, ((afstand/17.95)*1000));
      retreatGestart = true;
    }
  }

  if (retreatGestart) {
    retreater.update();
  }
}
