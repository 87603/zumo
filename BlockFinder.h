/**
 * @file BlockFinder.h
 * @author Lars, Ivo & Lucas
 * @brief Declaratie van de BlockFinder-klasse, verantwoordelijk voor het zoeken van een blok met behulp van proximity sensors.
 * @version 0.1
 * @date 2025-07-05
 * 
 * @copyright Copyright (c) 2025
 */

#ifndef BLOCKFINDER_H
#define BLOCKFINDER_H

#include <Zumo32U4.h>

/**
 * @brief Mogelijke toestanden van de BlockFinder.
 * 
 * - ZOEKEN: Robot is bezig met zoeken naar het blok.
 * - GEVONDEN: Robot heeft het blok gevonden.
 */
enum ZoekerState { ZOEKEN, GEVONDEN };

/**
 * @brief De BlockFinder-klasse bestuurt een Zumo-robot om een blok te detecteren via infraroodsensoren.
 * 
 * De klasse gebruikt proximity sensors aan de voorzijde van de robot en past zijn snelheid en draairichting aan op basis van sensorinput.
 */
class BlockFinder {
public:
  /**
   * @brief Constructor. Initialiseert interne variabelen.
   */
  BlockFinder();

  /**
   * @brief Initialiseert de proximity sensors.
   */
  void setup();

  /**
   * @brief Voert één update-stap uit. Gebaseerd op sensorwaarden wordt het gedrag aangepast.
   */
  void update();

  /**
   * @brief Controleert of het blok is gevonden.
   * @return true als het blok is gevonden.
   * @return false als het blok nog niet is gevonden.
   */
  bool isBlokGevonden() const;

  /**
   * @brief Geeft de huidige toestand van de zoekmachine terug.
   * @return ZoekerState enumwaarde (ZOEKEN of GEVONDEN).
   */
  ZoekerState getState() const;

  /**
   * @brief Zet de BlockFinder terug in zijn beginstatus (ZOEKEN).
   */
  void reset();

private:
  /**
   * @brief Object voor het uitlezen van de proximity sensors.
   */
  Zumo32U4ProximitySensors proxSensors;

  /**
   * @brief Richting waarin de robot zoekt bij geen detectie (true = rechts, false = links).
   */
  bool senseDir;

  /**
   * @brief Geeft aan of de robot momenteel naar links draait.
   */
  bool turningLeft;

  /**
   * @brief Geeft aan of de robot momenteel naar rechts draait.
   */
  bool turningRight;

  /**
   * @brief Huidige draaisnelheid van de robot.
   */
  uint8_t turnSpeed;

  /**
   * @brief Tijdstip waarop het blok voor het laatst werd gedetecteerd.
   */
  unsigned long lastTimeObjectSeen;

  /**
   * @brief Teller voor hoe vaak het blok gecentreerd is waargenomen.
   */
  uint8_t centrumDetectieTeller;

  /**
   * @brief Huidige toestand van de robot (ZOEKEN of GEVONDEN).
   */
  ZoekerState state;

  /**
   * @brief Laat de robot naar links draaien.
   */
  void turnLeft();

  /**
   * @brief Laat de robot naar rechts draaien.
   */
  void turnRight();

  /**
   * @brief Laat de robot rechtdoor rijden.
   */
  void vooruit();

  /**
   * @brief Laat de robot stoppen met bewegen.
   */
  void stop();
};

#endif
