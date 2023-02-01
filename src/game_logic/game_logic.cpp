#include "game_logic/game_logic.h"

using namespace game_logic;
using namespace game_logic::matrix_figure;

MatrixFigure& GameLogic::GetMatrix() noexcept {
  return this->matrix;
}