//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "investment_simulator.h"
using namespace std;

static void test_1_4() {
  investment_simulator<long double> i_simulator;
  i_simulator.add(36, 0.25, 'A');
  i_simulator.add(36, 0.25, 'A');
  i_simulator.add(36, 0.25, 'A');
  auto result = i_simulator(15);
  cout << std::setprecision(2) << std::fixed << result.first << " " << result.second;
}

TEST_CASE("Question #1.4") {
    execute_test("test_1_4.in", test_1_4);
}