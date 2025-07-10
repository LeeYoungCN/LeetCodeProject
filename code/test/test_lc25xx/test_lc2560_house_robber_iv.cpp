/*
 * Time : 2025-06-13 17:39:36
 * URL  : https://leetcode.cn/problems/house-robber-iv/description/
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc25xx/lc2560_house_robber_iv.h"
#include "leetcode_utils_vector.hpp"

using namespace std;

class TEST_LC2560 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC2560_HouseRobberIV *> m_testList;
    void RunTest(vector<int> &nums, int k, int expect);
};

void TEST_LC2560::SetUp()
{
    m_testList.push_back(new LC2560_HouseRobberIV());
}

void TEST_LC2560::TearDown()
{
    for (LC2560_HouseRobberIV *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC2560::RunTest(vector<int> &nums, int k, int expect)
{
    for (LC2560_HouseRobberIV *inst : m_testList) {
        int result = inst->minCapability(nums, k);
        EXPECT_EQ(expect, result) << "nums: " << Vector2String(nums) << ", k = " << k;
    }
}

TEST_F(TEST_LC2560, case1)
{
    vector<int> nums = {2, 3, 5, 9};
    int k = 2;
    int expect = 5;
    RunTest(nums, k, expect);
}

TEST_F(TEST_LC2560, case2)
{
    vector<int> nums = {2, 7, 9, 3, 1};
    int k = 2;
    int expect = 2;
    RunTest(nums, k, expect);
}

TEST_F(TEST_LC2560, case3)
{
    vector<int> nums = {1, 2, 3, 4, 1, 3, 5};
    int k = 2;
    int expect = 1;
    RunTest(nums, k, expect);
}

TEST_F(TEST_LC2560, case4)
{
    vector<int> nums = {4, 1, 1, 3, 1, 3, 5};
    int k = 3;
    int expect = 3;
    RunTest(nums, k, expect);
}

TEST_F(TEST_LC2560, case5)
{
    vector<int> nums = {1, 2, 3, 4};
    int k = 2;
    int expect = 3;
    RunTest(nums, k, expect);
}
