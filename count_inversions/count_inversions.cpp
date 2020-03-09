//
// Created by yhzhan on 3/8/2020.
//

#include "count_inversions.h"

namespace count_inversions {
    namespace fast {
        unsigned long count(const std::vector<int> &vec) {
            auto result = countInversions(vec);
            return result.first;
        }

        std::pair<unsigned long, std::vector<int>> countInversions(const std::vector<int> &vec) {
            if (vec.empty()) { return std::make_pair(0, vec); }
            int sz = vec.size();
            if (sz == 1) { return std::make_pair(0, vec); }

            int firstSize = sz / 2;
            std::vector<int> first(vec.begin(), vec.begin() + firstSize);
            std::vector<int> second(vec.begin() + firstSize, vec.end());
            auto firstRes = countInversions(first);
            auto secondRes = countInversions(second);
            auto mergeResult = countInversionsAndMerge(firstRes.second, secondRes.second);
            return std::make_pair(firstRes.first + secondRes.first + mergeResult.first, mergeResult.second);
        }

        std::pair<unsigned long, std::vector<int>>
        countInversionsAndMerge(const std::vector<int> &vec1, const std::vector<int> &vec2) {
            if (vec1.empty()) { return std::make_pair(0, vec2); };
            if (vec2.empty()) { return std::make_pair(0, vec1); };
            auto it1 = vec1.begin();
            auto it2 = vec2.begin();
            std::pair<unsigned long, std::vector<int>> ret;
            unsigned long &count = ret.first;
            std::vector<int> &merged = ret.second;
            while (true) {
                if (it1 == vec1.end()) {
                    std::copy(it2, vec2.end(), std::back_inserter(merged));
                    break;
                }
                if (it2 == vec2.end()) {
                    std::copy(it1, vec1.end(), std::back_inserter(merged));
                    break;
                }
                if (*it1 <= *it2) {
                    merged.push_back(*it1);
                    ++it1;
                } else {
                    merged.push_back(*it2);
                    count += std::distance(it1, vec1.end());
                    ++it2;
                }
            }
            return ret;
        }
    }

    namespace slow {
        unsigned long count(const std::vector<int> &vec)
        {
            unsigned long count = 0;
            for (auto it1 = vec.begin(); it1 != vec.end(); ++it1) {
                for (auto it2 = vec.begin(); it2 != vec.end(); ++it2) {
                    if (it1 == it2) { continue; }
                    if (it1 < it2 && *it1 > *it2) {
                        ++count;
                    }
                }
            }
            return count;
        }
    }
}

