//
// Created by yhzhan on 4/8/2020.
//

#include "unimodal_search.h"

#include <chrono>
#include <set>

namespace unimodal_search {
    void UnimodalVec::createUnimodalVector() {
        if (m_length < 1) {
            return;
        }
        auto now = std::chrono::high_resolution_clock::now().time_since_epoch();
        std::srand(now.count());
        // std::srand(std::time(0));

        m_pivot = std::rand() % m_length;
        std::set<int> createdElems;
        while (createdElems.size() < (m_pivot + 1)) {
            createdElems.insert(std::rand() % m_upperLimit);
        }
        std::copy(createdElems.begin(), createdElems.end(), std::back_inserter(m_vec));
        int max = *(std::prev(createdElems.end()));
        std::set<int> newCreatedElems;
        while (newCreatedElems.size() < (m_length - (m_pivot + 1))) {
            int elem = std::rand() % m_upperLimit;
            if (elem < max && createdElems.insert(elem).second) {
                newCreatedElems.insert(elem);
            }
        }
        std::copy(newCreatedElems.rbegin(), newCreatedElems.rend(), std::back_inserter(m_vec));
    }

    std::ostream &operator<<(std::ostream &os, const UnimodalVec &vec) {
        os << "length [" << vec.m_length << "] vector [";
        for (auto it = vec.m_vec.begin(); it != vec.m_vec.end(); ++it) {
            if (std::distance(vec.m_vec.begin(), it) == vec.m_pivot) {
                os << "*";
            }
            os << (*it);
            if (std::next(it) != vec.m_vec.end()) {
                os << ",";
            }
        }
        os << "] pivot [" << vec.m_pivot << "]" << std::endl;
    }

    int UnimodalVec::find_max() const {
        if (m_vec.empty()) { return -1; }
        size_t len = m_vec.size();
        if (len < 2) {
            return 0;
        }

        return find_max(m_vec, 0, len - 1);

    }

    int UnimodalVec::find_max(const std::vector<int> &vec, int start, int end) {
        if (start > end) {
            std::cerr << "start [" << start << "] > end [" << end << "]" << std::endl;
            abort();
        }
        if (start == end) {
            return start;
        } else if (end - start == 1) {
            if (vec[start] < vec[end]) {
                return end;
            } else if (vec[end] < vec[start]) {
                return start;
            } else {
                std::cerr << "do not support equal elements" << std::endl;
                abort();
            }
        }
        int mid = (start + end) / 2;
        int prev = mid - 1;
        int next = mid + 1;

        // meet the peak here
        if (vec[mid] > vec[prev] && vec[mid] > vec[next]) {
            return mid;
        }
        Direction dir = Direction::Up;
        if (vec[mid] < vec[next]) {
            dir = Direction::Up;
        } else if (vec[next] < vec[mid]) {
            dir = Direction::Down;
        } else {
            std::cerr << "do not support equal elements in the vector right now" << std::endl;
            abort();
        }

        if (dir == Direction::Up) {
            return find_max(vec, mid, end);
        } else {
            return find_max(vec, start, mid);
        }
    }
}
