/*
 * Time : 2025-06-17 23:18:53
 * URL  :
 * https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array-ii/description/?envType=problem-list-v2URL_STRenvId=binary-search
 */
#ifndef LC0154_FIND_MINIMUM_IN_ROTATED_SORTED_ARRAY_II_H
#define LC0154_FIND_MINIMUM_IN_ROTATED_SORTED_ARRAY_II_H

#include <vector>

class LC0154_FindMinimumInRotatedSortedArrayII {
public:
    LC0154_FindMinimumInRotatedSortedArrayII() = default;
    virtual ~LC0154_FindMinimumInRotatedSortedArrayII() = default;
    virtual int findMin(std::vector<int>& nums) = 0;
};

class LC0154_FindMinimumInRotatedSortedArrayII_F1 : public LC0154_FindMinimumInRotatedSortedArrayII {
public:
    LC0154_FindMinimumInRotatedSortedArrayII_F1() = default;
    ~LC0154_FindMinimumInRotatedSortedArrayII_F1() override = default;
    int findMin(std::vector<int>& nums) final;
};

class LC0154_FindMinimumInRotatedSortedArrayII_F2 : public LC0154_FindMinimumInRotatedSortedArrayII {
public:
    LC0154_FindMinimumInRotatedSortedArrayII_F2() = default;
    ~LC0154_FindMinimumInRotatedSortedArrayII_F2() override = default;
    int findMin(std::vector<int>& nums) final;
};

#endif  // LC0154_FIND_MINIMUM_IN_ROTATED_SORTED_ARRAY_II_H
