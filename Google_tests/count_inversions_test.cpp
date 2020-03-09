//
// Created by yhzhan on 3/8/2020.
//

#include "gtest/gtest.h"
#include "count_inversions.h"

#define VERIFY(vec, count) EXPECT_EQ(count_inversions::count(std::vector<int>(vec)), count);

TEST(test_counting_inversions, test_case) {
VERIFY({1}, 0);
VERIFY({1,2}, 0);
VERIFY({2,1}, 1);
VERIFY({3,2,1}, 3);
VERIFY({1,4,2,3}, 2);
}
