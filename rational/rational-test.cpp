#include "rational.hpp"
#include <iostream>

using namespace std;

#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest.h"

TEST_CASE("Constructor") {
  Rat r1 = Rat(17);
  CHECK(r1.get_nom() == 17);
  CHECK(r1.get_denom() == 1);

  Rat r2 = Rat(15, 6);
  CHECK(r2.get_nom() == 5);
  CHECK(r2.get_denom() == 2);

  Rat r3 = Rat(17, 6);
  CHECK(r3.get_nom() == 17);
  CHECK(r3.get_denom() == 6);

  Rat r4 = Rat(3, 3);
  CHECK(r4 == Rat(1));

  CHECK(Rat{-2, 3} == Rat{2, -3});
  CHECK(Rat{2, 3} == Rat{-2, -3});
}

TEST_CASE("operator == ") {
  Rat r1 = Rat(17);
  CHECK(r1 == 17);
  CHECK(17 == r1);
  CHECK(r1 == r1);

  // Rat r2 = Rat(1, 2);
  // CHECK(r2 == 0.5);
}

TEST_CASE("Operator +"){
  CHECK(Rat{1, 2} + Rat{1, 2} == Rat{1});

  CHECK(Rat(1, 2) + Rat(3, 5) == Rat(11, 10));

  CHECK(Rat(5) + Rat(6) == Rat(11));
}

TEST_CASE("Operator -"){
  CHECK(Rat{1, 2} - Rat{1, 2} == Rat{0});
  CHECK(-Rat{1, 2} == Rat{-1, 2});

  CHECK(Rat{4, 5} - Rat{3, 2} == -Rat{7, 10});
}

TEST_CASE("Operator *"){
  CHECK(Rat{1, 2} * 3 == Rat{3, 2});
  CHECK(Rat{1, 2} * Rat{3, 4} == Rat{3, 8});
  CHECK(Rat{4, 5} * Rat{5, 4} == Rat{1});
  CHECK(Rat{4, 5} * Rat{5, 4} == 1);
}

TEST_CASE("Operator /"){
  CHECK(Rat{1, 2} / 2 == Rat{1, 4});
  CHECK(Rat{4, 5} / Rat{6, 7} == Rat{14, 15});
}

int main(int argc, const char **argv) {
  doctest::Context context(argc, argv);
  int test_result = context.run();
  if (context.shouldExit())
    return test_result;
  return 0;
}
