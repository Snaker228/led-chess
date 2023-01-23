#include <Arduino.h>
<<<<<<< Updated upstream
=======
#include "WiFi_Connect.h"
#include "Configuration.h"
>>>>>>> Stashed changes

bool wifi;
void setup() {
  wifi = connectWifi(APPSSID);
}

void loop() {
}