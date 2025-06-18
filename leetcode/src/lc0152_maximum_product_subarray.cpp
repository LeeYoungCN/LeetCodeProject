/*
 * Time : 2025-05-20 15:14:30
 * URL  : https://leetcode.cn/problems/maximum-product-subarray/
 */
#include "lc0152_maximum_product_subarray.h"

#include <algorithm>
#include <cstdint>
#include <vector>

using namespace std;

int LC00152_MaximumProductSubarray::maxProduct(vector<int>& nums)
{
    int ret = nums[0];
    auto len = static_cast<uint32_t>(nums.size());
    vector<int32_t> dpMax(len);
    vector<int32_t> dpMin(len);

    for (uint32_t i = 0; i < len; ++i) {
        int32_t n = nums[i];
        if (i == 0) {
            dpMax[i] = dpMin[i] = n;
        } else {
            dpMax[i] = max(n, max(dpMax[i - 1] * n, dpMin[i - 1] * n));
            dpMin[i] = min(n, min(dpMax[i - 1] * n, dpMin[i - 1] * n));
        }
        ret = max(dpMax[i], ret);
    }
    return ret;
}
