/*
 * Time : 2025-05-22 15:54:36
 * URL  : https://leetcode.cn/problems/zero-array-transformation-ii/description/
 */
#include <vector>
#include "gtest/gtest.h"
#include "lc3356_zero_array_transformation_ii.h"

using namespace std;

class TEST_LC3356 : public testing::Test {
    protected:
        static void SetUpTestSuite() {};
        static void TearDownTestSuite() {};
        void SetUp() override;
        void TearDown() override;

        vector<LC3356_ZeroArrayTransformationII *> m_testList;
        void RunTest(vector<int>& nums, vector<vector<int>>& queries, int expectResult);
};

void TEST_LC3356::SetUp()
{
    m_testList.push_back(new LC3356_ZeroArrayTransformationII_Array());
}

void TEST_LC3356::TearDown()
{
    for (LC3356_ZeroArrayTransformationII *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC3356::RunTest(vector<int>& nums, vector<vector<int>>& queries, int expectResult)
{
    for (LC3356_ZeroArrayTransformationII *inst : m_testList) {
        EXPECT_EQ(expectResult, inst->minZeroArray(nums, queries));
    }
}

TEST_F(TEST_LC3356, case1)
{
    vector<int32_t> nums = {2, 0, 2};
    vector<vector<int32_t>> queries = {{0, 2, 1}, {0, 2, 1}, {1, 1, 3}};
    RunTest(nums, queries, 2);
}

TEST_F(TEST_LC3356, case2)
{
    vector<int32_t> nums = {4, 3, 2, 1};
    vector<vector<int32_t>> queries = {{1, 3, 2}, {0, 2, 1}, {0, 2, 1}};
    RunTest(nums, queries, -1);
}

TEST_F(TEST_LC3356, case3)
{
    vector<int32_t> nums = {0, 0, 0};
    vector<vector<int32_t>> queries = {{1, 3, 2}, {0, 2, 1}, {0, 2, 1}};
    RunTest(nums, queries, 0);
}

TEST_F(TEST_LC3356, case4)
{
    vector<int32_t> nums = {0, 0, 4};
    vector<vector<int32_t>> queries = {{0, 2, 1}, {0, 2, 1}, {0, 2, 1}, {0, 2, 1}};
    RunTest(nums, queries, 4);
}
