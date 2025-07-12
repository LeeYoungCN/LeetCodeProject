/*
 * Time : 2025-06-20 00:23:10
 * URL  : https://leetcode.cn/problems/partition-array-such-that-maximum-difference-is-k/description/
 */
#include "lc2xxx/lc22xx/lc229x/lc2294_partition_array_such_that_maximum_difference_is_k.h"

#include <algorithm>
#include <cstdint>
#include <vector>

using namespace std;

int32_t LC2294_PartitionArraySuchThatMaximumDifferenceIsK::partitionArray(vector<int32_t>& nums, int32_t k)
{
    sort(nums.begin(), nums.end());
    int32_t start = nums[0];
    int32_t ans = 1;
    for (int32_t n : nums) {
        if (n - start > k) {
            start = n;
            ans++;
        }
    }
    return ans;
}
