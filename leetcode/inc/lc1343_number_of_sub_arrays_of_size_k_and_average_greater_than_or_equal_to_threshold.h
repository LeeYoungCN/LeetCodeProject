/*
 * Time : 2025-05-31 22:32:25
 * URL  :
 * https://leetcode.cn/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/description/
 */
#ifndef LC1343_NUMBER_OF_SUB_ARRAYS_OF_SIZE_K_AND_AVERAGE_GREATER_THAN_OR_EQUAL_TO_THRESHOLD_H
#define LC1343_NUMBER_OF_SUB_ARRAYS_OF_SIZE_K_AND_AVERAGE_GREATER_THAN_OR_EQUAL_TO_THRESHOLD_H

#include <vector>

class LC1343_NumberOfSubArraysOfSizeKAndAverageGreaterThanOrEqualToThreshold {
public:
    LC1343_NumberOfSubArraysOfSizeKAndAverageGreaterThanOrEqualToThreshold() = default;
    virtual ~LC1343_NumberOfSubArraysOfSizeKAndAverageGreaterThanOrEqualToThreshold() = default;
    int numOfSubarrays(std::vector<int>& arr, int k, int threshold);
};

#endif  // LC1343_NUMBER_OF_SUB_ARRAYS_OF_SIZE_K_AND_AVERAGE_GREATER_THAN_OR_EQUAL_TO_THRESHOLD_H
