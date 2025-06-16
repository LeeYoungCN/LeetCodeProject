/*
 * Time : 2025-06-16 21:43:15
 * URL  :
 * https://leetcode.cn/problems/search-in-rotated-sorted-array-ii/description/?envType=problem-list-v2URL_STRenvId=binary-search
 */
#include "lc0081_search_in_rotated_sorted_array_ii.h"

#include <cmath>
#include <cstdint>
#include <vector>

using namespace std;

bool isLeftArea(const vector<int32_t>& nums, int32_t n)
{
    return n >= nums[0];
}

bool LC0081_SearchInRotatedSortedArrayII_DFS::dfs(const vector<int32_t>& nums, int32_t target, uint32_t left,
                                                  uint32_t right)
{
    if (left >= right) {
        return false;
    }

    const uint32_t curr = (left + right) / 2;
    const int32_t currNum = nums[curr];
    if (currNum == target) {
        return true;
    }

    if (currNum == nums[0] && currNum == nums.back()) {
        return (dfs(nums, target, curr + 1, right) || dfs(nums, target, left, curr));
    } else {
        if (isLeftArea(nums, target) == isLeftArea(nums, currNum)) {
            if (currNum < target) {
                left = curr + 1;  // 右缩进
            } else {
                right = curr;  // 左缩进
            }
        } else {
            if (isLeftArea(nums, target)) {
                right = curr;  // 左缩进
            } else {
                left = curr + 1;  // 右缩进
            }
        }
        return dfs(nums, target, left, right);
    }
}

bool LC0081_SearchInRotatedSortedArrayII_DFS::search(vector<int32_t>& nums, int32_t target)
{
    return dfs(nums, target, 0, static_cast<uint32_t>(nums.size()));
}
