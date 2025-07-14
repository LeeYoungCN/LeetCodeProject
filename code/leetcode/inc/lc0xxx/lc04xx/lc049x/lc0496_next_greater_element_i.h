/*
 * Time : 2025-07-13 22:21:47
 * URL  : https://leetcode.cn/problems/next-greater-element-i/description/?envType=problem-list-v2&envId=monotonic-stack
 */
#ifndef LC0496_NEXT_GREATER_ELEMENT_I_H
#define LC0496_NEXT_GREATER_ELEMENT_I_H

#include <cstdint>
#include <vector>

class LC0496_NextGreaterElementI {
public:
    LC0496_NextGreaterElementI() = default;
    virtual ~LC0496_NextGreaterElementI() = default;
    std::vector<int32_t> nextGreaterElement(std::vector<int32_t>& nums1, std::vector<int32_t>& nums2);
};

#endif  // LC0496_NEXT_GREATER_ELEMENT_I_H
