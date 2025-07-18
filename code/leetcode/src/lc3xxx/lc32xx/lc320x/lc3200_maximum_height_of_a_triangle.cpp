/*
 * Time : 2025-07-17 16:47:02
 * URL  : https://leetcode.cn/problems/maximum-height-of-a-triangle/
 */
#include "lc3xxx/lc32xx/lc320x/lc3200_maximum_height_of_a_triangle.h"

#include <algorithm>
#include <cstdint>
#include <vector>

using namespace std;

int32_t GetHeight(int32_t red, int32_t blue)
{
    vector<int32_t> colorCnt{red, blue};

    uint32_t idx = 0;
    int32_t ans = 0;
    for (; colorCnt[idx] >= ans; ++ans) {
        colorCnt[idx] -= ans;
        idx = 1 - idx;
    }
    return ans - 1;
}

int32_t LC3200_MaximumHeightOfATriangle::maxHeightOfTriangle(int32_t red, int32_t blue)
{
    return max(GetHeight(red, blue), GetHeight(blue, red));
}
