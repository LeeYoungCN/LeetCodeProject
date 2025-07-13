/*
 * Time : 2025-07-13 22:21:47
 * URL  : https://leetcode.cn/problems/next-greater-element-i/description/?envType=problem-list-v2&envId=monotonic-stack
 */
#include "lc0xxx/lc04xx/lc049x/lc0496_next_greater_element_i.h"

#include <cmath>
#include <cstdint>
#include <map>
#include <stack>
#include <vector>

#include "leetcode_utils_map.hpp"

using namespace std;

std::vector<int32_t> LC0496_NextGreaterElementI::nextGreaterElement(std::vector<int32_t>& nums1,
                                                                    std::vector<int32_t>& nums2)
{
    std::map<int32_t, int32_t> nexMaxMap;
    std::stack<int32_t> idxStack;

    for (int32_t i : nums2) {
        while (!idxStack.empty() && i > idxStack.top()) {
            nexMaxMap[idxStack.top()] = i;
            idxStack.pop();
        }
        idxStack.push(i);
    }
    while (!idxStack.empty()) {
        nexMaxMap[idxStack.top()] = -1;
        idxStack.pop();
    }
    PrintMap(nexMaxMap);
    std::vector<int32_t> ans;
    ans.reserve(nums1.size());
    for (int32_t i : nums1) {
        ans.push_back(nexMaxMap[i]);
    }
    return ans;
}
