#include "../include/big_int.h"

std::vector<std::string> toBin(BigInt &number)
{
    std::vector<std::string> output;
    std::string result = "";

    while (number > BigInt(0))
    {
        BigInt a = number % BigInt(2);
        result += (number % BigInt(2)).operator std::string();
        number /= BigInt(2);
    }

    if (result.length() % BIT_SIZE != 0)
    {
        int countExtraZeros = BIT_SIZE - result.length() % BIT_SIZE;

        for (int i = 0; i < countExtraZeros; i++)
        {
            result += "0";
        }
    }

    reverse(result.begin(), result.end());

    for (int i = 0; i < result.length() / BIT_SIZE; i++)
    {
        output.push_back(result.substr(BIT_SIZE * i, BIT_SIZE));
    }

    return output;
}

BigInt toDec(std::vector<std::string> &number)
{
    int currentFactor = 1;
    BigInt result = 0;

    for (int i = number.size() - 1; i >= 0; i--)
    {
        for (int j = BIT_SIZE - 1; j >= 0; j--)
        {
            result += BigInt((number[i][j] - '0') * currentFactor);
            currentFactor *= BASE;
        }
    }

    return result;
}

BigInt operatorNot(BigInt &number)
{
    std::vector<std::string> strDigit = toBin(number);
    std::vector<std::string> partDigit;

    for (int i = 0; i < strDigit.size(); i++)
    {
        std::string temp = "";

        for (int j = 0; j < BIT_SIZE; j++)
        {
            strDigit[i][j] == '1' ? temp += "0" : temp += '1';
        }

        partDigit.push_back(temp);
    }

    return toDec(partDigit);
}

BigInt operatorAnd(BigInt &numberA, BigInt &numberB)
{
    std::vector<std::string> strNumberA = toBin(numberA);
    std::vector<std::string> strNumberB = toBin(numberB);
    std::vector<std::string> result;

    int minSize = min(strNumberA.size(), strNumberB.size());
    int indexA = 0;
    int indexB = 0;

    if (strNumberA.size() != minSize)
    {
        indexA = strNumberA.size() - minSize;
    }
    else
    {
        indexB = strNumberB.size() - minSize;
    }

    for (int i = 0; i < minSize; i++)
    {
        std::string temp = "";
        for (int j = 0; j < BIT_SIZE; j++)
        {
            if (strNumberA[indexA][j] != strNumberB[indexB][j])
            {
                temp += "0";
            }

            else if (strNumberA[indexA][j] == '1')
            {
                temp += "1";
            }

            else
            {
                temp += "0";
            }
        }

        indexA++;
        indexB++;

        result.push_back(temp);
    }

    return toDec(result);
}

void AddExtraZerosPart(std::vector<std::string> &result, int count)
{
    reverse(result.begin(), result.end());

    for (int i = 0; i < count; i++)
    {
        result.push_back(NEUTRAL_ELEMENT);
    }
}

BigInt operatorOr(BigInt &numberA, BigInt &numberB)
{
    std::vector<std::string> strNumberA = toBin(numberA);
    std::vector<std::string> strNumberB = toBin(numberB);
    std::vector<std::string> result;

    int maxSize = max(strNumberA.size(), strNumberB.size());
    int indexA = 0;
    int indexB = 0;

    if (strNumberA.size() != maxSize)
    {
        int count = maxSize - strNumberA.size();
        AddExtraZerosPart(strNumberA, count);
    }
    else
    {
        int count = maxSize - strNumberB.size();
        AddExtraZerosPart(strNumberB, count);
    }

    for (int i = 0; i < maxSize; i++)
    {
        std::string temp = "";
        for (int j = 0; j < BIT_SIZE; j++)
        {
            if (strNumberA[indexA][j] != strNumberB[indexB][j])
                temp += "1";

            else if (strNumberA[indexA][j] == '0')
                temp += "0";

            else
                temp += "1";
        }

        indexA++;
        indexB++;

        result.push_back(temp);
    }

    return toDec(result);
}

int ReverseNumber(int number)
{
    int temp;
    int answer = 0;

    while (number != 0)
    {
        temp = number % 10;
        answer = answer * 10 + temp;
        number /= 10;
    }

    return answer;
}

bool isDigit(std::string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] > '9' || str[i] < '0')
        {
            return false;
        }
    }

    return true;
}

BigInt ::BigInt()
{
    this->sign = PLUS;
}

BigInt ::BigInt(int number)
{
    this->SetSign(number);

    number = abs(number);

    if (number == 0)
    {
        digits.push_back(number);
    }

    while (number > 0)
    {
        digits.push_back(number % MAX_NUMBER);
        number /= MAX_NUMBER;
    }
}

