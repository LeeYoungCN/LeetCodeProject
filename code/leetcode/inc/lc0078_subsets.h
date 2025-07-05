/*
 * Time : 2025-07-05 17:33:28
 * URL  : https://leetcode.cn/problems/subsets/description/
 */
#ifndef LC0078_SUBSETS_H
#define LC0078_SUBSETS_H

#include <cstdint>
#include <vector>

class LC0078_Subsets {
public:
    LC0078_Subsets() = default;
    virtual ~LC0078_Subsets() = default;
    std::vector<std::vector<int32_t>> subsets(std::vector<int32_t>& nums);
};

#endif  // LC0078_SUBSETS_H
