#include "ArduinoJson.h"
#include "EspMQTTClient.h"

int ledPin1 = 2;    // pino do LED 1
int ledPin2 = 0;    // pino do LED 2
int ledPin3 = 4;    // pino do LED 3
int potPin = 5;     // pino do potenciômetro
int potPin1 = 33;   // Pino do potenciômetro 1
int potPin2 = 32;   // Pino do potenciômetro 2

void onConnectionEstablished() {
}

EspMQTTClient client{
  "Wokwi-GUEST",   // SSID do WiFi
  "",              // Senha do WiFi
  "mqtt.tago.io",  // Endereço do servidor
  "Default",       // Usuário
  "fc84c027-2ec3-440f-beb7-0c8f9c276fc5", // Token do dispositivo
  "esp",           // Nome do dispositivo
  1883             // Porta de comunicação
};

void setup() {
  Serial.begin(9600);
  pinMode(potPin1, INPUT);
  pinMode(potPin2, INPUT);



  Serial.println("Conectando WiFi");

  while (!client.isWifiConnected()) {
    Serial.print('.');
    client.loop();
    delay(1000);
  }

  Serial.println("WiFi Conectado");
  Serial.println("Conectando com Servidor MQTT");

  while (!client.isMqttConnected()) {
    Serial.print('.');
    client.loop();
    delay(1000);
  }

  Serial.println("MQTT Conectado");

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  int valorPot1 = analogRead(potPin1);
  int valorPot2 = analogRead(potPin2);

  Serial.print("Potenciômetro 1: ");
  Serial.println(valorPot1);
  
  Serial.print("Potenciômetro 2: ");
  Serial.println(valorPot2);

  delay(10); // Ajuste conforme necessário




  // Multímetro 1
  int valorPotenciometro1 = analogRead(32);
  int valorMapeado1 = map(valorPotenciometro1, 0, 4095, 0, 10);

  Serial.print("Multímetro 1: ");
  Serial.println(valorMapeado1);

  char bufferJson1[100];
  StaticJsonDocument<300> documentoJson1;
  documentoJson1["variable"] = "multimetro1";
  documentoJson1["value"] = valorMapeado1;
  documentoJson1["unit"] = "amper";

  serializeJson(documentoJson1, bufferJson1);

  Serial.println(bufferJson1);

  client.publish("multimetro1", bufferJson1);

  delay(2500);
  client.loop();

  // Multímetro 2
  int valorPotenciometro2 = analogRead(33);
  int valorMapeado2 = map(valorPotenciometro2, 0, 4095, 0, 5);

  Serial.print("Multímetro 2: ");
  Serial.println(valorMapeado2);

  char bufferJson2[100];
  StaticJsonDocument<300> documentoJson2;
  documentoJson2["variable"] = "multimetro2";
  documentoJson2["value"] = valorMapeado2;
  documentoJson2["unit"] = "volt";

  serializeJson(documentoJson2, bufferJson2);

  Serial.println(bufferJson2);

  client.publish("multimetro2", bufferJson2);

  delay(2500);
  client.loop();
}