BigInt ::BigInt(std::string str)
{
    this->sign = PLUS;

    if (str[0] == '-')
    {
        this->sign = MINUS;
        str.erase(0, 1);
    }

    if (!isDigit(str))
    {
        throw std::logic_error("invalid_argument");
    }

    reverse(str.begin(), str.end());

    int size = (str.size() + MAX_NUMBER_LENGTH - 1) / MAX_NUMBER_LENGTH;

    for (int i = 0; i < size; i++)
    {
        std::string temp = str.substr(0, min(MAX_NUMBER_LENGTH, str.size()));
        reverse(temp.begin(), temp.end());
        digits.push_back(std::stoi(temp));
        str.erase(0, min(9, str.size()));
    }
}

BigInt::BigInt(const BigInt &other)
{
    this->digits = other.digits;
    this->sign = other.sign;
}

std::vector<int> BigInt ::GetNumber()
{
    return this->digits;
}

void BigInt::SetNumber(int number)
{
    BigInt tmp(number);
    this->digits = tmp.digits;
    this->sign = tmp.sign;
}

void BigInt::SetNumber(std::string str)
{
    BigInt tmp(str);
    this->digits = tmp.digits;
    this->sign = tmp.sign;
}

void BigInt::SetNumber(std::vector<int> digits)
{
    this->digits = digits;
}

void BigInt ::SetSign(int number)
{
    if (number >= 0)
    {
        this->sign = BigInt::PLUS;
    }

    else
    {
        this->sign = BigInt::MINUS;
    }
}

bool BigInt ::GetSign()
{
    return this->sign;
}

BigInt &BigInt::operator+=(const BigInt &other)
{
    if (!this->sign && other.sign)
    {
        BigInt temp = other;
        temp.sign = PLUS;

        *this -= temp;
        return *this;
    }

    if (this->sign && !other.sign)
    {
        BigInt temp = *this;
        temp.sign = PLUS;

        BigInt temp2 = other;
        temp2 -= temp;

        *this = temp2;
        return *this;
    }

    std::vector<int> firstDigit = this->digits;
    std::vector<int> secondDigit = other.digits;

    std::vector<int> result;

    bool carry = false;

    for (int i = 0; i < min(firstDigit.size(), secondDigit.size()); i++)
    {
        if (carry)
        {
            firstDigit[i] += 1;
            carry = false;
        }

        int temp = firstDigit[i] + secondDigit[i];
        result.push_back(temp % MAX_NUMBER);

        if (temp >= MAX_NUMBER)
        {
            carry = true;
        }
    }

    BigInt maxBigInt;
    if (*this > other)
    {
        maxBigInt = *this;
    }
    else
    {
        maxBigInt = other;
    }

    for (int i = min(firstDigit.size(), secondDigit.size()); i < max(firstDigit.size(), secondDigit.size()); i++)
    {
        if (carry)
        {
            maxBigInt.digits[i] += 1;

            if (maxBigInt.digits[i] < MAX_NUMBER)
            {
                carry = false;
            }
        }

        result.push_back(maxBigInt.digits[i] % MAX_NUMBER);
    }

    this->digits = result;
    return *this;
}

BigInt &BigInt::operator-=(const BigInt &other)
{
    if (!this->sign && other.sign)
    {
        BigInt temp = other;
        temp.sign = PLUS;

        *this += temp;
        return *this;
    }

    if (this->sign && !other.sign)
    {
        BigInt temp = other;
        temp.sign = MINUS;

        *this += temp;
        return *this;
    }

    std::vector<int> reduced = this->digits;
    std::vector<int> subtracted = other.digits;
    std::vector<int> result;

    if (*this < other)
    {
        this->sign = MINUS;
        reduced = other.digits;
        subtracted = this->digits;
    }

    bool carry = false;
    for (int i = 0; i < subtracted.size(); i++)
    {
        if (carry)
        {
            reduced[i] -= 1;
            carry = false;
        }

        if (reduced[i] < subtracted[i])
        {
            carry = true;
            reduced[i] += MAX_NUMBER;
        }

        result.push_back(reduced[i] - subtracted[i]);
    }

    for (int i = subtracted.size(); i < reduced.size(); i++)
    {
        if (carry)
        {
            if ((i == reduced.size() - 1) && reduced[i] == 1)
                break;

            if (reduced[i] > 0)
            {
                reduced[i] -= 1;
                carry = false;
            }
            else
            {
                reduced[i] = MAX_NUMBER - 1;
            }
        }

        result.push_back(reduced[i]);
    }

    this->digits = result;
    return *this;
}

void AddExtraZeros(std::string &number, int n)
{
    for (int i = 0; i < n; i++)
    {
        number += "0";
    }
}

