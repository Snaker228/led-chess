#include <ESP8266WiFi.h> 

bool connectWifi(const char* ssid, const char* password, int timeout)
{
    bool connect = true;
    WiFi.begin(ssid, password);
    int n = 0;
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(1000);
        n++;
        if(n==timeout) {
            connect = false; 
            break;
        }
    }
    return connect;
}