#include "BigInteger.hpp"

BigInteger BigInteger::operator+(const BigInteger& val) const {
  if (val.signum == 0) return *this;
  if (this->signum == 0) return val;
  if (val.signum == this->signum) {
    BigInteger ret;
    ret.mag = BigInteger::add(*this, val);
    ret.signum = this->signum;
    ret.RemoveZero();
    return ret;
  }
  int cmp = this->compareMagnitude(val);
  if (!cmp) return BigInteger();
  BigInteger ret;
  ret.mag = (cmp > 0 ? BigInteger::subtract(*this, val)
                     : BigInteger::subtract(val, *this));
  ret.signum = cmp == this->signum ? 1 : -1;
  ret.RemoveZero();
  return ret;
}

BigInteger BigInteger::operator-(const BigInteger& val) const {
  if (val.signum == 0) return *this;
  if (this->signum == 0) return -val;
  if (this->signum != val.signum) {
    BigInteger ret;
    ret.mag = BigInteger::add(*this, val);
    ret.signum = this->signum;
    ret.RemoveZero();
    return ret;
  }
  int cmp = this->compareMagnitude(val);
  if (!cmp) return BigInteger();
  BigInteger ret;
  ret.mag = (cmp > 0 ? BigInteger::subtract(*this, val)
                     : BigInteger::subtract(val, *this));
  ret.signum = (cmp == this->signum ? 1 : -1);
  ret.RemoveZero();
  return ret;
}

BigInteger BigInteger::operator+() const { return *this; }

BigInteger BigInteger::operator-() const {
  BigInteger ret = *this;
  ret.signum *= -1;
  return ret;
}