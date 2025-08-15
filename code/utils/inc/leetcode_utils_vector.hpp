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
std::string Vector2String(const std::vector<T> &vec, uint32_t start = 0, uint32_t end = 0, bool hasIdx = false)
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
                          bool hasIdx = false);

template <class T>
void PrintVector(const std::vector<T> &vec, uint32_t start = 0, uint32_t end = 0, bool hasIdx = false)
{
    std::cout << Vector2String(vec, start, end, hasIdx) << std::endl;
}

template <class T = int32_t>
std::string Matrix2String(const std::vector<std::vector<T>> &matrix, uint32_t start = 0, uint32_t end = 0,
                          bool hasIdx = false)
{
    if (matrix.empty()) {
        return "{}";
    }
    if (end == 0) {
        end = static_cast<uint32_t>(matrix.size());
    }
    end = std::min(end, static_cast<uint32_t>(matrix.size()));
    if (start >= end) {
        LOG("Invalid param. start=%u, end=%u.", start, end);
        return "{}";
    }

    const uint32_t vecNum = end - start;
    std::string str = "{\n";

    for (uint32_t i = 0; i < vecNum; i++) {
        uint32_t index = i + start;

        if (hasIdx) {
            str += "[" + std::to_string(index) + "]=";
        }

        str += Vector2String(matrix[index], 0, 0, hasIdx);
        str += "\n";
    }
    str += "}";
    return str;
}

template <class T>
void PrintMatrix(const std::vector<std::vector<T>> &matrix, uint32_t start = 0, uint32_t end = 0, bool hasIdx = false)
{
    std::cout << Matrix2String(matrix, start, end, hasIdx) << std::endl;
}

std::vector<std::string> CreateStringVector(const std::string &str);
std::vector<int32_t> CreateIntVector(const std::string &str);
std::vector<std::vector<int32_t>> CreateIntMatrix(const std::string &str);

#endif  // LEETCODE_UTILS_VECTOR_HPP
