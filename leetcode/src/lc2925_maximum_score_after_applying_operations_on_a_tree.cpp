/*
 * Time : 2025-05-24 17:13:11
 * URL  : https://leetcode.cn/problems/maximum-score-after-applying-operations-on-a-tree/description/
 */
#include "lc2925_maximum_score_after_applying_operations_on_a_tree.h"

#include <cstdint>
#include <functional>
#include <vector>

using namespace std;

struct TreeValInfo {
    int64_t healthVal;
    int64_t totalVal;
};

long long LC2925_MaximumScoreAfterApplyingOperationsOnATree::maximumScoreAfterOperations(vector<vector<int>>& edges,
                                                                                         vector<int>& values)
{
    const auto length = static_cast<uint32_t>(values.size());

    vector<vector<uint32_t>> grid(length);
    vector<vector<uint32_t>> TreeVal(length);

    for (const vector<int32_t>& edge : edges) {
        auto n1 = static_cast<uint32_t>(edge[0]);
        auto n2 = static_cast<uint32_t>(edge[1]);
        grid[n1].push_back(n2);
        grid[n2].push_back(n1);
    }

    function<TreeValInfo(uint32_t, uint32_t)> dfs = [&](uint32_t curr, uint32_t parent) -> TreeValInfo {
        TreeValInfo currVal = {0, values[curr]};
        // 叶节点
        if (grid[curr].size() == 1 && grid[curr][0] == parent) {
            return currVal;
        }

        TreeValInfo tmpChild = {0, 0};
        for (uint32_t child : grid[curr]) {
            if (child != parent) {
                TreeValInfo childVal = dfs(child, curr);
                tmpChild.healthVal += childVal.healthVal;
                tmpChild.totalVal += childVal.totalVal;
            }
        }
        currVal.healthVal = max(tmpChild.healthVal + values[curr], tmpChild.totalVal);
        currVal.totalVal += tmpChild.totalVal;
        return currVal;
    };

    return dfs(0, length).healthVal;
}
