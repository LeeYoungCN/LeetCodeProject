/*
 * Time : 2025-05-29 17:35:45
 * URL  : https://leetcode.cn/problems/minimum-height-trees/
 */
#include "lc0310_minimum_height_trees.h"

#include <algorithm>
#include <cstdint>
#include <functional>
#include <queue>
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

vector<int> LC0310_MinimumHeightTrees_BFS::findMinHeightTrees(int n, vector<vector<int>> &edges)
{
    if (n == 1) {
        return {0};
    }

    uint32_t nodeCnt = (uint32_t)n;
    vector<vector<uint32_t>> graph = GetGraphByEdges(edges);
    vector<uint32_t> parentNode(nodeCnt, nodeCnt);
    vector<uint32_t> distance(nodeCnt, 0);

    function<uint32_t(uint32_t)> bfs = [&](uint32_t startNode) -> uint32_t {
        fill(distance.begin(), distance.end(), 0);
        fill(parentNode.begin(), parentNode.end(), nodeCnt);

        queue<uint32_t> nodeQueue;
        uint32_t node = startNode;
        nodeQueue.push(node);
        distance[node] = 1;

        while (!nodeQueue.empty()) {
            node = nodeQueue.front();
            nodeQueue.pop();
            for (uint32_t child : graph[node]) {
                if (distance[child] != 0) {
                    continue;
                }
                parentNode[child] = node;
                distance[child] = distance[node] + 1;
                nodeQueue.push(child);
            }
        }
        return node;
    };

    uint32_t maxNode1 = bfs(0);
    uint32_t maxNode2 = bfs(maxNode1);
    uint32_t maxDist = distance[maxNode2];

    vector<int32_t> path(maxDist, 0);
    uint32_t tmp = maxNode2;

    for (uint32_t i = 0; i < maxDist; i++) {
        uint32_t j = maxDist - i - 1;
        path[j] = (int32_t)tmp;
        tmp = parentNode[tmp];
    }

    vector<int32_t> ans = {path[maxDist / 2]};
    if (maxDist % 2 == 0) {
        ans.push_back(path[maxDist / 2 - 1]);
    }
    return ans;
}

vector<int> LC0310_MinimumHeightTrees_TopologicalSort::findMinHeightTrees(int n, vector<vector<int>> &edges)
{
    if (n == 1) {
        return {0};
    }

    uint32_t nodeCnt = (uint32_t)n;
    vector<vector<uint32_t>> graph(nodeCnt, vector<uint32_t>());
    vector<uint32_t> nodeDegree(nodeCnt, 0);

    for (const vector<int32_t> &edge : edges) {
        uint32_t start = (uint32_t)edge[0];
        uint32_t end = (uint32_t)edge[1];

        graph[start].push_back(end);
        graph[end].push_back(start);

        nodeDegree[start]++;
        nodeDegree[end]++;
    }

    queue<uint32_t> leafNodes;
    for (uint32_t i = 0; i < nodeCnt; i++) {
        if (nodeDegree[i] == 1) {
            leafNodes.push(i);
        }
    }

    uint32_t remnant = nodeCnt;

    while (remnant > 2) {
        uint32_t leafCnt = (uint32_t)leafNodes.size();

        for (uint32_t i = 0; i < leafCnt; i++) {
            uint32_t leaf = leafNodes.front();
            leafNodes.pop();

            for (uint32_t neighbor : graph[leaf]) {
                if (--nodeDegree[neighbor] == 1) {
                    leafNodes.push(neighbor);
                }
            }
        }

        remnant -= leafCnt;
    }

    vector<int32_t> ans;
    while (!leafNodes.empty()) {
        ans.push_back((int32_t)leafNodes.front());
        leafNodes.pop();
    }

    return ans;
}
