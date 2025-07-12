/*
 * Time : 2025-06-29 14:38:01
 * URL  : https://leetcode.cn/problems/count-pairs-whose-sum-is-less-than-target/description/
 */
#ifndef LC2824_COUNT_PAIRS_WHOSE_SUM_IS_LESS_THAN_TARGET_H
#define LC2824_COUNT_PAIRS_WHOSE_SUM_IS_LESS_THAN_TARGET_H

#include <cstddef>
#include <cstdint>
#include <vector>

class LC2824_CountPairsWhoseSumIsLessThanTarget {
public:
    LC2824_CountPairsWhoseSumIsLessThanTarget() = default;
    virtual ~LC2824_CountPairsWhoseSumIsLessThanTarget() = default;
    virtual int32_t countPairs(std::vector<int32_t>& nums, int32_t target) = 0;
};

class LC2824_CountPairsWhoseSumIsLessThanTarget_Enum : public LC2824_CountPairsWhoseSumIsLessThanTarget {
public:
    LC2824_CountPairsWhoseSumIsLessThanTarget_Enum() = default;
    ~LC2824_CountPairsWhoseSumIsLessThanTarget_Enum() override = default;
    int32_t countPairs(std::vector<int32_t>& nums, int32_t target) override;
};

class LC2824_CountPairsWhoseSumIsLessThanTarget_Find : public LC2824_CountPairsWhoseSumIsLessThanTarget {
public:
    LC2824_CountPairsWhoseSumIsLessThanTarget_Find() = default;
    ~LC2824_CountPairsWhoseSumIsLessThanTarget_Find() override = default;
    int32_t countPairs(std::vector<int32_t>& nums, int32_t target) override;

private:
    size_t findLowerBound(const std::vector<int32_t>& nums, size_t end, int32_t target);
};

class LC2824_CountPairsWhoseSumIsLessThanTarget_DoublePtr : public LC2824_CountPairsWhoseSumIsLessThanTarget {
public:
    LC2824_CountPairsWhoseSumIsLessThanTarget_DoublePtr() = default;
    ~LC2824_CountPairsWhoseSumIsLessThanTarget_DoublePtr() override = default;
    int32_t countPairs(std::vector<int32_t>& nums, int32_t target) override;
};

#endif  // LC2824_COUNT_PAIRS_WHOSE_SUM_IS_LESS_THAN_TARGET_H
