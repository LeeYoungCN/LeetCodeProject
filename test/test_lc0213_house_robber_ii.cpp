/*
 * Time : 2025-05-24 14:22:36
 * URL  : https://leetcode.cn/problems/house-robber-ii/
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc0213_house_robber_ii.h"

using namespace std;

class TEST_LC0213 : public testing::Test {
    protected:
        static void SetUpTestSuite() {};
        static void TearDownTestSuite() {};
        void SetUp() override;
        void TearDown() override;

        vector<LC0213_HouseRobberII *> m_testList;
        void RunTest(vector<int> &nums, int expectResult);
};

void TEST_LC0213::SetUp()
{
    m_testList.push_back(new LC0213_HouseRobberII());
}

void TEST_LC0213::TearDown()
{
    for (LC0213_HouseRobberII *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0213::RunTest(vector<int> &nums, int expectResult)
{
    for (LC0213_HouseRobberII *inst : m_testList) {
        EXPECT_EQ(expectResult, inst->rob(nums));
    }
}

TEST_F(TEST_LC0213, case1)
{
    vector<int> nums = {2,3,2};
    RunTest(nums, 3);
}

TEST_F(TEST_LC0213, case2)
{
    vector<int> nums = {1,2,3,1};
    RunTest(nums, 4);
}

TEST_F(TEST_LC0213, case3)
{
    vector<int> nums = {1,2,3};
    RunTest(nums, 3);
}
