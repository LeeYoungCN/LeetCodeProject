/*
 * Time : 2025-08-15 19:22:46
 * URL  : https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/
 */
#ifndef LC0019_REMOVE_NTH_NODE_FROM_END_OF_LIST_H
#define LC0019_REMOVE_NTH_NODE_FROM_END_OF_LIST_H

#include <cstdint>
#include "leetcode_utils/leetcode_utils_list.hpp"

class LC0019_RemoveNthNodeFromEndOfList {
public:
    LC0019_RemoveNthNodeFromEndOfList() = default;
    virtual ~LC0019_RemoveNthNodeFromEndOfList() = default;
    ListNode* removeNthFromEnd(ListNode* head, int32_t n);
};

#endif  // LC0019_REMOVE_NTH_NODE_FROM_END_OF_LIST_H
