/*
 * Time : 2025-05-27 16:34:50
 * URL  : https://leetcode.cn/problems/zero-array-transformation-iv/
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc34xx/lc3489_zero_array_transformation_iv.h"

using namespace std;

class TEST_LC3489 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC3489_ZeroArrayTransformationIV*> m_testList;
    void RunTest(vector<int>& nums, vector<vector<int>>& queries, int expect);
};

void TEST_LC3489::SetUp()
{
    m_testList.push_back(new LC3489_ZeroArrayTransformationIV());
}

void TEST_LC3489::TearDown()
{
    for (LC3489_ZeroArrayTransformationIV* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC3489::RunTest(vector<int>& nums, vector<vector<int>>& queries, int expect)
{
    for (LC3489_ZeroArrayTransformationIV* inst : m_testList) {
        EXPECT_EQ(expect, inst->minZeroArray(nums, queries));
    }
}

TEST_F(TEST_LC3489, case1)
{
    vector<int> nums = {2, 0, 2};
    vector<vector<int>> queries = {{0, 2, 1}, {0, 2, 1}, {1, 1, 3}};
    RunTest(nums, queries, 2);
}

TEST_F(TEST_LC3489, case2)
{
    vector<int> nums = {4, 3, 2, 1};
    vector<vector<int>> queries = {{1, 3, 2}, {0, 2, 1}};
    RunTest(nums, queries, -1);
}

TEST_F(TEST_LC3489, case3)
{
    vector<int> nums = {1, 2, 3, 2, 1};
    vector<vector<int>> queries = {{0, 1, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 4, 1}};
    RunTest(nums, queries, 4);
}

TEST_F(TEST_LC3489, case4)
{
    vector<int> nums = {1, 2, 3, 2, 6};
    vector<vector<int>> queries = {{0, 1, 1}, {0, 2, 1}, {1, 4, 2}, {4, 4, 4}, {3, 4, 1}, {4, 4, 5}};
    RunTest(nums, queries, 4);
}

TEST_F(TEST_LC3489, case5)
{
    vector<int> nums = {2};
    vector<vector<int>> queries = {{0, 0, 6}, {0, 0, 2}, {0, 0, 9}, {0, 0, 5}, {0, 0, 10}};
    RunTest(nums, queries, 2);
}

TEST_F(TEST_LC3489, case6)
{
    vector<int> nums = {0};
    vector<vector<int>> queries = {{0, 0, 6}};
    RunTest(nums, queries, 0);
}
