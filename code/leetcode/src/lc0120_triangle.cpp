/*
 * Time : 2025-06-24 11:50:45
 * URL  : https://leetcode.cn/problems/triangle/description/?envType=problem-list-v2&envId=dynamic-programming
 */
#include "lc0120_triangle.h"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <vector>

using namespace std;

int LC0120_Triangle::minimumTotal(std::vector<std::vector<int>> &triangle)
{
    vector<int32_t> dp(triangle.back().size() + 1, 0);

    for (size_t i = triangle.size(); i > 0; --i) {
        const auto &line = triangle[i - 1];
        for (size_t j = 0; j < line.size(); ++j) {
            dp[j] = min(dp[j], dp[j + 1]) + line[j];
        }
    }

    return dp[0];
}
