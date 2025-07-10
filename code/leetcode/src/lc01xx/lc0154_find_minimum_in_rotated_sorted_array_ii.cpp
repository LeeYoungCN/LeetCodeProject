/*
 * Time : 2025-06-17 23:18:53
 * URL  :
 * https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array-ii/description/?envType=problem-list-v2URL_STRenvId=binary-search
 */
#include "lc01xx/lc0154_find_minimum_in_rotated_sorted_array_ii.h"

#include <algorithm>
#include <cstdint>
#include <vector>

using namespace std;

int32_t LC0154_FindMinimumInRotatedSortedArrayII_F1::findMin(vector<int32_t>& nums)
{
    uint32_t left = 0;
    auto right = static_cast<uint32_t>(nums.size()) - 1;

    while (left < right) {
        uint32_t curr = (left + right) / 2;
        if (curr == left) {
            break;
        }

        if (nums[curr] == nums[right] || nums[curr] == nums[left]) {
            if (nums[curr] == nums[left]) {
                left = left + 1;
            }

            if (nums[curr] == nums[right]) {
                right = (right == 0 ? right : right - 1);
            }
            continue;
        }

        if (nums[curr] > nums[left] && nums[curr] > nums[right]) {
            left = curr + 1;
        } else if (nums[curr] < nums[left] && nums[curr] < nums[right]) {
            right = curr;
        } else {
            break;
        }
    }

    return min(nums[left], nums[right]);
}

int32_t LC0154_FindMinimumInRotatedSortedArrayII_F2::findMin(vector<int32_t>& nums)
{
    uint32_t left = 0;
    auto right = static_cast<uint32_t>(nums.size()) - 1;
    while (left < right) {
        uint32_t curr = (left + right) / 2;
        if (nums[curr] > nums[right]) {
            left = curr + 1;
        } else if (nums[curr] < nums[right]) {
            right = curr;
        } else {
            --right;
        }
    }
    return nums[left];
}
