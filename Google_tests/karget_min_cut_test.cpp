//
// Created by yhzhan on 4/3/2020.
//

#include "gtest/gtest.h"
#include "common.h"
#include "min_cut.h"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <limits>

/*
The file contains the adjacency list representation of a simple undirected graph. There are 200 vertices labeled
 1 to 200. The first column in the file represents the vertex label, and the particular row (other entries except the
 first column) tells all the vertices that the vertex is adjacent to. So for example, the 6^{th}6 th row looks like
 : "6	155	56	52	120	......". This just means that the vertex with label 6 is adjacent to (i.e., shares an edge with)
 the vertices with labels 155,56,52,120,......,etc
 Your task is to code up and run the randomized contraction algorithm for the min cut problem and use it on the above
 graph to compute the min cut. (HINT: Note that you'll have to figure out an implementation of edge contractions.
 Initially, you might want to do this naively, creating a new graph from the old every time there's an edge contraction.
 But you should also think about more efficient implementations.) (WARNING: As per the video lectures, please make sure
 to run the algorithm many times with different random seeds, and remember the smallest cut that you ever find.)
 rite your numeric answer in the space provided. So e.g., if your answer is 5, just type 5 in the space provided.
*/

using namespace min_cut;
TEST(min_cut, test_lambda) {
    std::vector<Node> vec{Node(1),Node(2),Node(3),Node(4),Node(5),Node(6)};
    int target(4);
    auto it = std::find_if(vec.begin(), vec.end(), [&](const Node &node) { return node.getId() == target; });
    std::cout << "found [" << *it << "]" << std::endl;
}

TEST(min_cut, test_remove_if) {
    Node node(1);
    node.addAdj(2);
    node.addAdj(2);
    node.addAdj(3);
    node.addAdj(3);
    node.addAdj(4);
    node.addAdj(4);
    node.removeAdj(3);
    EXPECT_EQ(node.adjs(), std::vector<int>({2, 2, 4, 4}));
}

TEST(min_cut, test_mergeAdj) {
    Node node1(1);
    node1.addAdj(2);
    node1.addAdj(3);
    node1.addAdj(4);
    EXPECT_EQ(node1.adjs(), std::vector<int>({2, 3, 4}));
    Node node2 = node1;
    Node newNode(3);
    newNode.mergeAdjs(node1);
    EXPECT_EQ(newNode.adjs(), std::vector<int>({2, 3, 4}));
    newNode.mergeAdjs(node2);
    EXPECT_EQ(newNode.adjs(), std::vector<int>({2, 3, 4, 2, 3, 4}));
}

TEST(min_cut, test_replaceAdj) {
    Node node1(1);
    node1.addAdj(2);
    node1.addAdj(2);
    node1.addAdj(3);
    node1.addAdj(3);
    node1.addAdj(4);
    node1.addAdj(4);
    node1.replaceAdj(3,5);
    EXPECT_EQ(node1.adjs(), std::vector<int>({2, 2, 5, 5, 4, 4}));
}

TEST(min_cut, coursera_case) {
    AdjList list("../../Google_tests/KargerMinCut.txt");
    // std::cout << list << std::endl;
    std::cout << "has parallel edges [" << list.hasParallelEdges() << "]" << std::endl;

    int minMinCut = std::numeric_limits<int>::max();
    for (int i = 1; i <= 1000; ++i) {
        int minCut = list.minCut();
        std::cout << "iteration [" << i << "] min_cut [" << minCut << "]" << std::endl;
        if (minCut < minMinCut) {
            minMinCut = minCut;
        }
    }
    std::cout << "Final min(minCut) [" << minMinCut << "]" << std::endl;
}
