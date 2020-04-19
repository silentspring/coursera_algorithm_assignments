//
// Created by yhzhan on 4/18/2020.
//

#ifndef ASSIGNMENTS_NUM_ISLANDS_H
#define ASSIGNMENTS_NUM_ISLANDS_H

#include <iostream>
#include <map>
#include <set>
#include <vector>

namespace num_islands {
    class Solution {
            public:
            int numIslands(const std::vector<std::vector<char>>& grid)
            {
                if (grid.empty()) {
                    return 0;
                }
                std::vector<std::vector<int>> info;
                for (const auto &v : grid) {
                    info.emplace_back(v.size(), 0);
                }

                int numIslands = 0;
                std::map<int, std::set<std::pair<int,int>>> islandsMap;
                int rows = grid.size();
                int columns = grid[0].size();
                for (int i = 0; i < rows; ++i) {
                    for (int j = 0; j < columns; ++j) {
                        if (grid[i][j] == '0') {
                            info[i][j] = 0;
                            continue;
                        } else if (grid[i][j] == '1') {
                            if (i == 0 && j == 0) {
                                ++numIslands;
                                islandsMap[numIslands].insert(std::make_pair(i, j));
                                info[i][j] = numIslands;
                            } else {
                                int island1 = 0;
                                if (i > 0 && grid[i - 1][j] == '1') {
                                    island1 = info[i-1][j];
                                }
                                int island2 = 0;
                                if (j > 0 && grid[i][j - 1] == '1') {
                                    island2 = info[i][j-1];
                                }
                                if (island1 == 0 && island2 == 0) {
                                    ++numIslands;
                                    info[i][j] = numIslands;
                                    islandsMap[numIslands].insert(std::make_pair(i, j));
                                } else if (island1 != 0 && island2 == 0) {
                                    islandsMap[island1].insert(std::make_pair(i, j));
                                    info[i][j] = island1;
                                } else if (island1 == 0 && island2 != 0){
                                    islandsMap[island2].insert(std::make_pair(i, j));
                                    info[i][j] = island2;
                                } else {
                                    if (island1 == island2) {
                                        islandsMap[island1].insert(std::make_pair(i, j));
                                        info[i][j] = island1;
                                    } else {
                                        size_t sz1 = islandsMap[island1].size();
                                        size_t sz2 = islandsMap[island2].size();
                                        if (sz1 < sz2) {
                                            const auto &islands1Set = islandsMap[island1];
                                            for (const auto &p : islands1Set) {
                                                info[p.first][p.second] = island2;
                                            }
                                            islandsMap[island2].insert(islands1Set.begin(), islands1Set.end());
                                            islandsMap.erase(island1);
                                            islandsMap[island2].insert(std::make_pair(i, j));
                                            info[i][j] = island2;
                                        } else {
                                            const auto &islands2Set = islandsMap[island2];
                                            for (const auto &p : islands2Set) {
                                                info[p.first][p.second] = island1;
                                            }
                                            islandsMap[island1].insert(islands2Set.begin(), islands2Set.end());
                                            islandsMap.erase(island2);
                                            islandsMap[island1].insert(std::make_pair(i, j));
                                            info[i][j] = island1;
                                        }
                                    }
                                }
                            }
                        } else {
                            abort();
                        }
                    }
                }
                return islandsMap.size();
            }
    };
}
#endif //ASSIGNMENTS_NUM_ISLANDS_H
