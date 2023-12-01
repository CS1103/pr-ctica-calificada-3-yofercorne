//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_PC3_TEO2_V2023_2_INVESTMENT_SIMULATOR_H
#define PROG3_PC3_TEO2_V2023_2_INVESTMENT_SIMULATOR_H

#include <queue>

template <typename T>
class instrument {
  T equity {};
  T rate {};
  char category {};
public:
  instrument(T equity, T rate, char category):
              equity(equity),
              rate(rate),
              category(category) {}
  T get_profit() {
    auto result = equity;
    equity *= rate;
    return result;
  }
  bool operator<(const instrument& b) const { return equity < b.equity; }
  bool operator>(const instrument& b) const { return equity > b.equity; }
  T get_equity() const {
    return equity;
  }
};

template <typename T>
class investment_simulator {
  std::vector<instrument<T>> instruments;
public:
  void add(T equity, T rate, char category) {
    instruments.emplace_back(equity, rate, category);
  }
  pair<T,T> operator()(size_t k) {
    T recovery {};
    std::priority_queue<instrument<T>> pq(begin(instruments), end(instruments));
    while (k--) {
      auto inst = pq.top();
      recovery += inst.get_profit();
      pq.pop();
      pq.push(inst);
    }
    
    T equity{};
    while (!pq.empty()) {
      equity += pq.top().get_equity();
      pq.pop();
    }
    return {recovery, equity};
  }
};



#endif //PROG3_PC3_TEO2_V2023_2_INVESTMENT_SIMULATOR_H