int GetFactorValue(int index, std::string strDigit)
{
    std::reverse(strDigit.begin(), strDigit.end());
    AddExtraZeros(strDigit, BigInt::MAX_NUMBER_LENGTH - strDigit.length());
    std::reverse(strDigit.begin(), strDigit.end());

    return strDigit[index] - '0';
}

void DeleteExtraZeros(BigInt &result)
{
    std::string temp = result.operator std::string();
    if (result != BigInt(0))
    {
        while (temp[0] == '0')
        {
            temp.erase(0, 1);
        }
    }

    result.SetNumber(temp);
}

BigInt &BigInt::operator*=(const BigInt &other)
{
    BigInt result(0);
    int realIndex = -1;

    for (int i = 0; i < other.digits.size(); i++)
    {
        for (int j = BigInt::MAX_NUMBER_LENGTH - 1; j >= 0; j--)
        {
            if (i == other.digits.size() - 1)
            {
                if (BigInt::MAX_NUMBER_LENGTH - (std::to_string(other.digits[i])).length() - 1 == j)
                {
                    break;
                }
            }

            int factor = GetFactorValue(j, std::to_string(other.digits[i]));
            int carry = 0;
            realIndex++;

            std::string temp = "";

            for (int part = 0; part < this->digits.size(); part++)
            {
                std::string currentDigit = std::to_string(this->digits[part]);
                for (int index = BigInt::MAX_NUMBER_LENGTH - 1; index >= 0; index--)
                {
                    int factor2 = GetFactorValue(index, currentDigit);
                    temp += std::to_string((factor * factor2 + carry) % 10);
                    carry = (factor * factor2 + carry) / 10;
                }
            }

            if (carry != 0)
            {
                temp += std::to_string(carry);
            }

            std::reverse(temp.begin(), temp.end());
            AddExtraZeros(temp, realIndex);
            result += BigInt(temp);
        }
    }

    DeleteExtraZeros(result);

    if (this->sign != other.sign)
    {
        result.SetSign(-1);
    }

    else
    {
        result.SetSign(PLUS);
    }

    *this = result;
    return *this;
}

BigInt &BigInt::operator^=(const BigInt &other)
{
    BigInt thisCopy = *this;
    BigInt result = *this;

    for (BigInt temp = other - BigInt(1); temp > BigInt(0); temp--)
    {
        result *= thisCopy;
    }

    *this = result;
    return *this;
}

int GetFactor(BigInt first, BigInt second)
{
    int factor = 0;

    for (int i = 1; i <= 10; i++)
    {
        BigInt subtractible = BigInt(second * BigInt(i));
        if (subtractible > first)
        {
            break;
        }

        factor = i;
    }

    return factor;
}

BigInt &BigInt::operator/=(const BigInt &other)
{
    if (other == BigInt(0))
        throw std::logic_error("division by zero");

    std::string firstDigit = this->operator std::string();
    std::string secondDigit = other.operator std::string();
    std::string result = "";

    BigInt divider = other;
    BigInt divisible = *this;
    divisible.SetSign(PLUS);

    if (divisible < divider)
    {
        this->SetNumber(0);
        return *this;
    }

    divider.SetSign(1);

    BigInt currentDecreasing = BigInt(firstDigit.substr(0, secondDigit.length()));

    int factor = 0;
    int index = 0;
    while (secondDigit.length() + index <= firstDigit.length())
    {
        if (divider > currentDecreasing)
        {
            if (index != 0)
            {
                result += "0";
            }

            std::string str1(1, firstDigit[secondDigit.length() + index]);

            currentDecreasing = currentDecreasing * BigInt(10) + BigInt(str1);
            index++;
        }

        factor = GetFactor(currentDecreasing, divider);
        result += std::to_string(factor);

        if (secondDigit.length() + index >= firstDigit.length())
        {
            break;
        }

        std::string str(1, firstDigit[secondDigit.length() + index]);

        if (isDigit(str))
        {
            currentDecreasing = (currentDecreasing - divider * BigInt(factor)) * BigInt(10) + BigInt(str);
        }

        index++;
    }

    bool firstSign = this->sign;
    this->SetNumber(result);

    if (firstSign != other.sign)
    {
        this->SetSign(-1);
    }

    else
    {
        this->SetSign(PLUS);
    }

    return *this;
}

BigInt &BigInt::operator%=(const BigInt &other)
{
    if (*this < other)
    {
        return *this;
    }

    BigInt temp = (*this) / other;
    BigInt result = (*this) - other * temp;

    this->SetNumber(result.digits);
    return *this;
}

BigInt &BigInt::operator&=(const BigInt &other)
{
    BigInt numberA = *this;
    BigInt numberB = other;

    BigInt temp = operatorAnd(numberA, numberB);

    this->digits = temp.digits;

    return *this;
}

