/*
 * Time : 2025-07-02 19:06:43
 * URL  : https://leetcode.cn/problems/path-sum/?envType=problem-list-v2&envId=depth-first-search
 */
#ifndef LC0112_PATH_SUM_H
#define LC0112_PATH_SUM_H

#include "leetcode_utils/leetcode_utils_tree_node.hpp"

class LC0112_PathSum {
public:
    LC0112_PathSum() = default;
    virtual ~LC0112_PathSum() = default;
    bool hasPathSum(TreeNode* root, int32_t targetSum);
};

#endif  // LC0112_PATH_SUM_H
