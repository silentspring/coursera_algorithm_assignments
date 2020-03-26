//
// Created by yhzhan on 3/15/2020.
//

#include "second_largest.h"
#include <limits>
#include <iostream>


namespace second_largest {
    namespace slow {
        int calculate(const std::vector<int> &vec) {
            int largest = std::numeric_limits<int>::min();
            int second_largest = std::numeric_limits<int>::min();
            for (auto e : vec) {
                if (largest < e) {
                    second_largest = largest;
                    largest = e;
                } else if (e > second_largest && e < largest) {
                    second_largest = e;
                } else {
                    // (e == largest || e == second_largest || e < second_largest)
                }
            }
            return second_largest;
        }
    }

    namespace fast {
        void dump(const std::vector<Node *> &vec) {
            for (auto e : vec) {
                std::cout << "[" << e->winner << ", " << e->loser << "]" ;
            }
            std::cout << std::endl;
        }
        int calculate(const std::vector<int> &vec) {
            std::vector<std::vector<Node *>> levels;
            bool odd = true;
            int temp = 0;
            std::vector<Node *> level;
            for (const auto e : vec) {
                if (odd) {
                    temp = e;
                    odd = false;
                } else {
                    if (temp < e) {
                        auto node = new Node(e, temp);
                        level.push_back(node);
                    } else if (e < temp) {
                        auto node = new Node(temp, e);
                        level.push_back(node);
                    } else {
                        // we do not allow equal elements
                        throw 99999;
                    }
                    odd = true;
                }
            }
            levels.push_back(level);
            // dump(level);
            return calculate(levels);
        }

        int calculate(std::vector<std::vector<Node *>> &levels) {
            bool odd = true;
            Node *temp = nullptr;
            std::vector<Node *> level;
            const auto &lastLevel = *(levels.end() - 1);
            for (const auto e : lastLevel) {
                if (odd) {
                    temp = e;
                    odd = false;
                } else {
                    if (temp->winner < e->winner) {
                        auto node = new Node(e->winner, temp->winner);
                        node->previous = e;
                        level.push_back(node);
                    } else if (e->winner < temp->winner) {
                        auto node = new Node(temp->winner, e->winner);
                        node->previous = temp;
                        level.push_back(node);
                    } else {
                        // we do not allow equal elements
                        throw 99999;
                    }
                    odd = true;
                }
            }
            // dump(level);
            if (level.size() == 1) {
                Node *node = *(level.begin());
                int bingo = node->loser;
                //std::cout << "loser :" << std::endl;
                //std::cout << "[" << bingo << "]";
                while (node->previous) {
                    if (node->previous->loser > bingo) {
                        bingo = node->previous->loser;
                        // std::cout << "[" << bingo << "]";
                    }
                    node = node->previous;
                }
                return bingo;
            }
            levels.push_back(level);
            return calculate(levels);
        }
    }
}
