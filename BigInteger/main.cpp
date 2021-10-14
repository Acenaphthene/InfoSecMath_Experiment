#include <iostream>

#include "include/BigInteger.hpp"

int main(int argc, char **argv) {
  BigInteger a, b;
  std::cin >> a >> b;
  std::cout << "a + b = " << a + b << std::endl;
  std::cout << "a - b = " << a - b << std::endl;
  std::cout << "a * b = " << a * b << std::endl;
  std::cout << "a / b = " << a / b << std::endl;
  std::cout << "a % b = " << a % b << std::endl;

  return 0;
}