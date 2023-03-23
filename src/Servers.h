#include <ESP8266WebServer.h>
#include "Configuration.h"
#include <ESP8266HTTPUpdateServer.h>
#include <LittleFS.h>

int SerPort = SERVERPORT;

ESP8266WebServer server(SerPort);
ESP8266HTTPUpdateServer httpUpdater;
void servers(){
    httpUpdater.setup(&server, OTAPATH, OTAUSER, OTAPASSWORD);
    // Настройки
    server.on("/", []()
    { 
        File index = LittleFS.open("/index.html", "r");
        server.send(200, "text/html", index);
        index.close();
    });
    // Инстркции
    server.on("/instruction", []()
    { 
        File instruction = LittleFS.open("/instruction.html", "r");
        server.send(200, "text/html", instruction); 
        instruction.close();
    });
    // Стили
    server.on("/style.css", []()
    { 
        File style = LittleFS.open("/style.css", "r");
        server.send(200, "text/css", style); 
        style.close();
    });
    server.begin();
}