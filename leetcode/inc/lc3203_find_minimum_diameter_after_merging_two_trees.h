/*
 * Time : 2025-05-29 14:32:49
 * URL  : https://leetcode.cn/problems/find-minimum-diameter-after-merging-two-trees/
 */
#ifndef LC3203_FIND_MINIMUM_DIAMETER_AFTER_MERGING_TWO_TREES_H
#define LC3203_FIND_MINIMUM_DIAMETER_AFTER_MERGING_TWO_TREES_H

#include <vector>

class LC3203_FindMinimumDiameterAfterMergingTwoTrees {
public:
    LC3203_FindMinimumDiameterAfterMergingTwoTrees() = default;
    virtual ~LC3203_FindMinimumDiameterAfterMergingTwoTrees() = default;
    int minimumDiameterAfterMerge(std::vector<std::vector<int>>& edges1, std::vector<std::vector<int>>& edges2);

private:
    int GeDiameter(std::vector<std::vector<int>>& edges);
};

#endif  // LC3203_FIND_MINIMUM_DIAMETER_AFTER_MERGING_TWO_TREES_H
