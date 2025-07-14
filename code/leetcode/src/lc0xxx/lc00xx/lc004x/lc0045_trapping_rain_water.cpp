/*
 * Time : 2025-07-14 15:30:14
 * URL  : https://leetcode.cn/problems/trapping-rain-water/description/
 */
#include "lc0xxx/lc00xx/lc004x/lc0045_trapping_rain_water.h"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <stack>
#include <vector>

using namespace std;

int32_t LC0045_TrappingRainWater_MonotonicStack::trap(std::vector<int32_t>& height)
{
    std::stack<uint32_t> hStack;
    int32_t ans = 0;
    for (uint32_t i = 0; i < height.size(); i++) {
        while (!hStack.empty() && height.at(hStack.top()) < height[i]) {
            int32_t bottom = height.at(hStack.top());
            hStack.pop();
            if (hStack.empty()) {
                break;
            }
            auto h = static_cast<int32_t>(i - hStack.top() - 1);
            auto w = min(height.at(hStack.top()), height[i]) - bottom;
            ans += h * w;
        }
        hStack.push(i);
    }
    return ans;
}

int32_t LC0045_TrappingRainWater_LeftAndRightMax::trap(std::vector<int32_t>& height)
{
    std::vector<int32_t> leftMax(height.size(), 0);
    std::vector<int32_t> rightMax(height.size(), 0);
    for (std::size_t i = 0; i < height.size(); ++i) {
        std::size_t j = height.size() - i - 1;
        if (i == 0) {
            leftMax[i] = height[i];
            rightMax[j] = height[j];
        } else {
            leftMax[i] = max(height[i], leftMax[i - 1]);
            rightMax[j] = max(height[j], rightMax[j + 1]);
        }
    }
    int32_t ans = 0;
    for (std::size_t i = 0; i < height.size(); ++i) {
        ans += min(leftMax[i], rightMax[i]) - height[i];
    }
    return ans;
}
