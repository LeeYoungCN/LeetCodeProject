/*
 * Time : 2025-06-27 17:05:51
 * URL  : https://leetcode.cn/problems/permutations-ii/description/
 */
#include "lc0047_permutations_ii.h"

#include <algorithm>
#include <cstdint>
#include <set>
#include <vector>

using namespace std;

void LC0047_PermutationsII_Set::dfs(const vector<int32_t>& nums, vector<int32_t>& permution, vector<bool>& visitor,
                                    set<vector<int32_t>>& listSet)
{
    if (permution.size() == nums.size()) {
        listSet.insert(permution);
    }

    for (uint32_t i = 0; i < nums.size(); ++i) {
        if (!visitor[i]) {
            visitor[i] = true;
            permution.push_back(nums[i]);
            dfs(nums, permution, visitor, listSet);
            visitor[i] = false;
            permution.pop_back();
        }
    }
}

std::vector<std::vector<int>> LC0047_PermutationsII_Set::permuteUnique(std::vector<int>& nums)
{
    set<vector<int32_t>> listSet;
    vector<bool> visitor(nums.size(), false);
    vector<int32_t> permution;

    permution.reserve(nums.size());
    dfs(nums, permution, visitor, listSet);
    return {listSet.begin(), listSet.end()};
}

void LC0047_PermutationsII_Sort::dfs(const vector<int32_t>& nums, vector<bool>& visitor, vector<int32_t>& permution,
                                     vector<vector<int32_t>>& ans)
{
    if (permution.size() == nums.size()) {
        ans.emplace_back(permution);
        return;
    }

    for (uint32_t i = 0; i < nums.size(); ++i) {
        if (visitor[i] || (i > 0 && nums[i] == nums[i - 1] && !visitor[i - 1])) {
            continue;
        }

        visitor[i] = true;
        permution.push_back(nums[i]);
        dfs(nums, visitor, permution, ans);
        visitor[i] = false;
        permution.pop_back();
    }
}

std::vector<std::vector<int>> LC0047_PermutationsII_Sort::permuteUnique(std::vector<int>& nums)
{
    ranges::sort(nums);
    vector<vector<int32_t>> ans;
    vector<bool> visitor(nums.size(), false);
    vector<int32_t> permution;

    permution.reserve(nums.size());
    dfs(nums, visitor, permution, ans);
    return ans;
}
