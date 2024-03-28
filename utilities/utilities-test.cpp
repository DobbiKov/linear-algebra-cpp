#include <iostream>

#include "utilities.hpp"

using namespace std;

#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest.h"

TEST_CASE("max function"){
    CHECK(max(1, 1) == 1);
    CHECK(max(1, 17) == 17);
    CHECK(max(196, 45) == 196);
}

TEST_CASE("min function"){
    CHECK(min(1, 1) == 1);
    CHECK(min(1, 17) == 1);
    CHECK(min(196, 45) == 45);
}

TEST_CASE("pgcd function"){
    CHECK(pgcd(1, 1) == 1);
    CHECK(pgcd(1, 17) == 1);
    CHECK(pgcd(15, 5) == 5);
    CHECK(pgcd(18, 12) == 6);
}

int main(int argc, const char **argv) {
  doctest::Context context(argc, argv);
  int test_result = context.run();
  if (context.shouldExit()) return test_result;
  return 0;
}
