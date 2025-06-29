/*
 * Time : 2025-06-29 18:45:48
 * URL  : https://leetcode.cn/problems/combination-sum/
 */
#include "lc0039_combination_sum.h"

#include <algorithm>
#include <cstdint>
#include <vector>

using namespace std;

void dfs(const std::vector<int32_t>& candidates, vector<vector<int32_t>>& ans, vector<int32_t>& currVec, int32_t target,
         uint32_t startIdx)
{
    if (target < candidates[startIdx]) {
        return;
    }
    currVec.emplace_back(candidates[startIdx]);
    int32_t newTarget = target - candidates[startIdx];
    if (newTarget == 0) {
        ans.emplace_back(currVec);
    } else {
        for (uint32_t nextIdx = startIdx; nextIdx < candidates.size(); nextIdx++) {
            dfs(candidates, ans, currVec, newTarget, nextIdx);
        }
    }
    currVec.pop_back();
}

std::vector<std::vector<int32_t>> LC0039_CombinationSum::combinationSum(std::vector<int32_t>& candidates,
                                                                        int32_t target)
{
    ranges::sort(candidates);
    std::vector<std::vector<int32_t>> ans;
    vector<int32_t> currVec;
    for (uint32_t i = 0; i < static_cast<uint32_t>(candidates.size()); i++) {
        dfs(candidates, ans, currVec, target, i);
    }

    return ans;
}
