/*
 * Time : 2025-05-26 10:28:20
 * URL  :
 * https://leetcode.cn/problems/largest-color-value-in-a-directed-graph/description/?envType=daily-questionURL_STRenvId=2025-05-26
 */
#include "lc1847_largest_color_value_in_a_directed_graph.h"

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <functional>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

namespace {
const uint32_t COLOR_CNT = 26;
}

bool LC1847_LargestColorValueInADirectedGraph_DFS::dfs(int32_t curr, vector<VisitStatus> &visitor,
                                                       vector<vector<int32_t>> &dp, const vector<vector<int32_t>> &grid)
{
    if (visitor[curr] == USING) {
        return false;
    }

    if (visitor[curr] == FINISH) {
        return true;
    }

    visitor[curr] = USING;

    for (int32_t child : grid[curr]) {
        if (!dfs(child, visitor, dp, grid)) {
            return false;
        }
        for (uint32_t i = 0; i < COLOR_CNT; i++) {
            dp[curr][i] = max(dp[child][i], dp[curr][i]);
        }
    }

    dp[curr][m_colors[curr] - 'a'] += 1;
    visitor[curr] = FINISH;
    return true;
};

int LC1847_LargestColorValueInADirectedGraph_DFS::largestPathValue(string colors, vector<vector<int>> &edges)
{
    m_colors = colors;
    m_edges = edges;
    uint32_t nodeCnt = m_colors.size();
    vector<vector<int32_t>> grid(nodeCnt);

    for (const vector<int32_t> &edge : m_edges) {
        grid[edge[0]].push_back(edge[1]);
    }

    vector<vector<int32_t>> dp(nodeCnt, vector<int32_t>(COLOR_CNT));
    vector<VisitStatus> visitor(nodeCnt, UNUSED);

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
