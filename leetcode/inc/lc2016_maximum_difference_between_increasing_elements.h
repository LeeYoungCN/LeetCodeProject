/*
 * Time : 2025-06-16 09:06:13
 * URL  :
 * https://leetcode.cn/problems/maximum-difference-between-increasing-elements/description/?envType=daily-questionURL_STRenvId=2025-06-16
 */
#ifndef LC2016_MAXIMUM_DIFFERENCE_BETWEEN_INCREASING_ELEMENTS_H
#define LC2016_MAXIMUM_DIFFERENCE_BETWEEN_INCREASING_ELEMENTS_H

#include <vector>

class LC2016_MaximumDifferenceBetweenIncreasingElements {
public:
    LC2016_MaximumDifferenceBetweenIncreasingElements() = default;
    virtual ~LC2016_MaximumDifferenceBetweenIncreasingElements() = default;
    virtual int maximumDifference(std::vector<int>& nums) = 0;
};

class LC2016_MaximumDifferenceBetweenIncreasingElements_MinArray : public LC2016_MaximumDifferenceBetweenIncreasingElements {
public:
    LC2016_MaximumDifferenceBetweenIncreasingElements_MinArray() = default;
    ~LC2016_MaximumDifferenceBetweenIncreasingElements_MinArray() override = default;
    int maximumDifference(std::vector<int>& nums) final;
};

class LC2016_MaximumDifferenceBetweenIncreasingElements_PreMin : public LC2016_MaximumDifferenceBetweenIncreasingElements {
public:
    LC2016_MaximumDifferenceBetweenIncreasingElements_PreMin() = default;
    ~LC2016_MaximumDifferenceBetweenIncreasingElements_PreMin() override = default;
    int maximumDifference(std::vector<int>& nums) final;
};

#endif  // LC2016_MAXIMUM_DIFFERENCE_BETWEEN_INCREASING_ELEMENTS_H
