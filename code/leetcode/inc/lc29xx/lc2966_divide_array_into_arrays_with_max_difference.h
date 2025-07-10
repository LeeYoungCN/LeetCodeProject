/*
 * Time : 2025-06-18 00:22:48
 * URL  :
 * https://leetcode.cn/problems/divide-array-into-arrays-with-max-difference/description/?envType=daily-questionURL_STRenvId=2025-06-18
 */
#ifndef LC2966_DIVIDE_ARRAY_INTO_ARRAYS_WITH_MAX_DIFFERENCE_H
#define LC2966_DIVIDE_ARRAY_INTO_ARRAYS_WITH_MAX_DIFFERENCE_H

#include <vector>

class LC2966_DivideArrayIntoArraysWithMaxDifference {
public:
    LC2966_DivideArrayIntoArraysWithMaxDifference() = default;
    virtual ~LC2966_DivideArrayIntoArraysWithMaxDifference() = default;
    std::vector<std::vector<int>> divideArray(std::vector<int>& nums, int k);
};

#endif  // LC2966_DIVIDE_ARRAY_INTO_ARRAYS_WITH_MAX_DIFFERENCE_H
