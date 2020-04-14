//
// Created by yhzhan on 4/8/2020.
//

#ifndef ASSIGNMENTS_UNIMODAL_SEARCH_H
#define ASSIGNMENTS_UNIMODAL_SEARCH_H

#include "common.h"
#include <chrono>
#include <ostream>
#include <set>
#include <unistd.h>
#include <cstdlib>
#include <time.h>

namespace unimodal_search {
    class UnimodalVec {
    public:
        UnimodalVec(size_t length, size_t upperLimit) : m_length(length), m_upperLimit(upperLimit) {
            createUnimodalVector();
        }
        int pivot() { return m_pivot; }

        int find_max() const;
        static int find_max(const std::vector<int> &vec, int start, int end);
    private:
        enum class Direction { Up, Down };
    private:
        void createUnimodalVector();

        friend std::ostream &operator<<(std::ostream &os, const UnimodalVec &vec);

    private:
        std::vector<int> m_vec;
        int m_pivot = 0;
        size_t m_length;
        size_t m_upperLimit;
    };

    std::ostream &operator<<(std::ostream &os, const UnimodalVec &vec);

}
#endif //ASSIGNMENTS_UNIMODAL_SEARCH_H
