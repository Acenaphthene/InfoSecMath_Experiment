#include "BigInteger.hpp"

bool BigInteger::operator==(const BigInteger &x) const {
  return (this->signum == x.signum && this->compareMagnitude(x) == 0);
}

bool BigInteger::operator!=(const BigInteger &x) const {
  return (this->signum != x.signum || this->compareMagnitude(x) != 0);
}

bool BigInteger::operator>(const BigInteger &x) const {
  if (this->signum > x.signum)
    return true;
  else if (x.signum > this->signum)
    return false;
  else
    return ((this->signum < 0 ? false : true) &&
            this->compareMagnitude(x) == 1);
}

bool BigInteger::operator<(const BigInteger &x) const { return (x > *this); }

bool BigInteger::operator>=(const BigInteger &x) const { return !(*this < x); }

bool BigInteger::operator<=(const BigInteger &x) const { return !(*this > x); }