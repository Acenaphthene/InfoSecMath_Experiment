#include "BigInteger.hpp"

bool BigInteger::operator==(const BigInteger &x) const {
  return (this->compareMagnitude(x) == 0);
}

bool BigInteger::operator!=(const BigInteger &x) const {
  return (this->compareMagnitude(x) != 0);
}

bool BigInteger::operator>(const BigInteger &x) const {
  return (this->compareMagnitude(x) == 1);
}

bool BigInteger::operator<(const BigInteger &x) const {
  return (this->compareMagnitude(x) == -1);
}

bool BigInteger::operator>=(const BigInteger &x) const {
  return (this->compareMagnitude(x) != -1);
}

bool BigInteger::operator<=(const BigInteger &x) const {
  return (this->compareMagnitude(x) != 1);
}