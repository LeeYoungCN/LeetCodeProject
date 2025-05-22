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
#include <deque>
#include "lc0918_maximum_sum_circular_subarray.h"
#include <cstdio>

using namespace std;

int LC0918_MaximumSumCircularSubarray_DP::maxSubarraySumCircular(std::vector<int>& nums)
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

typedef struct {
    uint32_t index;
    int32_t  sum;
} PreSumSt;

int LC0918_MaximumSumCircularSubarray_Stack::maxSubarraySumCircular(std::vector<int>& nums)
{
    const uint32_t length = nums.size();
    PreSumSt preSum = {0, 0};
    deque<PreSumSt> sumStack;

    int32_t ret = nums[0];
    for (uint32_t i = 0; i < 2 * length; i++) {
        while (!sumStack.empty() && i - sumStack.front().index > length) {
            sumStack.pop_front();
        }
        preSum.index = i;
        preSum.sum += nums[i % length];

        if (sumStack.empty()) {
            ret = max(ret, preSum.sum);
        } else {
            ret = max(ret, preSum.sum - sumStack.front().sum);
        }
        
        while(!sumStack.empty() && sumStack.back().sum >= preSum.sum) {
            sumStack.pop_back();
        }
        sumStack.push_back(preSum);
    }
    return ret;
}