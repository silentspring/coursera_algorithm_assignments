//
// Created by yhzhan on 3/25/2020.
//

#include "quick_sort.h"
#include "gtest/gtest.h"
#include "common.h"
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include <set>
#include <vector>



using namespace quick_sort;
namespace {
    std::vector<PivotPolicy > policies{PivotPolicy::BEGIN, PivotPolicy::END, PivotPolicy::MIN_BEGIN_END_MID};
}

TEST(quick_sort_test, case_empty) {
    for (auto policy : policies) {
        std::vector<int> vec;
        std::vector<int> gold;
        int cnt_compare = 0;
        quickSort(vec, policy, cnt_compare);
        EXPECT_EQ(vec, gold);
    }
}

TEST(quick_sort_test, case_one_element) {
    for (auto policy : policies) {
        std::vector<int> vec{{1}};
        std::vector<int> gold{{1}};
        int cnt_compare = 0;
        quickSort(vec, policy, cnt_compare);
        EXPECT_EQ(vec, gold);
    }
}

TEST(quick_sort_test, case_two_elements) {
    for (auto policy : policies) {
        std::vector<int> vec{{1,2}};
        std::vector<int> gold{{1,2}};
        int cnt_compare = 0;
        quickSort(vec, policy, cnt_compare);
        EXPECT_EQ(vec, gold);
    }
    for (auto policy : policies) {
        std::vector<int> vec{{2, 1}};
        std::vector<int> gold{{1, 2}};
        int cnt_compare = 0;
        quickSort(vec, policy, cnt_compare);
        EXPECT_EQ(vec, gold);
    }
    for (auto policy : policies) {
        std::vector<int> vec{{1,1}};
        std::vector<int> gold{{1,1}};
        int cnt_compare = 0;
        quickSort(vec, policy, cnt_compare);
        EXPECT_EQ(vec, gold);
    }
}

TEST(quick_sort_test, case_three_elements) {
    for (auto policy : policies) {
        std::vector<int> vec{{1,2,3}};
        std::vector<int> gold{{1,2,3}};
        int cnt_compare = 0;
        quickSort(vec, policy, cnt_compare);
        EXPECT_EQ(vec, gold);
    }
    for (auto policy : policies) {
        std::vector<int> vec{{3,2,1}};
        std::vector<int> gold{{1,2,3}};
        int cnt_compare = 0;
        quickSort(vec, policy, cnt_compare);
        EXPECT_EQ(vec, gold);
    }
    for (auto policy : policies) {
        std::vector<int> vec{{2,1,3}};
        std::vector<int> gold{{1,2,3}};
        int cnt_compare = 0;
        quickSort(vec, policy, cnt_compare);
        EXPECT_EQ(vec, gold);
    }
    for (auto policy : policies) {
        std::vector<int> vec{{2,3,1}};
        std::vector<int> gold{{1,2,3}};
        int cnt_compare = 0;
        quickSort(vec, policy, cnt_compare);
        EXPECT_EQ(vec, gold);
    }
    for (auto policy : policies) {
        std::vector<int> vec{{2,1,3}};
        std::vector<int> gold{{1,2,3}};
        int cnt_compare = 0;
        quickSort(vec, policy, cnt_compare);
        EXPECT_EQ(vec, gold);
    }
}

TEST(quick_sort_test, case_three_elements_duplicated) {
    for (auto policy : policies) {
        std::vector<int> vec{{2, 2, 3}};
        std::vector<int> gold{{2, 2, 3}};
        int cnt_compare = 0;
        quickSort(vec, policy, cnt_compare);
        EXPECT_EQ(vec, gold);
    }

    for (auto policy : policies) {
        std::vector<int> vec{{2, 3, 3}};
        std::vector<int> gold{{2, 3, 3}};
        int cnt_compare = 0;
        quickSort(vec, policy, cnt_compare);
        EXPECT_EQ(vec, gold);
    }

    for (auto policy : policies) {
        std::vector<int> vec{{3, 3, 3}};
        std::vector<int> gold{{3, 3, 3}};
        int cnt_compare = 0;
        quickSort(vec, policy, cnt_compare);
        EXPECT_EQ(vec, gold);
    }
}

TEST(quick_sort_test, case1) {
    for (auto policy : policies) {
        std::vector<int> vec{{5, 4, 3, 2, 1}};
        std::vector<int> gold{{1, 2, 3, 4, 5}};
        int cnt_compare = 0;
        quickSort(vec, policy, cnt_compare);
        EXPECT_EQ(vec, gold);
    }
}

