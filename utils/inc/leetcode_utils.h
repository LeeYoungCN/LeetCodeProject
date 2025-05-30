#ifndef LEETCODE_UTILS_H
#define LEETCODE_UTILS_H

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::vector<uint32_t>> GetGraphByEdges(const std::vector<std::vector<int32_t>> &edges);

template <class NUMBER>
std::string Vector2String(const std::vector<NUMBER> &vec, uint32_t start = 0, uint32_t end = 0, bool hasIdx = true)
{
    if (end == 0) {
        end = (uint32_t)vec.size();
    }

    const uint32_t length = end - start;
    std::string str = "{";

    for (uint32_t i = 0; i < length; i++) {
        uint32_t index = i + start;

        if (hasIdx) {
            str += "[" + std::to_string(index) + "]=";
        }

        str += std::to_string(vec[i]);
        if (i < length - 1) {
            str += ", ";
        }
    }
    str += "}";
    return str;
}

template <class NUMBER>
void PrintVector(const std::vector<NUMBER> &vec, uint32_t start = 0, uint32_t end = 0, bool hasIdx = true)
{
    std::cout << Vector2String(vec, start, end, hasIdx) << std::endl;
}

class UtilsDegbug {
public:
    virtual std::string ToString() = 0;
};

void PrintVector(const std::vector<UtilsDegbug *> &vec, uint32_t start = 0, uint32_t end = 0, bool hasIdx = true);
std::string Vector2String(const std::vector<UtilsDegbug *> &vec, uint32_t start = 0, uint32_t end = 0,
                          bool hasIdx = true);

#endif  // LEETCODE_UTILS_H
