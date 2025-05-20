/*
 * Time : 2025-05-20 17:47:22
 * URL  : https://leetcode.cn/problems/maximum-sum-circular-subarray/description/
 */

#include <cstdint>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include "lc0918_maximum_sum_circular_subarray.h"
#include <cstdio>

using namespace std;

namespace method1 {
int LC0918_MaximumSumCircularSubarray::maxSubarraySumCircular(std::vector<int>& nums)
{
    int32_t maxSum = nums[0];
    int32_t minSum = nums[0];
    int32_t total = 0;
    int32_t preMax = 0;
    int32_t preMin = 0;

    for (int32_t n : nums) {
        preMax = max(preMax + n, n);
        preMin = min(preMin + n, n);
        maxSum = max(preMax, maxSum);
        minSum = min(preMin, minSum);
        total += n; 
    }
    return (maxSum < 0 ? maxSum : max(maxSum, total - minSum));
}
}
