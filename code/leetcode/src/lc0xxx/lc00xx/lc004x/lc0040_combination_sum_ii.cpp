/*
 * Time : 2025-07-13 17:59:31
 * URL  : https://leetcode.cn/problems/combination-sum-ii/description/
 */
#include "lc0xxx/lc00xx/lc004x/lc0040_combination_sum_ii.h"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <vector>

using namespace std;

void LC0040_CombinationSumII::dfs(size_t idx, int32_t target)
{
    if (target == 0) {
        ans.emplace_back(currVec);
        return;
    }

    for (size_t i = idx; i < candidates.size(); ++i) {
        if (target - candidates[i] < 0 || (i > idx && candidates[i - 1] == candidates[i])) {
            continue;
        }
        currVec.emplace_back(candidates[i]);

        dfs(i + 1, target - candidates[i]);
        currVec.pop_back();
    }
}

std::vector<std::vector<int32_t>> LC0040_CombinationSumII::combinationSum2(std::vector<int32_t>& candidates,
                                                                           int32_t target)
{
    this->candidates = candidates;
    sort(this->candidates.begin(), this->candidates.end());
    currVec.reserve(candidates.size());
    dfs(0, target);
    return ans;
}
