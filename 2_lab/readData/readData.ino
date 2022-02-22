/*

  Get request from PC and send monitor's data into serial

  Author: Shirokov Maxim aka Geloger
  Created: 18.02.2022 15:50
  Version: 0.2
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.print((char)255);
  Serial.flush();
}

// the loop routine runs over and over again forever:
void loop() {
//  if the module get some message from PC
  if(Serial.available() > 0) {
//    read the first available bite
    int bite = Serial.read();
//    if bite is equal to '0' then send data into serial
    if(bite == 48) {
//      temperature monitor should be connected to pin A0
      Serial.print(analogRead(A0)); 
//      separator for different data
      Serial.print(":");
//      pressure should be connected to pin A1
      Serial.print(analogRead(A1));
//      end of data
      Serial.print('\n');
      Serial.flush();
    }
  }

  
  // read the input on analog pin 0:
//  int sensorValue = analogRead(A0);
  // print out the value you read:
//  Serial.println("Hello, world!");
//  Serial.println(sensorValue);
//  delay(1);        // delay in between reads for stability
}
