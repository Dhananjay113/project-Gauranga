// ACS712 Arduino Code (without header file)
// Reads current using ACS712 current sensor and displays it on the Serial Monitor

// Define the ACS712 sensitivity (mV/A) and the Arduino analog pin to which it is connected
#define ACS712_SENSITIVITY 185  // Sensitivity for 5A ACS712 module
#define ACS712_PIN A1  // Analog pin for ACS712

#define ZMPT101B_PIN A0 // Analog input pin for ZMPT101B

// AC Voltage Calibration Parameters
#define ADC_RESOLUTION 1024.0 // ADC resolution (for 10-bit ADC)
#define VREF 5.0 // Reference voltage of the Arduino
#define ZMPT101B_VOLTAGE_RATIO 0.707 // Voltage ratio of ZMPT101B (calibration value)

float   phaseAngle;

void setup() {
  // Start Serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the analog value from the ACS712 sensor
  int sensorValue = analogRead(ACS712_PIN);

  // Convert the analog value to current in milliamperes (mA)
  float current;
  current = (sensorValue - 512) * ACS712_SENSITIVITY / 1024.0;

  // Display the current value on the Serial Monitor
  Serial.print("Current: ");
  Serial.print(current);
  Serial.println(" mA");

  //delay(100); // Wait for 1 second

  // Read ADC value from ZMPT101B
  int rawValue = analogRead(ZMPT101B_PIN);
  
  // Convert ADC value to AC voltage
  float voltage = (rawValue / ADC_RESOLUTION) * VREF / ZMPT101B_VOLTAGE_RATIO;
  
  // Print the AC voltage to serial monitor
  Serial.print("AC Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");
  
  //delay(100); // Delay for 1 second

  phaseAngle = atan2(voltage, current) * (180 / PI); // Calculate phase angle in degrees

    Serial.println(phaseAngle);
    delay(100);


}
