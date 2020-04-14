//
// Created by yhzhan on 4/12/2020.
//

#ifndef ASSIGNMENTS_BACKSPACE_PROCESS_H
#define ASSIGNMENTS_BACKSPACE_PROCESS_H

#include <string>

namespace backspace_process {
// Leetcode
/*
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.
Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters anu '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?
*/

    class Solution {
    private:
        std::string::iterator process(std::string &S) {
            auto it = S.begin();
            auto itHead = it;
            while (it != S.end()) {
                while (it != S.end() && *it == '#') {
                    if (itHead != S.begin()) {
                        --itHead;
                    }
                    ++it;
                }
                if (it == S.end()) {
                    break;
                }
                *itHead = *it;
                ++it;
                ++itHead;
            }
            return itHead;
        }
    public:
        bool backspaceCompare(std::string S, std::string T) {
            auto itHeadS = process(S);
            auto itHeadT = process(T);
            auto itS = S.begin();
            auto itT = T.begin();
            while (itS != itHeadS || itT != itHeadT) {
                if (itS == itHeadS && itT != itHeadT
                    || itS != itHeadS && itT == itHeadT) {
                    return false;
                }
                if (*itS != *itT) {
                    return false;
                }
                ++itS;
                ++itT;
            }
            return true;
        }
    };
}


#endif //ASSIGNMENTS_BACKSPACE_PROCESS_H
