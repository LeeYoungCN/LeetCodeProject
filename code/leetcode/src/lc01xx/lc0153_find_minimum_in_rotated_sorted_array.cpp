/*
 * Time : 2025-06-17 17:27:54
 * URL  :
 * https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/description/?envType=problem-list-v2URL_STRenvId=binary-search
 */
#include "lc01xx/lc0153_find_minimum_in_rotated_sorted_array.h"

#include <algorithm>
#include <cstdint>
#include <vector>

using namespace std;

int LC0153_FindMinimumInRotatedSortedArray_F1::findMin(vector<int>& nums)
{
    uint32_t left = 0;
    auto right = static_cast<uint32_t>(nums.size()) - 1;

    while (left < right) {
        uint32_t curr = (left + right) / 2;
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

int LC0153_FindMinimumInRotatedSortedArray_F2::findMin(vector<int>& nums)
{
    uint32_t left = 0;
    auto right = static_cast<uint32_t>(nums.size()) - 1;
    while (left < right) {
        uint32_t curr = (left + right) / 2;
        if (nums[curr] > nums[right]) {
            left = curr + 1;
        } else {
            right = curr;
        }
    }
    return nums[left];
}
