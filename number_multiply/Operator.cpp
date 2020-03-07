//
// Created by yhzhan on 3/7/2020.
//

#include "Number.h"
#include "Operator.h"

#include <algorithm>
#include <iostream>
#include <sstream>

Number basic::operator*(const Number &num1, const Number &num2)
{
    if (num1.isZero() || num2.isZero()) { return Number::Zero; }
    const auto &numUp = num1;
    const auto &numDown = num2;
    std::vector<std::vector<Digit>> intermediate;
    for (int j = numDown.size()-1; j >= 0; --j) {
        Digit carryOver(Digit::Zero);
        std::vector<Digit> result;
        for (int i = numUp.size()-1; i >= 0; --i) {
            Number tmp = (numDown[j] * numUp[i]) + carryOver;
            if (i > 0) {
                result.push_back(tmp.getUnit());
                carryOver = tmp.getTens();
            } else {
                result.push_back(tmp.getUnit());
                if (tmp.getTens() != Digit::Zero) {
                    result.push_back(tmp.getTens());
                }
            }
        }
        intermediate.push_back(result);
    }

    int arraySize = intermediate.size();
    // current idx and array size
    std::vector<std::pair<int,int>> idxArray;
    //std::cout << std::endl;
    //std::cout << "in1: " << std::to_string(numUp) << std::endl;
    //std::cout << "in2: " << std::to_string(numDown) << std::endl;
    //std::cout << "intersize: " << arraySize << std::endl;
    for (int i = 0; i < arraySize; ++i) {
        idxArray.emplace_back(-i, intermediate[i].size());
        /*
        auto tmp = intermediate[i];
        std::ostringstream oss;
        oss << std::string(i, ' ') << std::to_string(tmp);
        std::string out = oss.str();
        std::cout << "pre-rev [" << out << "]" << std::endl;
        std::reverse(out.begin(), out.end());
        std::cout << "reverse [" << out << "]" << std::endl;
         */
    }
    // std::cout << "staring to sum up ..." << std::endl;
    std::vector<Digit> ret;
    int round = 0;
    int carryOver = 0;
    while (true) {
        ++round;
        // std::cout << "Round [" << round << "]" << std::endl;
        int temp = 0;
        bool end = true;
        // std::cout << "temp [" << temp << "]";
        for (int j = 0; j < arraySize; ++j) {
            if (idxArray[j].first < 0) {
                ++(idxArray[j].first);
                end = false;
            } else if (idxArray[j].first < idxArray[j].second) {
                temp += intermediate[j][idxArray[j].first].value();
                // std::cout << "[" << temp << "]";
                ++(idxArray[j].first);
                end = false;
            } else {
            }
        }
        // std::cout << std::endl;
        if (!end) {
            temp += carryOver;
            ret.emplace_back(temp%10);
            carryOver = temp / 10;
            // std::cout << "Get carryOver [" << carryOver << "] unit [" << temp%10 << "]" << std::endl;
        } else {
            if (carryOver != 0) {
                int tmpCarryOver = carryOver;
                while (true) {
                   int div = tmpCarryOver/10;
                   int mod = tmpCarryOver%10;
                   if (div == 0 && mod != 0) {
                       ret.emplace_back(mod);
                       // std::cout << "!Get carryOver [" << 0 << "] unit [" << mod << "]" << std::endl;
                       break;
                   } else if (div != 0) {
                       ret.emplace_back(mod);
                       tmpCarryOver = div;
                       // std::cout << "!Get carryOver [" << tmpCarryOver << "] unit [" << mod << "]" << std::endl;
                   } else {
                       break;
                   }
                }
            }
            break;
        }
    }
    std::reverse(ret.begin(), ret.end());
    return Number(ret);
}

Number fast::operator*(const Number &num1, const Number &num)
{
    if (num1.isZero() || num.isZero()) { return Number::Zero; }
    if (num1.isSingleDigit() && num.isSingleDigit()) {
        Number result = num1.getUnit() * num.getUnit();
        if (result.getTens() == Digit::Zero) {
            return Number{result.getUnit()};
        } else {
            return Number{result.getTens(), result.getUnit()};
        }
    }
    auto num1Size = num1.size();
    auto sizeA = num1Size / 2;
    auto sizeB = num1Size - sizeA;
    auto A = (sizeA == 0 ? Number::Zero : num1.sliceFromBeginToMid(sizeA));
    auto B = (sizeB == 0 ? Number::Zero : num1.sliceFromMidToEnd(sizeA));
    auto num2Size = num.size();
    auto sizeC = num2Size / 2;
    auto sizeD = num2Size - sizeC;
    auto C = (sizeC == 0 ? Number::Zero : num.sliceFromBeginToMid(sizeC));
    auto D = (sizeD == 0 ? Number::Zero : num.sliceFromMidToEnd(sizeC));

    auto part1 = (A*C).pad_with_zeros(sizeB+sizeD);
    auto part2 = (A*D).pad_with_zeros(sizeB);
    auto part3 = (B*C).pad_with_zeros(sizeD);
    auto part4 = B*D;
    // std::cout << "part1 [" << part1 << "] part2 [" << part2 << "] part3 [" << part3 << "] part4 [" << part4 << "]" << std::endl;
    return part1+part2+part3+part4;
}
