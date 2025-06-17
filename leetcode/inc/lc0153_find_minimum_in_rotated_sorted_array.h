/*
 * Time : 2025-06-17 17:27:54
 * URL  :
 * https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/description/?envType=problem-list-v2URL_STRenvId=binary-search
 */
#ifndef LC0153_FIND_MINIMUM_IN_ROTATED_SORTED_ARRAY_H
#define LC0153_FIND_MINIMUM_IN_ROTATED_SORTED_ARRAY_H

#include <vector>

class LC0153_FindMinimumInRotatedSortedArray {
public:
    LC0153_FindMinimumInRotatedSortedArray() = default;
    virtual ~LC0153_FindMinimumInRotatedSortedArray() = default;
    virtual int findMin(std::vector<int>& nums) = 0;
};

class LC0153_FindMinimumInRotatedSortedArray_F1 : public LC0153_FindMinimumInRotatedSortedArray {
public:
    LC0153_FindMinimumInRotatedSortedArray_F1() = default;
    ~LC0153_FindMinimumInRotatedSortedArray_F1() override = default;
    int findMin(std::vector<int>& nums) final;
};

class LC0153_FindMinimumInRotatedSortedArray_F2 : public LC0153_FindMinimumInRotatedSortedArray {
public:
    LC0153_FindMinimumInRotatedSortedArray_F2() = default;
    ~LC0153_FindMinimumInRotatedSortedArray_F2() override = default;
    int findMin(std::vector<int>& nums) final;
};

#endif  // LC0153_FIND_MINIMUM_IN_ROTATED_SORTED_ARRAY_H
