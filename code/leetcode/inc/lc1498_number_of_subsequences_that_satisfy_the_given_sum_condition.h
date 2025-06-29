/*
 * Time : 2025-06-29 11:23:20
 * URL  :
 * https://leetcode.cn/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/?envType=daily-question&envId=2025-06-29
 */
#ifndef LC1498_NUMBER_OF_SUBSEQUENCES_THAT_SATISFY_THE_GIVEN_SUM_CONDITION_H
#define LC1498_NUMBER_OF_SUBSEQUENCES_THAT_SATISFY_THE_GIVEN_SUM_CONDITION_H

#include <vector>

class LC1498_NumberOfSubsequencesThatSatisfyTheGivenSumCondition {
public:
    LC1498_NumberOfSubsequencesThatSatisfyTheGivenSumCondition() = default;
    virtual ~LC1498_NumberOfSubsequencesThatSatisfyTheGivenSumCondition() = default;
    int numSubseq(std::vector<int>& nums, int target);
};

#endif  // LC1498_NUMBER_OF_SUBSEQUENCES_THAT_SATISFY_THE_GIVEN_SUM_CONDITION_H
