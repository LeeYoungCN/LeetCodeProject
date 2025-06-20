/*
 * Time : 2025-06-20 22:02:04
 * URL  : https://leetcode.cn/problems/unique-paths-ii/description/?envType=problem-list-v2&envId=dynamic-programming
 */
#ifndef LC0063_UNIQUE_PATHS_II_H
#define LC0063_UNIQUE_PATHS_II_H

#include <vector>

class LC0063_UniquePathsII {
public:
    LC0063_UniquePathsII() = default;
    virtual ~LC0063_UniquePathsII() = default;
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid);
};

#endif  // LC0063_UNIQUE_PATHS_II_H
