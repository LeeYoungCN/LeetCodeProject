/*
 * Time : 2025-06-16 17:41:26
 * URL  : https://leetcode.cn/problems/search-in-rotated-sorted-array/description/
 */
#include "lc0033_search_in_rotated_sorted_array.h"

#include <cstdint>
#include <functional>
#include <vector>

using namespace std;

int32_t LC0033_SearchInRotatedSortedArray_F1::search(vector<int32_t>& nums, int32_t target)
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
                left = curr + 1;
            } else {
                right = curr;
            }
        } else {
            if (isTargetInLeft) {
                right = curr;
            } else {
                left = curr + 1;
            }
        }
    }

    return -1;
}

int32_t LC0033_SearchInRotatedSortedArray_F2::search(vector<int32_t>& nums, int32_t target)
{
    uint32_t left = 0;
    auto right = static_cast<uint32_t>(nums.size());

    function isLeftArea = [&](uint32_t left, int32_t n) -> bool { return n >= nums[left]; };

    while (left < right) {
        uint32_t curr = (left + right) / 2;
        if (nums[curr] == target) {
            return static_cast<int32_t>(curr);
        }

        if (isLeftArea(left, target) == isLeftArea(left, nums[curr])) {
            if (nums[curr] < target) {
                left = curr + 1;
            } else {
                right = curr;
            }
        } else {
            if (isLeftArea(left, target)) {
                right = curr;
            } else {
                left = curr + 1;
            }
        }
    }

    return -1;
}
