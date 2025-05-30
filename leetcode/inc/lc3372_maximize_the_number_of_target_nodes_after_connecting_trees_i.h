/*
 * Time : 2025-05-28 14:14:32
 * URL  :
 * https://leetcode.cn/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/description/?envType=daily-questionURL_STRenvId=2025-05-28
 */
#ifndef LC3372_MAXIMIZE_THE_NUMBER_OF_TARGET_NODES_AFTER_CONNECTING_TREES_I_H
#define LC3372_MAXIMIZE_THE_NUMBER_OF_TARGET_NODES_AFTER_CONNECTING_TREES_I_H

#include <vector>

class LC3372_MaximizeTheNumberOfTargetNodesAfterConnectingTreesI {
public:
    LC3372_MaximizeTheNumberOfTargetNodesAfterConnectingTreesI() = default;
    virtual ~LC3372_MaximizeTheNumberOfTargetNodesAfterConnectingTreesI() = default;
    std::vector<int> maxTargetNodes(std::vector<std::vector<int>>& edges1, std::vector<std::vector<int>>& edges2,
                                    int k);

private:
    int GetKNodeCnt(const std::vector<std::vector<int>>& graph, int k, unsigned int nodeIdx, unsigned int parent);
    std::vector<int> GetKNodeList(const std::vector<std::vector<int>>& edges, int k);
};

#endif  // LC3372_MAXIMIZE_THE_NUMBER_OF_TARGET_NODES_AFTER_CONNECTING_TREES_I_H
