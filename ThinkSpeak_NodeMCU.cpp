#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
const char apiKey[] = "L8ZID0ZTX01K2SAI";
const char readApiKey[] = "UV4A2NIRICC8IC7B";
long channelID = 1848934;
const int fieldNumber = 1;
const char *ssid = "POCO X3";
const char *pass = "hari633839";
const char* server = "api.thingspeak.com";
WiFiClient client;
//D6 = Rx & D5 = Tx
SoftwareSerial arduino(D6 , D5);
//D3 = Rx & D2 = Tx
SoftwareSerial actuation(D3 , D2);
void setup() {
Serial.begin(9600);
arduino.begin(9600);
actuation.begin(9600);
WiFi.begin(ssid, pass);
while(WiFi.status() != WL_CONNECTED)
{
delay(200);
Serial.print("still waiting to connect to internet");
}
Serial.println();
Serial.println("NodeMCU is connected!");
Serial.println(WiFi.localIP());
ThingSpeak.begin(client);
delay(1000);
}
void loop() {
long speedFromCloud=ThingSpeak.readLongField(channelID , fieldNumber , readApiKey);
int statusCode = ThingSpeak.getLastReadStatus();
if(statusCode == 200)
{
Serial.println(speedFromCloud);
if(speedFromCloud > 50)
{
int result = 1;
Serial.println("this is coming from the cloud");
Serial.println(speedFromCloud);
actuation.write(result);
delay(1000);
ThingSpeak.writeField(channelID, 1, 0, apiKey);
}
}
else Serial.println("some error occurred while reading the channel");
}