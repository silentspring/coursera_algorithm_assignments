//
// Created by yhzhan on 3/29/2020.
//

#include "ith_smallest.h"
#include "quick_sort.h"

#include <limits>

namespace smallest {
    quick_sort::PartitionWildMiddle partition;
    int ith_smallest(const std::vector<int> &vec, int ith) {
        if (vec.empty()) {
            return std::numeric_limits<int>::min();
        }
        int sz = vec.size();
        std::vector<int> vecCpy = vec;
        if (ith < 1 || ith > sz) {
            return std::numeric_limits<int>::min();
        }
        if (sz == 1) {
            return vec[0];
        }
        return ith_smallest_impl(vecCpy, 0, sz-1, ith-1);
    }

    int ith_smallest_impl(std::vector<int> &vec, int start, int end, int desiredIdx) {
        int cnt_compare = 0;
        int pivot = partition.partition(vec, quick_sort::PivotPolicy::MIN_BEGIN_END_MID, start, end, cnt_compare);
        if (desiredIdx < pivot) {
            return ith_smallest_impl(vec, start, pivot-1, desiredIdx);
        } else if (pivot < desiredIdx) {
            return ith_smallest_impl(vec, pivot+1, end, desiredIdx);
        } else {
            return vec[pivot];
        }
    }
}
