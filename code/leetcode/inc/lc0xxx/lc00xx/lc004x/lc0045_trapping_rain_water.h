/*
 * Time : 2025-07-14 15:30:14
 * URL  : https://leetcode.cn/problems/trapping-rain-water/description/
 */
#ifndef LC0045_TRAPPING_RAIN_WATER_H
#define LC0045_TRAPPING_RAIN_WATER_H

#include <cstdint>
#include <vector>

class LC0045_TrappingRainWater {
public:
    LC0045_TrappingRainWater() = default;
    virtual ~LC0045_TrappingRainWater() = default;
    virtual int32_t trap(std::vector<int32_t>& height) = 0;
};

class LC0045_TrappingRainWater_MonotonicStack : public LC0045_TrappingRainWater {
public:
    LC0045_TrappingRainWater_MonotonicStack() = default;
    ~LC0045_TrappingRainWater_MonotonicStack() override = default;
    int32_t trap(std::vector<int32_t>& height) final;
};

class LC0045_TrappingRainWater_LeftAndRightMax : public LC0045_TrappingRainWater {
public:
    LC0045_TrappingRainWater_LeftAndRightMax() = default;
    ~LC0045_TrappingRainWater_LeftAndRightMax() override = default;
    int32_t trap(std::vector<int32_t>& height) final;
};

#endif  // LC0045_TRAPPING_RAIN_WATER_H
