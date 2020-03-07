//
// Created by yhzhan on 3/2/2020.
//

#ifndef ASSIGNMENTS_NUMBER_H
#define ASSIGNMENTS_NUMBER_H

#include <string>
#include <vector>
#include <exception>
#include <stdexcept>

class Digit {
public:
    explicit Digit(const std::string &str) : m_digit(0) {
        if (str.empty() || str.size() > 1) {
            throw std::runtime_error("invalid digit " + str);
        }
        size_t sz;
        m_digit = std::stoi(str, &sz);
    }
    explicit Digit(int digit) : m_digit(digit) {
        if (m_digit > 9) {
            throw std::runtime_error("invalid digit " + std::to_string(digit));
        }
    }
    int value() const { return m_digit; }
    bool operator==(const Digit &other) const {
        if (this == &other) {
            return true;
        }
        return this->m_digit == other.m_digit;
    }
    bool operator!=(const Digit &other) const { return !(*this == other); }
private:
    int m_digit;
public:
    static Digit Zero;
};

namespace std {
    std::string to_string(const Digit &value);
    std::string to_string(const std::vector<Digit> &value);
    std::vector<Digit> to_digit_vector(const std::string &str);
}
std::ostream &operator<<(std::ostream &os, const std::vector<int> &result);
class Number {
public:
    Number() = default;
    explicit Number(Digit unit) : m_num({unit}) {
        if (unit == Digit::Zero) {
            m_num.clear();
        }
    }
    Number(const Digit &tens, const Digit &unit) {
        if (tens == Digit::Zero && unit == Digit::Zero) {
            return;
        }
        if (tens != Digit::Zero) {
            m_num.push_back(tens);
            m_num.push_back(unit);
        } else if (unit != Digit::Zero) {
            m_num.push_back(unit);
        }
    }
    explicit Number(const std::string &num);
    explicit Number(const std::vector<Digit> &num);
    std::vector<Digit> value() const { return m_num; }
    Digit getTens() const {
        int sz = m_num.size();
        return (sz >= 2 ? m_num[sz-2] : Digit::Zero);
    }
    Digit getUnit() const {
        return (!m_num.empty() ? *(m_num.end()-1) : Digit::Zero);
    }
    Digit operator[](int idx) const {return m_num[idx]; }
    bool operator==(const Number &other) const;
    Number operator+(const Number &num) const;
    Number operator+(const Digit &digit);
    Number &operator+=(const Digit &digit);
    Number sliceFromBeginToMid(int count) const {
        return Number(std::vector<Digit>(m_num.begin(), m_num.begin() + count));
    }
    Number sliceFromMidToEnd(int count) const {
        return Number(std::vector<Digit>(m_num.begin() + count, m_num.end()));
    }
    const Number &pad_with_zeros(int zeros);
    bool isZero() const { return m_num.empty(); }
    bool isSingleDigit() const { return m_num.size() == 1; }
    int size() const { return m_num.size(); }
public:
    static Number Zero;
private:
    std::vector<Digit> m_num;
};

Number operator+(const Digit &digit1, const Digit &digit2);
Number operator*(const Digit &digit1, const Digit &digit2);

namespace std {
    string to_string(const Number &num);
}
std::ostream &operator<<(std::ostream &os, const Number &num);

#endif //ASSIGNMENTS_NUMBER_H
