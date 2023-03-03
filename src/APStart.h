#include <ESP8266WiFi.h>

void AP(const char* ssid, const char* pass){
    Serial.println("Tочка доступа");
    WiFi.softAP(ssid, pass);
    digitalWrite(2, LOW);
}