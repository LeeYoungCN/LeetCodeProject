/*
 * Time : 2025-05-28 14:14:32
 * URL  :
 * https://leetcode.cn/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/description/?envType=daily-questionURL_STRenvId=2025-05-28
 */
#include "lc3372_maximize_the_number_of_target_nodes_after_connecting_trees_i.h"

#include <algorithm>
#include <cstdint>
#include <vector>

using namespace std;

int32_t LC3372_MaximizeTheNumberOfTargetNodesAfterConnectingTreesI::GetKNodeCnt(const vector<vector<uint32_t>>& graph,
                                                                                int32_t k, uint32_t nodeIdx,
                                                                                uint32_t parent)
{
    if (k < 0) {
        return 0;
    }

    int32_t ans = 1;

    for (uint32_t child : graph[(uint32_t)nodeIdx]) {
        if (child == parent) {
            continue;
        }
        ans += GetKNodeCnt(graph, k - 1, child, nodeIdx);
    }

    return ans;
}

vector<int32_t> LC3372_MaximizeTheNumberOfTargetNodesAfterConnectingTreesI::GetKNodeList(
    const vector<vector<int>>& edges, int32_t k)
{
    const uint32_t nodeCnt = (uint32_t)edges.size() + 1;
    const uint32_t START_NODE = 0;
    const uint32_t END_NODE = 1;

    vector<vector<uint32_t>> graph(nodeCnt, vector<uint32_t>());

    for (const vector<int32_t>& edge : edges) {
        uint32_t start = (uint32_t)edge[START_NODE];
        uint32_t end = (uint32_t)edge[END_NODE];

        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    vector<int32_t> ans(nodeCnt, 0);
    for (uint32_t i = 0; i < nodeCnt; i++) {
        ans[i] = GetKNodeCnt(graph, k, i, nodeCnt);
    }

    return ans;
}

vector<int> LC3372_MaximizeTheNumberOfTargetNodesAfterConnectingTreesI::maxTargetNodes(vector<vector<int>>& edges1,
                                                                                       vector<vector<int>>& edges2,
                                                                                       int k)
{
    vector<int32_t> count1 = GetKNodeList(edges1, k);
    vector<int32_t> count2 = GetKNodeList(edges2, k - 1);

    vector<int32_t>::iterator maxIt = max_element(count2.begin(), count2.end());

    for (vector<int32_t>::iterator it = count1.begin(); it != count1.end(); it++) {
        *it += *maxIt;
    }

    return count1;
}
