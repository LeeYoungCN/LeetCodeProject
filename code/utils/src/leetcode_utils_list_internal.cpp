#include "internal/leetcode_utils_list_internal.hpp"

#include <format>

#include "leetcode_utils/leetcode_utils_list.hpp"
#include "leetcode_utils/leetcode_utils_logging.hpp"

namespace internal {

ListNodeContainer::~ListNodeContainer()
{
    std::unique_lock<std::mutex> lock(m_mtx);
    DEBUG_LOG_DBG("List node count: {}", m_nodeSet.size());
    for (auto node : m_nodeSet) {
        delete node;
    }
    m_nodeSet.clear();
}

ListNode *ListNodeContainer::NewListNode(int32_t val)
{
    std::unique_lock<std::mutex> lock(m_mtx);
    auto *node = new ListNode(val);
    RegisterList_(node);
    return node;
}

void ListNodeContainer::DeleteListNode(ListNode *node)
{
    if (node == nullptr) {
        return;
    }

    std::unique_lock<std::mutex> lock(m_mtx);
    auto it = m_nodeSet.find(node);
    if (it == m_nodeSet.end()) {
        DEBUG_LOG_ERR("[Failed] node not register: {:#x}", reinterpret_cast<uintptr_t>(node));
        return;
    }
    delete *it;
    m_nodeSet.erase(it);
    DEBUG_LOG_DBG("Delete node : {:#x}, count: {}", reinterpret_cast<uintptr_t>(node), m_nodeSet.size());
}

void ListNodeContainer::RegisterList(ListNode *node)
{
    std::unique_lock<std::mutex> lock(m_mtx);
    RegisterList_(node);
}

void ListNodeContainer::RegisterList_(ListNode *node)
{
    while (node) {
        m_nodeSet.insert(node);
        DEBUG_LOG_DBG("Register node : {:#x}, count: {}", reinterpret_cast<uintptr_t>(node), m_nodeSet.size());
        node = node->next;
    }
}

bool ListNodeContainer::IsRegister(ListNode *node)
{
    std::unique_lock<std::mutex> lock(m_mtx);
    return m_nodeSet.find(node) != m_nodeSet.end();
}
}  // namespace internal
