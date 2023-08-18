#include<SoftwareSerial.h>
//5 = Rx & 6 = Tx
SoftwareSerial nodemcu(5 , 6);
//9 = Rx & 10 = Tx
SoftwareSerial actuation(9 , 10);
int buzzer = 11;
void setup() {
pinMode(buzzer , OUTPUT);
Serial.begin(9600);
nodemcu.begin(9600);
actuation.begin(9600);
delay(1000);
}
void loop() {
int result = 0;
if(actuation.available()) result = actuation.read();
if(result == 1)
{
tone(buzzer, 50);
delay(50);
noTone(buzzer);
delay(100);
}
Serial.println(result);
}