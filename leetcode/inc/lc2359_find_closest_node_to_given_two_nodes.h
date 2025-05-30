/*
 * Time : 2025-05-30 21:17:28
 * URL  :
 * https://leetcode.cn/problems/find-closest-node-to-given-two-nodes/description/?envType=daily-questionURL_STRenvId=2025-05-30
 */
#ifndef LC2359_FIND_CLOSEST_NODE_TO_GIVEN_TWO_NODES_H
#define LC2359_FIND_CLOSEST_NODE_TO_GIVEN_TWO_NODES_H

#include <vector>

class LC2359_FindClosestNodeToGivenTwoNodes {
public:
    LC2359_FindClosestNodeToGivenTwoNodes() = default;
    virtual ~LC2359_FindClosestNodeToGivenTwoNodes() = default;
    int closestMeetingNode(std::vector<int>& edges, int node1, int node2);
};

#endif  // LC2359_FIND_CLOSEST_NODE_TO_GIVEN_TWO_NODES_H
