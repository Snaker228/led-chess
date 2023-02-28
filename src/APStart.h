#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "Configuration.h"
#include <LittleFS.h>

int SerPort = SERVERPORT;

ESP8266WebServer server(SerPort);
void AP(const char* ssid, const char* pass){
    Serial.println("Tочка доступа");
    WiFi.softAP(ssid, pass);
    digitalWrite(2, LOW);
    //server.on("/", [](){
    //  File file = LittleFS.open("index.html", "r");
    //  server.streamFile(file, "text/html");
    //  file.close();
    //  return ;
    //});
    //server.begin();
    //while(true){
    //  server.handleClient();
    //}
}
