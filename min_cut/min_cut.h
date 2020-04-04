//
// Created by yhzhan on 3/23/2020.
//

#ifndef MIN_CUT_H
#define MIN_CUT_H

#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>

namespace min_cut {
    class Node {
    public:
        void setId(int id) { m_id = id; }
        void addAdj(int i) { m_adj.push_back(i); }
        int getId() const { return m_id; }
        bool operator<(const Node &other) const;
    private:
        int m_id = 0;
        std::vector<int> m_adj;
        friend std::ostream &operator<<(std::ostream &os, const Node &node);
    };

    std::ostream &operator<<(std::ostream &os, const Node &node);

    class AdjList {
    public:
        AdjList(const std::string &file);
        bool hasParallelEdges();
    private:
    friend std::ostream &operator<<(std::ostream &os, const AdjList &list);
    private:
        std::vector<Node> m_nodes;
    };
    std::ostream &operator<<(std::ostream &os, const AdjList &list);
}
#endif