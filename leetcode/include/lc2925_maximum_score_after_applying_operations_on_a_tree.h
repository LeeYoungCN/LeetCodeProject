/*
 * Time : 2025-05-24 17:13:11
 * URL  : https://leetcode.cn/problems/maximum-score-after-applying-operations-on-a-tree/description/
 */
#ifndef LC2925_MAXIMUM_SCORE_AFTER_APPLYING_OPERATIONS_ON_A_TREE_H
#define LC2925_MAXIMUM_SCORE_AFTER_APPLYING_OPERATIONS_ON_A_TREE_H

#include <vector>

class LC2925_MaximumScoreAfterApplyingOperationsOnATree {
public:
    LC2925_MaximumScoreAfterApplyingOperationsOnATree() = default;
    virtual ~LC2925_MaximumScoreAfterApplyingOperationsOnATree() = default;
    long long maximumScoreAfterOperations(std::vector<std::vector<int>>& edges, std::vector<int>& values);
};

#endif  // LC2925_MAXIMUM_SCORE_AFTER_APPLYING_OPERATIONS_ON_A_TREE_H
