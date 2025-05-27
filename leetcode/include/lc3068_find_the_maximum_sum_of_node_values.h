/*
 * Time : 2025-05-23 01:03:47
 * URL  :
 * https://leetcode.cn/problems/find-the-maximum-sum-of-node-values/description/?envType=daily-questionURL_STRenvId=2025-05-23
 */
#ifndef LC3068_FIND_THE_MAXIMUM_SUM_OF_NODE_VALUES_H
#define LC3068_FIND_THE_MAXIMUM_SUM_OF_NODE_VALUES_H

#include <vector>

class LC3068_FindTheMaximumSumOfNodeValues {
public:
    LC3068_FindTheMaximumSumOfNodeValues() = default;
    virtual ~LC3068_FindTheMaximumSumOfNodeValues() = default;
    virtual long long maximumValueSum(std::vector<int>& nums, int k, std::vector<std::vector<int>>& edges) = 0;
};

class LC3068_FindTheMaximumSumOfNodeValues_Greedy : public LC3068_FindTheMaximumSumOfNodeValues {
public:
    LC3068_FindTheMaximumSumOfNodeValues_Greedy() = default;
    ~LC3068_FindTheMaximumSumOfNodeValues_Greedy() override = default;
    long long maximumValueSum(std::vector<int>& nums, int k, std::vector<std::vector<int>>& edges) override;
};

class LC3068_FindTheMaximumSumOfNodeValues_DFS : public LC3068_FindTheMaximumSumOfNodeValues {
public:
    LC3068_FindTheMaximumSumOfNodeValues_DFS() = default;
    ~LC3068_FindTheMaximumSumOfNodeValues_DFS() override = default;
    long long maximumValueSum(std::vector<int>& nums, int k, std::vector<std::vector<int>>& edges) override;
};

#endif  // LC3068_FIND_THE_MAXIMUM_SUM_OF_NODE_VALUES_H
