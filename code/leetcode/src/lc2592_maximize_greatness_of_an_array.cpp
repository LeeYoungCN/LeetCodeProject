/*
 * Time : 2025-06-02 17:06:28
 * URL  : https://leetcode.cn/problems/maximize-greatness-of-an-array/description/
 */
#include "lc2592_maximize_greatness_of_an_array.h"

#include <algorithm>
#include <cstdint>
#include <functional>
#include <vector>

using namespace std;

int LC2592_MaximizeGreatnessOfAnArray::maximizeGreatness(std::vector<int>& nums)
{
    sort(nums.begin(), nums.end(), greater<>());
    int32_t ans = 0;

    uint32_t left = 0;

    for (const int32_t n : nums) {
        if (nums[left] > n) {
            ans++;
            left++;
        }
    }
    return ans;
}
