/*
 * Time : 2025-08-15 15:21:49
 * URL  : https://leetcode.cn/problems/swap-nodes-in-pairs/
 */
#include "lc0xxx/lc00xx/lc002x/lc0024_swap_nodes_in_pairs.h"

#include <cstdint>

#include "leetcode_utils/leetcode_utils_list.hpp"

using namespace std;

ListNode* LC0024_SwapNodesInPairs::swapPairs(ListNode* head)
{
    ListNode* node = head;
    while (node) {
        if (node->next) {
            int32_t tmp = node->val;
            node->val = node->next->val;
            node->next->val = tmp;
            node = node->next->next;
        } else {
            break;
        }
    }
    return head;
}
