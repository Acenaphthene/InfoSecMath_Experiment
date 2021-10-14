#include <iostream>

#include "include/BigInteger.hpp"

int main(int argc, char **argv) {
  BigInteger a, b;
  std::cin >> a >> b;

  printf("a == b: %s\n", (a == b ? "true" : "false"));
  printf("a != b: %s\n", (a != b ? "true" : "false"));
  printf("a >  b: %s\n", (a > b ? "true" : "false"));
  printf("a <  b: %s\n", (a < b ? "true" : "false"));
  printf("a >= b: %s\n", (a >= b ? "true" : "false"));
  printf("a <= b: %s\n", (a <= b ? "true" : "false"));

  return 0;
}