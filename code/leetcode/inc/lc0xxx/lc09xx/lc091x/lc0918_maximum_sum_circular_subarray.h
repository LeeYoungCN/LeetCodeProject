/*
 * Time : 2025-05-20 17:47:22
 * URL  : https://leetcode.cn/problems/maximum-sum-circular-subarray/description/
 */

#ifndef LC0918_MAXIMUM_SUM_CIRCULAR_SUBARRAY_H
#define LC0918_MAXIMUM_SUM_CIRCULAR_SUBARRAY_H

#include <vector>

class LC0918_MaximumSumCircularSubarray {
public:
    LC0918_MaximumSumCircularSubarray() = default;
    virtual ~LC0918_MaximumSumCircularSubarray() = default;
    virtual int maxSubarraySumCircular(std::vector<int>& nums) = 0;
};

class LC0918_MaximumSumCircularSubarray_Reverse : public LC0918_MaximumSumCircularSubarray {
public:
    int maxSubarraySumCircular(std::vector<int>& nums) final;
};

class LC0918_MaximumSumCircularSubarray_Stack : public LC0918_MaximumSumCircularSubarray {
public:
    int maxSubarraySumCircular(std::vector<int>& nums) final;
};

class LC0918_MaximumSumCircularSubarray_DP : public LC0918_MaximumSumCircularSubarray {
public:
    int maxSubarraySumCircular(std::vector<int>& nums) final;
};

#endif  // LC0918_MAXIMUM_SUM_CIRCULAR_SUBARRAY_H
