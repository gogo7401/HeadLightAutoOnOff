// A0 - the input 
float sensorValue = 0;  // variable to store the value coming from the sensor
float targetVoltageON=13.4;
float targetVoltageOFF=12.8;
void setup()
{
    Serial.begin(9600); 
  // declare the ledPin as an OUTPUT:
  //delay(15000);
  digitalWrite(12, HIGH);
  //digitalWrite(13, HIGH);
  pinMode(12, OUTPUT);
  //digitalWrite(12, HIGH);
  //pinMode(13, OUTPUT);

  delay(15000);
}
void loop() {
  for (int i=0; i<=9; i++)// read the value from the sensor:
    {
      sensorValue = sensorValue + analogRead(A3);
      // stop the program for <sensorValue> milliseconds:
      delay(100);
    }
if  (5*sensorValue/10240>(targetVoltageON)/3) // turn the ledPin on
  {
  digitalWrite(12, LOW);
  //digitalWrite(13, LOW);
  }
if  (5*sensorValue/10240<(targetVoltageOFF)/3)   // turn the ledPin off:
  {
  digitalWrite(12, HIGH);
  //digitalWrite(13, HIGH);
  }

   Serial.print("U e: "); 
   Serial.print(5*sensorValue/10240*5.56);
   Serial.println(" V");  
   Serial.println(sensorValue/10240); 

sensorValue=0;  
}
