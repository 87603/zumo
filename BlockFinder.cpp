/**
 * @file BlockFinder.cpp
 * @author Lars, Ivo & Lucas
 * @brief Implementatie van de BlockFinder-klasse, die verantwoordelijk is voor het detecteren van een blok met behulp van proximity sensors.
 * @version 0.1
 * @date 2025-07-05
 * 
 * @copyright Copyright (c) 2025
 */

#include "BlockFinder.h"

// Maximale draaisnelheid
#define turnSpeedMax 300

// Minimale draaisnelheid
#define turnSpeedMin 100

// Verhoogt draaisnelheid bij geen detectie
#define acceleration 2

// Verlaagt draaisnelheid bij detectie
#define deceleration 5

// Drempelwaarde voor objectdetectie via sensors
#define sensorThreshold 6

// Aantal keren dat centrumdetectie bevestigd moet worden
#define nodigAantalCentrums 3

// Constante voor maximale snelheid vooruit
#define MAXSNELHEID 300

Zumo32U4Motors motors;

/**
 * @brief Constructor voor BlockFinder-object. Initialiseert beginsituatie van alle interne variabelen.
 */
BlockFinder::BlockFinder() :
  senseDir(true), turningLeft(false), turningRight(false),
  turnSpeed(turnSpeedMax), lastTimeObjectSeen(0),
  centrumDetectieTeller(0), state(ZOEKEN) {}

/**
 * @brief Initialiseert de proximity sensors aan de voorkant van de robot.
 */
void BlockFinder::setup() {
  proxSensors.initFrontSensor();
}

/**
 * @brief Laat de robot naar links draaien met huidige draaisnelheid.
 */
void BlockFinder::turnLeft() {
  motors.setSpeeds(-turnSpeed, turnSpeed);
  turningLeft = true;
  turningRight = false;
}

/**
 * @brief Laat de robot naar rechts draaien met huidige draaisnelheid.
 */
void BlockFinder::turnRight() {
  motors.setSpeeds(turnSpeed, -turnSpeed);
  turningLeft = false;
  turningRight = true;
}

/**
 * @brief Laat de robot vooruit rijden met maximale snelheid.
 */
void BlockFinder::vooruit() {
  motors.setSpeeds(MAXSNELHEID, MAXSNELHEID);
  turningLeft = false;
  turningRight = false;
}

/**
 * @brief Laat de robot stoppen met bewegen.
 */
void BlockFinder::stop() {
  motors.setSpeeds(0, 0);
  turningLeft = false;
  turningRight = false;
}

/**
 * @brief Update de interne toestand van de robot. Stuurt de motoren op basis van sensorinput.
 * 
 * In toestand ZOEKEN: draait tot object gevonden is in centrum.  
 * In toestand GEVONDEN: doet momenteel niets (kan later worden uitgebreid).
 */
void BlockFinder::update() {
  proxSensors.read();
  uint8_t left = proxSensors.countsFrontWithLeftLeds();
  uint8_t right = proxSensors.countsFrontWithRightLeds();
  bool objectSeen = (left >= sensorThreshold || right >= sensorThreshold);

  switch (state) {
    case ZOEKEN:
      if (objectSeen) {
        lastTimeObjectSeen = millis();
        turnSpeed = constrain(turnSpeed - deceleration, turnSpeedMin, turnSpeedMax);

        if (left < right) {
          turnRight();
          senseDir = true;
          centrumDetectieTeller = 0;
        } else if (left > right) {
          turnLeft();
          senseDir = false;
          centrumDetectieTeller = 0;
        } else {
          centrumDetectieTeller++;
          if (centrumDetectieTeller >= nodigAantalCentrums) {
            vooruit();
            delay(150);
            stop();
            state = GEVONDEN;
          }
        }
      } else {
        centrumDetectieTeller = 0;
        turnSpeed = constrain(turnSpeed + acceleration, turnSpeedMin, turnSpeedMax);
        senseDir ? turnRight() : turnLeft();
      }
      break;

    case GEVONDEN:  // Het block is gevonden
      
      break;
  }
}

/**
 * @brief Geeft aan of het blok gevonden is.
 * @return true als blok gevonden is (state == GEVONDEN), anders false.
 */
bool BlockFinder::isBlokGevonden() const {
  return state == GEVONDEN;
}

/**
 * @brief Geeft de huidige staat van de zoekmachine terug.
 * @return De huidige ZoekerState (ZOEKEN of GEVONDEN).
 */
ZoekerState BlockFinder::getState() const {
  return state;
}

/**
 * @brief Zet het BlockFinder object terug naar de beginstatus.
 */
void BlockFinder::reset() {
  state = ZOEKEN;
  centrumDetectieTeller = 0;
  turnSpeed = turnSpeedMax;
}
