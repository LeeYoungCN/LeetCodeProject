/*
 * Time : 2025-05-29 14:32:49
 * URL  : https://leetcode.cn/problems/find-minimum-diameter-after-merging-two-trees/
 */
#include "lc3203_find_minimum_diameter_after_merging_two_trees.h"

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <functional>
#include <vector>

#include "leetcode_utils.h"

using namespace std;

int32_t LC3203_FindMinimumDiameterAfterMergingTwoTrees::GeDiameter(vector<vector<int32_t>>& edges)
{
    vector<vector<int32_t>> graph = GetGraphByEdges(edges);

    int32_t res = 0;

    auto dfs = [&](auto&& dfs, int32_t curr, int32_t parent) -> int32_t {
        int32_t maxLen = 0;
        for (int32_t child : graph[(uint32_t)curr]) {
            if (child == parent) {
                continue;
            }
            int32_t currLen = dfs(dfs, child, curr) + 1;
            res = max(res, maxLen + currLen);
            maxLen = max(maxLen, currLen);
        }
        return maxLen;
    };
    (void)dfs(dfs, 0, -1);
    return res;
}

int32_t LC3203_FindMinimumDiameterAfterMergingTwoTrees::minimumDiameterAfterMerge(vector<vector<int32_t>>& edges1,
                                                                                  vector<vector<int32_t>>& edges2)
{
    int32_t d1 = GeDiameter(edges1);
    int32_t d2 = GeDiameter(edges2);

    return max({d1, d2, ((d1 + 1) / 2 + (d2 + 1) / 2 + 1)});
}
