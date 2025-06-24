/*
 * Time : 2025-06-24 11:06:59
 * URL  : https://leetcode.cn/problems/pascals-triangle/?envType=problem-list-v2&envId=dynamic-programming
 */
#ifndef LC0118_PASCALS_TRIANGLE_H
#define LC0118_PASCALS_TRIANGLE_H

#include <vector>

class LC0118_PascalsTriangle {
public:
    LC0118_PascalsTriangle() = default;
    virtual ~LC0118_PascalsTriangle() = default;
    std::vector<std::vector<int>> generate(int numRows);
};

#endif  // LC0118_PASCALS_TRIANGLE_H
