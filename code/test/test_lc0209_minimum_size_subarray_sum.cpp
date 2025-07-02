/*
 * Time : 2025-06-12 10:12:40
 * URL  :
 * https://leetcode.cn/problems/minimum-size-subarray-sum/description/?envType=problem-list-v2URL_STRenvId=prefix-sum
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc0209_minimum_size_subarray_sum.h"
#include "leetcode_utils_vector.hpp"
using namespace std;

class TEST_LC0209 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0209_MinimumSizeSubarraySum *> m_testList;
    void RunTest(int target, vector<int> &nums, int expect);
};

void TEST_LC0209::SetUp()
{
    m_testList.push_back(new LC0209_MinimumSizeSubarraySum_MyLowerBound());
    m_testList.push_back(new LC0209_MinimumSizeSubarraySum_StdLowerBound());
    m_testList.push_back(new LC0209_MinimumSizeSubarraySum_Loop());
    m_testList.push_back(new LC0209_MinimumSizeSubarraySum_SlidingWindow());
}

void TEST_LC0209::TearDown()
{
    for (LC0209_MinimumSizeSubarraySum *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0209::RunTest(int target, vector<int> &nums, int expect)
{
    for (LC0209_MinimumSizeSubarraySum *inst : m_testList) {
        int result = inst->minSubArrayLen(target, nums);
        EXPECT_EQ(expect, result) << Vector2String(nums, 0, 10);
    }
}

TEST_F(TEST_LC0209, case1)
{
    int target = 7;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int expect = 2;
    RunTest(target, nums, expect);
}

TEST_F(TEST_LC0209, case2)
{
    int target = 4;
    vector<int> nums = {1, 4, 4};
    int expect = 1;
    RunTest(target, nums, expect);
}

TEST_F(TEST_LC0209, case3)
{
    int target = 11;
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1};
    int expect = 0;
    RunTest(target, nums, expect);
}

TEST_F(TEST_LC0209, case4)
{
    int target = 11;
    vector<int> nums = {1, 2, 3, 4, 5};
    int expect = 3;
    RunTest(target, nums, expect);
}

TEST_F(TEST_LC0209, case5)
{
    int target = 15;
    vector<int> nums = {1, 2, 3, 4, 5};
    int expect = 5;
    RunTest(target, nums, expect);
}
