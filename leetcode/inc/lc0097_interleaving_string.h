/*
 * Time : 2025-06-23 21:08:36
 * URL  :
 * https://leetcode.cn/problems/interleaving-string/description/?envType=problem-list-v2&envId=dynamic-programming
 */
#ifndef LC0097_INTERLEAVING_STRING_H
#define LC0097_INTERLEAVING_STRING_H

#include <string>

class LC0097_InterleavingString {
public:
    LC0097_InterleavingString() = default;
    virtual ~LC0097_InterleavingString() = default;
    bool isInterleave(std::string s1, std::string s2, std::string s3);
};

#endif  // LC0097_INTERLEAVING_STRING_H
