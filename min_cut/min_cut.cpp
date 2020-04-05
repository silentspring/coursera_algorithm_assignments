//
// Created by yhzhan on 3/23/2020.
//

#include "min_cut.h"
#include <algorithm>
#include <set>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <assert.h>

namespace min_cut {
    bool Node::operator<(const Node &other) const
    {
        return m_id < other.m_id;
    }
    bool Node::operator==(const Node &other) const
    {
        return m_id == other.m_id;
    }
    void Node::replaceAdj(int oldAdj, int newAdj)
    {
        for (auto &adj : m_adjs) {
            if (adj == oldAdj) {
                adj = newAdj;
            }
        }
    }
    void Node::mergeAdjs(const Node &other)
    {
        for (const auto &adj : other.adjs()) {
            m_adjs.push_back(adj);
        }
    }

    void Node::removeAdj(int id)
    {
        auto itEnd = std::remove_if(m_adjs.begin(), m_adjs.end(), [&](const int &adj) { return adj == id; });
        m_adjs = std::vector<int>(m_adjs.begin(), itEnd);
    }

    AdjList::AdjList(const std::string &file) {
        std::ifstream ifs(file);
        std::string line;
        int i = 0;
        int maxNodeId = std::numeric_limits<int>::min();
        while (std::getline(ifs, line)) {
            std::stringstream ss(line);
            std::string token;
            bool firstMet = false;
            Node node;
            while (std::getline(ss, token, '\t')) {
                if (token == "\r") { break; }
                int id = std::stoi(token);
                if (!firstMet) {
                    node.setId(id);
                    if (id > maxNodeId) {
                        maxNodeId = id;
                    }
                    firstMet = true;
                } else {
                    node.addAdj(id);
                }
            }
            m_nodes.push_back(node);
        }
        m_newNodeId = maxNodeId;
        m_nodesBackup = m_nodes;
    }

    bool AdjList::hasParallelEdges() {
        for (const auto &node : m_nodes) {
             std::set<Node> s;
             if (!s.insert(node).second) {
                 return true;
             }
        }
        return false;
    }

    int AdjList::minCut()
    {
        m_nodes = m_nodesBackup;
        std::ofstream ofs("debug.txt");
        int iteration = 0;
        std::srand(std::time(0));
        while (true) {
            ++iteration;
            ofs << "**************" << std::endl;
            ofs << "iteration [" << iteration << "]" << std::endl;
            size_t sz = m_nodes.size();
            if (sz <= 2) {
                break;
            }
            auto itNode = m_nodes.begin() + (std::rand()%sz);
            auto &node = *itNode;
            int nodeId = node.getId();
            size_t szAdjs = node.adjCount();
            int idxAdj = std::rand() % szAdjs;
            if (idxAdj >= node.adjs().size()) {
                ofs << "idxAdj [" << idxAdj << "] size [" << node.adjs().size() << "]" << std::endl;
                abort();
            }
            int adjId = node.getAdj(idxAdj);
            auto itAdjNode = std::find_if(m_nodes.begin(), m_nodes.end(), [&](const Node &node) { return node.getId() == adjId; });
            if (itAdjNode == m_nodes.end()) {
                ofs << "could not find node [" << adjId << "] from node list" << std::endl;
                abort();
            }
            if (adjId != itAdjNode->getId()) {
                ofs << "adjId [" << adjId << "] itAdjNode->getId() [" << itAdjNode->getId() << "]" << std::endl;
                abort();
            }
            auto &adjNode = (*itAdjNode);
            Node newNode(newNodeId());
            int newNodeId = newNode.getId();

            // remove the inter-reference between the two nodes to be merged
            node.removeAdj(nodeId);
            node.removeAdj(adjId);
            adjNode.removeAdj(nodeId);
            adjNode.removeAdj(adjId);
            // merge the two nodes into new node
            newNode.mergeAdjs(node);
            newNode.mergeAdjs(adjNode);
            // remove the two nodes
            ofs << "removing node [" << itNode->getId() << ", " << nodeId << "]" << std::endl;
            ofs << "removing adjNode [" << itAdjNode->getId() << ", " << adjId << "]" << std::endl;
            m_nodes.erase(itNode);
            // refresh the itAdjNode since the above erase will invalidate the iterator
            itAdjNode = std::find_if(m_nodes.begin(), m_nodes.end(), [&](const Node &node) { return node.getId() == adjId; });
            m_nodes.erase(itAdjNode);
            // replace the reference to the two nodes with the reference to the new node
            for (auto &node : m_nodes) {
                node.replaceAdj(nodeId, newNodeId);
                node.replaceAdj(adjId, newNodeId);
            }
            m_nodes.push_back(newNode);
            ofs << "m_nodes new node [" << newNode.getId() << "] inserted" << std::endl;

            ofs << "********" << std::endl;
            ofs << (*this) << std::endl;
        }

        if (m_nodes.size() < 2) {
            return 0;
        }
        // get the edges left by the two remaining nodes
        const auto &node1 = m_nodes[0];
        const auto &node2 = m_nodes[1];
        size_t edges1 = node1.adjs().size();
        size_t edges2 = node2.adjs().size();
        if (edges1 != edges2) {
            abort();
        }
        return edges1;
    }

    std::ostream &operator<<(std::ostream &os, const Node &node) {
        os << "Node [" << node.getId() << "] Adjs [";
        for (auto it = node.m_adjs.begin(); it != node.m_adjs.end(); ++it) {
            os << *it;
            if (std::next(it) != node.m_adjs.end()) {
                os << ",";
            }
        }
        os << "]" << std::endl;
        return os;
    }
    std::ostream &operator<<(std::ostream &os, const AdjList &list) {
        for (const auto &node : list.m_nodes) {
            os << node << std::endl;
        }
        return os;
    }
}
