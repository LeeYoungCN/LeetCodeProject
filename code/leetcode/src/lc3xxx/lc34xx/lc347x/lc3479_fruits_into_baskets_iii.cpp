/*
 * Time : 2025-08-12 09:27:14
 * URL  : https://leetcode.cn/problems/fruits-into-baskets-iii/?envType=daily-question&envId=2025-08-12
 */
#include "lc3xxx/lc34xx/lc347x/lc3479_fruits_into_baskets_iii.h"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <vector>

using namespace std;

namespace tree_node {
struct SegTreeNode {
    int32_t value{-1};
    size_t idx{0};
    SegTreeNode* left{nullptr};
    SegTreeNode* right{nullptr};
};

class SegmentTree {
public:
    SegmentTree() = default;
    ~SegmentTree();
    explicit SegmentTree(const std::vector<int32_t>& baskets);
    bool consume(int32_t value);

private:
    SegTreeNode* build_(const std::vector<int32_t>& baskets, size_t left, size_t right);
    bool consume_(SegTreeNode*& node, int32_t value);
    void free_(SegTreeNode* node);

private:
    SegTreeNode* m_root{nullptr};
};

SegmentTree::SegmentTree(const std::vector<int32_t>& baskets)
{
    m_root = build_(baskets, 0, baskets.size() - 1);
}

void SegmentTree::free_(SegTreeNode* node)
{
    if (node == nullptr) {
        return;
    }
    free_(node->left);
    free_(node->right);
    delete node;
}

SegmentTree::~SegmentTree()
{
    free_(m_root);
    m_root = nullptr;
}

SegTreeNode* SegmentTree::build_(const std::vector<int32_t>& baskets, size_t left, size_t right)
{
    auto node = new SegTreeNode();
    if (left == right) {
        node->value = baskets[left];
    } else {
        size_t mid = (left + right) / 2;
        node->left = build_(baskets, left, mid);
        node->right = build_(baskets, mid + 1, right);
        node->value = max(node->left->value, node->right->value);
    }

    return node;
}

bool SegmentTree::consume_(SegTreeNode*& node, int32_t value)
{
    if (node->value < value) {
        return false;
    }

    if (node->left == nullptr && node->right == nullptr) {
        node->value = -1;
        return true;
    }
    bool rst = consume_(node->left, value) || consume_(node->right, value);
    node->value = max(node->left->value, node->right->value);
    return rst;
}

bool SegmentTree::consume(int32_t value)
{
    return consume_(m_root, value);
}
}  // namespace tree_node

int32_t LC3479_FruitsIntoBasketsIII_Node::numOfUnplacedFruits(std::vector<int32_t>& fruits,
                                                              std::vector<int32_t>& baskets)
{
    int32_t ans = 0;
    tree_node::SegmentTree tree(baskets);
    for (const auto& f : fruits) {
        if (!tree.consume(f)) {
            ans++;
        }
    }
    return ans;
}

namespace tree_vector {

}
