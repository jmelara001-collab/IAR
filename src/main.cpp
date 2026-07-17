#include <Arduino.h>
#include <WiFi.h>

const char* ssid = "Tinto";
const char* pass = "Csw$2023";

const char* mqtt_broker = "test.mosquitto.org";
const char* mqtt_port = "1883";
const char* mqtt_topic = "sp/26/2015";
const char* mqtt_client = "3232";

WiFiClient espClient;
PubSubClient vehiculo(espClient);

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

  vehiculo.setServer(mqtt_broker, mqtt_port);
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