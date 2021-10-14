#include "BigInteger.hpp"

BigInteger BigInteger::operator++() {
  *this += BigInteger(1);
  return *this;
}
BigInteger BigInteger::operator++(int) {
  BigInteger ret = *this;
  *this += BigInteger(1);
  return ret;
}
BigInteger BigInteger::operator--() {
  *this -= BigInteger(1);
  return *this;
}
BigInteger BigInteger::operator--(int) {
  BigInteger ret = *this;
  *this -= BigInteger(1);
  return ret;
}