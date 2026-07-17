#include <Arduino.h>
#include <WiFi.h>

const char* ssid = "Tinto";
const char* pass = "Csw$2023";

void setup() 
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);

  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }

}

void loop() 
{
  /*int n = WiFi.scanNetworks();
  for(int i=0; i<n;i++)
  {
    Serial.println(WiFi.SSID(i));
    delay(2500);
  }*/

  Serial.println(WiFi.localIP());
  delay(1000);
}