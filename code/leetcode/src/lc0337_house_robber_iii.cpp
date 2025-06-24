/*
 * Time : 2025-05-24 11:30:31
 * URL  : https://leetcode.cn/problems/house-robber-iii/description/
 */
#include "lc0337_house_robber_iii.h"

#include <algorithm>
#include <cstdint>

using namespace std;

struct TreeVal {
    int32_t selectVal = 0;
    int32_t notSelectVal = 0;
};

void GetMaxVal(const TreeNode *node, TreeVal &maxVal)
{
    if (node == nullptr) {
        maxVal.notSelectVal = 0;
        maxVal.selectVal = 0;
        return;
    }

    TreeVal leftVal = {0, 0};
    GetMaxVal(node->left, leftVal);

    TreeVal rightVal = {0, 0};
    GetMaxVal(node->right, rightVal);

    maxVal.selectVal = node->val + leftVal.notSelectVal + rightVal.notSelectVal;
    maxVal.notSelectVal = max(leftVal.selectVal, leftVal.notSelectVal) + max(rightVal.selectVal, rightVal.notSelectVal);
}

int LC0337_HouseRobberIII::rob(TreeNode *root)
{
    TreeVal val;
    GetMaxVal(root, val);
    return max(val.notSelectVal, val.selectVal);
}
