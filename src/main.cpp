#include <Arduino.h>
#include "game_logic/game_logic.hpp"

void setup() {
  game_logic game;
  game.get_matrix().print();
}

void loop() {}