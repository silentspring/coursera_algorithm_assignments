//
// Created by yhzhan on 3/8/2020.
//

#include "gtest/gtest.h"
#include "common.h"
#include <chrono>
#include "count_inversions.h"
#include <unistd.h>


using Vec = std::vector<int>;

TEST(count_inversions_test, slow) {
    using namespace count_inversions::slow;
    EXPECT_EQ(count(Vec{{1}}), 0);
    EXPECT_EQ(count(Vec{{1,2}}), 0);
    EXPECT_EQ(count(Vec{{2,1}}), 1);
    EXPECT_EQ(count(Vec{{3,2,1}}), 3);
    EXPECT_EQ(count(Vec{{1,4,2,3}}), 2);
}

#define COMPARE(vec) EXPECT_EQ(count_inversions::slow::count(vec), count_inversions::fast::count(vec));

TEST(count_inversions_test, fast) {
    COMPARE(Vec{{1}});
    COMPARE((Vec{{1,2}}));
    COMPARE((Vec{{2,1}}));
    COMPARE((Vec{{3,2,1}}));
    COMPARE((Vec{{100,99,98,97,1,2,3,4,90,91,92,93,94,80,81,82,83,84}}));
}

#include <fstream>
void collectData(const std::string &file, std::vector<int> &vec)
{
    std::ifstream ifs(file);
    vec.reserve(1000000);
    int num;
    int i = 0;
    while (ifs >> num) {
        vec.push_back(num);
    }
}

TEST(count_inversions_test, big) {
    char path[1024];
    getcwd(path, 1024);
    std::vector<int> vec;
    collectData("../../Google_tests/IntegerArray.txt", vec);
    EXPECT_EQ(vec.size(), 100000);
    unsigned long count1;
    {
        Duration dur("fast");
        count1 = count_inversions::fast::count(vec);
        std::cout << "fast result [" << count1 << "]" << std::endl;
    }
    return;
    int count2;
    {
        Duration dur("slow");
        count2 = count_inversions::slow::count(vec);
        std::cout << "slow result [" << count2 << "]" << std::endl;
    }
    EXPECT_EQ(count1, count2);
}
