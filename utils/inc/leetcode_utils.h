#ifndef LEETCODE_UTILS_H
#define LEETCODE_UTILS_H

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <vector>

template <class T>
std::string Vector2String(const std::vector<T> &vec, uint32_t start = 0, uint32_t end = 0, bool hasIdx = true)
{
    if (end == 0) {
        end = static_cast<uint32_t>(vec.size());
    }
    end = std::min(end, static_cast<uint32_t>(vec.size()));

    const uint32_t length = end - start;
    std::string str = "{";

    for (uint32_t i = 0; i < length; i++) {
        uint32_t index = i + start;

        if (hasIdx) {
            str += "[" + std::to_string(index) + "]=";
        }

        str += std::to_string(vec[index]);
        if (i < length - 1) {
            str += ", ";
        }
    }
    str += "}";
    return str;
}

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
