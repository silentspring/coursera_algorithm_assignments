//
// Created by yhzhan on 3/8/2020.
//

#ifndef ASSIGNMENTS_COUNT_INVERSIONS_H
#define ASSIGNMENTS_COUNT_INVERSIONS_H

#include <vector>

namespace count_inversions {
    namespace fast {
        std::pair<unsigned long, std::vector<int>> countInversions(const std::vector<int> &vec);

        std::pair<unsigned long, std::vector<int>>
        countInversionsAndMerge(const std::vector<int> &vec1, const std::vector<int> &vec2);

        unsigned long count(const std::vector<int> &vec);
    }
    namespace slow {
        unsigned long count(const std::vector<int> &vec);
    }
}
#endif //ASSIGNMENTS_COUNT_INVERSIONS_H
