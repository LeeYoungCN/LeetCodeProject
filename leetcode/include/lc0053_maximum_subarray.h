/*
 * Time : 2025-05-20 01:28:53
 * URL  : https://leetcode.cn/problems/maximum-subarray/description/
 */
#ifndef LC0053_MAXIMUM_SUBARRAY_H
#define LC0053_MAXIMUM_SUBARRAY_H
#include <vector>

class LC0053_MaximumSubarray {
    public:
        LC0053_MaximumSubarray() = default;
        virtual ~LC0053_MaximumSubarray() = default;
        virtual int maxSubArray(std::vector<int>& nums) = 0;
};


class LC0053_MaximumSubarray_dp : public LC0053_MaximumSubarray {
    public:
        int maxSubArray(std::vector<int>& nums) override;
};

class LC0053_MaximumSubarray_stack : public LC0053_MaximumSubarray {
    public:
        int maxSubArray(std::vector<int>& nums) override;
};

#endif // LC0053_MAXIMUM_SUBARRAY_H
