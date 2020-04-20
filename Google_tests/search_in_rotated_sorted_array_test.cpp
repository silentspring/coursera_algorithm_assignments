//
// Created by yhzhan on 4/20/2020.
//

#include "gtest/gtest.h"
#include "common.h"
#include "search_in_rotated_sorted_array.h"
#include <chrono>
#include <unistd.h>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <cmath>

using namespace search_in_rotated_sorted_array;
TEST(search_in_rotated_sorted_array, findCliff) {
    EXPECT_EQ(Solution().findCliff(std::vector<int>({})), -1);
    EXPECT_EQ(Solution().findCliff(std::vector<int>({4})), -1);
    EXPECT_EQ(Solution().findCliff(std::vector<int>({4,5})), -1);
    EXPECT_EQ(Solution().findCliff(std::vector<int>({5,4})), 0);
    EXPECT_EQ(Solution().findCliff(std::vector<int>({4,5,6})), -1);
    EXPECT_EQ(Solution().findCliff(std::vector<int>({5,4,6})), 0);
    EXPECT_EQ(Solution().findCliff(std::vector<int>({4,5,6,7,0,1,2})), 3);

    // EXPECT_EQ(Solution().search(std::vector<int>({4,5,6,7,0,1,2}), 3), -1);
    // EXPECT_EQ(Solution().search(std::vector<int>({4,5,6,7,0,1,2}), 0), 4);
    // EXPECT_EQ(Solution().search(std::vector<int>({4,5,6,7,0,1,2}), 3), -1);
}

TEST(search_in_rotated_sorted_array, findIndex) {
    EXPECT_EQ(Solution().findIndex(std::vector<int>({}), 3), -1);
    EXPECT_EQ(Solution().findIndex(std::vector<int>({1}), 3), -1);
    EXPECT_EQ(Solution().findIndex(std::vector<int>({1,2}), 3), -1);
    EXPECT_EQ(Solution().findIndex(std::vector<int>({1,2,3}), 1), 0);
    EXPECT_EQ(Solution().findIndex(std::vector<int>({1,2,3}), 2), 1);
    EXPECT_EQ(Solution().findIndex(std::vector<int>({1,2,3}), 3), 2);
    EXPECT_EQ(Solution().findIndex(std::vector<int>({1,2,3,4,5,6,7}), 1), 0);
    EXPECT_EQ(Solution().findIndex(std::vector<int>({1,2,3,4,5,6,7}), 2), 1);
    EXPECT_EQ(Solution().findIndex(std::vector<int>({1,2,3,4,5,6,7}), 3), 2);
    EXPECT_EQ(Solution().findIndex(std::vector<int>({1,2,3,4,5,6,7}), 4), 3);
    EXPECT_EQ(Solution().findIndex(std::vector<int>({1,2,3,4,5,6,7}), 5), 4);
    EXPECT_EQ(Solution().findIndex(std::vector<int>({1,2,3,4,5,6,7}), 6), 5);
    EXPECT_EQ(Solution().findIndex(std::vector<int>({1,2,3,4,5,6,7}), 7), 6);
}

