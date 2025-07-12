/*
 * Time : 2025-06-16 15:03:49
 * URL  :
 * https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/?envType=problem-list-v2URL_STRenvId=binary-search
 */
#ifndef LC0034_FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_H
#define LC0034_FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_H

#include <vector>

class LC0034_FindFirstAndLastPositionOfElementInSortedArray {
public:
    LC0034_FindFirstAndLastPositionOfElementInSortedArray() = default;
    virtual ~LC0034_FindFirstAndLastPositionOfElementInSortedArray() = default;
    std::vector<int> searchRange(std::vector<int>& nums, int target);
};

#endif  // LC0034_FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_H
