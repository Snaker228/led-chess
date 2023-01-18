#pragma once

#include <cstdint>
#include "detail.hpp"

using namespace detail::constant;

/// @brief Типы фигур в шашек
enum figure : uint8_t {
  /// @brief Белая фигура
  white,

  /// @brief Чёрная фигура
  black,

  /// @brief Пустая ячейка
  empty,

  /// @brief Это ячейка вообще не используется в игре
  not_used,
};

/// @brief Матрица шашек
struct matrix_figure {
  /// @brief Вставить один слой в матрице
  /// @param is_even Номер ячейки должны быть чётными
  /// @param height Координата высоты матрицы
  /// @param type_figure Сам тип фигуры для вставки
  constexpr void insert_layer(bool is_even,
                              uint8_t height,
                              figure type_figure) {
    for (auto w = 0; w != WIDTH_MATRIX; ++w)
      if (!is_even && w % 2 != 0)
        this->matrix[height][w] = type_figure;
      else if (is_even && w % 2 == 0)
        this->matrix[height][w] = type_figure;
  }

  /// @brief Конструктор, который генерирует матрицу
  constexpr matrix_figure() : matrix() {
    for (auto h = 0; h != HEIGHT_MATRIX; ++h)
      for (auto w = 0; w != WIDTH_MATRIX; ++w)
        matrix[h][w] = figure::not_used;

    insert_layer(false, 0, white);
    insert_layer(true, 1, white);
    insert_layer(false, 2, white);

    insert_layer(true, 3, empty);
    insert_layer(false, 4, empty);

    insert_layer(true, 5, black);
    insert_layer(false, 6, black);
    insert_layer(true, 7, black);
    // TODO Проверить это
  }

  /// @brief Сама наша матрица
  figure matrix[HEIGHT_MATRIX][WIDTH_MATRIX];
};

/// @brief Вся логика игры в шашках
class game_logic {
 public:
  game_logic();

 private:
  matrix_figure matrix;
};