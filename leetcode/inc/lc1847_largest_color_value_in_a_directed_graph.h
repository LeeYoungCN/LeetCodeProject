/*
 * Time : 2025-05-26 10:28:20
 * URL  :
 * https://leetcode.cn/problems/largest-color-value-in-a-directed-graph/description/?envType=daily-questionURL_STRenvId=2025-05-26
 */
#ifndef LC1847_LARGEST_COLOR_VALUE_IN_A_DIRECTED_GRAPH_H
#define LC1847_LARGEST_COLOR_VALUE_IN_A_DIRECTED_GRAPH_H

#include <string>
#include <vector>

class LC1847_LargestColorValueInADirectedGraph {
public:
    LC1847_LargestColorValueInADirectedGraph() = default;
    virtual ~LC1847_LargestColorValueInADirectedGraph() = default;
    virtual int largestPathValue(std::string colors, std::vector<std::vector<int>> &edges) = 0;
};

class LC1847_LargestColorValueInADirectedGraph_DFS : public LC1847_LargestColorValueInADirectedGraph {
public:
    LC1847_LargestColorValueInADirectedGraph_DFS() = default;
    ~LC1847_LargestColorValueInADirectedGraph_DFS() override = default;
    int largestPathValue(std::string colors, std::vector<std::vector<int>> &edges) override;

private:
    enum class VisitStatus { UNUSED = 0, USING, FINISH };
    bool dfs(int curr, std::vector<VisitStatus> &visitor, std::vector<std::vector<int>> &dp,
             const std::vector<std::vector<int>> &grid);

private:
    std::string m_colors;
    std::vector<std::vector<int>> m_edges;
};

class LC1847_LargestColorValueInADirectedGraph_BFS : public LC1847_LargestColorValueInADirectedGraph {
public:
    LC1847_LargestColorValueInADirectedGraph_BFS() = default;
    ~LC1847_LargestColorValueInADirectedGraph_BFS() override = default;
    int largestPathValue(std::string colors, std::vector<std::vector<int>> &edges) override;
};

#endif  // LC1847_LARGEST_COLOR_VALUE_IN_A_DIRECTED_GRAPH_H
