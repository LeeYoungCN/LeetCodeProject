#ifndef LEETCODE_UTILS_VECTOR_HPP
#define LEETCODE_UTILS_VECTOR_HPP

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

#include "leetcode_utils_common.hpp"

template <class T = int32_t>
std::string Vector2String(const std::vector<T> &vec, uint32_t start = 0, uint32_t end = 0, bool hasIdx = true)
{
    if (vec.empty()) {
        return "{}";
    }
    if (end == 0) {
        end = static_cast<uint32_t>(vec.size());
    }
    end = std::min(end, static_cast<uint32_t>(vec.size()));
    if (start >= end) {
        LOG("Invalid param. start=%u, end=%u.", start, end);
        return "{}";
    }
    const uint32_t length = end - start;
    std::string str = "{";

    for (uint32_t i = 0; i < length; i++) {
        uint32_t index = i + start;

        if (hasIdx) {
            str += "[" + std::to_string(index) + "]=";
        }

        T val = vec[index];
        if constexpr (std::is_same<T, char>::value) {
            str += val;
        } else {
            str += std::to_string(val);
        }
        if (i < length - 1) {
            str += ", ";
        }
    }
    str += "}";
    return str;
}

std::string Vector2String(const std::vector<std::string> &vec, uint32_t start = 0, uint32_t end = 0,
                          bool hasIdx = true);

template <class T>
void PrintVector(const std::vector<T> &vec, uint32_t start = 0, uint32_t end = 0, bool hasIdx = true)
{
    std::cout << Vector2String(vec, start, end, hasIdx) << std::endl;
}

#endif  // LEETCODE_UTILS_VECTOR_HPP
