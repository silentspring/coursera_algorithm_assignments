//
// Created by yhzhan on 4/19/2020.
//

#ifndef ASSIGNMENTS_MIN_SUM_PATH_H
#define ASSIGNMENTS_MIN_SUM_PATH_H

#include <vector>
#include <string>
#include <limits>

namespace min_sum_path {
    class Solution {
    public:
        int minPathSum(const std::vector<std::vector<int>> &grid) {
            if (grid.empty()) { return 0; }
            size_t xLen = grid.size();
            size_t yLen = grid[0].size();
            std::vector<std::vector<int>> minPathSum;
            for (int i = 0; i < grid.size(); ++i) {
                minPathSum.emplace_back(grid[0].size(), 0);
            }
            for (int i = xLen-1; i >= 0; --i) {
                for (int j = yLen-1; j >= 0; --j) {
                    if (i == xLen-1 && j == yLen-1) {
                        minPathSum[i][j] = grid[i][j];
                    } else if (i == xLen-1 && j < yLen-1) {
                        minPathSum[i][j] = grid[i][j] + minPathSum[i][j+1];
                    } else if (i < xLen-1 && j == yLen-1) {
                        minPathSum[i][j] = grid[i][j] + minPathSum[i+1][j];
                    } else {
                        minPathSum[i][j] = grid[i][j] + std::min(minPathSum[i+1][j], minPathSum[i][j+1]);
                    }
                }
            }
            return minPathSum[0][0];
        }
        int minPathSumBruteForce(const std::vector<std::vector<int>> &grid, int i, int j) {
            if (i == grid.size()-1 && j == grid[0].size()-1) {
                return grid[i][j];
            }
            if (i == grid.size()-1) {
                return grid[i][j] + minPathSumBruteForce(grid, i, j + 1);
            }
            if (j == grid[0].size()-1) {
                return grid[i][j] + minPathSumBruteForce(grid, i+1, j);
            }
            return grid[i][j] + std::min(minPathSumBruteForce(grid, i + 1, j), minPathSumBruteForce(grid, i, j + 1));
        }
    };
}
#endif //ASSIGNMENTS_MIN_SUM_PATH_H
