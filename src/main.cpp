#include <Arduino.h>
#include "Servers.h"
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "WiFi_Connect.h"
#include "Configuration.h"
#include "Adafruit_NeoPixel.h"
#include "SD.h"
#include "SPI.h"

unsigned long proverka = TIMERESPONSE;
unsigned long f;

void setup() {
    Serial.begin(115200);
        strip.show();
    if (!SD.begin(4)) {                                         //Если не удалось подключиться к сд карте
        Serial.println("initialization failed!");
        sdnebegin();
    }
    servers();
}

void loop() {
    f = millis();
    Serial.println(WiFi.localIP());
    server.handleClient();
    if ((millis() - f) == proverka * 1000){                            //Проверяется, подключено ли устройство к интернету
        f = millis();
        if (WiFi.status() == WL_CONNECTED && !SD.begin(4)){
            sdnebegin();
        }
    }
}