/*
 * Time : 2025-06-24 11:06:59
 * URL  : https://leetcode.cn/problems/pascals-triangle/?envType=problem-list-v2&envId=dynamic-programming
 */
#include "lc0118_pascals_triangle.h"

#include <cstdint>
#include <vector>

using namespace std;

std::vector<std::vector<int>> LC0118_PascalsTriangle::generate(int numRows)
{
    const auto rowCnt = static_cast<uint32_t>(numRows);
    vector<vector<int32_t>> ans(rowCnt);

    for (uint32_t i = 0; i < rowCnt; ++i) {
        ans[i] = vector(i + 1, 0);
        for (uint32_t j = 0; j <= i; ++j) {
            if (j == 0 || j == i) {
                ans[i][j] = 1;
            } else {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
        }
    }

    return ans;
}
