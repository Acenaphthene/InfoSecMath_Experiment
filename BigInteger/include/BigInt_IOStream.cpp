#include "BigInteger.hpp"

std::istream& operator>>(std::istream& is, BigInteger& x) {
  std::string str;
  is >> str;
  x = BigInteger(str);
  return is;
}

std::ostream& operator<<(std::ostream& os, const BigInteger& x) {
  BigInteger y = x;
  if (y.signum == 0) {
    os << '0';
  } else {
    if (y.signum == -1) os << '-';
    std::reverse(y.mag.begin(), y.mag.end());
    os << y.mag[0];
    y.mag = std::vector<unsigned int>(y.mag.begin() + 1, y.mag.end());
    for (auto i : y.mag) os << std::setw(8) << std::setfill('0') << i;
  }
  return os;
}