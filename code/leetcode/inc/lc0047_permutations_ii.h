/*
 * Time : 2025-06-27 17:05:51
 * URL  : https://leetcode.cn/problems/permutations-ii/description/
 */
#ifndef LC0047_PERMUTATIONS_II_H
#define LC0047_PERMUTATIONS_II_H

#include <set>
#include <vector>

class LC0047_PermutationsII {
public:
    LC0047_PermutationsII() = default;
    virtual ~LC0047_PermutationsII() = default;
    virtual std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) = 0;
};

class LC0047_PermutationsII_Set : public LC0047_PermutationsII {
public:
    LC0047_PermutationsII_Set() = default;
    ~LC0047_PermutationsII_Set() override = default;
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) final;

private:
    void dfs(const std::vector<int>& nums, std::vector<int>& permution, std::vector<bool>& visitor,
             std::set<std::vector<int>>& listSet);
};

class LC0047_PermutationsII_Sort : public LC0047_PermutationsII {
public:
    LC0047_PermutationsII_Sort() = default;
    ~LC0047_PermutationsII_Sort() override = default;
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) final;

private:
    void dfs(const std::vector<int>& nums, std::vector<bool>& visitor, std::vector<int>& permution,
             std::vector<std::vector<int>>& ans);
};

#endif  // LC0047_PERMUTATIONS_II_H
