/*
 * Time : 2025-08-14 18:19:47
 * URL  : https://leetcode.cn/problems/add-two-numbers/description/
 */
#include "lc0xxx/lc00xx/lc000x/lc0002_add_two_numbers.h"

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <functional>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "leetcode_utils/leetcode_utils_list.hpp"

using namespace std;

ListNode* LC0002_AddTwoNumbers::addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode ans;
    ListNode* node = &ans;
    int32_t carry = 0;
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int32_t val1 = l1 ? l1->val : 0;
        int32_t val2 = l2 ? l2->val : 0;
        int32_t sum = val1 + val2 + carry;
        node->next = new ListNode(sum % 10);
        carry = sum / 10;
        node = node->next;
        l1 = l1 ? l1->next : nullptr;
        l2 = l2 ? l2->next : nullptr;
    }
    return ans.next;
}
