/**
 * @file BlockPusher.h
 * @brief Declaratie van de BlockPusher klasse voor blokduwen.
 */

#ifndef BLOCKPUSHER_H
#define BLOCKPUSHER_H

#include <Zumo32U4.h>
#include "BlockFinder.h"

/** Mogelijke toestanden van de BlockPusher. 
 * 
*/
enum PusherState { INIT, RAMMEN, STOPPEN };

/** Klasse die de robot aanstuurt om blokken te duwen. 
 * 
*/
class BlockPusher {
public:
  /** Constructor voor BlockPusher. 
   * 
  */
  BlockPusher();

  /** Initialiseer hardware en wacht op start. 
   * 
  */
  void setup();

  /** Voer de hoofdlogica uit op basis van de toestand. 
   * 
  */
  void loop();

  /** Controleer of de robot gestopt is. 
   * 
  */
  bool isGestopt() const;

private:
  Zumo32U4ButtonA buttonA;          /** Knop A van de Zumo. */
  Zumo32U4LineSensors lineSensors;  /** Lijnsensoren. */
  Zumo32U4Motors motors;            /** Motoren. */
  BlockFinder finder;               /**<Blokzoeker. */

  PusherState state;                /** Huidige status van de robot. */
  bool middenUitgevoerd;            /** Geeft aan of naar het midden is gereden. */
  unsigned long rammenStartTijd;   /** Tijdstip waarop rammen begon. */
  uint16_t lineSensorValues[5];    /** Waarden van de lijnsensoren. */

  /** Rijd naar het midden. 
   * 
  */
  void gaNaarMidden();

  /** Rijd vooruit. 
   * 
  */
  void vooruit();

  /** Stop de robot. 
   * 
  */
  void stop();
};

#endif
