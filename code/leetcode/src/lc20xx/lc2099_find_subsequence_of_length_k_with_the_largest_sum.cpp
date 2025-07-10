/*
 * Time : 2025-06-28 00:18:24
 * URL  :
 * https://leetcode.cn/problems/find-subsequence-of-length-k-with-the-largest-sum/?envType=daily-question&envId=2025-06-28
 */
#include "lc20xx/lc2099_find_subsequence_of_length_k_with_the_largest_sum.h"

#include <algorithm>
#include <cstdint>
#include <vector>

using namespace std;

std::vector<int> LC2099_FindSubsequenceOfLengthKWithTheLargestSum::maxSubsequence(std::vector<int>& nums, int k)
{
    const auto len = static_cast<uint32_t>(k);

    vector<pair<uint32_t, int32_t>> dataArray;
    dataArray.reserve(nums.size());

    for (uint32_t i = 0; i < nums.size(); ++i) {
        dataArray.emplace_back(i, nums[i]);
    }

    sort(dataArray.begin(), dataArray.end(), [&](auto x, auto y) { return x.second > y.second; });
    sort(dataArray.begin(), dataArray.begin() + k);

    vector<int32_t> ans(len, 0);

    for (uint32_t i = 0; i < len; ++i) {
        ans[i] = dataArray[i].second;
    }

    return ans;
}
