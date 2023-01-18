#include "game_logic/game_logic.hpp"

game_logic::game_logic() {
  constexpr matrix_figure generated_matrix = matrix_figure();
  this->matrix = generated_matrix;
}