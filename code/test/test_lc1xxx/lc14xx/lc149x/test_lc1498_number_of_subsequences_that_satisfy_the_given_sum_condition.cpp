/*
 * Time : 2025-06-29 11:23:20
 * URL  :
 * https://leetcode.cn/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/?envType=daily-question&envId=2025-06-29
 */
#include <cmath>
#include <cstdio>
#include <vector>

#include "gtest/gtest.h"
#include "lc1xxx/lc14xx/lc149x/lc1498_number_of_subsequences_that_satisfy_the_given_sum_condition.h"
#include "leetcode_utils/leetcode_utils_vector.hpp"

using namespace std;

class TEST_LC1498 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC1498_NumberOfSubsequencesThatSatisfyTheGivenSumCondition*> m_testList;
    void RunTest(std::vector<int>& nums, int target, const int& expect);
};

void TEST_LC1498::SetUp()
{
    m_testList.push_back(new LC1498_NumberOfSubsequencesThatSatisfyTheGivenSumCondition());
}

void TEST_LC1498::TearDown()
{
    for (LC1498_NumberOfSubsequencesThatSatisfyTheGivenSumCondition* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC1498::RunTest(std::vector<int>& nums, int target, const int& expect)
{
    for (LC1498_NumberOfSubsequencesThatSatisfyTheGivenSumCondition* inst : m_testList) {
        int result = inst->numSubseq(nums, target);
        EXPECT_EQ(expect, result) << Vector2String(nums) << ", target = " << target;
    }
}

TEST_F(TEST_LC1498, case1)
{
    std::vector<int> nums = {3, 5, 6, 7};
    int target = 9;
    const int expect = 4;
    RunTest(nums, target, expect);
}

TEST_F(TEST_LC1498, case2)
{
    std::vector<int> nums = {3, 3, 6, 8};
    int target = 10;
    const int expect = 6;
    RunTest(nums, target, expect);
}

TEST_F(TEST_LC1498, case3)
{
    std::vector<int> nums = {2, 3, 3, 4, 6, 7};
    int target = 12;
    const int expect = 61;
    RunTest(nums, target, expect);
}

TEST_F(TEST_LC1498, case4)
{
    std::vector<int> nums = {5, 2, 4, 1, 7, 6, 8};
    int target = 16;
    const int expect = 127;
    RunTest(nums, target, expect);
}
