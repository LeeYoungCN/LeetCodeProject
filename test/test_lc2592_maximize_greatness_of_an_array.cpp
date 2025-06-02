/*
 * Time : 2025-06-02 17:06:28
 * URL  : https://leetcode.cn/problems/maximize-greatness-of-an-array/description/
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc2592_maximize_greatness_of_an_array.h"

using namespace std;

class TEST_LC2592 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC2592_MaximizeGreatnessOfAnArray *> m_testList;
    void RunTest(std::vector<int> &nums, int expect);
};

void TEST_LC2592::SetUp()
{
    m_testList.push_back(new LC2592_MaximizeGreatnessOfAnArray());
}

void TEST_LC2592::TearDown()
{
    for (LC2592_MaximizeGreatnessOfAnArray *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC2592::RunTest(std::vector<int> &nums, int expect)
{
    for (LC2592_MaximizeGreatnessOfAnArray *inst : m_testList) {
        EXPECT_EQ(expect, inst->maximizeGreatness(nums));
    }
}

TEST_F(TEST_LC2592, case1)
{
    std::vector<int> nums = {1, 3, 5, 2, 1, 3, 1};
    int expect = 4;
    RunTest(nums, expect);
}

TEST_F(TEST_LC2592, case2)
{
    std::vector<int> nums = {1, 2, 3, 4};
    int expect = 3;
    RunTest(nums, expect);
}
