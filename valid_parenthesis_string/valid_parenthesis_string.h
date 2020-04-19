//
// Created by yhzhan on 4/16/2020.
//

#ifndef ASSIGNMENTS_VALID_PARENTHESIS_STRING_H
#define ASSIGNMENTS_VALID_PARENTHESIS_STRING_H

#include <string>
#include <vector>

namespace valid_parenthesis_string {
    class Solution {
    public:
        bool checkValidString(const std::string &s) {
            if (s.empty()) { return true; }
            int weight = 0;
            int asterisk = 0;
            for (const auto &e : s) {
                if (e == '(') {
                    ++weight;
                } else if (e == ')') {
                    if (weight == 0 && asterisk == 0) {
                        return false;
                    } else {
                        --weight;
                    }
                } else if (e == '*') {
                    ++asterisk;
                } else {
                    abort();
                }
            }
            if (weight == 0) {
                return true;
            } else {
                return std::abs(weight) <= asterisk;
            }
        }
    };
}
#endif //ASSIGNMENTS_VALID_PARENTHESIS_STRING_H
