#pragma once
#ifndef BIG_INT_H
#define BIG_INT_H

#include <iostream>
#include <string>
#include <algorithm>
#include <exception>
#include <cmath>
#include <vector>
#include <climits>
#include "comparison.h"

#define BIT_SIZE 8
#define BASE 2
#define NEUTRAL_ELEMENT "00000000"

class BigInt
{
public:
    static const int MAX_NUMBER = 1000000000;
    static const int MAX_NUMBER_LENGTH = 9;
    static const bool MINUS = true;
    static const bool PLUS = false;

    BigInt();
    BigInt(int number);
    BigInt(std::string str);

    BigInt(const BigInt &other);

    std::vector<int> GetNumber();
    void SetNumber(int number);
    void SetNumber(std::string str);
    void SetNumber(std::vector<int> digits);
    bool GetSign();
    void SetSign(int number);

    bool operator==(const BigInt &) const;
    bool operator!=(const BigInt &) const;
    bool operator<(const BigInt &) const;
    bool operator>(const BigInt &) const;
    bool operator<=(const BigInt &) const;
    bool operator>=(const BigInt &) const;

    BigInt &operator++();
    BigInt &operator--();
    BigInt operator++(int);
    BigInt operator--(int);

    operator std::string() const;
    std::string GetString() const;

    BigInt &operator+=(const BigInt &);
    BigInt &operator-=(const BigInt &);
    BigInt &operator*=(const BigInt &);
    BigInt &operator^=(const BigInt &);
    BigInt &operator/=(const BigInt &);
    BigInt &operator%=(const BigInt &);
    BigInt &operator&=(const BigInt &);
    BigInt &operator|=(const BigInt &);

    BigInt operator~() const;

    BigInt operator+() const; // unary +
    BigInt operator-();

    operator int() const;

    size_t size() const;

private:
    std::vector<int> digits;
    bool sign;
};

BigInt operator+(const BigInt &, const BigInt &);
BigInt operator-(const BigInt &, const BigInt &);
BigInt operator*(const BigInt &, const BigInt &);
BigInt operator^(const BigInt &, const BigInt &);
BigInt operator/(const BigInt &, const BigInt &);
BigInt operator%(const BigInt &, const BigInt &);
BigInt operator&(const BigInt &, const BigInt &);
BigInt operator|(const BigInt &, const BigInt &);

std::ostream &operator<<(std::ostream &out, const BigInt &i);

#endif