//
// Created by yhzhan on 4/12/2020.
//

#include "gtest/gtest.h"
#include "common.h"
#include "min_stack.h"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <limits>

TEST(min_stack, testcase1) {
    MinStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    EXPECT_EQ(stack.top(), 3);
    EXPECT_EQ(stack.getMin(), 1);
}

TEST(min_stack, testcase2) {
    MinStack stack;
    stack.push(3);
    stack.push(2);
    stack.push(1);
    EXPECT_EQ(stack.top(), 1);
    EXPECT_EQ(stack.getMin(), 1);
}

TEST(min_stack, testcase3) {
    MinStack stack;
    stack.push(3);
    EXPECT_EQ(stack.top(), 3);
    EXPECT_EQ(stack.getMin(), 3);
    stack.push(2);
    EXPECT_EQ(stack.top(),2);
    EXPECT_EQ(stack.getMin(), 2);
    stack.push(1);
    EXPECT_EQ(stack.top(), 1);
    EXPECT_EQ(stack.getMin(), 1);
    stack.pop();
    EXPECT_EQ(stack.top(),2);
    EXPECT_EQ(stack.getMin(), 2);
    stack.pop();
    EXPECT_EQ(stack.top(), 3);
    EXPECT_EQ(stack.getMin(), 3);
}

TEST(min_stack, testcase4) {
    MinStack stack;
    stack.push(3);
    EXPECT_EQ(stack.top(), 3);
    EXPECT_EQ(stack.getMin(), 3);
    stack.push(1);
    EXPECT_EQ(stack.top(), 1);
    EXPECT_EQ(stack.getMin(), 1);
    stack.push(2);
    EXPECT_EQ(stack.top(),2);
    EXPECT_EQ(stack.getMin(), 1);
    stack.pop();
    EXPECT_EQ(stack.top(), 1);
    EXPECT_EQ(stack.getMin(), 1);
    stack.pop();
    EXPECT_EQ(stack.top(), 3);
    EXPECT_EQ(stack.getMin(), 3);
}

TEST(min_stack, testcase5) {
    MinStack stack;
    stack.push(1);
    EXPECT_EQ(stack.top(), 1);
    EXPECT_EQ(stack.getMin(), 1);
    stack.push(2);
    EXPECT_EQ(stack.top(), 2);
    EXPECT_EQ(stack.getMin(), 1);
    stack.push(3);
    EXPECT_EQ(stack.top(),3);
    EXPECT_EQ(stack.getMin(), 1);
    stack.pop();
    EXPECT_EQ(stack.top(), 2);
    EXPECT_EQ(stack.getMin(), 1);
    stack.pop();
    EXPECT_EQ(stack.top(), 1);
    EXPECT_EQ(stack.getMin(), 1);
}
TEST(min_stack, testcase6) {
    MinStack stack;
    stack.push(2147483646);
    stack.push(2147483646);
    stack.push(2147483647);
    EXPECT_EQ(stack.top(), 2147483647);
    stack.pop();
    EXPECT_EQ(stack.getMin(), 2147483646);
    stack.pop();
    EXPECT_EQ(stack.getMin(), 2147483646);
    stack.pop();

    stack.push(2147483647);
    EXPECT_EQ(stack.top(), 2147483647);
    EXPECT_EQ(stack.getMin(), 2147483647);
    stack.push(-2147483648);
    EXPECT_EQ(stack.top(), -2147483648);
    EXPECT_EQ(stack.getMin(), -2147483648);
    stack.pop();
    EXPECT_EQ(stack.getMin(), 2147483647);
}
