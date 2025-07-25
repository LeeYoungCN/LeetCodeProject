/*
 * Time : 2025-07-25 09:10:06
 * URL  :
 * https://leetcode.cn/problems/maximum-unique-subarray-sum-after-deletion/description/?envType=daily-question&envId=2025-07-25
 */
#include "lc3xxx/lc34xx/lc348x/lc3487_maximum_unique_subarray_sum_after_deletion.h"

#include <algorithm>
#include <cstdint>
#include <functional>
#include <vector>

using namespace std;

int32_t LC3487_MaximumUniqueSubarraySumAfterDeletion::maxSum(std::vector<int32_t>& nums)
{
    std::sort(nums.begin(), nums.end(), greater());
    int32_t ans = 0;
    for (uint32_t i = 0; i < nums.size(); i++) {
        if (i != 0) {
            if (nums[i] == nums[i - 1]) {
                continue;
            }
            if (nums[i] <= 0) {
                break;
            }
        }
        ans += nums[i];
    }
    return ans;
}
