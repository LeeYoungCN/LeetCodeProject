/*
 * Time : 2025-06-16 17:41:26
 * URL  : https://leetcode.cn/problems/search-in-rotated-sorted-array/description/
 */
#ifndef LC0033_SEARCH_IN_ROTATED_SORTED_ARRAY_H
#define LC0033_SEARCH_IN_ROTATED_SORTED_ARRAY_H

#include <vector>

class LC0033_SearchInRotatedSortedArray {
public:
    LC0033_SearchInRotatedSortedArray() = default;
    virtual ~LC0033_SearchInRotatedSortedArray() = default;
    int search(std::vector<int>& nums, int target);
};

#endif  // LC0033_SEARCH_IN_ROTATED_SORTED_ARRAY_H
