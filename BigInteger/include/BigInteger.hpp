#ifndef SIFR_BIGINTEGER
#define SIFR_BIGINTEGER

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

#endif