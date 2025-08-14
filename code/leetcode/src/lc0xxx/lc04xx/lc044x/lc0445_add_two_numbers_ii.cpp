/*
 * Time : 2025-08-14 12:14:22
 * URL  : https://leetcode.cn/problems/add-two-numbers-ii/description/
 */
#include "lc0xxx/lc04xx/lc044x/lc0445_add_two_numbers_ii.h"

#include <cstdint>
#include <stack>

#include "leetcode_utils_list.hpp"

using namespace std;

ListNode* LC0445_AddTwoNumbersII::addTwoNumbers(ListNode* l1, ListNode* l2)
{
    std::stack<int32_t> stack1;
    std::stack<int32_t> stack2;
    while (l1) {
        stack1.push(l1->val);
        l1 = l1->next;
    }
    while (l2) {
        stack2.push(l2->val);
        l2 = l2->next;
    }
    int32_t n = 0;
    ListNode* ans = nullptr;
    while (!stack1.empty() || !stack2.empty() || n > 0) {
        int32_t val1 = stack1.empty() ? 0 : stack1.top();
        int32_t val2 = stack2.empty() ? 0 : stack2.top();
        int32_t sum = val1 + val2 + n;
        n = sum / 10;
        auto* node = new ListNode(sum % 10, ans);
        ans = node;
        if (!stack1.empty()) {
            stack1.pop();
        }
        if (!stack2.empty()) {
            stack2.pop();
        }
    }

    return ans;
}
