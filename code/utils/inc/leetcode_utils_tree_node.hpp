#ifndef LEETCODE_UTILS_TREE_NODE_HPP
#define LEETCODE_UTILS_TREE_NODE_HPP

#include <cstdint>
#include <string>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *NodeVal2TreeNode(const std::vector<std::string> &nodeValList, uint32_t index);
void FreeTreeNode(TreeNode *root);

#endif  // LEETCODE_UTILS_TREE_NODE_HPP
