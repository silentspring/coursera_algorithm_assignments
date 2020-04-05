//
// Created by yhzhan on 3/23/2020.
//

#ifndef MIN_CUT_H
#define MIN_CUT_H

#include <fstream>
#include <iostream>
#include <limits>
#include <ostream>
#include <vector>

namespace min_cut {
    class Node {
    public:
        Node(int id) : m_id(id) {}
        Node() {}
        void setId(int id) { m_id = id; }
        void addAdj(int i) { m_adjs.push_back(i); }
        void removeAdj(int i);
        int getId() const { return m_id; }
        int getAdj(int i) const { return m_adjs[i]; }
        size_t adjCount() const { return m_adjs.size(); }
        void replaceAdj(int oldAdj, int newAdj);
        void mergeAdjs(const Node &other);
        const std::vector<int> adjs() const { return m_adjs; }
        bool operator<(const Node &other) const;
        bool operator==(const Node &other) const;
    private:
        int m_id = 0;
        std::vector<int> m_adjs;
        friend std::ostream &operator<<(std::ostream &os, const Node &node);
    };

    std::ostream &operator<<(std::ostream &os, const Node &node);

    class AdjList {
    public:
        AdjList(const std::string &file);
        bool hasParallelEdges();
        int minCut();
        int newNodeId() { return ++m_newNodeId; }
    private:
    friend std::ostream &operator<<(std::ostream &os, const AdjList &list);
    private:
        std::vector<Node> m_nodes;
        std::vector<Node> m_nodesBackup;
        int m_newNodeId = 0;
    };
    std::ostream &operator<<(std::ostream &os, const AdjList &list);
}
#endif