#include <Arduino.h>
#include "WiFi_Connect.h"
#include "Configuration.h"

bool wifi;
void setup() {
    wifi = connectWifi(APSSID, APPSK, TIMEOUT);
    if(!wifi) wifi = connectWifi(APSSID1, APPSK1, TIMEOUT);
    if(!wifi) wifi = connectWifi(APSSID2, APPSK2, TIMEOUT);
    if(!wifi) 
}

void loop() {
}