#include "Arduino.h"
#include "WiFi.h"
#include <HTTPClient.h>

char nomeWifi[] = "Iphone Jotape";
char senhaWifi[] = "12345678";
char serverAddress[] = "https://api.tago.io/data";
char contentHeader[] = "application/json";
char tokenHeader[]   = "8d79bd74-b037-4f18-940b-819389defa82";

float M1xM2 = 0
int ledPin1 = 9;    // pino do LED 1
int ledPin2 = 10;   // pino do LED 2
int ledPin3 = 11;   // pino do LED 3
int potPin = A0;    // pino do potenciômetro

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(potPin, INPUT);
  Serial.begin(9600);
  init_wifi();
}

void loop() {
  int potValue = analogRead(potPin);   // ler o valor do potenciômetro
  int ledValue = map(potValue, 0, 1023, 0, 255); // mapear o valor lido para o intervalo 0-255
  analogWrite(ledPin1, ledValue);      // ajustar o brilho do LED 1
  analogWrite(ledPin2, ledValue);      // ajustar o brilho do LED 2
  analogWrite(ledPin3, ledValue);      // ajustar o brilho do LED 3

  void init_wifi(){
  Serial.println("Conectando WiFi");
  Serial.print("Wifi: ");
  Serial.println(nomeWifi);
  WiFi.begin(nomeWifi,senhaWifi);
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
  }
  Serial.println("WiFi Conectado");
  Serial.print("Meu IP eh: ");
  Serial.println(WiFi.localIP());
}
  void send_M1xM2() {
  char anyData[30];
  char postData[300];
  char anyData1[30];
  char bAny[30];
  int statusCode = 0;
     strcpy(postData, "{\n\t\"variable\": \"M1xM2\",\n\t\"value\": ");
  dtostrf(M1xM2, 6, 2, anyData);
  strncat(postData, anyData, 100);
  strcpy(anyData1, ",\n\t\"unit\": \"C\"\n\t}\n");
  strncat (postData, anyData1, 100);
  Serial.println(postData);
  client.begin(serverAddress);
  client.addHeader("Content-Type", contentHeader);
  client.addHeader("Device-Token", tokenHeader);
  statusCode = client.POST(postData);
  delay(2000);
  
    
  Serial.print("Status code: ");
  Serial.println(statusCode);
  Serial.println("End of POST to TagoIO");
  Serial.println()
}
}
