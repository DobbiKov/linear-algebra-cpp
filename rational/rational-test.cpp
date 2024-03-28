#include <iostream>
#include "rational.hpp"

using namespace std;

#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest.h"

TEST_CASE("Constructor"){
    Rat r1 = Rat(17);
    CHECK(r1.get_nom() == 17);
    CHECK(r1.get_denom() == 1);

    Rat r2 = Rat(15, 6);
    CHECK(r2.get_nom() == 5);
    CHECK(r2.get_denom() == 2);

    Rat r3 = Rat(17, 6);
    CHECK(r3.get_nom() == 17);
    CHECK(r3.get_denom() == 6);
}

TEST_CASE("operator == "){
    Rat r1 = Rat(17);
    CHECK(r1 == 17);
    CHECK(17 == r1);
    CHECK(r1 == r1);
}

int main(int argc, const char **argv) {
  doctest::Context context(argc, argv);
  int test_result = context.run();
  if (context.shouldExit()) return test_result;
  return 0;
}
