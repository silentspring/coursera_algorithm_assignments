//
// Created by yhzhan on 4/12/2020.
//

#include "gtest/gtest.h"
#include "common.h"
#include <chrono>
#include "backspace_process.h"

using namespace backspace_process;

TEST(backspace_process, testcase) {
    EXPECT_TRUE(Solution().backspaceCompare("ab#c", "ad#c"));
    EXPECT_TRUE(Solution().backspaceCompare("ab##c", "ad##c"));
    EXPECT_TRUE(Solution().backspaceCompare("##c", "##c"));
    EXPECT_FALSE(Solution().backspaceCompare("ab##c", "c#d#"));
    EXPECT_FALSE(Solution().backspaceCompare("isfcow#", "isfco#w#"));
}
