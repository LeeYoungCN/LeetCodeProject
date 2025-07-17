/*
 * Time : 2025-07-17 15:26:19
 * URL  :
 * https://leetcode.cn/problems/find-the-maximum-length-of-valid-subsequence-ii/description/?envType=daily-question&envId=2025-07-17
 */
#ifndef LC3202_FIND_THE_MAXIMUM_LENGTH_OF_VALID_SUBSEQUENCE_II_H
#define LC3202_FIND_THE_MAXIMUM_LENGTH_OF_VALID_SUBSEQUENCE_II_H

#include <cstdint>
#include <vector>

class LC3202_FindTheMaximumLengthOfValidSubsequenceII {
public:
    LC3202_FindTheMaximumLengthOfValidSubsequenceII() = default;
    virtual ~LC3202_FindTheMaximumLengthOfValidSubsequenceII() = default;
    virtual int32_t maximumLength(std::vector<int32_t>& nums, int32_t k) = 0;
};

class LC3202_FindTheMaximumLengthOfValidSubsequenceII_DP : public LC3202_FindTheMaximumLengthOfValidSubsequenceII {
public:
    LC3202_FindTheMaximumLengthOfValidSubsequenceII_DP() = default;
    ~LC3202_FindTheMaximumLengthOfValidSubsequenceII_DP() override = default;
    int32_t maximumLength(std::vector<int32_t>& nums, int32_t k) override;
};

class LC3202_FindTheMaximumLengthOfValidSubsequenceII_Enum : public LC3202_FindTheMaximumLengthOfValidSubsequenceII {
public:
    LC3202_FindTheMaximumLengthOfValidSubsequenceII_Enum() = default;
    ~LC3202_FindTheMaximumLengthOfValidSubsequenceII_Enum() override = default;
    int32_t maximumLength(std::vector<int32_t>& nums, int32_t k) override;
};

#endif  // LC3202_FIND_THE_MAXIMUM_LENGTH_OF_VALID_SUBSEQUENCE_II_H
