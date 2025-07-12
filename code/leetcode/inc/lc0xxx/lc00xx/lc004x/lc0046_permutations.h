/*
 * Time : 2025-06-27 17:46:05
 * URL  : https://leetcode.cn/problems/permutations/description/
 */
#ifndef LC0046_PERMUTATIONS_H
#define LC0046_PERMUTATIONS_H

#include <vector>

class LC0046_Permutations {
public:
    LC0046_Permutations() = default;
    virtual ~LC0046_Permutations() = default;
    std::vector<std::vector<int>> permute(std::vector<int>& nums);
};

#endif  // LC0046_PERMUTATIONS_H
