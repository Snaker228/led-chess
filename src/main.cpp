#include <Arduino.h>
#include "Servers.h"
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "WiFi_Connect.h"
#include "Configuration.h"
#include "Adafruit_NeoPixel.h"
#include "SD.h"
#include "SPI.h"
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include "Firmware.h"

unsigned long proverka = TIMERESPONSE;
unsigned long f;

void setup() {
    Serial.begin(115200);
        strip.show();
    if (!SD.begin(4)) {                                         //Если не удалось подключиться к сд карте
        Serial.println("initialization failed!");
        sdnebegin();
    }
  firmware_setup();
    //servers();
    // updateFirmware();
}

void loop() {
  f = millis();
  firmware_loop();
  Serial.println(WiFi.localIP());
  // updateServer();
  if(wifi){
    if (WiFi.status() == WL_DISCONNECTED){
        LastGin();
      }
  }
}