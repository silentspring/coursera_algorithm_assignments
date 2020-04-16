//
// Created by yhzhan on 4/12/2020.
//

#ifndef ASSIGNMENTS_MIN_STACK_H
#define ASSIGNMENTS_MIN_STACK_H

#include <vector>
#include <limits>
/*
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 *  */
namespace {
    class Node {
    public:
        Node(int value) : m_value(value) {}
        int value() { return m_value; }
        Node *next() { return m_next; }
        Node *prev() { return m_prev; }
        void setNext(Node *next) { m_next = next; }
        void setPrev(Node *prev) { m_prev = prev; }
    private:
        int m_value = 0;
        Node *m_next = nullptr;
        Node *m_prev = nullptr;
    };
    class MinStack {
    public:
        /** initialize your data structure here. */
        MinStack() {
        }

        void push(int x) {
            auto node = new Node(x);
            m_vec.push_back(node);
            insertNodeIntoOrderList(node);
        }

        void insertNodeIntoOrderList(Node *node) {
            if (!node) { return; }
            if (!m_minNode) {
                m_minNode = node;
            } else {
                auto currNode = m_minNode;
                while (currNode) {
                    if (currNode->value() < node->value()) {
                        if (!currNode->next()) {
                            currNode->setNext(node);
                            node->setPrev(currNode);
                            break;
                        }
                        currNode = currNode->next();
                        continue;
                    }
                    auto prevNode = currNode->prev();
                    if (!prevNode) {
                        currNode->setPrev(node);
                        node->setNext(currNode);
                        m_minNode = node;
                        break;
                    } else {
                        prevNode->setNext(node);
                        currNode->setPrev(node);
                        node->setPrev(prevNode);
                        node->setNext(currNode);
                        break;
                    }
                }
            }
        }
        void pop() {
            if (m_vec.begin() == m_vec.end()) { return; }
            auto lastIt = std::prev(m_vec.end());
            removeFromOrderedList(*lastIt);
            m_vec.erase(lastIt);
        }

        void removeFromOrderedList(Node *node)
        {
            if (!node) {
                return;
            }
            if (!node->prev()) {
                m_minNode = node->next();
                if (m_minNode) {
                    m_minNode->setPrev(nullptr);
                }
            } else if (!node->next()) {
                node->prev()->setNext(nullptr);
            } else {
                auto prevNode = node->prev();
                auto nextNode = node->next();
                prevNode->setNext(nextNode);
                nextNode->setPrev(prevNode);
            }
        }

        int top() {
            if (m_vec.begin() == m_vec.end()) { return std::numeric_limits<int>::min(); }
            return (*(std::prev(m_vec.end())))->value();
        }

        int getMin() {
            if (!m_minNode) {
                return std::numeric_limits<int>::min();
            }
            return m_minNode->value();
        }

    private:
        std::vector<Node *> m_vec;
        Node *m_minNode = nullptr;
    };
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
#endif //ASSIGNMENTS_MIN_STACK_H
