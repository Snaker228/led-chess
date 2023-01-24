#include <ESP8266WiFi.h>
int n = 0;

bool connectWifi(char ssid, char password, int timeout){
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(1000);
        n++;
        if(n==timeout) return false; break;
    }
    if(n!=timeout) return true;
}