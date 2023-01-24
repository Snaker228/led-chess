#include <Arduino.h>
#include "game_logic/game_logic.h"

void setup() {
  auto game_logic = game_logic::GameLogic();
  auto matrix = game_logic.GetMatrix();
}

void loop() {}