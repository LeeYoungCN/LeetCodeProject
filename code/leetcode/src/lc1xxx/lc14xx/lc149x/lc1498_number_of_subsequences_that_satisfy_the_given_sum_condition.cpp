/*
 * Time : 2025-06-29 11:23:20
 * URL  :
 * https://leetcode.cn/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/?envType=daily-question&envId=2025-06-29
 */
#include "lc1xxx/lc14xx/lc149x/lc1498_number_of_subsequences_that_satisfy_the_given_sum_condition.h"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <vector>

using namespace std;

int LC1498_NumberOfSubsequencesThatSatisfyTheGivenSumCondition::numSubseq(std::vector<int>& nums, int target)
{
    constexpr uint32_t MOD = 1'000'000'007;

    vector<uint32_t> pow(nums.size() + 1, 1);

    for (uint32_t i = 1; i <= nums.size(); ++i) {
        pow[i] = pow[i - 1] * 2 % MOD;
    }

    sort(nums.begin(), nums.end());

    size_t ans = 0;
    size_t left = 0;
    size_t right = nums.size() - 1;

    while (left <= right && left < nums.size() && right < nums.size()) {
        if (nums[left] + nums[right] <= target) {
            ans += pow[right - left] % MOD;
            left++;
        } else {
            right--;
        }
    }

    return static_cast<int32_t>(ans % MOD);
}
