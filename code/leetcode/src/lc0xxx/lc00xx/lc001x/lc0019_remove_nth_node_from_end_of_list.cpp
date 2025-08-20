/*
 * Time : 2025-08-15 19:22:46
 * URL  : https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/
 */
#include "lc0xxx/lc00xx/lc001x/lc0019_remove_nth_node_from_end_of_list.h"

#include <cstdint>

#include "leetcode_utils/leetcode_utils_list.hpp"

using namespace std;

ListNode* LC0019_RemoveNthNodeFromEndOfList::removeNthFromEnd(ListNode* head, int32_t n)
{
    int32_t idx = 0;
    ListNode ans(0, head);
    ListNode* preNode = &ans;

    while (head) {
        idx++;
        if (idx > n) {
            preNode = preNode->next;
        }
        head = head->next;
    }

    preNode->next = preNode->next->next;
    return ans.next;
}
