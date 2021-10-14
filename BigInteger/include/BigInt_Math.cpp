#include "BigInteger.hpp"

BigInteger abs(const BigInteger &x) {
  BigInteger ret = x;
  if (ret < BigInteger(0)) ret = -ret;
  return ret;
}

BigInteger pow(const BigInteger &a, const BigInteger &b) {
  BigInteger ret(1), base = a, times = b, ZERO, TWO(2);
  while (b != ZERO) {
    if (times % TWO != ZERO) ret *= base;
    base *= base;
    times /= TWO;
  }
  return ret;
}

BigInteger pow(const BigInteger &a, const BigInteger &b,
               const BigInteger &MOD) {
  BigInteger ret(1), base = a % MOD, times = b, ZERO, TWO(2);
  while (b != ZERO) {
    if (times % TWO != ZERO) ret = ret * base % MOD;
    base = base * base % MOD;
    times /= TWO;
  }
  return ret;
}