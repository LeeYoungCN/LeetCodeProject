/*
 * Time : 2025-06-03 14:12:55
 * URL  : https://leetcode.cn/problems/delete-and-earn/description/
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc0740_delete_and_earn.h"

using namespace std;

class TEST_LC0740 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0740_DeleteAndEarn *> m_testList;
    void RunTest(std::vector<int> &nums, int expect);
};

void TEST_LC0740::SetUp()
{
    m_testList.push_back(new LC0740_DeleteAndEarn());
}

void TEST_LC0740::TearDown()
{
    for (LC0740_DeleteAndEarn *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0740::RunTest(std::vector<int> &nums, int expect)
{
    for (LC0740_DeleteAndEarn *inst : m_testList) {
        EXPECT_EQ(expect, inst->deleteAndEarn(nums));
    }
}

TEST_F(TEST_LC0740, case1)
{
    std::vector<int> nums = {3, 4, 2};
    int expect = 6;
    RunTest(nums, expect);
}

TEST_F(TEST_LC0740, case2)
{
    std::vector<int> nums = {2, 2, 3, 3, 3, 4};
    int expect = 9;
    RunTest(nums, expect);
}
