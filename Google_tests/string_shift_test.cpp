//
// Created by yhzhan on 4/14/2020.
//

#include "gtest/gtest.h"
#include "common.h"
#include <chrono>
#include "string_shift.h"
#include <unistd.h>

using namespace string_shift;
TEST(string_shift, testcase)
{
    EXPECT_EQ(Solution().stringShift("abc", {{0,1}, {1,2}}), "cab");
}
