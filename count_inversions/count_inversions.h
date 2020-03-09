//
// Created by yhzhan on 3/8/2020.
//

#ifndef ASSIGNMENTS_COUNT_INVERSIONS_H
#define ASSIGNMENTS_COUNT_INVERSIONS_H

#include <vector>

namespace count_inversions {
    std::pair<int, std::vector<int>> countInversions(const std::vector<int> &vec);
    std::pair<int, std::vector<int>> countInversionsAndMerge(const std::vector<int> &vec1, const std::vector<int> &vec2);
    int count(const std::vector<int> &vec);
}
#endif //ASSIGNMENTS_COUNT_INVERSIONS_H
