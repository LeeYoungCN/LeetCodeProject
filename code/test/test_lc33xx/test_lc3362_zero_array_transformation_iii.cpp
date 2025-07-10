/*
 * Time : 2025-05-22 15:45:08
 * URL  : https://leetcode.cn/problems/zero-array-transformation-iii/?envType=daily-questionURL_STRenvId=2025-05-22
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc33xx/lc3362_zero_array_transformation_iii.h"

using namespace std;

class TEST_LC3362 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC3362_ZeroArrayTransformationIII*> m_testList;
    void RunTest(vector<int>& nums, vector<vector<int>>& queries, int expectResult);
};

void TEST_LC3362::SetUp()
{
    m_testList.push_back(new LC3362_ZeroArrayTransformationIII());
}

void TEST_LC3362::TearDown()
{
    for (LC3362_ZeroArrayTransformationIII* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC3362::RunTest(vector<int>& nums, vector<vector<int>>& queries, int expectResult)
{
    for (LC3362_ZeroArrayTransformationIII* inst : m_testList) {
        EXPECT_EQ(expectResult, inst->maxRemoval(nums, queries));
    }
}

TEST_F(TEST_LC3362, case1)
{
    vector<int32_t> nums = {2, 0, 2};
    vector<vector<int32_t>> queries = {{0, 2}, {0, 2}, {1, 1}};
    RunTest(nums, queries, 1);
}

TEST_F(TEST_LC3362, case2)
{
    vector<int32_t> nums = {1, 1, 1, 1};
    vector<vector<int32_t>> queries = {{1, 3}, {0, 2}, {1, 3}, {1, 2}};
    RunTest(nums, queries, 2);
}

TEST_F(TEST_LC3362, case3)
{
    vector<int32_t> nums = {1, 2, 3, 4};
    vector<vector<int32_t>> queries = {{0, 3}};
    RunTest(nums, queries, -1);
}

TEST_F(TEST_LC3362, case4)
{
    vector<int32_t> nums = {0, 0, 0, 0};
    vector<vector<int32_t>> queries = {{0, 3}, {0, 3}, {0, 3}, {0, 3}};
    RunTest(nums, queries, 4);
}

TEST_F(TEST_LC3362, case5)
{
    vector<int32_t> nums = {0, 0, 0, 4};
    vector<vector<int32_t>> queries = {{0, 3}, {0, 3}, {0, 3}, {0, 3}};
    RunTest(nums, queries, 0);
}
