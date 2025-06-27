/*
 * Time : 2025-06-27 17:05:51
 * URL  : https://leetcode.cn/problems/permutations-ii/description/
 */
#include "lc0047_permutations_ii.h"

#include <cstdint>
#include <set>
#include <vector>

using namespace std;

void dfs(const vector<int32_t>& nums, vector<int32_t>& permution, vector<bool>& visitor, set<vector<int32_t>>& listSet)
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

std::vector<std::vector<int>> LC0047_PermutationsII::permuteUnique(std::vector<int>& nums)
{
    set<vector<int32_t>> listSet;
    vector<bool> visitor(nums.size(), false);
    vector<int32_t> permution;

    permution.reserve(nums.size());
    dfs(nums, permution, visitor, listSet);
    return {listSet.begin(), listSet.end()};
}
