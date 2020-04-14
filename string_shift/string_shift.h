//
// Created by yhzhan on 4/14/2020.
//

#ifndef ASSIGNMENTS_STRING_SHIFT_H
#define ASSIGNMENTS_STRING_SHIFT_H

#include <list>
#include <string>
#include <vector>
#include <iostream>

namespace string_shift {
    class Solution {
    public:
        std::string stringShift(const std::string s, const std::vector<std::vector<int>>& shift) {
            std::list<char> charList;
            std::copy(s.begin(), s.end(), std::back_inserter(charList));
            for (const auto &cmd : shift) {
                int direction = cmd[0];
                int step = cmd[1];
                if (direction == 0) {
                    for (int i = 0; i < step; ++i) {
                        auto front = charList.front();
                        charList.pop_front();
                        charList.push_back(front);
                    }
                } else if (direction == 1) {
                    for (int i = 0; i < step; ++i) {
                        auto back = charList.back();
                        charList.pop_back();
                        charList.push_front(back);
                    }
                } else if (direction == 1) {
                } else {
                    abort();
                }
            }
            return std::string(charList.begin(), charList.end());
        }
    };
}
#endif //ASSIGNMENTS_STRING_SHIFT_H
