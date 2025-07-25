/*
 * Time : 2025-07-25 09:10:06
 * URL  :
 * https://leetcode.cn/problems/maximum-unique-subarray-sum-after-deletion/description/?envType=daily-question&envId=2025-07-25
 */
#ifndef LC3487_MAXIMUM_UNIQUE_SUBARRAY_SUM_AFTER_DELETION_H
#define LC3487_MAXIMUM_UNIQUE_SUBARRAY_SUM_AFTER_DELETION_H

#include <cstdint>
#include <vector>

class LC3487_MaximumUniqueSubarraySumAfterDeletion {
public:
    LC3487_MaximumUniqueSubarraySumAfterDeletion() = default;
    virtual ~LC3487_MaximumUniqueSubarraySumAfterDeletion() = default;
    int32_t maxSum(std::vector<int32_t>& nums);
};

#endif  // LC3487_MAXIMUM_UNIQUE_SUBARRAY_SUM_AFTER_DELETION_H
