//
// Created by yhzhan on 4/16/2020.
//

#include "valid_parenthesis_string.h"

#include "gtest/gtest.h"
#include "common.h"
#include <chrono>
#include "valid_parenthesis_string.h"
#include <unistd.h>

using namespace valid_parenthesis_string;
TEST(valid_parenthesis_string, testcase)
{
    EXPECT_TRUE(Solution().checkValidString(""));
    EXPECT_TRUE(Solution().checkValidString("*"));
    EXPECT_TRUE(Solution().checkValidString("**"));
    EXPECT_TRUE(Solution().checkValidString("***"));
    EXPECT_TRUE(Solution().checkValidString("()"));
    EXPECT_TRUE(Solution().checkValidString("(*)"));
    EXPECT_TRUE(Solution().checkValidString("(*))"));
    EXPECT_TRUE(Solution().checkValidString("(*))"));
    EXPECT_TRUE(Solution().checkValidString("(**())*"));
    EXPECT_TRUE(Solution().checkValidString("*)"));
    EXPECT_TRUE(Solution().checkValidString("(((******))"));

    EXPECT_FALSE(Solution().checkValidString("("));
    EXPECT_FALSE(Solution().checkValidString(")"));
    EXPECT_FALSE(Solution().checkValidString(")*"));
    EXPECT_FALSE(Solution().checkValidString("(()()))"));
    EXPECT_FALSE(Solution().checkValidString("(())((())()()(*)(*()(())())())()()((()())((()))(*"));
}
