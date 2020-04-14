//
// Created by yhzhan on 4/7/2020.
//

#include "gtest/gtest.h"
#include "common.h"
#include "unimodal_search.h"
#include <chrono>
#include <unistd.h>
#include <cstdlib>
#include <time.h>
#include <cmath>




using namespace unimodal_search;
TEST(unimodal_search_test, random_case1) {
    for (int i = 1; i <= 10000; ++i) {
        std::cout << "iteration [" << i << "]" << std::endl;
        UnimodalVec vec(10, 100);
        std::cout << vec << std::endl;
        EXPECT_EQ(vec.find_max(), vec.pivot());
    }
}

TEST(unimodal_search_test, random_case2) {
    for (int i = 1; i <= 10000; ++i) {
        std::cout << "iteration [" << i << "]" << std::endl;
        UnimodalVec vec(100, 1000000);
        std::cout << vec << std::endl;
        int maxIdx = vec.find_max();
        if (maxIdx != vec.pivot()) {
            std::cerr << "FAIL!! maxIdx [" << maxIdx << "] pivot [" << vec.pivot() <<"]" << std::endl;
            abort();
        } else {
            std::cout << "PASS!!" << std::endl;
        }
    }
}


TEST(unimodal_search_test, random_case3) {
    for (int i = 1; i <= 10000; ++i) {
        std::cout << "iteration [" << i << "]" << std::endl;
        UnimodalVec vec(10000, 1000000000);
        std::cout << vec << std::endl;
        int maxIdx = vec.find_max();
        if (maxIdx != vec.pivot()) {
            std::cerr << "FAIL!! maxIdx [" << maxIdx << "] pivot [" << vec.pivot() <<"]" << std::endl;
            abort();
        } else {
            std::cout << "PASS!!" << std::endl;
        }
    }
}


TEST(unimodal_search_test, specific_case1) {
    std::vector<int> vec{2,15,26,32,33,37,78,86,97,16};
    EXPECT_EQ(UnimodalVec::find_max(vec, 0, 9), 8);
}

TEST(unimodal_search_test, specific_case2) {
    std::vector<int> vec{37836,67228,70510,72928,88167,205241,232458,235625,239414,266061,280950,294118,341711,377542,400585,416229,418141,432903,437077,442501,444961,451293,468345,511726,532053,532815,573631,574460,581658,605654,607765,609436,611475,618601,624116,639043,652258,657119,660150,668914,688231,717626,787614,792946,815117,815212,846451,851950,872128,879321,950096,963269,974402,976209,986807,987462,870788,864158,851380,836431,825363,822320,775613,773655,740546,735219,709192,657069,600400,570733,538631,503877,498430,495881,495493,460418,431662,345621,322465,302612,296759,287831,281717,259810,254728,227153,219026,205827,183710,169295,164233,128990,118929,118737,91939,61122,53451,46833,45947,10832};
    EXPECT_EQ(UnimodalVec::find_max(vec, 0, vec.size()-1), 55 /* 987462 */);
}


TEST(unimodal_search_test, specific_case3) {
    std::vector<int> vec{13841,38239,47683,52569,61119,70880,85313,100154,138054,147060,150503,151936,152420,156115,169987,174435,176686,194614,217852,224873,254398,262935,267718,279569,298638,341573,358206,363601,373777,393137,397857,412804,419658,432334,466943,497429,506690,543169,552241,572212,586494,600491,628623,635826,649019,661806,665724,665969,682409,692275,699826,720529,740267,743029,745214,752931,762201,805071,807473,815229,816079,820507,833472,836579,850229,883957,927708,944040,982227,982994,942124,938870,896254,882305,826609,824865,807858,699533,613320,508133,503304,499388,497957,465153,446490,376450,336566,288211,285879,254306,205481,199394,180484,158740,155650,112296,102784,80749,53257,12171};
    EXPECT_EQ(UnimodalVec::find_max(vec, 0, vec.size()-1), 69 /* 982994 */);
}


