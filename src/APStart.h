#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "Configuration.h"



AsyncWebServer server(80);
void AP(const char* ssid, const char* pass){
    WiFi.softAP(ssid, pass);
    server.on("/", conf_chess);
    server.begin();
}

void conf_chess(){
    server.send(200, "text/html", htmlFile);
}