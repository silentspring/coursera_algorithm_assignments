//
// Created by yhzhan on 4/20/2020.
//

#ifndef ASSIGNMENTS_SEARCH_IN_ROTATED_SORTED_ARRAY_H
#define ASSIGNMENTS_SEARCH_IN_ROTATED_SORTED_ARRAY_H

#include <vector>
#include <stdlib.h>

/*
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
 */
namespace search_in_rotated_sorted_array {
    class Solution {
        enum class CliffOn { Left, Right };
    public:
        int findCliff(const std::vector<int> &nums) {
            if (nums.empty()) { return -1; }
            if (nums.size() < 2) { return -1; }
            return findCliff(nums, 0, nums.size()-1);
        }
        int findCliff(const std::vector<int> &nums, int begin, int end) {
            if (begin == end) { return -1; }
            if (end-begin == 1) {
                if (nums[begin] < nums[end]) {
                    return -1;
                } else if (nums[begin] > nums[end]) {
                    return begin;
                }
            }
            if (begin > end) {
                abort();
            }
            CliffOn cliffOn;
            int mid = (begin+end)/2;
            if (nums[mid] < nums[end]) {
                cliffOn = CliffOn::Left;
            } else if (nums[end] < nums[mid]) {
                cliffOn = CliffOn::Right;
            } else {
                abort();
            }

            if (cliffOn == CliffOn::Left) {
                return findCliff(nums, begin, mid);
            } else {
                return findCliff(nums, mid, end);
            }
        }
        int findIndex(const std::vector<int> &nums, int target) {
            if (nums.empty()) { return -1; }
            return findIndex(nums, 0, nums.size()-1, target);
        }
        int findIndex(const std::vector<int> &nums, int begin, int end, int target) {
            if (begin == end) {
                if (nums[begin] == target) {
                    return begin;
                } else {
                    return -1;
                }
            }
            if (begin > end) {
                return -1;
            }
            int mid = (begin + end) /2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                return findIndex(nums, mid+1, end, target);
            } else {
                return findIndex(nums, begin, mid-1, target);
            }
        }
    public:
        int search(const std::vector<int>& nums, int target) {
            if (nums.empty()) { return -1; }
            size_t sz = nums.size();
            int cliff = findCliff(nums, 0, sz-1);
            if (cliff == -1) {
                return findIndex(nums, 0, sz - 1, target);
            } else {
                if (target == nums[sz - 1]) {
                    return sz - 1;
                }
                if (target == nums[0]) {
                    return 0;
                }
                if (target < nums[0]) {
                    return findIndex(nums, cliff + 1, sz - 1, target);
                } else if (target > nums[sz - 1]) {
                    return findIndex(nums, 0, cliff, target);
                } else {
                    abort();
                }
            }
        }
    };
}
#endif //ASSIGNMENTS_SEARCH_IN_ROTATED_SORTED_ARRAY_H
