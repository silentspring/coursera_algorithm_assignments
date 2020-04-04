//
// Created by yhzhan on 3/23/2020.
//

#include "min_cut.h"
#include <set>
#include <sstream>

namespace min_cut {
    bool Node::operator<(const Node &other) const
    {
        return m_id < other.m_id;
    }
    AdjList::AdjList(const std::string &file) {
        std::ifstream ifs(file);
        std::string line;
        int i = 0;
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
                    firstMet = true;
                } else {
                    node.addAdj(id);
                }
            }
            m_nodes.push_back(node);
        }
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
    std::ostream &operator<<(std::ostream &os, const Node &node) {
        os << "Node [" << node.getId() << "] Adjs [";
        for (auto it = node.m_adj.begin(); it != node.m_adj.end(); ++it) {
            os << *it;
            if (std::next(it) != node.m_adj.end()) {
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
