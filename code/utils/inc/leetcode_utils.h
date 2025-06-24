#ifndef LEETCODE_UTILS_H
#define LEETCODE_UTILS_H

#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <vector>

#define LOG(fmt, ...)                                        \
    do {                                                     \
        printf("[%s:%d %s] ", __FILE__, __LINE__, __func__); \
        printf(fmt, __VA_ARGS__);                            \
        printf("\n");                                        \
    } while (0);

template <class T = int32_t>
std::string Vector2String(const std::vector<T> &vec, uint32_t start = 0, uint32_t end = 0, bool hasIdx = true)
{
    if (end == 0) {
        end = static_cast<uint32_t>(vec.size());
    }
    end = std::min(end, static_cast<uint32_t>(vec.size()));
    if (start >= end) {
        LOG("Invalid param. start=%u, end=%u.", start, end);
        return "";
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
            str += &val;
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

template <class K = int32_t, class V = int32_t, class cmp = std::less<K>>
std::string Map2String(std::map<K, V, cmp> map)
{
    std::string str;
    for (const auto &[key, val] : map) {
        if constexpr (std::is_same<K, char>::value) {
            str += "[" + &key + " : " + std::to_string(val) + "], ";
        } else {
            str += "[" + std::to_string(key) + " : " + std::to_string(val) + "], ";
        }
    }
    str.pop_back();
    str.pop_back();
    return str;
}

template <class K, class V>
std::string Map2String(std::unordered_map<K, V> map)
{
    std::string str;
    for (const auto &[key, val] : map) {
        if (std::is_same<K, char>::value) {
            str += "[" + &key + " : " + std::to_string(val) + "], ";
        } else {
            str += "[" + std::to_string(key) + " : " + std::to_string(val) + "], ";
        }
    }
    str.pop_back();
    str.pop_back();
    return str;
}

template <class K = int32_t, class V = int32_t, class cmp = std::less<K>>
void PrintMap(std::map<K, V, cmp> map)
{
    std::cout << Map2String(map) << std::endl;
}

template <class K, class V>
void PrintMap(std::map<K, V> map)
{
    std::cout << Map2String(map) << std::endl;
}

class UtilsDebug {
public:
    UtilsDebug() = default;
    virtual ~UtilsDebug() = default;

    virtual std::string toString() = 0;
};

void PrintVector(const std::vector<UtilsDebug *> &vec, uint32_t start = 0, uint32_t end = 0, bool hasIdx = true);
std::string Vector2String(const std::vector<UtilsDebug *> &vec, uint32_t start = 0, uint32_t end = 0,
                          bool hasIdx = true);

#endif  // LEETCODE_UTILS_H
