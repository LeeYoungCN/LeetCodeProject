/*
 * Time : 2025-05-26 10:28:20
 * URL  :
 * https://leetcode.cn/problems/largest-color-value-in-a-directed-graph/description/?envType=daily-questionURL_STRenvId=2025-05-26
 */
#include "lc1847_largest_color_value_in_a_directed_graph.h"

#include <algorithm>
#include <cstdint>
#include <queue>
#include <string>
#include <vector>

using namespace std;

namespace {
const uint32_t COLOR_CNT = 26;
const uint32_t EDGE_START = 0;
const uint32_t EDGE_END = 1;
}  // namespace

bool LC1847_LargestColorValueInADirectedGraph_DFS::dfs(uint32_t curr, vector<VisitStatus> &visitor,
                                                       vector<vector<int32_t>> &dp,
                                                       const vector<vector<uint32_t>> &grid)
{
    if (visitor[curr] == VisitStatus::USING) {
        return false;
    }

    if (visitor[curr] == VisitStatus::FINISH) {
        return true;
    }

    visitor[curr] = VisitStatus::USING;

    for (uint32_t child : grid[curr]) {
        if (!dfs(child, visitor, dp, grid)) {
            return false;
        }
        for (uint32_t i = 0; i < COLOR_CNT; i++) {
            dp[curr][i] = max(dp[child][i], dp[curr][i]);
        }
    }
    auto idx = static_cast<uint32_t>(m_colors[curr] - 'a');
    dp[curr][idx] += 1;
    visitor[curr] = VisitStatus::FINISH;
    return true;
};

int LC1847_LargestColorValueInADirectedGraph_DFS::largestPathValue(string colors, vector<vector<int>> &edges)
{
    m_colors = colors;
    m_edges = edges;
    auto nodeCnt = static_cast<uint32_t>(m_colors.size());
    vector<vector<uint32_t>> grid(nodeCnt);

    for (const vector<int32_t> &edge : m_edges) {
        grid[static_cast<uint32_t>(edge[EDGE_START])].push_back(static_cast<uint32_t>(edge[EDGE_END]));
    }

    vector<vector<int32_t>> dp(nodeCnt, vector<int32_t>(COLOR_CNT));
    vector<VisitStatus> visitor(nodeCnt, VisitStatus::UNUSED);

    int32_t ret = 0;
    for (uint32_t i = 0; i < nodeCnt; i++) {
        if (!dfs(i, visitor, dp, grid)) {
            return -1;
        }
        for (int32_t colorNum : dp[i]) {
            ret = max(colorNum, ret);
        }
    }
    return ret;
}

int LC1847_LargestColorValueInADirectedGraph_BFS::largestPathValue(std::string colors,
                                                                   std::vector<std::vector<int>> &edges)
{
    auto nodeCnt = static_cast<uint32_t>(colors.size());

    vector<vector<uint32_t>> grid(nodeCnt);
    vector<uint32_t> inDegree(nodeCnt, 0);

    for (const vector<int32_t> &edge : edges) {
        grid[static_cast<uint32_t>(edge[EDGE_START])].push_back(static_cast<uint32_t>(edge[EDGE_END]));
        ++inDegree[static_cast<uint32_t>(edge[EDGE_END])];
    }

    queue<uint32_t> nodeQue;

    for (uint32_t i = 0; i < nodeCnt; i++) {
        if (inDegree[i] == 0) {
            nodeQue.push(i);
        }
    }
    vector<vector<int32_t>> colorTable(nodeCnt, vector<int32_t>(COLOR_CNT));
    uint32_t processNodeCnt = 0;

    while (!nodeQue.empty()) {
        processNodeCnt++;

        uint32_t node = nodeQue.front();
        nodeQue.pop();
        uint32_t idx = static_cast<uint32_t>(colors[node]) - 'a';
        colorTable[node][idx]++;

        for (uint32_t next : grid[node]) {
            inDegree[next]--;
            for (uint32_t c = 0; c < COLOR_CNT; c++) {
                colorTable[next][c] = max(colorTable[next][c], colorTable[node][c]);
            }
            if (inDegree[next] == 0) {
                nodeQue.push(next);
            }
        }
    }

    if (processNodeCnt < nodeCnt) {
        return -1;
    }

    int32_t ans = 0;

    for (const vector<int32_t> &colorNumList : colorTable) {
        for (int n : colorNumList) {
            ans = max(n, ans);
        }
    }
    return ans;
}
