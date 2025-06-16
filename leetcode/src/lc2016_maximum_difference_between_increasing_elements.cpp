/*
 * Time : 2025-06-16 09:06:15
 * URL  :
 * https://leetcode.cn/problems/maximum-difference-between-increasing-elements/description/?envType=daily-questionURL_STRenvId=2025-06-16
 */
#include "lc2016_maximum_difference_between_increasing_elements.h"

#include <cstdint>
#include <vector>

using namespace std;

int32_t LC2016_MaximumDifferenceBetweenIncreasingElements_MinArray::maximumDifference(vector<int32_t>& nums)
{
    const auto length = static_cast<uint32_t>(nums.size());

    vector<int32_t> minNums(length, 0);
    minNums[1] = nums[0];
    for (uint32_t i = 2; i < length; i++) {
        minNums[i] = min(minNums[i - 1], nums[i - 1]);
    }

    int32_t result = INT32_MIN;
    for (uint32_t i = 1; i < length; i++) {
        result = max(result, nums[i] - minNums[i]);
    }

    return result <= 0 ? -1 : result;
}

int32_t LC2016_MaximumDifferenceBetweenIncreasingElements_PreMin::maximumDifference(vector<int32_t>& nums)
{
    const auto length = static_cast<uint32_t>(nums.size());

    int32_t result = INT32_MIN;
    int32_t preMin = nums[0];
    for (uint32_t i = 1; i < length; i++) {
        result = max(result, nums[i] - preMin);
        preMin = min(preMin, nums[i]);
    }

    return result <= 0 ? -1 : result;
}
