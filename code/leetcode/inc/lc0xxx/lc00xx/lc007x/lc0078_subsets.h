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
    virtual std::vector<std::vector<int32_t>> subsets(std::vector<int32_t>& nums) = 0;
};

class LC0078_Subsets_Enum : public LC0078_Subsets {
public:
    LC0078_Subsets_Enum() = default;
    ~LC0078_Subsets_Enum() override = default;
    std::vector<std::vector<int32_t>> subsets(std::vector<int32_t>& nums) final;
};

class LC0078_Subsets_DFS : public LC0078_Subsets {
public:
    LC0078_Subsets_DFS() = default;
    ~LC0078_Subsets_DFS() override = default;
    std::vector<std::vector<int32_t>> subsets(std::vector<int32_t>& nums) final;
};

#endif  // LC0078_SUBSETS_H
