#pragma once

#include <Arduino.h>
#include "detail.h"
#include "matrix_figure.h"

namespace game_logic {

using namespace detail::constant;

/// @brief Вся логика игры в шашках
class GameLogic {
 public:
  /// @brief Констуктор
  constexpr GameLogic() : matrix(matrix_figure::GetGeneratedMatrixFigure()){};

  matrix_figure::MatrixFigure& GetMatrix() noexcept;

 private:
  matrix_figure::MatrixFigure matrix;
};
}  // namespace game_logic