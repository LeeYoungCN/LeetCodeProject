/*
 * Time : 2025-06-16 17:41:26
 * URL  : https://leetcode.cn/problems/search-in-rotated-sorted-array/description/
 */
#include "lc0033_search_in_rotated_sorted_array.h"

#include <cstdint>
#include <functional>
#include <vector>

using namespace std;

int32_t LC0033_SearchInRotatedSortedArray::search(vector<int32_t>& nums, int32_t target)
{
    uint32_t left = 0;
    auto right = static_cast<uint32_t>(nums.size());

    function isLeftArea = [&](int32_t n) -> bool { return n >= nums[0]; };
    bool isTargetInLeft = isLeftArea(target);

    while (left < right) {
        uint32_t curr = (left + right) / 2;
        if (nums[curr] == target) {
            return static_cast<int32_t>(curr);
        }

        if (isTargetInLeft == isLeftArea(nums[curr])) {
            if (nums[curr] < target) {
                left = curr + 1;  // 右缩进
            } else {
                right = curr;  // 左缩进
            }
        } else {
            if (isTargetInLeft) {
                right = curr;  // 左缩进
            } else {
                left = curr + 1;  // 右缩进
            }
        }
    }

    return -1;
}
