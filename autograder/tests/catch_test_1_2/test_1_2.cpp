//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "investment_simulator.h"
using namespace std;

static void test_1_2() {
  investment_simulator<float> i_simulator;
  i_simulator.add(10, 0.5, 'A');
  i_simulator.add(50, 0.5, 'A');
  i_simulator.add(60, 0.5, 'M');
  i_simulator.add(30, 0.5, 'B');
  i_simulator.add(20, 0.5, 'B');
  i_simulator.add(40, 0.5, 'A');
  i_simulator.add(70, 0.5, 'M');
  auto result = i_simulator(8);
  cout << std::setprecision(2) << std::fixed << result.first << " " << result.second;
}

TEST_CASE("Question #1.2") {
    execute_test("test_1_2.in", test_1_2);
}