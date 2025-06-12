/*
 * Time : 2025-06-12 10:00:49
 * URL  :
 * https://leetcode.cn/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/?envType=daily-questionURL_STRenvId=2025-06-12
 */
#ifndef LC3423_MAXIMUM_DIFFERENCE_BETWEEN_ADJACENT_ELEMENTS_IN_A_CIRCULAR_ARRAY_H
#define LC3423_MAXIMUM_DIFFERENCE_BETWEEN_ADJACENT_ELEMENTS_IN_A_CIRCULAR_ARRAY_H

#include <vector>

class LC3423_MaximumDifferenceBetweenAdjacentElementsInACircularArray {
public:
    LC3423_MaximumDifferenceBetweenAdjacentElementsInACircularArray() = default;
    virtual ~LC3423_MaximumDifferenceBetweenAdjacentElementsInACircularArray() = default;
    int maxAdjacentDistance(std::vector<int>& nums);
};

#endif  // LC3423_MAXIMUM_DIFFERENCE_BETWEEN_ADJACENT_ELEMENTS_IN_A_CIRCULAR_ARRAY_H
