/*
 * Time : 2025-07-05 17:33:28
 * URL  : https://leetcode.cn/problems/subsets/description/
 */
#include "lc0078_subsets.h"

#include <cstdint>
#include <functional>
#include <vector>

using namespace std;

std::vector<std::vector<int32_t>> LC0078_Subsets::subsets(std::vector<int32_t>& nums)
{
    std::vector<std::vector<int32_t>> ans;
    const auto bitWidth = static_cast<uint32_t>(nums.size());
    const uint32_t maxNum = (1U << bitWidth);
    function num2Vec = [&](uint32_t num)->vector<int32_t> {
        vector<int32_t> ans;
        for (uint32_t i = 0; i < bitWidth; i++) {
            if (num & (1U << i)) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    };
    ans.reserve(maxNum);
    for (uint32_t i = 0; i < maxNum; ++i) {
        ans.emplace_back(num2Vec(i));
    }
    return ans;
}
