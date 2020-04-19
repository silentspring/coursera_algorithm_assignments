//
// Created by yhzhan on 4/19/2020.
//

#include "min_sum_path.h"

#include "gtest/gtest.h"
#include "common.h"
#include <chrono>
#include <unistd.h>

using namespace min_sum_path;
TEST(min_sum_path, testcase) {
    std::vector<std::vector<int>> grid(
            {
                    {1, 3, 1},
                    {1, 5, 1},
                    {4, 2, 1}

            }
    );
    EXPECT_EQ(Solution().minPathSum(grid), 7);
}

