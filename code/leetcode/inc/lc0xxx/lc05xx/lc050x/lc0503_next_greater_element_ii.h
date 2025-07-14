/*
 * Time : 2025-07-14 10:37:14
 * URL  : https://leetcode.cn/problems/next-greater-element-ii/?envType=problem-list-v2&envId=monotonic-stack
 */
#ifndef LC0503_NEXT_GREATER_ELEMENT_II_H
#define LC0503_NEXT_GREATER_ELEMENT_II_H

#include <cstdint>
#include <vector>

class LC0503_NextGreaterElementII {
public:
    LC0503_NextGreaterElementII() = default;
    virtual ~LC0503_NextGreaterElementII() = default;
    std::vector<int32_t> nextGreaterElements(std::vector<int32_t>& nums);
};

#endif  // LC0503_NEXT_GREATER_ELEMENT_II_H