TEST(quick_sort_test, case2) {
    for (auto policy : policies) {
        std::vector<int> vec{{1, 2, 3, 4, 5}};
        std::vector<int> gold{{1, 2, 3, 4, 5}};
        int cnt_compare = 0;
        quickSort(vec, policy, cnt_compare);
        EXPECT_EQ(vec, gold);
    }
}

TEST(quick_sort_test, case3) {
    for (auto policy : policies) {
        std::vector<int> vec{{1, 2, 5, 4, 3}};
        std::vector<int> gold{{1, 2, 3, 4, 5}};
        int cnt_compare = 0;
        quickSort(vec, policy, cnt_compare);
        EXPECT_EQ(vec, gold);
    }
}

TEST(quick_sort_test, case4) {
    for (auto policy : policies) {
        std::vector<int> vec{{1, 2, 5, 4, 3}};
        std::vector<int> gold{{1, 2, 3, 4, 5}};
        int cnt_compare = 0;
        quickSort(vec, policy, cnt_compare);
        EXPECT_EQ(vec, gold);
    }
}

TEST(quick_sort_test, case_small_duplicates1) {
    for (auto policy : policies) {
        std::vector<int> vec{{1, 2, 5, 4, 4, 3}};
        std::vector<int> gold{{1, 2, 3, 4, 4, 5}};
        int cnt_compare = 0;
        quickSort(vec, policy, cnt_compare);
        EXPECT_EQ(vec, gold);
    }
}

TEST(quick_sort_test, case_small_duplicates2) {
    for (auto policy : policies) {
        std::cout << "policy [" << static_cast<int>(policy) << "]" << std::endl;
        std::vector<int> vec{{1, 2, 5, 4, 3,3}};
        std::vector<int> gold{{1, 2, 3, 3,4, 5}};
        int cnt_compare = 0;
        quickSort(vec, policy, cnt_compare);
        EXPECT_EQ(vec, gold);
    }
}

TEST(quick_sort_test, case_small_duplicates3) {
    for (auto policy : policies) {
        std::vector<int> vec{{5, 4, 3, 3}};
        std::vector<int> gold{{3, 3, 4, 5}};
        int cnt_compare = 0;
        quickSort(vec, PivotPolicy::BEGIN, cnt_compare);
        EXPECT_EQ(vec, gold);
    }
}

TEST(quick_sort_test, case_small_duplicates4) {
    for (auto policy : policies) {
        std::vector<int> vec{{3, 3, 4, 5}};
        std::vector<int> gold{{3, 3, 4, 5}};
        int cnt_compare = 0;
        quickSort(vec, PivotPolicy::BEGIN, cnt_compare);
        EXPECT_EQ(vec, gold);
    }
}

void getRandomArray(std::vector<int> &vec, bool unique, int count, int max)
{
    std::set<int> hit;
    for (int i = 0; i < count; ++i)  {
        int num = rand() % max + 1;
        if (unique) {
            if (hit.find(num) != hit.end()) {
                continue;
            }
        }
        vec.push_back(num);
        if (unique) {
            hit.insert(num);
        }
    }
}

TEST(quick_sort_test, case_no_duplicates) {
    for (int i = 0; i < 100; ++i) {
        for (auto policy : policies) {
            std::vector<int> vec;
            getRandomArray(vec, true, 1000, 10000);
            std::vector<int> gold = vec;
            int cnt_compare = 0;
            quickSort(vec, policy, cnt_compare);
            std::sort(gold.begin(), gold.end());
            EXPECT_EQ(vec, gold);
        }
    }
}

TEST(quick_sort_test, case_duplicates) {
    for (int i = 0; i < 100; ++i) {
        for (auto policy : policies) {
            std::vector<int> vec;
            getRandomArray(vec, false, 1000, 10000);
            std::vector<int> gold = vec;
            int cnt_compare = 0;
            quickSort(vec, policy, cnt_compare);
            std::sort(gold.begin(), gold.end());
            EXPECT_EQ(vec, gold);
        }
    }
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

TEST(quick_sort_test, coursera_case) {
    for (auto policy : policies) {
        std::cout << std::endl;
        std::cout << "policy [" << static_cast<int>(policy) << "]" << std::endl;
        char path[1024];
        getcwd(path, 1024);
        std::vector<int> vec;
        collectData("../../Google_tests/QuickSortBigVector.txt", vec);
        std::cout << "vector size [" << vec.size() << "]" << std::endl;
        std::cout << "set size [" << std::set<int>(vec.begin(), vec.end()).size() << "]" << std::endl;
        std::vector<int> gold = vec;
        int cnt_compare = 0;
        quickSort(vec, policy, cnt_compare);
        std::cout << "cnt_compare [" << cnt_compare << "]" << std::endl;
        std::sort(gold.begin(), gold.end());
        EXPECT_EQ(vec, gold);
    }
}