BigInt &BigInt::operator|=(const BigInt &other)
{
    BigInt numberA = *this;
    BigInt numberB = other;

    BigInt temp = operatorOr(numberA, numberB);

    this->digits = temp.digits;
    return *this;
}

BigInt operator+(const BigInt &first, const BigInt &second)
{
    BigInt temp = first;
    temp += second;
    return temp;
}

BigInt operator-(const BigInt &first, const BigInt &second)
{
    BigInt temp = first;
    temp -= second;
    return temp;
}

BigInt operator*(const BigInt &first, const BigInt &second)
{
    BigInt temp = first;
    temp *= second;
    return temp;
}

BigInt operator^(const BigInt &first, const BigInt &second)
{
    BigInt temp = first;
    temp ^= second;
    return temp;
}

BigInt operator/(const BigInt &first, const BigInt &second)
{
    BigInt temp = first;
    temp /= second;
    return temp;
}

BigInt operator%(const BigInt &first, const BigInt &second)
{
    BigInt temp = first;
    temp %= second;
    return temp;
}

BigInt operator&(const BigInt &first, const BigInt &second)
{
    BigInt numberA = first;
    BigInt numberB = second;

    BigInt temp = operatorAnd(numberA, numberB);

    return temp;
}

BigInt operator|(const BigInt &first, const BigInt &second)
{
    BigInt numberA = first;
    BigInt numberB = second;

    BigInt temp = operatorOr(numberA, numberB);

    return temp;
}

bool BigInt::operator==(const BigInt &other) const
{
    if (this->sign == other.sign)
    {
        return this->digits == other.digits;
    }

    return false;
}

bool BigInt::operator!=(const BigInt &other) const
{
    return !(*this == other);
}

bool BigInt::operator<(const BigInt &other) const
{
    if (*this == other)
        return false;

    if (this->sign != other.sign)
    {
        return this->sign == MINUS;
    }

    return (this->digits == min(this->digits, other.digits) && this->sign == PLUS);
}

bool BigInt::operator>(const BigInt &other) const
{
    return (other < *this && *this != other);
}

bool BigInt::operator<=(const BigInt &other) const
{
    return *this < other || *this == other;
}

bool BigInt::operator>=(const BigInt &other) const
{
    return *this > other || *this == other;
}

BigInt &BigInt::operator++()
{
    *this += 1;
    return *this;
}

BigInt &BigInt::operator--()
{
    *this -= 1;
    return *this;
}

BigInt BigInt::operator++(int)
{
    BigInt temp = *this;
    ++(*this);
    return temp;
}

BigInt BigInt::operator--(int)
{
    BigInt temp = *this;
    --(*this);
    return temp;
}

std::string PrintPartNumber(int number)
{
    std::string result = "";
    if (number >= BigInt::MAX_NUMBER / 10)
    {
        result += std::to_string(number);
    }

    else
    {
        int countExtraZeros = BigInt::MAX_NUMBER_LENGTH - (std::to_string(number)).size();
        for (int i = 0; i < countExtraZeros; i++)
        {
            result += "0";
        }

        result += std::to_string(number);
    }

    return result;
}

BigInt::operator std::string() const
{
    std::string result = "";

    for (int i = this->digits.size() - 1; i >= 0; i--)
    {
        if (i == this->digits.size() - 1)
        {
            result += std::to_string(this->digits[i]);
        }
        else
        {
            result += PrintPartNumber(this->digits[i]);
        }
    }

    return result;
}

std::string BigInt::GetString() const
{
    std::string result = "";

    if (this->sign == MINUS)
    {
        result += '-';
    }

    result += this->operator std::string();
    return result;
}

BigInt BigInt::operator~() const
{
    BigInt thisCopy = *this;
    BigInt temp = operatorNot(thisCopy);

    if (this->sign != MINUS)
    {
        temp.SetSign(-1);
    }

    else
    {
        temp.SetSign(PLUS);
    }

    return temp;
}

std::ostream &operator<<(std::ostream &out, const BigInt &i)
{
    BigInt temp = i;
    if (temp.GetSign() == 1)
    {
        out << "-";
    }

    DeleteExtraZeros(temp);

    std::string result = temp.operator std::string();
    out << result;

    return out;
}

BigInt BigInt::operator+() const
{
    return *this;
}

BigInt BigInt::operator-()
{
    BigInt temp = *this;
    this->sign = !this->sign;
    return temp;
}

BigInt::operator int() const
{
    if (*this < BigInt(INT_MIN) || *this > BigInt(INT_MAX))
    {
        throw std::logic_error("not integer");
    }

    else
    {
        return std::stoi(this->GetString());
    }
}

size_t BigInt::size() const
{
    return sizeof(*this);
}