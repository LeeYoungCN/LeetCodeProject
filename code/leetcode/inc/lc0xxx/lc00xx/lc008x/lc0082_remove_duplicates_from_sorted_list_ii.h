/*
 * Time : 2025-08-15 11:15:53
 * URL  : https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/description/
 */
#ifndef LC0082_REMOVE_DUPLICATES_FROM_SORTED_LIST_II_H
#define LC0082_REMOVE_DUPLICATES_FROM_SORTED_LIST_II_H

#include "leetcode_utils/leetcode_utils_list.hpp"

class LC0082_RemoveDuplicatesFromSortedListII {
public:
    LC0082_RemoveDuplicatesFromSortedListII() = default;
    virtual ~LC0082_RemoveDuplicatesFromSortedListII() = default;
    ListNode* deleteDuplicates(ListNode* head);
};

#endif  // LC0082_REMOVE_DUPLICATES_FROM_SORTED_LIST_II_H
