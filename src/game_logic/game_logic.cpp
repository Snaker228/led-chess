#include "game_logic/game_logic.hpp"

game_logic::game_logic() noexcept {
  matrix_figure generated_matrix = matrix_figure();
  this->matrix = generated_matrix;
}

matrix_figure& game_logic::get_matrix() noexcept {
  return this->matrix;
}