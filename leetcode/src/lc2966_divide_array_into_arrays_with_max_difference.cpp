/*
 * Time : 2025-06-18 00:22:48
 * URL  :
 * https://leetcode.cn/problems/divide-array-into-arrays-with-max-difference/description/?envType=daily-questionURL_STRenvId=2025-06-18
 */
#include "lc2966_divide_array_into_arrays_with_max_difference.h"

#include <algorithm>
#include <cstdint>
#include <vector>

using namespace std;

vector<vector<int32_t>> LC2966_DivideArrayIntoArraysWithMaxDifference::divideArray(vector<int32_t>& nums, int32_t k)
{
    sort(nums.begin(), nums.end());
    vector<vector<int32_t>> ans(nums.size() / 3, vector<int32_t>(3, 0));
    for (uint32_t i = 0; i < nums.size();) {
        uint32_t n = i / 3;
        ans[n][0] = nums[i++];
        ans[n][1] = nums[i++];
        ans[n][2] = nums[i++];
        if (ans[n][2] - ans[n][0] > k) {
            return {};
        }
    }
    return ans;
}
