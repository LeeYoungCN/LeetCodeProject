/*
 * Time : 2025-06-12 10:12:40
 * URL  :
 * https://leetcode.cn/problems/minimum-size-subarray-sum/description/?envType=problem-list-v2URL_STRenvId=prefix-sum
 */
#ifndef LC0209_MINIMUM_SIZE_SUBARRAY_SUM_H
#define LC0209_MINIMUM_SIZE_SUBARRAY_SUM_H

#include <vector>

class LC0209_MinimumSizeSubarraySum {
public:
    LC0209_MinimumSizeSubarraySum() = default;
    virtual ~LC0209_MinimumSizeSubarraySum() = default;
    virtual int minSubArrayLen(int target, std::vector<int>& nums) = 0;
};

class LC0209_MinimumSizeSubarraySum_MyLowerBound : public LC0209_MinimumSizeSubarraySum {
public:
    LC0209_MinimumSizeSubarraySum_MyLowerBound() = default;
    ~LC0209_MinimumSizeSubarraySum_MyLowerBound() override = default;
    int minSubArrayLen(int target, std::vector<int>& nums) final;

private:
    unsigned int FindLastLessEqual(const std::vector<int>& prefixSums, int num);
};

class LC0209_MinimumSizeSubarraySum_StdLowerBound : public LC0209_MinimumSizeSubarraySum {
public:
    LC0209_MinimumSizeSubarraySum_StdLowerBound() = default;
    ~LC0209_MinimumSizeSubarraySum_StdLowerBound() override = default;
    int minSubArrayLen(int target, std::vector<int>& nums) final;
};

class LC0209_MinimumSizeSubarraySum_Loop : public LC0209_MinimumSizeSubarraySum {
public:
    LC0209_MinimumSizeSubarraySum_Loop() = default;
    ~LC0209_MinimumSizeSubarraySum_Loop() override = default;
    int minSubArrayLen(int target, std::vector<int>& nums) final;
};

class LC0209_MinimumSizeSubarraySum_SlidingWindow : public LC0209_MinimumSizeSubarraySum {
public:
    LC0209_MinimumSizeSubarraySum_SlidingWindow() = default;
    ~LC0209_MinimumSizeSubarraySum_SlidingWindow() override = default;
    int minSubArrayLen(int target, std::vector<int>& nums) final;
};

#endif  // LC0209_MINIMUM_SIZE_SUBARRAY_SUM_H
