/*
 * Time : 2025-06-01 21:43:59
 * URL  : https://leetcode.cn/problems/apple-redistribution-into-boxes/description/
 */
#ifndef LC3074_APPLE_REDISTRIBUTION_INTO_BOXES_H
#define LC3074_APPLE_REDISTRIBUTION_INTO_BOXES_H

#include <vector>

class LC3074_AppleRedistributionIntoBoxes {
public:
    LC3074_AppleRedistributionIntoBoxes()          = default;
    virtual ~LC3074_AppleRedistributionIntoBoxes() = default;
    int minimumBoxes(std::vector<int>& apple, std::vector<int>& capacity);
};

#endif  // LC3074_APPLE_REDISTRIBUTION_INTO_BOXES_H
