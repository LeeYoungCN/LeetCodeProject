/*
 * Time : 2025-07-13 19:56:45
 * URL  : https://leetcode.cn/problems/single-element-in-a-sorted-array/description/
 */
#include "lc0xxx/lc05xx/lc054x/lc0540_single_element_in_a_sorted_array.h"

#include <cstddef>
#include <cstdint>
#include <vector>

using namespace std;

int32_t LC0540_SingleElementInASortedArray::singleNonDuplicate(std::vector<int32_t>& nums)
{
    size_t left = 0;
    size_t right = nums.size();

    while (left < right) {
        size_t curr = (left + right) / 2;
        if (curr == 0 || curr == nums.size() - 1) {
            return nums[curr];
        }

        if (((curr % 2 == 1) && nums.at(curr) == nums.at(curr - 1)) ||
            ((curr % 2 == 0) && nums.at(curr) == nums.at(curr + 1))) {
            left = curr + 1;
        } else {
            right = curr;
        }
    }

    return nums[left];
}
