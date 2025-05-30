// https://leetcode.cn/problems/sort-colors/description/?envType=daily-question&envId=2025-05-17
#include "lc0075_sort_colors.h"

#include <cstdint>
#include <vector>

using namespace std;

void LC0075_SortColors::sortColors(vector<int> &nums)
{
    sort(nums, 0, (uint32_t)nums.size());
}

void LC0075_SortColors::sort(vector<int> &nums, uint32_t start, uint32_t length)
{
    if (length <= 1) {
        return;
    }
    uint32_t lStart = start;
    uint32_t lLength = length / 2;
    uint32_t rStart = lStart + lLength;
    uint32_t rLength = length - lLength;

    sort(nums, lStart, lLength);
    sort(nums, rStart, rLength);

    merge(nums, lStart, lLength, rStart, rLength);
}

void LC0075_SortColors::merge(vector<int> &nums, uint32_t lStart, uint32_t lLen, uint32_t rStart, uint32_t rLen)
{
    const uint32_t length = lLen + rLen;
    vector<int> temp(length);
    uint32_t lIndex = 0;
    uint32_t rIndex = 0;

    for (uint32_t i = 0; i < length; i++) {
        if (lIndex >= lLen) {
            temp[i] = nums[rStart + rIndex++];
        } else if (rIndex >= rLen) {
            temp[i] = nums[lStart + lIndex++];
        } else {
            if (nums[lStart + lIndex] < nums[rStart + rIndex]) {
                temp[i] = nums[lStart + lIndex++];
            } else {
                temp[i] = nums[rStart + rIndex++];
            }
        }
    }
    for (uint32_t i = 0; i < length; i++) {
        nums[lStart + i] = temp[i];
    }
}
