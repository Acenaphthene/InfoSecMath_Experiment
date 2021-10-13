#include "BigInteger.hpp"

BigInteger::BigInteger() {
  this->signum = 0;
  this->mag = std::vector<unsigned int>();
}

BigInteger::BigInteger(const char &x) { new (this) BigInteger((long long)x); }

BigInteger::BigInteger(const unsigned char &x) {
  new (this) BigInteger((unsigned long long)x);
}

BigInteger::BigInteger(const short &x) { new (this) BigInteger((long long)x); }

BigInteger::BigInteger(const unsigned short &x) {
  new (this) BigInteger((unsigned long long)x);
}

BigInteger::BigInteger(const int &x) { new (this) BigInteger((long long)x); }

BigInteger::BigInteger(const unsigned int &x) {
  new (this) BigInteger((unsigned long long)x);
}

BigInteger::BigInteger(const long &x) { new (this) BigInteger((long long)x); }

BigInteger::BigInteger(const unsigned long &x) {
  new (this) BigInteger((unsigned long long)x);
}

BigInteger::BigInteger(const long long &x) {
  if (!x) {
    new (this) BigInteger();
  } else {
    this->signum = x > 0 ? 1 : -1;
    this->mag = std::vector<unsigned int>();
    long long y = x > 0 ? x : -x;
    while (y) {
      this->mag.push_back(y % 100000000ll);
      y /= 100000000ll;
    }
  }
}

BigInteger::BigInteger(const unsigned long long &x) {
  if (!x) {
    new (this) BigInteger();
  } else {
    this->signum = 1;
    this->mag = std::vector<unsigned int>();
    unsigned long long y = x;
    while (y) {
      this->mag.push_back(y % 100000000ull);
      y /= 100000000ull;
    }
  }
}

BigInteger::BigInteger(const float &x) {}

BigInteger::BigInteger(const double &x) {}

BigInteger::BigInteger(const long double &x) {}

BigInteger::BigInteger(const char *x) { new (this) BigInteger(std::string(x)); }

BigInteger::BigInteger(const std::string &x) {
  std::string y = x;
  y = std::string(y.begin() + y.find_first_not_of(' '), y.end());
  if (y[0] == '-') {
    this->signum = -1;
    y = std::string(y.begin() + 1, y.end());
  } else if (y[0] == '+') {
    this->signum = 1;
    y = std::string(y.begin() + 1, y.end());
  } else {
    this->signum = 1;
  }
  std::reverse(y.begin(), y.end());
  y = std::string(y.begin() + y.find_first_not_of(' '), y.end());
  int cnt = 1, cur = 0;
  this->mag = std::vector<unsigned int>();
  for (auto i : y) {
    cur += cnt * (i - '0');
    cnt *= 10;
    if (cnt == 100000000) {
      cnt = 1;
      this->mag.push_back(cur);
      cur = 0;
    }
  }
  if (cur != 0) this->mag.push_back(cur);
  this->RemoveZero();
}

BigInteger::~BigInteger() {
  this->mag.clear();
  this->mag.shrink_to_fit();
}