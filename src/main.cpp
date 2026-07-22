#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

// Definición del LED integrado para el ESP32 DevKit V1 (GPIO 2)
#ifndef LED_BUILTIN
  #define LED_BUILTIN 2
#endif

const char* ssid = "Tinto";
const char* pass = "Csw$2023";

const char* mqtt_broker = "test.mosquitto.org";
const int mqtt_port = 1883;
const char* mqtt_topic = "sp/26/2015";
const char* mqtt_client = "3232";

WiFiClient espClient;
PubSubClient vehiculo(espClient);

void setup() 
{
  Serial.begin(115200);

  // Configuración del LED como salida
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW); // Aseguramos que inicie apagado

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);

  Serial.print("Conectando a WiFi");
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("\nWiFi Conectado!");
  Serial.print("IP asignada: ");
  Serial.println(WiFi.localIP());

  // Asignamos el servidor MQTT
  vehiculo.setServer(mqtt_broker, mqtt_port);
}

void loop() 
{
  // Verificamos si seguimos conectados a Mosquitto
  if (!vehiculo.connected()) 
  {
    Serial.print("Conectando a broker MQTT... ");
    if (vehiculo.connect(mqtt_client)) 
    {
      Serial.println("¡Conectado!");
    } 
    else 
    {
      Serial.print("Fallo, rc=");
      Serial.print(vehiculo.state());
      Serial.println(" Reintentando en 2 segundos...");
      delay(2000);
      return; 
    }
  }

  // Mantiene vivo el cliente MQTT
  vehiculo.loop();

  // Generación del dato
  long data = random(5);
  char payload[16];
  itoa(data, payload, 10);

  // Encendemos el LED justo antes de intentar publicar
  digitalWrite(LED_BUILTIN, HIGH);

  if (vehiculo.publish(mqtt_topic, payload)) 
  {
    Serial.print("Publicado en [");
    Serial.print(mqtt_topic);
    Serial.print("]: ");
    Serial.println(payload);
  } 
  else 
  {
    Serial.println("Error al publicar mensaje.");
  }

  // Pequeña pausa para que el destello sea visible antes de apagarlo
  delay(25);
  digitalWrite(LED_BUILTIN, LOW);

  // Resto del tiempo de espera (900ms para completar 1 segundo en total)
  delay(975);
}