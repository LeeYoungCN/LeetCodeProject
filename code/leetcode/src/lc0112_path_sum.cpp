/*
 * Time : 2025-07-02 19:06:43
 * URL  : https://leetcode.cn/problems/path-sum/?envType=problem-list-v2&envId=depth-first-search
 */
#include "lc0112_path_sum.h"

#include <cstdint>
#include <stack>

#include "leetcode_utils_tree_node.hpp"

using namespace std;

enum Status { LEFT = 0, RIGHT, FINISH };

bool LC0112_PathSum::hasPathSum(TreeNode *root, int32_t targetSum)
{
    if (root == nullptr) {
        return false;
    }

    stack<pair<TreeNode *, Status>> callStack;

    callStack.emplace(root, LEFT);
    int32_t sum = 0;
    while (!callStack.empty()) {
        auto [node, status] = callStack.top();
        callStack.pop();
        switch (status) {
            case LEFT:
                if (node->left == nullptr && node->right == nullptr) {
                    if (sum + node->val == targetSum) {
                        return true;
                    }
                } else {
                    sum += node->val;
                    callStack.emplace(node, RIGHT);
                    if (node->left != nullptr) {
                        callStack.emplace(node->left, LEFT);
                    }
                }
                break;
            case RIGHT:
                callStack.emplace(node, FINISH);
                if (node->right != nullptr) {
                    callStack.emplace(node->right, LEFT);
                }
                break;
            case FINISH:
                sum -= node->val;
                break;
        }
    }

    return false;
}
