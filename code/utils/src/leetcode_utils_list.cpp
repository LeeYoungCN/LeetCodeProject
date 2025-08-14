#include "leetcode_utils_list.hpp"

#include "leetcode_utils_vector.hpp"

bool operator==(const ListNode &lhs, const ListNode &rhs)
{
    const ListNode *node1 = &lhs;
    const ListNode *node2 = &rhs;

    while (node1 != nullptr && node2 != nullptr) {
        if (node1->val != node2->val) {
            return false;
        }
        node1 = node1->next;
        node2 = node2->next;
    }
    return (node1 == nullptr && node2 == nullptr);
}

bool operator!=(const ListNode &lhs, const ListNode &rhs)
{
    return !(lhs == rhs);
}

ListNode *CreateList(const std::string &valStr)
{
    return CreateList(String2VecInt(valStr));
}

ListNode *CreateList(const std::vector<int32_t> &valList)
{
    ListNode root{};
    ListNode *node = &root;
    for (const auto &value : valList) {
        node->next = new ListNode(value);
        node = node->next;
    }
    return root.next;
}

void FreeList(ListNode *node)
{
    if (node == nullptr) {
        return;
    }
    FreeList(node->next);
    node->next = nullptr;
    delete node;
}
