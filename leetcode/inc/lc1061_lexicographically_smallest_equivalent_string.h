/*
 * Time : 2025-06-05 19:17:03
 * URL  :
 * https://leetcode.cn/problems/lexicographically-smallest-equivalent-string/?envType=daily-questionURL_STRenvId=2025-06-05
 */
#ifndef LC1061_LEXICOGRAPHICALLY_SMALLEST_EQUIVALENT_STRING_H
#define LC1061_LEXICOGRAPHICALLY_SMALLEST_EQUIVALENT_STRING_H

#include <cstdint>
#include <string>
#include <vector>

class UnionFind {
public:
    explicit UnionFind(uint32_t size);
    UnionFind() = default;
    ~UnionFind() = default;
    uint32_t Find(uint32_t x);
    void Union(uint32_t x, uint32_t y);

private:
    std::vector<uint32_t> pa;
};

class LC1061_LexicographicallySmallestEquivalentString {
public:
    LC1061_LexicographicallySmallestEquivalentString() = default;
    virtual ~LC1061_LexicographicallySmallestEquivalentString() = default;
    std::string smallestEquivalentString(std::string s1, std::string s2, std::string baseStr);
};

#endif  // LC1061_LEXICOGRAPHICALLY_SMALLEST_EQUIVALENT_STRING_H