TEST(search_in_rotated_sorted_array, search) {
    EXPECT_EQ(Solution().search(std::vector<int>(), 1), -1);
    EXPECT_EQ(Solution().search(std::vector<int>({4}), 1), -1);
    EXPECT_EQ(Solution().search(std::vector<int>({4}), 4), 0);
    EXPECT_EQ(Solution().search(std::vector<int>({4,5}), 4), 0);
    EXPECT_EQ(Solution().search(std::vector<int>({4,5}), 5), 1);
    EXPECT_EQ(Solution().search(std::vector<int>({4,5,6}), 4), 0);
    EXPECT_EQ(Solution().search(std::vector<int>({4,5,6}), 5), 1);
    EXPECT_EQ(Solution().search(std::vector<int>({4,5,6}), 6), 2);
    EXPECT_EQ(Solution().search(std::vector<int>({5,4}), 4), 1);
    EXPECT_EQ(Solution().search(std::vector<int>({5,4,6}), 3), -1);
    EXPECT_EQ(Solution().search(std::vector<int>({5,4,6}), 10), -1);
    EXPECT_EQ(Solution().search(std::vector<int>({5,4,6}), 5), 0);
    EXPECT_EQ(Solution().search(std::vector<int>({5,4,6}), 4), 1);
    EXPECT_EQ(Solution().search(std::vector<int>({5,4,6}), 6), 2);

    EXPECT_EQ(Solution().search(std::vector<int>({5,6,7,1,2,3}), 8), -1);
    EXPECT_EQ(Solution().search(std::vector<int>({5,6,7,1,2,3}), 0), -1);
    EXPECT_EQ(Solution().search(std::vector<int>({5,6,7,1,2,3}), 5), 0);
    EXPECT_EQ(Solution().search(std::vector<int>({5,6,7,1,2,3}), 6), 1);
    EXPECT_EQ(Solution().search(std::vector<int>({5,6,7,1,2,3}), 7), 2);
    EXPECT_EQ(Solution().search(std::vector<int>({5,6,7,1,2,3}), 1), 3);
    EXPECT_EQ(Solution().search(std::vector<int>({5,6,7,1,2,3}), 2), 4);
    EXPECT_EQ(Solution().search(std::vector<int>({5,6,7,1,2,3}), 3), 5);


    EXPECT_EQ(Solution().search(std::vector<int>({6,7,1,2,3,4,5}), 0), -1);
    EXPECT_EQ(Solution().search(std::vector<int>({6,7,1,2,3,4,5}), 8), -1);
    EXPECT_EQ(Solution().search(std::vector<int>({6,7,1,2,3,4,5}), 6), 0);
    EXPECT_EQ(Solution().search(std::vector<int>({6,7,1,2,3,4,5}), 7), 1);
    EXPECT_EQ(Solution().search(std::vector<int>({6,7,1,2,3,4,5}), 1), 2);
    EXPECT_EQ(Solution().search(std::vector<int>({6,7,1,2,3,4,5}), 2), 3);
    EXPECT_EQ(Solution().search(std::vector<int>({6,7,1,2,3,4,5}), 3), 4);
    EXPECT_EQ(Solution().search(std::vector<int>({6,7,1,2,3,4,5}), 4), 5);
    EXPECT_EQ(Solution().search(std::vector<int>({6,7,1,2,3,4,5}), 5), 6);


    EXPECT_EQ(Solution().search(std::vector<int>({7,1,2,3,4,5,6}), 0), -1);
    EXPECT_EQ(Solution().search(std::vector<int>({7,1,2,3,4,5,6}), 8), -1);
    EXPECT_EQ(Solution().search(std::vector<int>({7,1,2,3,4,5,6}), 7), 0);
    EXPECT_EQ(Solution().search(std::vector<int>({7,1,2,3,4,5,6}), 1), 1);
    EXPECT_EQ(Solution().search(std::vector<int>({7,1,2,3,4,5,6}), 2), 2);
    EXPECT_EQ(Solution().search(std::vector<int>({7,1,2,3,4,5,6}), 3), 3);
    EXPECT_EQ(Solution().search(std::vector<int>({7,1,2,3,4,5,6}), 4), 4);
    EXPECT_EQ(Solution().search(std::vector<int>({7,1,2,3,4,5,6}), 5), 5);
    EXPECT_EQ(Solution().search(std::vector<int>({7,1,2,3,4,5,6}), 6), 6);

    EXPECT_EQ(Solution().search(std::vector<int>({3,4,5,6,7,1,2}), 0), -1);
    EXPECT_EQ(Solution().search(std::vector<int>({3,4,5,6,7,1,2}), 8), -1);
    EXPECT_EQ(Solution().search(std::vector<int>({3,4,5,6,7,1,2}), 3), 0);
    EXPECT_EQ(Solution().search(std::vector<int>({3,4,5,6,7,1,2}), 4), 1);
    EXPECT_EQ(Solution().search(std::vector<int>({3,4,5,6,7,1,2}), 5), 2);
    EXPECT_EQ(Solution().search(std::vector<int>({3,4,5,6,7,1,2}), 6), 3);
    EXPECT_EQ(Solution().search(std::vector<int>({3,4,5,6,7,1,2}), 7), 4);
    EXPECT_EQ(Solution().search(std::vector<int>({3,4,5,6,7,1,2}), 1), 5);
    EXPECT_EQ(Solution().search(std::vector<int>({3,4,5,6,7,1,2}), 2), 6);

    EXPECT_EQ(Solution().search(std::vector<int>({2,3,4,5,6,7,1}), 0), -1);
    EXPECT_EQ(Solution().search(std::vector<int>({2,3,4,5,6,7,1}), 8), -1);
    EXPECT_EQ(Solution().search(std::vector<int>({2,3,4,5,6,7,1}), 2), 0);
    EXPECT_EQ(Solution().search(std::vector<int>({2,3,4,5,6,7,1}), 3), 1);
    EXPECT_EQ(Solution().search(std::vector<int>({2,3,4,5,6,7,1}), 4), 2);
    EXPECT_EQ(Solution().search(std::vector<int>({2,3,4,5,6,7,1}), 5), 3);
    EXPECT_EQ(Solution().search(std::vector<int>({2,3,4,5,6,7,1}), 6), 4);
    EXPECT_EQ(Solution().search(std::vector<int>({2,3,4,5,6,7,1}), 7), 5);
    EXPECT_EQ(Solution().search(std::vector<int>({2,3,4,5,6,7,1}), 1), 6);
}
