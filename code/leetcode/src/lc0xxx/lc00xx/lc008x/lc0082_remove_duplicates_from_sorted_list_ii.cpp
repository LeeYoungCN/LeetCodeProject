/*
 * Time : 2025-08-15 11:15:53
 * URL  : https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/description/
 */
#include "lc0xxx/lc00xx/lc008x/lc0082_remove_duplicates_from_sorted_list_ii.h"

#include <cstdint>

#include "leetcode_utils/leetcode_utils_list.hpp"

using namespace std;

ListNode* LC0082_RemoveDuplicatesFromSortedListII::deleteDuplicates(ListNode* head)
{
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode ans;
    ListNode* node = &ans;
    int32_t preNum = INT32_MIN;
    while (head) {
        if (head->val == preNum) {
            head = head->next;
            continue;
        }

        if (head->val != preNum && head->next && head->next->val == head->val) {
            preNum = head->val;
            head = head->next;
        } else {
            node->next = head;
            head = head->next;
            node = node->next;
            node->next = nullptr;
        }
    }
    return ans.next;
}
