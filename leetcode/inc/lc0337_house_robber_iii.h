/*
 * Time : 2025-05-24 11:30:31
 * URL  : https://leetcode.cn/problems/house-robber-iii/description/
 */
#ifndef LC0337_HOUSE_ROBBER_III_H
#define LC0337_HOUSE_ROBBER_III_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class LC0337_HouseRobberIII {
public:
    LC0337_HouseRobberIII() = default;
    virtual ~LC0337_HouseRobberIII() = default;
    int rob(TreeNode *root);
};

#endif  // LC0337_HOUSE_ROBBER_III_H
