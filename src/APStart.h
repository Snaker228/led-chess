#include <ESP8266WiFi.h>

void startAP(const char* ssid, const char* passw, ESP8266WiFiClass Wifi){
    Wifi.softAP(ssid, passw);
}