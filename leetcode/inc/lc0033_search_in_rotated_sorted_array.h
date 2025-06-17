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
    virtual int search(std::vector<int>& nums, int target) = 0;
};

class LC0033_SearchInRotatedSortedArray_F1 : public LC0033_SearchInRotatedSortedArray {
public:
    LC0033_SearchInRotatedSortedArray_F1() = default;
    ~LC0033_SearchInRotatedSortedArray_F1() override = default;
    int search(std::vector<int>& nums, int target) final;
};

class LC0033_SearchInRotatedSortedArray_F2 : public LC0033_SearchInRotatedSortedArray {
public:
    LC0033_SearchInRotatedSortedArray_F2() = default;
    ~LC0033_SearchInRotatedSortedArray_F2() override = default;
    int search(std::vector<int>& nums, int target) final;
};

#endif  // LC0033_SEARCH_IN_ROTATED_SORTED_ARRAY_H
