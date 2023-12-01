//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "investment_simulator.h"
#include <iomanip>
using namespace std;

static void test_1_3() {
  investment_simulator<float> i_simulator;
  i_simulator.add(360, 0.25, 'A');
  auto result = i_simulator(12);
  cout << std::setprecision(2) << std::fixed << result.first  << " " << result.second;
}

TEST_CASE("Question #1.3") {
    execute_test("test_1_3.in", test_1_3);
}