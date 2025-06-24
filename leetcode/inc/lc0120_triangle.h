/*
 * Time : 2025-06-24 11:50:45
 * URL  : https://leetcode.cn/problems/triangle/description/?envType=problem-list-v2&envId=dynamic-programming
 */
#ifndef LC0120_TRIANGLE_H
#define LC0120_TRIANGLE_H

#include <vector>

class LC0120_Triangle {
public:
    LC0120_Triangle() = default;
    virtual ~LC0120_Triangle() = default;
    int minimumTotal(std::vector<std::vector<int>>& triangle);
};

#endif  // LC0120_TRIANGLE_H
