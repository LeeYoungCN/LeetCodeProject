/*
 * Time : 2025-06-12 10:12:40
 * URL  :
 * https://leetcode.cn/problems/minimum-size-subarray-sum/description/?envType=problem-list-v2URL_STRenvId=prefix-sum
 */
#include "lc0209_minimum_size_subarray_sum.h"

#include <algorithm>
#include <cstdint>
#include <vector>

using namespace std;

uint32_t LC0209_MinimumSizeSubarraySum_MyLowerBound::FindLastLessEqual(const vector<int32_t> prefixSums, int32_t num)
{
    uint32_t left = 0;
    uint32_t right = (uint32_t)prefixSums.size();
    uint32_t result = UINT32_MAX;

    while (left < right) {
        uint32_t curr = (left + right) / 2;
        int32_t currNum = prefixSums[curr];

        if (currNum <= num) {
            result = curr;
            left = curr + 1;
        } else {
            right = curr;
        }
    }

    return result;
}

int LC0209_MinimumSizeSubarraySum_MyLowerBound::minSubArrayLen(int target, vector<int>& nums)
{
    const uint32_t length = (uint32_t)nums.size();
    vector<int32_t> prefixSums;
    prefixSums.reserve(length + 1);
    prefixSums.push_back(0);

    uint32_t ans = UINT32_MAX;
    for (uint32_t i = 0; i < length; ++i) {
        prefixSums.push_back(prefixSums.back() + nums[i]);
        int32_t delta = prefixSums.back() - target;

        if (delta < 0) {
            continue;
        }

        uint32_t idx = FindLastLessEqual(prefixSums, delta);
        if (idx != UINT32_MAX) {
            ans = min(i - idx + 1, ans);
        }
    }

    return (ans == UINT32_MAX ? 0 : (int32_t)ans);
}

int LC0209_MinimumSizeSubarraySum_StdLowerBound::minSubArrayLen(int target, vector<int>& nums)
{
    const uint32_t length = (uint32_t)nums.size();
    vector<int32_t> prefixSums;
    prefixSums.reserve(length + 1);
    prefixSums.push_back(0);

    uint32_t ans = UINT32_MAX;
    for (uint32_t i = 0; i < length; ++i) {
        prefixSums.push_back(prefixSums.back() + nums[i]);
        int32_t delta = prefixSums.back() - target;

        if (delta < 0) {
            continue;
        }

        auto itr = lower_bound(prefixSums.begin(), prefixSums.end(), delta);

        if (itr != prefixSums.end()) {
            uint32_t idx = (uint32_t)(itr - prefixSums.begin());
            if (prefixSums[idx] != delta) {
                idx--;
            }
            ans = min(i - idx + 1, ans);
        }
    }

    return (ans == UINT32_MAX ? 0 : (int32_t)ans);
}

int LC0209_MinimumSizeSubarraySum_Loop::minSubArrayLen(int target, vector<int>& nums)
{
    const uint32_t length = (uint32_t)nums.size();
    uint32_t ans = UINT32_MAX;
    for (uint32_t i = 0; i < length; i++) {
        int32_t sum = 0;
        for (uint32_t j = i; j < length; j++) {
            sum += nums[j];
            if (sum >= target) {
                ans = min(ans, j - i + 1);
            }
        }
    }
    return (ans == UINT32_MAX ? 0 : (int32_t)ans);
}

int LC0209_MinimumSizeSubarraySum_SlidingWindow::minSubArrayLen(int target, vector<int>& nums)
{
    const uint32_t length = (uint32_t)nums.size();

    uint32_t left = 0;
    uint32_t right = 0;
    int32_t sum = 0;
    uint32_t ans = UINT32_MAX;
    while (right < length) {
        sum += nums[right];

        while (sum >= target) {
            ans = min(ans, right - left + 1);
            sum -= nums[left++];
        }
        right++;
    }
    return (ans == UINT32_MAX ? 0 : (int32_t)ans);
}
