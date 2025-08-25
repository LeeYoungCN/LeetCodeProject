#pragma once
#ifndef LEETCODE_UTILS_LIST_INTERNAL_HPP
#define LEETCODE_UTILS_LIST_INTERNAL_HPP

#include <cstdint>
#include <mutex>
#include <set>

#include "leetcode_utils/leetcode_utils_list.hpp"

namespace internal {
class ListNodeContainer {
public:
    ListNodeContainer() = default;
    ~ListNodeContainer();

    ListNode *NewListNode(int32_t val);
    void DeleteListNode(ListNode *node);
    void RegisterList(ListNode *node);
    bool IsRegister(ListNode *node);

private:
    void RegisterList_(ListNode *node);
    std::mutex m_mtx;
    std::set<ListNode *> m_nodeSet;
};
}  // namespace internal
#endif  // LEETCODE_UTILS_LIST_INTERNAL_HPP
