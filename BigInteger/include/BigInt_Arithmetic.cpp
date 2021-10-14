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

BigInteger BigInteger::operator*(const BigInteger& val) const {
  BigInteger ret;
  ret.signum = this->signum * val.signum;
  if (ret.signum == 0) return BigInteger();
  int len1 = this->mag.size(), len2 = val.mag.size();
  ret.mag = vi(len1 + len2);
  long long tmp;
  for (int i = 0; i < len1; ++i) {
    for (int j = 0; j < len2; ++j) {
      tmp = (long long)this->mag[i] * (long long)val.mag[j] + ret.mag[i + j];
      ret.mag[i + j] = (int)(tmp % BigInteger::kMod_);
      ret.mag[i + j + 1] += (int)(tmp / BigInteger::kMod_);
    }
  }
  ret.RemoveZero();
  return ret;
}

BigInteger BigInteger::operator+() const { return *this; }

BigInteger BigInteger::operator-() const {
  BigInteger ret = *this;
  ret.signum *= -1;
  return ret;
}