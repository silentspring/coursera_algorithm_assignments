//
// Created by yhzhan on 4/18/2020.
//

#include "num_islands.h"

#include "gtest/gtest.h"
#include "common.h"
#include <chrono>
#include <unistd.h>

using namespace num_islands;
TEST(num_islands, testcase) {
    std::vector<std::vector<char>> grid(
            {
                    {'1','1','1','1','0'},
                    {'1','1','0','1','0'},
                    {'1','1','0','0','0'},
                    {'0','0','0','0','0'}
            }
            );
    EXPECT_EQ(Solution().numIslands(grid), 1);
}

TEST(num_islands, testcase2) {
    std::vector<std::vector<char>> grid(
            {
                    {'1','1','0','0','0'},
                    {'1','1','0','0','0'},
                    {'0','0','1','0','0'},
                    {'0','0','0','1','1'}
            }
    );
    EXPECT_EQ(Solution().numIslands(grid), 3);
}

TEST(num_islands, testcase3) {
    std::vector<std::vector<char>> grid(
            {
                    {'1','1','1'},
                    {'0','1','0'},
                    {'1','1','1'}
            }
    );
    EXPECT_EQ(Solution().numIslands(grid), 1);
}


