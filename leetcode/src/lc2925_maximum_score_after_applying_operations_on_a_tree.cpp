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
    uint32_t length = values.size();

    vector<vector<int32_t>> grid(length);
    vector<vector<int32_t>> TreeVal(length);

    for (const vector<int32_t>& edge : edges) {
        int32_t n1 = edge[0];
        int32_t n2 = edge[1];
        grid[n1].push_back(n2);
        grid[n2].push_back(n1);
    }

    function<TreeValInfo(int32_t, int32_t)> dfs = [&](int32_t curr, int32_t parent) -> TreeValInfo {
        TreeValInfo currVal = {0, values[curr]};
        // 叶节点
        if (grid[curr].size() == 1 && grid[curr][0] == parent) {
            return currVal;
        }

        TreeValInfo tmpChild = {0, 0};
        for (int32_t child : grid[curr]) {
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

    return dfs(0, -1).healthVal;
}
