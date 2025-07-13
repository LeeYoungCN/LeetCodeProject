/*
 * Time : 2025-07-13 19:56:45
 * URL  : https://leetcode.cn/problems/single-element-in-a-sorted-array/description/
 */
#ifndef LC0540_SINGLE_ELEMENT_IN_A_SORTED_ARRAY_H
#define LC0540_SINGLE_ELEMENT_IN_A_SORTED_ARRAY_H

#include <cstdint>
#include <vector>

class LC0540_SingleElementInASortedArray {
public:
    LC0540_SingleElementInASortedArray() = default;
    virtual ~LC0540_SingleElementInASortedArray() = default;
    int32_t singleNonDuplicate(std::vector<int32_t>& nums);
};

#endif  // LC0540_SINGLE_ELEMENT_IN_A_SORTED_ARRAY_H
