#define sensorPin A1
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


}
