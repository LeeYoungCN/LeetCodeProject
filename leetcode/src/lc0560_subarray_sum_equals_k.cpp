/*
 * Time : 2025-06-12 18:03:55
 * URL  : https://leetcode.cn/problems/subarray-sum-equals-k/description/?envType=problem-list-v2URL_STRenvId=prefix-sum
 */
#include "lc0560_subarray_sum_equals_k.h"

#include <cstdint>
#include <unordered_map>
#include <vector>

using namespace std;

int LC0560_SubarraySumEqualsK::subarraySum(vector<int>& nums, int k)
{
    unordered_map<int32_t, int32_t> prefixSums;
    prefixSums[0] = 1;

    int32_t prefixSum = 0;
    int32_t ans = 0;
    for (auto n : nums) {
        prefixSum += n;

        int32_t delta = prefixSum - k;

        if (prefixSums.find(delta) != prefixSums.end()) {
            ans += prefixSums[delta];
        }
        prefixSums[prefixSum]++;
    }

    return ans;
}
