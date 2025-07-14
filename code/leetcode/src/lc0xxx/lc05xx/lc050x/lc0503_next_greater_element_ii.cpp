/*
 * Time : 2025-07-14 10:37:14
 * URL  : https://leetcode.cn/problems/next-greater-element-ii/?envType=problem-list-v2&envId=monotonic-stack
 */
#include "lc0xxx/lc05xx/lc050x/lc0503_next_greater_element_ii.h"

#include <cstddef>
#include <cstdint>
#include <stack>
#include <vector>

using namespace std;

std::vector<int32_t> LC0503_NextGreaterElementII::nextGreaterElements(std::vector<int32_t>& nums)
{
    std::vector<int32_t> ans(nums.size(), -1);
    std::stack<std::size_t> nextMaxStack;

    for (size_t idx = 0; idx < 2 * nums.size(); idx++) {
        size_t i = idx % nums.size();
        while (!nextMaxStack.empty() && nums[i] > nums[nextMaxStack.top()]) {
            ans[nextMaxStack.top()] = nums[i];
            nextMaxStack.pop();
        }
        nextMaxStack.push(i);
    }

    return ans;
}
