/*
 * Time : 2025-06-12 18:03:55
 * URL  : https://leetcode.cn/problems/subarray-sum-equals-k/description/?envType=problem-list-v2URL_STRenvId=prefix-sum
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc05xx/lc0560_subarray_sum_equals_k.h"

using namespace std;

class TEST_LC0560 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0560_SubarraySumEqualsK *> m_testList;
    void RunTest(vector<int> &nums, int k, int expect);
};

void TEST_LC0560::SetUp()
{
    m_testList.push_back(new LC0560_SubarraySumEqualsK());
}

void TEST_LC0560::TearDown()
{
    for (LC0560_SubarraySumEqualsK *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0560::RunTest(vector<int> &nums, int k, int expect)
{
    for (LC0560_SubarraySumEqualsK *inst : m_testList) {
        int result = inst->subarraySum(nums, k);
        EXPECT_EQ(expect, result);
    }
}

TEST_F(TEST_LC0560, case1)
{
    vector<int> nums = {1, 1, 1};
    int k = 2;
    int expect = 2;
    RunTest(nums, k, expect);
}

TEST_F(TEST_LC0560, case2)
{
    vector<int> nums = {1, 2, 3};
    int k = 3;
    int expect = 2;
    RunTest(nums, k, expect);
}

TEST_F(TEST_LC0560, case3)
{
    vector<int> nums = {1, 2, 3};
    int k = 10;
    int expect = 0;
    RunTest(nums, k, expect);
}

TEST_F(TEST_LC0560, case4)
{
    vector<int> nums = {1};
    int k = 0;
    int expect = 0;
    RunTest(nums, k, expect);
}
