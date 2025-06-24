/*
 * Time : 2025-06-16 15:03:49
 * URL  :
 * https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/?envType=problem-list-v2URL_STRenvId=binary-search
 */
#include "lc0034_find_first_and_last_position_of_element_in_sorted_array.h"

#include <cstdint>
#include <functional>
#include <vector>

using namespace std;

vector<int> LC0034_FindFirstAndLastPositionOfElementInSortedArray::searchRange(vector<int>& nums, int target)
{
    constexpr uint32_t FIRST = 0;
    constexpr uint32_t LAST = 1;

    function findTargetPos = [&](const uint32_t pos) -> int32_t {
        uint32_t left = 0;
        auto right = static_cast<uint32_t>(nums.size());
        uint32_t ans = UINT32_MAX;
        while (left < right) {
            uint32_t curr = (left + right) / 2;
            if (nums[curr] == target) {
                ans = curr;
                if (pos == FIRST) {
                    right = curr;
                } else {
                    left = curr + 1;
                }
            } else if (nums[curr] < target) {
                left = curr + 1;
            } else {
                right = curr;
            }
        }

        return ans == UINT32_MAX ? -1 : static_cast<int32_t>(ans);
    };

    return vector<int32_t>{findTargetPos(FIRST), findTargetPos(LAST)};
}
