/*
 * Time : 2025-07-05 17:33:28
 * URL  : https://leetcode.cn/problems/subsets/description/
 */
#include "lc0xxx/lc00xx/lc007x/lc0078_subsets.h"

#include <cstdint>
#include <functional>
#include <vector>

using namespace std;

std::vector<std::vector<int32_t>> LC0078_Subsets_Enum::subsets(std::vector<int32_t>& nums)
{
    std::vector<std::vector<int32_t>> ans;
    const auto bitWidth = static_cast<uint32_t>(nums.size());
    const uint32_t maxNum = (1U << bitWidth);
    function num2Vec = [&](uint32_t num) -> vector<int32_t> {
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

void dfs(const std::vector<int32_t>& nums, uint32_t currIdx, vector<int32_t>& currVec, vector<vector<int32_t>>& ans)
{
    if (currIdx == nums.size()) {
        ans.emplace_back(currVec);
        return;
    }

    currVec.push_back(nums[currIdx]);
    dfs(nums, currIdx + 1, currVec, ans);
    currVec.pop_back();
    dfs(nums, currIdx + 1, currVec, ans);
}

std::vector<std::vector<int32_t>> LC0078_Subsets_DFS::subsets(std::vector<int32_t>& nums)
{
    std::vector<std::vector<int32_t>> ans;
    ans.reserve(static_cast<size_t>(1ULL << nums.size()));
    vector<int32_t> currVec;
    currVec.reserve(nums.size());
    dfs(nums, 0, currVec, ans);
    return ans;
}
