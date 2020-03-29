//
// Created by yhzhan on 3/29/2020.
//

#ifndef ASSIGNMENTS_ITH_SMALLEST_H
#define ASSIGNMENTS_ITH_SMALLEST_H

#include <vector>

namespace smallest {
    int ith_smallest(const std::vector<int> &vec, int ith);
    int ith_smallest_impl(std::vector<int> &vec, int start, int end, int ith);
}
#endif //ASSIGNMENTS_ITH_SMALLEST_H
