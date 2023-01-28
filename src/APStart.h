#include <ESP8266WiFi.h>

void AP(const char* ssid, const char* pass){
    WiFi.softAP(ssid, pass);
}