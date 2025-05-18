#include <Zumo32U4.h>
#include <Wire.h>

Zumo32U4Motors motors;
Zumo32U4IMU Mag;

class Lijnsensor {
private:
    static const int numSensor = 5;
    unsigned int values[numSensor]; // Sensorwaarden (laag = zwart, hoog = wit)

    Zumo32U4LineSensors sensors;

public:
    Lijnsensor() {
        sensors.initFiveSensors();  // Initialiseer de sensoren in de constructor
    }

    void calibrate() {
        Serial.println("Kalibratie start...");
        for (int i = 0; i < 80; i++) {
            sensors.calibrate();  // Voer de kalibratie uit
            delay(100);  // Verhoogde vertraging om kalibratie te stabiliseren
            if (i % 10 == 0) {  // Laat de sensorwaarden zien om het proces te volgen
                Serial.print("Kalibratie stap: ");
                Serial.println(i);
                sensors.read(values);  // Lees de sensorwaarden
                for (int j = 0; j < numSensor; j++) {
                    Serial.print("Sensor ");
                    Serial.print(j + 1);
                    Serial.print(": ");
                    Serial.println(values[j]);
                }
            }
        }
        Serial.println("Kalibratie klaar.");
    }

    void readValues() {
        sensors.read(values);  // Lees de sensorwaarden
        
    }
    unsigned int getSensorValue(int index) {
      return (index >= 0 && index < numSensor) ? values[index] : 0;
    }

    void printSensorValues() {
        for (int i = 0; i < numSensor; i++) {
            Serial.print("Sensor ");
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.println(values[i]);
        }
    }
};

















class Motor {
  private:
  unsigned int Treshold = 600;
  unsigned int Treshold2 = 400;
  public:
  void D_Forward(int L, int R) {
    motors.setSpeeds(L, R);
  }
  void bocht(int Links,int Rechts,int Voor){
  
  }
  void microcorrectie(int Links, int Rechts, int Voor) {
    if (!((Links < Treshold && Links > Treshold2) &&
          (Rechts < Treshold && Rechts > Treshold2) &&
          (Voor < Treshold && Voor > Treshold2))) {
      motors.setSpeeds(10, -10); 
     
    }
  }

  void Stop() {
    motors.setSpeeds(0, 0);
  }
};
Lijnsensor lijnsensor;
Motor Zumo;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  delay(1000);
  
}


int zwartGevondenTeller = 0;
const int maxTeller = 2;
int Treshold = 600;
int Treshool2 = 400;
void loop() {



  lijnsensor.readValues();
  unsigned int s1 = lijnsensor.getSensorValue(0); 
  unsigned int s2 = lijnsensor.getSensorValue(1);
  unsigned int s3 = lijnsensor.getSensorValue(2); 
  unsigned int s4 = lijnsensor.getSensorValue(3);
  unsigned int s5 = lijnsensor.getSensorValue(4);
  bool zietZwart = (s3 < Treshold)&& (s3> Treshool2) ;
  bool zietZwartL = (s1 < Treshold)&& (s1> Treshool2) ;
  bool zietZwartR = (s5 < Treshold)&& (s5> Treshool2) ;
 
  
if (zietZwart&&zietZwartL){
  Serial.println(" bocht gezien");
  Zumo.Stop();

  return;
}
  
if (zietZwart&&zietZwartR){
  Serial.println(" bocht gezien");
  Zumo.Stop();

  return;
}


if (zietZwart) {

    zwartGevondenTeller = maxTeller;  
    Zumo.D_Forward(400, 400);
  } else if (zwartGevondenTeller > 0) {
    zwartGevondenTeller--;  
    Zumo.D_Forward(400, 400); 
  } else {
    Zumo.microcorrectie(s1, s5, s3);
    Zumo.Stop(); 
  }

  delay(50);

 

  delay(100);  
}
