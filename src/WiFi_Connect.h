#include <ESP8266WiFi.h> 
#include <Configuration.h> 
#include "Adafruit_NeoPixel.h"

int led_pin = matrixLed;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(67, led_pin, NEO_GRB + NEO_KHZ800);
bool wifi;
const char* LastSSID;
const char* LastPASS;

bool connectWifi(const char* ssid, const char* password, int timeout)
{
    WiFi.mode(WIFI_AP_STA);
    Serial.print("Connected");
    bool connect = true;
    bool stat = true;
    WiFi.begin(ssid, password);
    int n = 0;
    bool l = 1;
    while (WiFi.status() != WL_CONNECTED) {
        for (int i = 0; i <35; i++) {              
            strip.setPixelColor(i, strip.Color(255, 255, 255)); // Белый цвет. 
        } 
        strip.show();
        Serial.print("...");
        l = !l;
        digitalWrite(2, l);
        stat = !stat;
        delay(500);
        for (int i = 0; i <35; i++) {              
            strip.setPixelColor(i, strip.Color(0, 0, 0)); // Белый цвет. 
        } 
        strip.show();
        delay(500);
        n++;
        LastSSID = ssid;
        LastPASS = password;
        if(n==timeout) {
            connect = false; 
            break;
        }
    }
    Serial.println(" ");
    return connect;
}

void LastGin(){
    strip.setBrightness(90);
    strip.show();
    if(!wifi) wifi = connectWifi(LastSSID, LastPASS, TIMEOUT);
    if(!wifi) {
        for (int i = 0; i <35; i++) {              
            strip.setPixelColor(i, strip.Color(255, 0, 0)); // Красный цвет. 
        } 
        strip.setBrightness(90);
        strip.show();
    }
    if(wifi){
        for (int i = 0; i < 35; i++) { 
            strip.setPixelColor(i, strip.Color(0, 0, 255)); // Синий цвет. 
        } 
        strip.setBrightness(170);
        strip.show();
        strip.setBrightness(170);
    }

}

void sdnebegin(){
    strip.begin();
    for (int i = 0; i <35; i++) {              
        strip.setPixelColor(i, strip.Color(255, 255, 255)); // Белый цвет. 
    } 
    strip.setBrightness(90);
    strip.show();
    const char* ssid = APSSID;
    const char* pass = APPSK;

    const char* ssid1 = APSSID1;
    const char* pass1 = APPSK1;

    const char* ssid2 = APSSID2;
    const char* pass2 = APPSK2;

    const char* ApSsid = SSID;
    const char* ApPass = PASS;

    wifi = connectWifi(ssid, pass, TIMEOUT);
    if(!wifi) wifi = connectWifi(ssid1, pass1, TIMEOUT);
    if(!wifi) wifi = connectWifi(ssid2, pass2, TIMEOUT);
    if(!wifi) {
        for (int i = 0; i <35; i++) {              
            strip.setPixelColor(i, strip.Color(255, 0, 0)); // Красный цвет. 
        } 
        strip.setBrightness(90);
        strip.show();
        Serial.println("CoHHeCD");
        WiFi.softAP(ApSsid, ApPass);
    }
    if(wifi){
        for (int i = 0; i < 35; i++) { 
            strip.setPixelColor(i, strip.Color(0, 0, 255)); // Синий цвет. 
        } 
        strip.setBrightness(170);
        strip.show();
        strip.setBrightness(170);
    }
}
