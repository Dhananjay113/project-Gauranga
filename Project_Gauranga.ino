#define sensorPin A1

#include<math.h>

float   phaseAngle;

float a;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {

  // ACS ...................................
  unsigned int x = 0;
  float AcsValue = 0.0; 
  float Samples =0.0; 
  float AvgAcs = 0.0;
  float AcsValueF = 0.0;
 
  for (int x =0; x<150;x++)
  {
    AcsValue = analogRead(sensorPin);
    Samples = Samples + AcsValue;
    delay(3);
  }

  AvgAcs = Samples/150.0;
  AcsValueF = (2.5 - (AvgAcs * (5.0/1024.0) ))/0.185;
  Serial.println(AcsValueF);
  delay(100);

  //ZMPT..........................................

  a = analogRead(A0);
  a = (a/512)*10;
  Serial.println(a);
  delay(100);

  //Pf................................................
  phaseAngle = atan2(a, AcsValueF) * (180 / PI); // Calculate phase angle in degrees

}

/*
// Include required libraries
#include <math.h>

// Define the pins for voltage and current inputs
const int voltagePin = A0; // Analog input pin for voltage
const int currentPin = A1; // Analog input pin for current

// Constants for calibration
const float Vcalibration = 1.0; // Calibration factor for voltage
const float Icalibration = 1.0; // Calibration factor for current

// Variables for storing the readings
int Vraw, Iraw; // Raw ADC readings for voltage and current
float Vrms, Irms; // RMS values for voltage and current

// Variable for storing the phase angle
float phaseAngle; // Phase angle between voltage and current

void setup() {
  Serial.begin(9600); // Initialize Serial communication
}

void loop() {
  // Read voltage and current values from analog inputs
  Vraw = analogRead(voltagePin);
  Iraw = analogRead(currentPin);

  // Convert ADC readings to voltage and current RMS values
  Vrms = Vcalibration * (Vraw * 5.0 / 1023.0); // Vcc is assumed to be 5V
  Irms = Icalibration * (Iraw * 5.0 / 1023.0); // Vcc is assumed to be 5V

  // Calculate the phase angle
  phaseAngle = atan2(Vrms, Irms) * (180 / PI); // Calculate phase angle in degrees

  // Print results to Serial monitor
  Serial.print("Vrms: ");
  Serial.print(Vrms);
  Serial.print("V, Irms: ");
  Serial.print(Irms);
  Serial.print("A, Phase Angle: ");
  Serial.println(phaseAngle);
  
  delay(1000); // Delay for stability
}
*/
