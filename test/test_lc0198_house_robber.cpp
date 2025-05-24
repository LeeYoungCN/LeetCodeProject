/*
 * Time : 2025-05-24 13:37:13
 * URL  : https://leetcode.cn/problems/house-robber/
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc0198_house_robber.h"

using namespace std;

class TEST_LC0198 : public testing::Test {
    protected:
        static void SetUpTestSuite() {};
        static void TearDownTestSuite() {};
        void SetUp() override;
        void TearDown() override;

        vector<LC0198_HouseRobber *> m_testList;
        void RunTest(vector<int> &nums, int expectResult);
};

void TEST_LC0198::SetUp()
{
    m_testList.push_back(new LC0198_HouseRobber());
}

void TEST_LC0198::TearDown()
{
    for (LC0198_HouseRobber *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0198::RunTest(vector<int> &nums, int expectResult)
{
    for (LC0198_HouseRobber *inst : m_testList) {
        EXPECT_EQ(expectResult, inst->rob(nums));
    }
}

TEST_F(TEST_LC0198, case1)
{
    vector<int> nums = {1, 2, 3, 1};
    RunTest(nums, 4);
}

TEST_F(TEST_LC0198, case2)
{
    vector<int> nums = {2, 7, 9, 3, 1};
    RunTest(nums, 12);
}
