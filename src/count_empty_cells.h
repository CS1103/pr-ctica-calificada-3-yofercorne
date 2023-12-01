//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_PC3_TEO3_V2023_2_COUNT_EMPTY_CELLS_H
#define PROG3_PC3_TEO3_V2023_2_COUNT_EMPTY_CELLS_H

#include <unordered_set>

template <size_t N, template <typename ...> class Container = std::initializer_list>
class count_empty_cells {
  std::unordered_set<size_t> rows;
  std::unordered_set<size_t> cols;
public:
  count_empty_cells() = default;
  explicit count_empty_cells(const Container<std::pair<size_t, size_t>>& cnt) {
    for (const auto& [r, c]: cnt) {
      rows.insert(r); cols.insert(c);
    }
  }
  void add(size_t r, size_t c) { rows.insert(r); cols.insert(c); }
  size_t operator()() const {
    return N * N - (std::size(rows)*(N - std::size(cols)) + std::size(cols) * N);
  }
};


#endif //PROG3_PC3_TEO3_V2023_2_COUNT_EMPTY_CELLS_H
