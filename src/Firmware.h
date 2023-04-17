#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPUpdateServer.h>
#include "Configuration.h"

const char* host = "esp8266-webupdate";
int port = SERVERPORT;

ESP8266WebServer httpServer(port);
ESP8266HTTPUpdateServer httpUpdater;

void firmware_setup() {
  MDNS.begin(host);

  httpUpdater.setup(&httpServer);
  httpServer.begin();

  MDNS.addService("http", "tcp", port);
  Serial.printf("HTTPUpdateServer ready! Open http://%s.local/update in your browser\n", host);
}

void firmware_loop() {
  httpServer.handleClient();
  MDNS.update();
}