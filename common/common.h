//
// Created by yhzhan on 3/4/2020.
//

#ifndef ASSIGNMENTS_COMMON_H
#define ASSIGNMENTS_COMMON_H

#include <string>
#include <vector>
#include <exception>
#include <stdexcept>
#include <iostream>
#include <chrono>

class Duration {
public:
    explicit Duration(const std::string &name) : m_name(name) {}
    ~Duration() {
        std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
        auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now - m_start);
        std::cout << "Duration [" << m_name << "] [" << milliseconds.count()/1000 << "." << milliseconds.count()%1000 << "]" << std::endl;
    }
private:
    std::chrono::time_point<std::chrono::system_clock> m_start = std::chrono::system_clock::now();
    std::string m_name;
};

#endif //ASSIGNMENTS_COMMON_H
