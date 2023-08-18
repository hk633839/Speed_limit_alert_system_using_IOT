#include <SoftwareSerial.h>
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
const char apiKey[] = "L8ZID0ZTX01K2SAI";
const char readApiKey[] = "UV4A2NIRICC8IC7B";
//D6 = Rx & D5 = Tx
SoftwareSerial nodemcu(D6 , D5);
long channelID = 1848934;
const int fieldNumber = 1;
const char *ssid = "POCO X3";
const char *pass = "hari633839";
const char* server = "api.thingspeak.com";
WiFiClient client;
void setup() {
Serial.begin(9600);
nodemcu.begin(9600);
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
}
void loop() {
StaticJsonBuffer<1000> jsonBuffer;
JsonObject& data = jsonBuffer.parseObject(nodemcu);
int speed = data["speed"];
Serial.println("speed: " + (String) speed);
if(speed > 0)
{ThingSpeak.writeField(channelID, 1, speed, apiKey);}
delay(2000);
}