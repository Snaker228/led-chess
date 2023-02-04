#include <Arduino.h>
#include <LittleFS.h>
#include "WiFi_Connect.h"
#include "Configuration.h"
#include "APStart.h"

#define LED_PIN  3

#define COLOR_ORDER GRB


const char* ssid = APSSID;
const char* pass = APPSK;

const char* ssid1 = APSSID1;
const char* pass1 = APPSK1;

const char* ssid2 = APSSID2;
const char* pass2 = APPSK2;

const char* ApSsid = SSID;
const char* ApPass = PASS;


void setup() {
    LittleFS.begin();
    bool wifi;
    wifi = connectWifi(ssid, pass, TIMEOUT);
    if(!wifi) wifi = connectWifi(ssid1, pass1, TIMEOUT);
    if(!wifi) wifi = connectWifi(ssid2, pass2, TIMEOUT);
    if(!wifi) {
        AP(ApSsid, ApPass);
    }
}

void loop() {
}