#include <ESPAsyncTCP.h>
#include <ESP8266WebServer.h>
#include <ESPAsyncWebServer.h>
#include "Configuration.h"
#include <ESP8266HTTPUpdateServer.h>
#include <LittleFS.h>

int SerPort = SERVERPORT;

// AsyncWebServer server(SerPort);
ESP8266WebServer server(SerPort);
ESP8266HTTPUpdateServer httpUpdater;
void servers(){
        File index = LittleFS.open("/index.html", "r");
        File instruction = LittleFS.open("/instruction.html", "r");
        File style = LittleFS.open("/style.css", "r")
        httpUpdater.setup(&server, OTAPATH, OTAUSER, OTAPASSWORD);
        server.on("/", []()
            { server.send(200, "text/html", index); });
        server.on("/instruction", []()
            { server.send(200, "text/html", instruction); });
        server.on("/style.css", []()
            { server.send(200, "text/css", style); });
        server.begin();
        index.close();
        instruction.close();
        style.close();
}