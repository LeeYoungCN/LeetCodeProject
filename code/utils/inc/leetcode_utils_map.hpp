#ifndef LEETCODE_UTILS_MAP_HPP
#define LEETCODE_UTILS_MAP_HPP

#include <cstdint>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

template <class K = int32_t, class V = int32_t, class cmp = std::less<K>>
std::string Map2String(std::map<K, V, cmp> map)
{
    if (map.empty()) {
        return "{}";
    }

    std::string str;
    for (const auto &[key, val] : map) {
        if constexpr (std::is_same<K, char>::value) {
            str += "[" + key + " : " + std::to_string(val) + "], ";
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

#endif  // LEETCODE_UTILS_MAP_HPP
