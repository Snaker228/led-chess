#include <ESP8266WiFi.h> 

bool connectWifi(const char* ssid, const char* password, int timeout){
    WiFi.begin(ssid, password);
    int n = 0;
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(1000);
        n++;
        if(n==timeout) return false; break;
    }
    if(n!=timeout) return true;
}