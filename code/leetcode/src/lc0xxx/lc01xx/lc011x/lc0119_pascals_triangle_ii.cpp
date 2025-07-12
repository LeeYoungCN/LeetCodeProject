/*
 * Time : 2025-06-24 11:31:51
 * URL  : https://leetcode.cn/problems/pascals-triangle-ii/?envType=problem-list-v2&envId=dynamic-programming
 */
#include "lc0xxx/lc01xx/lc011x/lc0119_pascals_triangle_ii.h"

#include <cstdint>
#include <vector>

using namespace std;

std::vector<int> LC0119_PascalsTriangleII::getRow(int rowIndex)
{
    const auto rowCnt = static_cast<uint32_t>(rowIndex) + 1;
    uint32_t curr = 0;
    uint32_t prev = 1;
    vector<vector<int32_t>> ans(2, vector<int32_t>(rowCnt, 0));

    for (uint32_t i = 0; i < rowCnt; ++i) {
        curr = 1 - curr;
        prev = 1 - prev;
        for (uint32_t j = 0; j <= i; ++j) {
            if (j == 0 || j == i) {
                ans[curr][j] = 1;
            } else {
                ans[curr][j] = ans[prev][j - 1] + ans[prev][j];
            }
        }
    }
    return ans[curr];
}
