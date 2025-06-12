/*
 * Time : 2025-06-12 10:00:49
 * URL  :
 * https://leetcode.cn/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/?envType=daily-questionURL_STRenvId=2025-06-12
 */
#include "lc3423_maximum_difference_between_adjacent_elements_in_a_circular_array.h"

#include <cstdint>
#include <cstdlib>
#include <vector>

using namespace std;

int32_t LC3423_MaximumDifferenceBetweenAdjacentElementsInACircularArray::maxAdjacentDistance(vector<int32_t>& nums)
{
    const auto length = static_cast<uint32_t>(nums.size());
    int32_t ans = 0;
    for (uint32_t i = 0; i < length; i++) {
        int32_t delta = 0;
        if (i == 0) {
            delta = nums[0] - nums[length - 1];
        } else {
            delta = nums[i] - nums[i - 1];
        }
        ans = max(ans, abs(delta));
    }
    return ans;
}
