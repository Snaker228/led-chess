#include <ESP8266WiFi.h> 
#include <Configuration.h> 

bool connectWifi(const char* ssid, const char* password, int timeout)
{
    Serial.print("Connected");
    bool connect = true;
    bool stat = true;
    WiFi.begin(ssid, password);
    int n = 0;
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print("...");
        digitalWrite(2, HIGH);
        stat = !stat;
        delay(1000);
        n++;
        if(n==timeout) {
            connect = false; 
            break;
        }
    }
    Serial.println(" ");
    return connect;
}