#include "Arduino.h"
#include "WiFi.h"


char nomeWifi[] = "Iphone Jotape";
char senhaWifi[] = "12345678";

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
