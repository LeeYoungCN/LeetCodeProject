/*
 * Time : 2025-05-30 21:17:28
 * URL  :
 * https://leetcode.cn/problems/find-closest-node-to-given-two-nodes/description/?envType=daily-questionURL_STRenvId=2025-05-30
 */
#include "lc2359_find_closest_node_to_given_two_nodes.h"

#include <algorithm>
#include <cstdint>
#include <functional>
#include <vector>

using namespace std;

int LC2359_FindClosestNodeToGivenTwoNodes::closestMeetingNode(vector<int> &edges, int node1, int node2)
{
    const auto nodeCnt = static_cast<uint32_t>(edges.size());

    const uint32_t node1Idx = 0;
    const uint32_t node2Idx = 1;
    vector<vector<int32_t>> nodeDist = {vector<int32_t>(nodeCnt, -1), vector<int32_t>(nodeCnt, -1)};

    function<void(uint32_t, vector<int32_t> &)> getDist = [&](uint32_t startNode, vector<int32_t> &dist) -> void {
        int32_t d = 0;
        auto tmp = static_cast<int32_t>(startNode);
        while (tmp != -1 && dist[static_cast<uint32_t>(tmp)] == -1) {
            dist[static_cast<uint32_t>(tmp)] = d;
            tmp = edges[static_cast<uint32_t>(tmp)];
            d++;
        }
    };

    getDist(static_cast<uint32_t>(node1), nodeDist.at(node1Idx));
    getDist(static_cast<uint32_t>(node2), nodeDist.at(node2Idx));

    int32_t ans = -1;

    for (uint32_t i = 0; i < nodeCnt; i++) {
        if (nodeDist[node1Idx][i] == -1 || nodeDist[node2Idx][i] == -1) {
            continue;
        }
        if (ans == -1 ||
            max(nodeDist[node1Idx][static_cast<uint32_t>(ans)], nodeDist[node2Idx][static_cast<uint32_t>(ans)]) >
                max(nodeDist[node1Idx][i], nodeDist[node2Idx][i])) {
            ans = static_cast<int32_t>(i);
        }
    }
    return ans;
}
