#include <cstdint>
#include <vector>

#include "leetcode_utils.h"

using namespace std;

vector<vector<int32_t>> GetGraphByEdges(const vector<vector<int32_t>>& edges)
{
    const uint32_t START_NODE = 0;
    const uint32_t END_NODE = 1;

    uint32_t nodeCnt = (uint32_t)edges.size() + 1;
    vector<vector<int32_t>> graph(nodeCnt, vector<int32_t>());

    for (const vector<int32_t>& edge : edges) {
        int32_t start = edge[START_NODE];
        int32_t end = edge[END_NODE];

        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    return graph;
}
