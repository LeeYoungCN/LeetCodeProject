/*
 * Time : 2025-05-29 00:11:51
 * URL  :
 * https://leetcode.cn/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/description/?envType=daily-questionURL_STRenvId=2025-05-29
 */
#ifndef LC3373_MAXIMIZE_THE_NUMBER_OF_TARGET_NODES_AFTER_CONNECTING_TREES_II_H
#define LC3373_MAXIMIZE_THE_NUMBER_OF_TARGET_NODES_AFTER_CONNECTING_TREES_II_H

#include <vector>

struct TreeData;

class LC3373_MaximizeTheNumberOfTargetNodesAfterConnectingTreesII {
public:
    LC3373_MaximizeTheNumberOfTargetNodesAfterConnectingTreesII() = default;
    virtual ~LC3373_MaximizeTheNumberOfTargetNodesAfterConnectingTreesII() = default;
    std::vector<int> maxTargetNodes(std::vector<std::vector<int>>& edges1, std::vector<std::vector<int>>& edges2);

private:
    void DFS(const std::vector<std::vector<int>>& graph, int depth, int curr, int parent, TreeData& treeNodeData);
    void GetTreeNodeData(const std::vector<std::vector<int>>& edges, TreeData& treeNodeData);
};

#endif  // LC3373_MAXIMIZE_THE_NUMBER_OF_TARGET_NODES_AFTER_CONNECTING_TREES_II_H
