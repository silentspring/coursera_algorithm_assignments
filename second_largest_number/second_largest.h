//
// Created by yhzhan on 3/15/2020.
//

#ifndef ASSIGNMENTS_SECOND_LARGEST_H
#define ASSIGNMENTS_SECOND_LARGEST_H

#include <limits>
#include <vector>
namespace second_largest {
    namespace slow {
        int calculate(const std::vector<int> &vec);
    }

    namespace fast {
        struct Node {
            Node(int w, int l) : winner(w), loser(l) {}

            int winner = std::numeric_limits<int>::min();
            int loser = std::numeric_limits<int>::min();
            Node *previous = nullptr;
        };
        int calculate(const std::vector<int> &vec);
        int calculate(std::vector<std::vector<Node *>> &levels);
    }
}
#endif //ASSIGNMENTS_SECOND_LARGEST_H
