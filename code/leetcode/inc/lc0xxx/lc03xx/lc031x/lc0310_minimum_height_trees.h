/*
 * Time : 2025-05-29 17:35:45
 * URL  : https://leetcode.cn/problems/minimum-height-trees/
 */
#ifndef LC0310_MINIMUM_HEIGHT_TREES_H
#define LC0310_MINIMUM_HEIGHT_TREES_H

#include <vector>

class LC0310_MinimumHeightTrees {
public:
    LC0310_MinimumHeightTrees() = default;
    virtual ~LC0310_MinimumHeightTrees() = default;
    virtual std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges) = 0;
};

class LC0310_MinimumHeightTrees_DFS : public LC0310_MinimumHeightTrees {
public:
    LC0310_MinimumHeightTrees_DFS() = default;
    ~LC0310_MinimumHeightTrees_DFS() override = default;
    std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges) final;
};

class LC0310_MinimumHeightTrees_BFS : public LC0310_MinimumHeightTrees {
public:
    LC0310_MinimumHeightTrees_BFS() = default;
    ~LC0310_MinimumHeightTrees_BFS() override = default;
    std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges) final;
};

class LC0310_MinimumHeightTrees_TopologicalSort : public LC0310_MinimumHeightTrees {
public:
    LC0310_MinimumHeightTrees_TopologicalSort() = default;
    ~LC0310_MinimumHeightTrees_TopologicalSort() override = default;
    std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges) final;
};

#endif  // LC0310_MINIMUM_HEIGHT_TREES_H
