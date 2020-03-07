//
// Created by yhzhan on 3/2/2020.
//

#include "Number.h"
#include "common.h"

#include <algorithm>
#include <iostream>
#include <sstream>

Digit Digit::Zero = Digit(0);

std::string std::to_string(const Digit &value)
{
    return std::to_string(value.value());
}

std::ostream &operator<<(std::ostream &os, const Digit &digit)
{
    os << std::to_string(digit);
    return os;
}

std::string std::to_string(const vector<Digit> &value)
{
    ostringstream oss;
    for (auto e : value) {
        oss << std::to_string(e);
    }
    return oss.str();
}

std::ostream &operator<<(std::ostream &os, const std::vector<Digit> &digits)
{
    os << std::to_string(digits);
    return os;
}

std::vector<Digit> std::to_digit_vector(const std::string &str)
{
    std::vector<Digit> ret;
    for (auto e : str) {
        ret.emplace_back(std::string(1,e));
    }
    return ret;
}

Number operator+(const Digit &digit1, const Digit &digit2)
{
    return Number(std::to_string(digit1.value() + digit2.value()));
}

Number operator*(const Digit &digit1, const Digit &digit2)
{
    auto ret = Number(std::to_string(digit1.value() * digit2.value()));
    // std::cout << "[" << digit1 << "] * [" << digit2 << "] => [" << ret << "]" << std::endl;
    return ret;
}

Number::Number(const std::string &num) : Number(std::to_digit_vector(num)){ }
Number::Number(const std::vector<Digit> &num) {
    if (num.empty()) { return; }
    if (num == std::vector<Digit>{{Digit(0)}}) { return; }
    if (num[0] == Digit::Zero) {
        bool inLeadingZeros = true;
        for (auto e : num) {
            if (inLeadingZeros && e == Digit::Zero) {
                continue;
            }
            inLeadingZeros = false;
            m_num.push_back(e);
        }
    } else {
        m_num = num;
    }
}

bool Number::operator==(const Number &other) const
{
    if (this == &other) {
            return true;
        }
        return this->m_num == other.m_num;
    }

    Number Number::operator+(const Number &num) const
    {
        const auto &num1 = m_num;
        const auto &num2 = num.m_num;
        if (num1.empty()) { return Number(num2); }
        if (num2.empty()) { return Number(num1); }
        auto it1 = num1.rbegin();
        auto it2 = num2.rbegin();
        Digit carryOver(Digit::Zero);
        std::vector<Digit> ret;
        while (true) {
            if (it1 == num1.rend() && it2 == num2.rend()) {
                if (carryOver != Digit::Zero) {
                    ret.push_back(carryOver);
                }
                break;
            }
            Digit val1 = Digit::Zero;
            Digit val2 = Digit::Zero;
            if (it1 != num1.rend()) {
                val1 = *it1;
                ++it1;
            }
            if (it2 != num2.rend()) {
                val2 = *it2;
                ++it2;
            }
            Number sum = val1 + val2 + carryOver;
            ret.push_back(sum.getUnit());
            carryOver = sum.getTens();
        }
        std::reverse(ret.begin(), ret.end());
        return Number(ret);
    }

Number Number::operator+(const Digit &digit)
{
    return (*this + Number(digit));
}

Number &Number::operator+=(const Digit &digit)
{
    std::cout << "[" << *this << "] + [" << digit << "] ";
    *this = (*this + Number(digit));
    std::cout << " => [" << *this << "]" << std::endl;
    return *this;
}

    const Number &Number::pad_with_zeros(int zeros) {
    if (m_num.empty() || zeros <= 0) { return *this; }
        for (auto i = 0; i < zeros; ++i) {
            m_num.push_back(Digit::Zero);
        }
        return *this;
    }

    Number Number::Zero = Number();

std::string std::to_string(const Number &num)
{
    return std::to_string(num.value());
}
std::ostream &operator<<(std::ostream &os, const Number &num) {
    os << std::to_string(num);
    return os;
}
