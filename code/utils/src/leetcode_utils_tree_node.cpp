#include "leetcode_utils/leetcode_utils_tree_node.hpp"

#include <cstdint>
#include <string>
#include <vector>

#include "leetcode_utils/leetcode_utils_vector.hpp"

TreeNode *String2TreeNode(const std::string &nodeValStr)
{
    return NodeVal2TreeNode(CreateStringVector(nodeValStr));
}

TreeNode *NodeVal2TreeNode(const std::vector<std::string> &nodeValList, uint32_t index)
{
    if (index >= nodeValList.size()) {
        return nullptr;
    }
    const std::string NULLPTR_STR = "null";
    if (nodeValList[index] == NULLPTR_STR) {
        return nullptr;
    }

    auto *root = new TreeNode();

    root->val = std::stoi(nodeValList[index]);
    root->left = NodeVal2TreeNode(nodeValList, 2 * index + 1);
    root->right = NodeVal2TreeNode(nodeValList, 2 * index + 2);

    return root;
}

void FreeTreeNode(TreeNode *root)
{
    if (root == nullptr) {
        return;
    }
    FreeTreeNode(root->left);
    root->left = nullptr;
    FreeTreeNode(root->right);
    root->right = nullptr;
    delete root;
}
