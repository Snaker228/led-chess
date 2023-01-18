#include <Arduino.h>
#include <unity.h>

void setup()
{
  // NOTE!!! Wait for >2 secs
  // if board doesn't support software reset via Serial.DTR/RTS
  delay(2000);

  pinMode(LED_BUILTIN, OUTPUT);

  UNITY_BEGIN(); // IMPORTANT LINE!
  //RUN_TEST(test_led_builtin_pin_number);
  UNITY_END();
}

void loop() {}