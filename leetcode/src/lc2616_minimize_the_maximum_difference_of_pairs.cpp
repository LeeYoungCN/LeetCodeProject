/*
 * Time : 2025-06-13 14:04:58
 * URL  :
 * https://leetcode.cn/problems/minimize-the-maximum-difference-of-pairs/description/?envType=daily-questionURL_STRenvId=2025-06-13
 */
#include "lc2616_minimize_the_maximum_difference_of_pairs.h"

#include <algorithm>
#include <cstdint>
#include <functional>
#include <vector>

using namespace std;

int LC2616_MinimizeTheMaximumDifferenceOfPairs::minimizeMax(vector<int>& nums, int p)
{
    const auto length = static_cast<uint32_t>(nums.size());
    sort(nums.begin(), nums.end());

    function isValid = [&](const int32_t delta) -> bool {
        int32_t cnt = 0;
        for (uint32_t i = 0; i < length - 1; ++i) {
            if (nums[i + 1] - nums[i] <= delta) {
                cnt++;
                i++;
            }
        }
        return cnt >= p;
    };
    int32_t left = 0;
    int32_t right = nums.back() - nums.at(0);

    while (left < right) {
        int32_t curr = (left + right) / 2;
        if (isValid(curr)) {
            right = curr;
        } else {
            left = curr + 1;
        }
    }
    return left;
}
