/*
 * Time : 2025-05-29 17:35:45
 * URL  : https://leetcode.cn/problems/minimum-height-trees/
 */
#include "lc0310_minimum_height_trees.h"

#include <cstdint>
#include <cstdio>
#include <vector>

#include "leetcode_utils.h"

using namespace std;

vector<int> LC0310_MinimumHeightTrees_DFS::findMinHeightTrees(int n, vector<vector<int>> &edges)
{
    if (n == 1) {
        return {0};
    }

    uint32_t nodeCnt = (uint32_t)n;
    vector<vector<uint32_t>> graph = GetGraphByEdges(edges);
    vector<uint32_t> parentNode(nodeCnt, nodeCnt);

    uint32_t maxNode = nodeCnt;
    uint32_t maxDepth = 0;

    auto dfs = [&](auto &&dfs, uint32_t curr, uint32_t parent, uint32_t depth) -> void {
        if (maxDepth < depth) {
            maxDepth = depth;
            maxNode = curr;
        }

        for (uint32_t child : graph[curr]) {
            if (child == parent) {
                continue;
            }
            parentNode[child] = curr;
            dfs(dfs, child, curr, depth + 1);
        };
    };
    // From 0 find x.
    dfs(dfs, 0, nodeCnt, 0);
    // From x find y.
    uint32_t startNode = maxNode;
    maxNode = nodeCnt;
    maxDepth = 0;
    dfs(dfs, startNode, nodeCnt, 0);
    // Build path.
    uint32_t tmpNode = maxNode;
    vector<int32_t> path(maxDepth + 1, 0);
    for (uint32_t i = 0; i <= maxDepth; i++) {
        uint32_t j = maxDepth - i;
        path[j] = (int32_t)tmpNode;
        tmpNode = parentNode[tmpNode];
    }
    // Build ans.
    vector<int32_t> ans = {path[maxDepth / 2]};
    if (maxDepth % 2 == 1) {
        ans.push_back(path[maxDepth / 2 + 1]);
    }
    return ans;
}
