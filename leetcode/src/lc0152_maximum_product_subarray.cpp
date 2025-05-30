/*
 * Time    : 2025-05-20 15:14:30
 * URL     : https://leetcode.cn/problems/maximum-product-subarray/
 * Problem : 给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续
 * 子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。 测试用例的答案是一个 32-位 整数。
 */
#include "lc0152_maximum_product_subarray.h"

#include <algorithm>
#include <cstdint>
#include <vector>

using namespace std;

int LC00152_MaximumProductSubarray::maxProduct(vector<int>& nums)
{
    int ret = nums[0];
    uint32_t len = (uint32_t)nums.size();
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
