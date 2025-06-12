/*
 * Time : 2025-05-29 14:32:49
 * URL  : https://leetcode.cn/problems/find-minimum-diameter-after-merging-two-trees/
 */
#include "lc3203_find_minimum_diameter_after_merging_two_trees.h"

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <vector>

using namespace std;

int32_t LC3203_FindMinimumDiameterAfterMergingTwoTrees::GeDiameter(vector<vector<int32_t>>& edges)
{
    const auto nodeCnt = static_cast<uint32_t>(edges.size()) + 1;
    vector<vector<uint32_t>> graph(nodeCnt, vector<uint32_t>());

    for (const vector<int32_t>& edge : edges) {
        constexpr uint32_t START_NODE = 0;
        constexpr uint32_t END_NODE = 1;

        auto start = static_cast<uint32_t>(edge[START_NODE]);
        auto end = static_cast<uint32_t>(edge[END_NODE]);

        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    int32_t res = 0;

    auto dfs = [&](auto&& dfs, uint32_t curr, uint32_t parent) -> int32_t {
        int32_t maxLen = 0;
        for (const uint32_t child : graph[curr]) {
            if (child == parent) {
                continue;
            }
            const int32_t currLen = dfs(dfs, child, curr) + 1;
            res = max(res, maxLen + currLen);
            maxLen = max(maxLen, currLen);
        }
        return maxLen;
    };
    (void)dfs(dfs, 0, static_cast<uint32_t>(edges.size()) + 1);
    return res;
}

int32_t LC3203_FindMinimumDiameterAfterMergingTwoTrees::minimumDiameterAfterMerge(vector<vector<int32_t>>& edges1,
                                                                                  vector<vector<int32_t>>& edges2)
{
    const int32_t d1 = GeDiameter(edges1);
    const int32_t d2 = GeDiameter(edges2);

    return max({d1, d2, ((d1 + 1) / 2 + (d2 + 1) / 2 + 1)});
}
