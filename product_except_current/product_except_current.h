//
// Created by yhzhan on 4/16/2020.
//

#ifndef ASSIGNMENTS_PRODUCT_EXCEPT_CURRENT_H
#define ASSIGNMENTS_PRODUCT_EXCEPT_CURRENT_H


#include <iostream>
#include <vector>

namespace product_except_current {
    /*
     * Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
     */
    class Solution {
    public:
        std::vector<int> productExceptSelf(const std::vector<int> &nums) {
            size_t sz = nums.size();
            std::vector<int> leftToRight(sz, 0);
            int product = 1;
            for (int i = 0; i < sz; ++i) {
                product *= nums[i];
                leftToRight[i] = product;
            }
            product = 1;
            for (int i = sz-1; i >= 0;  --i) {
                std::cout << "i [" << i << "]" << std::endl;
                if (i == sz-1) {
                    leftToRight[i] = leftToRight[i - 1];
                } else if (i == 0) {
                    leftToRight[i] = product;
                } else {
                    leftToRight[i] = leftToRight[i-1] * product;
                    std::cout << "i " << i << " leftToRight[i-i] " << leftToRight[i-i] << " * product " << product << " = " << leftToRight[i] << std::endl;
                }
                product *= nums[i];
            }
            return leftToRight;
        }
        std::vector<int> productExceptSelfBigMemory(const std::vector<int> &nums) {
            size_t sz = nums.size();
            std::vector<int> leftToRight(sz, 0);
            std::vector<int> rightToLeft(sz, 0);
            int product = 1;
            for (int i = 0; i < sz; ++i) {
                product *= nums[i];
                leftToRight[i] = product;
            }
            product = 1;
            for (int i = sz-1; i >= 0; --i) {
                product *= nums[i];
                rightToLeft[i] = product;
            }

            std::vector<int> ret(sz, 0);
            for (int i = 0; i < sz; ++i) {
                if (i == 0) {
                    ret[i] = rightToLeft[i + 1];
                } else if (i == sz-1) {
                    ret[i] = leftToRight[i - 1];
                } else {
                    ret[i] = leftToRight[i - 1] * rightToLeft[i + 1];
                }
            }
            return ret;
        }
    };
}

#endif //ASSIGNMENTS_PRODUCT_EXCEPT_CURRENT_H
