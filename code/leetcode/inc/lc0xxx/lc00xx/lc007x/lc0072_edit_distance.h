/*
 * Time : 2025-06-20 22:43:05
 * URL  : https://leetcode.cn/problems/edit-distance/description/?envType=problem-list-v2&envId=dynamic-programming
 */
#ifndef LC0072_EDIT_DISTANCE_H
#define LC0072_EDIT_DISTANCE_H

#include <string>

class LC0072_EditDistance {
public:
    LC0072_EditDistance() = default;
    virtual ~LC0072_EditDistance() = default;
    int minDistance(std::string word1, std::string word2);
};

#endif  // LC0072_EDIT_DISTANCE_H
