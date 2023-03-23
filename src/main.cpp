#include <Arduino.h>
#include "Servers.h"
#include "LittleFS.h"
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "WiFi_Connect.h"
#include "Configuration.h"
#include "APStart.h"
#include "Adafruit_NeoPixel.h"
#include "SD.h"
#include "SPI.h"

int led_pin = matrixLed;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(67, led_pin, NEO_GRB + NEO_KHZ800);


void sD_BEGIN(){

}

void sD_NOT_BEGIN(){
    const char* ssid = APSSID;
    const char* pass = APPSK;

    const char* ssid1 = APSSID1;
    const char* pass1 = APPSK1;

    const char* ssid2 = APSSID2;
    const char* pass2 = APPSK2;

    const char* ApSsid = SSID;
    const char* ApPass = PASS;




    bool wifi;
    wifi = connectWifi(ssid, pass, TIMEOUT);
    if(!wifi) wifi = connectWifi(ssid1, pass1, TIMEOUT);
    if(!wifi) wifi = connectWifi(ssid2, pass2, TIMEOUT);
    if(!wifi) {
        // for (int i = 0; i <35; i++) {              
        //     strip.setPixelColor(i, strip.Color(255, 0, 0)); // Красный цвет. 
        // } 
        // strip.show();
        Serial.println("CoHHeCD");
        startAP(ApSsid, ApPass, WiFi);
    }
    if(wifi){
        for (int i = 0; i < 35; i++) { 
            strip.setPixelColor(i, strip.Color(0, 0, 255)); // Синий цвет. 
        } 
        strip.show();
    }
}

void setup() {
    LittleFS.begin();
    Serial.begin(115200);
    strip.begin();
        for (int i = 0; i < 35; i++) {              
            strip.setPixelColor(i, strip.Color(0, 0, 0)); // Красный цвет. 
        } 
        strip.show();
    if (!SD.begin(15)) {                                         //Если не удалось пдключиться к сд карте
        Serial.println("initialization failed!");
        sD_NOT_BEGIN();
    } else {
        sD_BEGIN();
    }
    servers();
}

void loop() {
    Serial.println(WiFi.localIP());
    server.handleClient();
}