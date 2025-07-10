/*
 * Time : 2025-05-24 11:30:31
 * URL  : https://leetcode.cn/problems/house-robber-iii/description/
 */
#include <cstdint>
#include <cstdlib>
#include <vector>

#include "gtest/gtest.h"
#include "lc03xx/lc0337_house_robber_iii.h"

using namespace std;

class TEST_LC0337 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0337_HouseRobberIII *> m_testList;
    void RunTest(const vector<string> &nodeVal, int32_t expect);
    TreeNode *ValList2TreeNode(const vector<string> &nodeValList, uint32_t index = 0);
    void FreeTreeNode(TreeNode *root);
};

void TEST_LC0337::SetUp()
{
    m_testList.push_back(new LC0337_HouseRobberIII());
}

void TEST_LC0337::TearDown()
{
    for (LC0337_HouseRobberIII *inst : m_testList) {
        delete inst;
    }
}

TreeNode *TEST_LC0337::ValList2TreeNode(const vector<string> &nodeValList, uint32_t index)
{
    if (index >= nodeValList.size()) {
        return nullptr;
    }

    const string NULLPTR_STR = "null";
    if (nodeValList[index] == NULLPTR_STR) {
        return nullptr;
    }

    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));

    root->val = stoi(nodeValList[index]);
    root->left = ValList2TreeNode(nodeValList, 2 * index + 1);
    root->right = ValList2TreeNode(nodeValList, 2 * index + 2);

    return root;
}

void TEST_LC0337::FreeTreeNode(TreeNode *root)
{
    if (root == nullptr) {
        return;
    }
    FreeTreeNode(root->left);
    root->left = nullptr;
    FreeTreeNode(root->right);
    root->right = nullptr;
}

void TEST_LC0337::RunTest(const vector<string> &nodeValList, int32_t expect)
{
    TreeNode *root = ValList2TreeNode(nodeValList);
    for (LC0337_HouseRobberIII *inst : m_testList) {
        EXPECT_EQ(expect, inst->rob(root));
    }
    FreeTreeNode(root);
    root = nullptr;
}

TEST_F(TEST_LC0337, case1)
{
    vector<string> nodeValList = {"3", "2", "3", "null", "3", "null", "1"};

    RunTest(nodeValList, 7);
}

TEST_F(TEST_LC0337, case2)
{
    vector<string> nodeValList = {"3", "4", "5", "1", "3", "null", "1"};

    RunTest(nodeValList, 9);
}
