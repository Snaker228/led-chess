
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "Configuration.h"
#include <LittleFS.h>
#include <ESP8266HTTPUpdateServer.h>

int SerPort = SERVERPORT;

AsyncWebServer server(SerPort);
ESP8266HTTPUpdateServer httpUpdater;
void servers(){
    httpUpdater.setup(&server, OTAPATH, OTAUSER, OTAPASSWORD);
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(LittleFS, "/index.html", "text/html"); });
    server.begin();
}