#include "leetcode_utils/leetcode_utils_list.hpp"

#include <cstdint>
#include <string>
#include <vector>

#include "internal/leetcode_utils_list_internal.hpp"
#include "leetcode_utils/leetcode_utils_vector.hpp"

namespace detail {
internal::ListNodeContainer g_container;

}  // namespace detail

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
    return CreateList(CreateIntVector(valStr));
}

ListNode *CreateList(const std::vector<int32_t> &valList)
{
    ListNode root{};
    ListNode *node = &root;
    for (const auto &value : valList) {
        node->next = detail::g_container.NewListNode(value);
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
    if (detail::g_container.IsRegister(node)) {
        detail::g_container.DeleteListNode(node);
    } else {
        delete node;
    }
}

std::string ToString(const ListNode *node)
{
    std::string str = "{";
    while (node != nullptr) {
        str += std::to_string(node->val);
        if (node->next) {
            str += " -> ";
        };
        node = node->next;
    }
    str += "}";
    return str;
}

void RegisterList(ListNode *node)
{
    detail::g_container.RegisterList(node);
}
