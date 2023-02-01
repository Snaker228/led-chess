#pragma once

#include <Arduino.h>
#include "detail.h"

namespace game_logic {
namespace matrix_figure {
using namespace game_logic::detail::constant;

/// @brief Типы фигур в шашек
enum Figure : uint8_t {
  /// @brief Белая фигура
  White,

  /// @brief Чёрная фигура
  Black,

  /// @brief Пустая ячейка
  Empty,

  /// @brief Это ячейка вообще не используется в игре
  NotUsed,
};

/// @brief Матрица шашек
struct MatrixFigure {
  /// @brief Конструктор, который везде ставит `Figure::NotUsed`
  constexpr MatrixFigure() : figures{Figure::NotUsed} {
    for (auto h = 0; h < HEIGHT_MATRIX; ++h)
      for (auto w = 0; w < WIDTH_MATRIX; ++w)
        this->figures[h][w] = Figure::NotUsed;
  }

  /// @brief Напечать их в Serial
  void Print() noexcept;

  /// @brief Сама наша матрица
  Figure figures[HEIGHT_MATRIX][WIDTH_MATRIX];
};

namespace detail {
/// @brief Вставить один слой в матрице
/// @param is_even Номер ячейки должны быть чётными
/// @param height Координата высоты матрицы
/// @param type_figure Сам тип фигуры для вставки
/// @warning Вам нужно использовать его вместе с объектом (из-за this)
constexpr void InsertLayerForMatrixFigure(MatrixFigure& matrix,
                                          bool is_even,
                                          uint8_t height,
                                          Figure type_figure) noexcept {
  for (auto w = 0; w < WIDTH_MATRIX; ++w)
    if (!is_even && w % 2 != 0)
      matrix.figures[height][w] = type_figure;
    else if (is_even && w % 2 == 0)
      matrix.figures[height][w] = type_figure;
}
}  // namespace detail

/// @brief Получить уже генерированный (генерация происходит во время
/// компиляции) шашки
/// @return Сами наша матрица фигур
constexpr MatrixFigure GetGeneratedMatrixFigure() {
  MatrixFigure matrix_figure;

  detail::InsertLayerForMatrixFigure(matrix_figure, false, 0, Figure::White);
  detail::InsertLayerForMatrixFigure(matrix_figure, true, 1, Figure::White);
  detail::InsertLayerForMatrixFigure(matrix_figure, false, 2, Figure::White);

  detail::InsertLayerForMatrixFigure(matrix_figure, true, 3, Figure::Empty);
  detail::InsertLayerForMatrixFigure(matrix_figure, false, 4, Figure::Empty);

  detail::InsertLayerForMatrixFigure(matrix_figure, true, 5, Figure::Black);
  detail::InsertLayerForMatrixFigure(matrix_figure, false, 6, Figure::Black);
  detail::InsertLayerForMatrixFigure(matrix_figure, true, 7, Figure::Black);

  return matrix_figure;
}
};  // namespace matrix_figure
}  // namespace game_logic