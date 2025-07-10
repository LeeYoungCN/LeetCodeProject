/*
 * Time : 2025-05-29 00:11:51
 * URL  :
 * https://leetcode.cn/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/description/?envType=daily-questionURL_STRenvId=2025-05-29
 */
#include "lc33xx/lc3373_maximize_the_number_of_target_nodes_after_connecting_trees_ii.h"

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <vector>

using namespace std;

enum class NodeType { EVEN, ODD };

struct TreeData {
    int32_t evenCnt;
    int32_t oddCnt;
    vector<NodeType> nodeList;
};

void LC3373_MaximizeTheNumberOfTargetNodesAfterConnectingTreesII::DFS(const vector<vector<uint32_t>>& graph,
                                                                      int32_t depth, uint32_t curr, uint32_t parent,
                                                                      TreeData& treeNodeData)
{
    if (depth % 2 == 0) {
        treeNodeData.evenCnt++;
        treeNodeData.nodeList[curr] = NodeType::EVEN;
    } else {
        treeNodeData.oddCnt++;
        treeNodeData.nodeList[curr] = NodeType::ODD;
    }

    for (const uint32_t child : graph[curr]) {
        if (child == parent) {
            continue;
        }
        DFS(graph, depth + 1, child, curr, treeNodeData);
    }
}

void LC3373_MaximizeTheNumberOfTargetNodesAfterConnectingTreesII::GetTreeNodeData(const vector<vector<int>>& edges,
                                                                                  TreeData& treeNodeData)
{
    const uint32_t nodeCnt = static_cast<uint32_t>(edges.size()) + 1;
    vector<vector<uint32_t>> graph(nodeCnt, vector<uint32_t>());

    for (const vector<int32_t>& edge : edges) {
        constexpr uint32_t START_NODE = 0;
        constexpr uint32_t END_NODE = 1;
        auto start = static_cast<uint32_t>(edge[START_NODE]);
        auto end = static_cast<uint32_t>(edge[END_NODE]);

        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    vector<int32_t> ans(nodeCnt, 0);

    DFS(graph, 0, 0, nodeCnt, treeNodeData);
}

vector<int32_t> LC3373_MaximizeTheNumberOfTargetNodesAfterConnectingTreesII::maxTargetNodes(
    vector<vector<int32_t>>& edges1, vector<vector<int32_t>>& edges2)
{
    const uint32_t nodeCnt1 = static_cast<uint32_t>(edges1.size()) + 1;
    const uint32_t nodeCnt2 = static_cast<uint32_t>(edges2.size()) + 1;

    TreeData treeData1 = {.evenCnt = 0, .oddCnt = 0, .nodeList = vector<NodeType>(nodeCnt1, NodeType::EVEN)};
    TreeData treeData2 = {.evenCnt = 0, .oddCnt = 0, .nodeList = vector<NodeType>(nodeCnt2, NodeType::EVEN)};

    GetTreeNodeData(edges1, treeData1);
    GetTreeNodeData(edges2, treeData2);

    const int32_t maxTree2 = max(treeData2.evenCnt, treeData2.oddCnt);
    vector<int32_t> ans(nodeCnt1);

    for (uint32_t i = 0; i < nodeCnt1; i++) {
        ans[i] = maxTree2 + (treeData1.nodeList[i] == NodeType::EVEN ? treeData1.evenCnt : treeData1.oddCnt);
    }

    return ans;
}
