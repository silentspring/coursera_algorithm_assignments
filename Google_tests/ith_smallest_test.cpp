//
// Created by yhzhan on 3/29/2020.
//

#include "gtest/gtest.h"
#include "common.h"
#include "ith_smallest.h"
#include <algorithm>
#include <limits>


using namespace smallest;

TEST(ith_smallest, testcase) {
    EXPECT_EQ(ith_smallest(std::vector<int>{}, 1), std::numeric_limits<int>::min());
    EXPECT_EQ(ith_smallest(std::vector<int>{1}, 1), 1);
    EXPECT_EQ(ith_smallest(std::vector<int>{1}, 0), std::numeric_limits<int>::min());
    EXPECT_EQ(ith_smallest(std::vector<int>{1}, 2), std::numeric_limits<int>::min());

    EXPECT_EQ(ith_smallest(std::vector<int>{1,2,3,4,5}, 1), 1);
    EXPECT_EQ(ith_smallest(std::vector<int>{1,2,3,4,5}, 2), 2);
    EXPECT_EQ(ith_smallest(std::vector<int>{1,2,3,4,5}, 3), 3);
    EXPECT_EQ(ith_smallest(std::vector<int>{1,2,3,4,5}, 4), 4);
    EXPECT_EQ(ith_smallest(std::vector<int>{1,2,3,4,5}, 5), 5);

    EXPECT_EQ(ith_smallest(std::vector<int>{5,4,3,2,1}, 1), 1);
    EXPECT_EQ(ith_smallest(std::vector<int>{5,4,3,2,1}, 2), 2);
    EXPECT_EQ(ith_smallest(std::vector<int>{5,4,3,2,1}, 3), 3);
    EXPECT_EQ(ith_smallest(std::vector<int>{5,4,3,2,1}, 4), 4);
    EXPECT_EQ(ith_smallest(std::vector<int>{5,4,3,2,1}, 5), 5);
}

#include <fstream>
namespace {
    void collectData(const std::string &file, std::vector<int> &vec) {
        std::ifstream ifs(file);
        vec.reserve(1000000);
        int num;
        int i = 0;
        while (ifs >> num) {
            vec.push_back(num);
        }
    }
}

#define VERIFY_ITH(index) \
    EXPECT_EQ(ith_smallest(vec, index), gold[index-1]);

TEST(ith_smallest_test, coursera_case) {
    std::cout << std::endl;
    char path[1024];
    getcwd(path, 1024);
    std::vector<int> vec;
    collectData("../../Google_tests/QuickSortBigVector.txt", vec);
    std::cout << "vector size [" << vec.size() << "]" << std::endl;
    std::cout << "set size [" << std::set<int>(vec.begin(), vec.end()).size() << "]" << std::endl;
    std::vector<int> gold = vec;
    int cnt_compare = 0;
    std::cout << "cnt_compare [" << cnt_compare << "]" << std::endl;
    std::sort(gold.begin(), gold.end());
    // verify through all the ith elements
    for (int i = 1; i <= gold.size(); ++i) {
        VERIFY_ITH(i);
    }
}
