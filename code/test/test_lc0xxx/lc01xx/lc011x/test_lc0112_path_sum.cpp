/*
 * Time : 2025-07-02 19:06:43
 * URL  : https://leetcode.cn/problems/path-sum/?envType=problem-list-v2&envId=depth-first-search
 */

#include <cstdint>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc0xxx/lc01xx/lc011x/lc0112_path_sum.h"
#include "leetcode_utils_tree_node.hpp"

using namespace std;

class TEST_LC0112 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0112_PathSum *> m_testList;
    void RunTest(const std::string &root, int32_t targetSum, const bool &expect);
};

void TEST_LC0112::SetUp()
{
    m_testList.push_back(new LC0112_PathSum());
}

void TEST_LC0112::TearDown()
{
    for (LC0112_PathSum *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0112::RunTest(const std::string &nodeValStr, int32_t targetSum, const bool &expect)
{
    TreeNode *root = String2TreeNode(nodeValStr);

    for (LC0112_PathSum *inst : m_testList) {
        bool result = inst->hasPathSum(root, targetSum);
        EXPECT_EQ(expect, result) << nodeValStr;
    }
    FreeTreeNode(root);
}

TEST_F(TEST_LC0112, case1)
{
    string str = "[5,4,8,11,null,13,4,7,2,null,null,null,1]";
    int32_t targetSum = 22;
    const bool expect = true;
    RunTest(str, targetSum, expect);
}

TEST_F(TEST_LC0112, case2)
{
    string str = "[1,2,3]";
    int32_t targetSum = 5;
    const bool expect = false;
    RunTest(str, targetSum, expect);
}

TEST_F(TEST_LC0112, case3)
{
    string str = "[]";
    int32_t targetSum = 0;
    const bool expect = false;
    RunTest(str, targetSum, expect);
}

TEST_F(TEST_LC0112, case4)
{
    string str = "[-2,null,-3]";
    int32_t targetSum = -2;
    const bool expect = false;
    RunTest(str, targetSum, expect);
}

TEST_F(TEST_LC0112, case5)
{
    string str = "[-2,-3,null]";
    int32_t targetSum = -2;
    const bool expect = false;
    RunTest(str, targetSum, expect);
}
