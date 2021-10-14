#include "BigInteger.hpp"

BigInteger &BigInteger::operator+=(const BigInteger &val) {
  *this = *this + val;
  return *this;
}
BigInteger &BigInteger::operator-=(const BigInteger &val) {
  *this = *this - val;
  return *this;
}
BigInteger &BigInteger::operator*=(const BigInteger &val) {
  *this = *this * val;
  return *this;
}
BigInteger &BigInteger::operator/=(const BigInteger &val) {
  *this = *this / val;
  return *this;
}
BigInteger &BigInteger::operator%=(const BigInteger &val) {
  *this = *this % val;
  return *this;
}