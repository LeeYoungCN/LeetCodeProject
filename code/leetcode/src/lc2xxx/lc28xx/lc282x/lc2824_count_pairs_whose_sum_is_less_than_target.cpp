/*
 * Time : 2025-06-29 14:38:01
 * URL  : https://leetcode.cn/problems/count-pairs-whose-sum-is-less-than-target/description/
 */
#include "lc2xxx/lc28xx/lc282x/lc2824_count_pairs_whose_sum_is_less_than_target.h"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <vector>

using namespace std;

int32_t LC2824_CountPairsWhoseSumIsLessThanTarget_Enum::countPairs(std::vector<int32_t>& nums, int32_t target)
{
    int32_t ans = 0;
    for (uint32_t i = 0; i < nums.size() - 1; i++) {
        for (uint32_t j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] < target) {
                ans++;
            }
        }
    }
    return ans;
}

size_t LC2824_CountPairsWhoseSumIsLessThanTarget_Find::findLowerBound(const std::vector<int32_t>& nums, size_t end,
                                                                      int32_t target)
{
    size_t left = 0;
    size_t right = end;
    size_t ans = end;
    while (left < right) {
        size_t curr = (left + right) / 2;
        if (nums[curr] < target) {
            left = curr + 1;
            ans = curr;
        } else {
            right = curr;
        }
    }
    return ans;
}

int32_t LC2824_CountPairsWhoseSumIsLessThanTarget_Find::countPairs(std::vector<int32_t>& nums, int32_t target)
{
    sort(nums.begin(), nums.end());

    size_t ans = 0;
    for (size_t i = 0; i < nums.size(); i++) {
        size_t lowerBound = findLowerBound(nums, i, target - nums[i]);
        if (lowerBound < i) {
            ans += lowerBound + 1;
        }
    }

    return static_cast<int32_t>(ans);
}

int32_t LC2824_CountPairsWhoseSumIsLessThanTarget_DoublePtr::countPairs(std::vector<int32_t>& nums, int32_t target)
{
    sort(nums.begin(), nums.end());
    uint32_t ans = 0;
    for (size_t left = 0, right = nums.size() - 1; left < right; left++) {
        while (nums[left] + nums[right] >= target && left < right) {
            right--;
        }
        if (left < right) {
            ans += static_cast<uint32_t>(right - left);
        }
    }
    return static_cast<int32_t>(ans);
}
