#pragma once

#include <algorithm>
#include <cstring>
#include <iomanip>
#include <istream>
#include <ostream>
#include <string>
#include <vector>

class BigInteger {
 private:
  // -1 for negative, 0 for zero, or 1 for positive.
  int signum;
  // The magnitude. When the integer is 0, the length will be 0.
  std::vector<unsigned int> mag;
  // Remove prefix 0s
  void RemoveZero() {
    std::reverse(this->mag.begin(), this->mag.end());
    auto ptr = this->mag.begin();
    while (*ptr == 0 && ptr != this->mag.end()) ++ptr;
    this->mag = std::vector<unsigned int>(ptr, this->mag.end());
    if (this->mag.size() == 0) {
      this->signum = 0;
    } else {
      std::reverse(this->mag.begin(), this->mag.end());
    }
  }

  int compareMagnitude(const BigInteger &val) const {
    std::vector<unsigned int> m1 = this->mag, m2 = val.mag;
    int len1 = m1.size(), len2 = m2.size();
    if (len1 < len2) return -1;
    if (len1 > len2) return 1;
    for (int i = len1 - 1, a, b; ~i; --i) {
      a = m1[i], b = m2[i];
      if (a != b) return (a < b ? -1 : 1);
    }
    return 0;
  }

 public:
  // Constructors
  BigInteger();
  BigInteger(const char &);
  BigInteger(const unsigned char &);
  BigInteger(const short &);
  BigInteger(const unsigned short &);
  BigInteger(const int &);
  BigInteger(const unsigned int &);
  BigInteger(const long &);
  BigInteger(const unsigned long &);
  BigInteger(const long long &);
  BigInteger(const unsigned long long &);
  BigInteger(const float &);
  BigInteger(const double &);
  BigInteger(const long double &);
  BigInteger(const char *);
  BigInteger(const std::string &);
  ~BigInteger();

  // Arithmetic operators
  BigInteger operator+(const BigInteger &) const;
  BigInteger operator-(const BigInteger &) const;
  BigInteger operator*(const BigInteger &) const;
  BigInteger operator/(const BigInteger &) const;
  BigInteger operator%(const BigInteger &) const;
  BigInteger operator+() const;
  BigInteger operator-() const;

  // Compound assignment
  BigInteger &operator+=(const BigInteger &);
  BigInteger &operator-=(const BigInteger &);
  BigInteger &operator*=(const BigInteger &);
  BigInteger &operator/=(const BigInteger &);
  BigInteger &operator%=(const BigInteger &);

  // Increment and decrement
  BigInteger operator++();
  BigInteger operator++(int);
  BigInteger operator--();
  BigInteger operator--(int);

  // Relational and comparison operators
  bool operator==(const BigInteger &) const;
  bool operator!=(const BigInteger &) const;
  bool operator>(const BigInteger &) const;
  bool operator<(const BigInteger &) const;
  bool operator>=(const BigInteger &) const;
  bool operator<=(const BigInteger &) const;

  // Istream and ostream
  friend std::istream &operator>>(std::istream &, BigInteger &);
  friend std::ostream &operator<<(std::ostream &, const BigInteger &);
};

BigInteger abs(const BigInteger &);
