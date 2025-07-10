/*
 * Time : 2025-06-06 11:46:02
 * URL  : https://leetcode.cn/problems/longest-consecutive-sequence/description/
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc01xx/lc0128_longest_consecutive_sequence.h"

using namespace std;

class TEST_LC0128 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0128_LongestConsecutiveSequence *> m_testList;
    void RunTest(vector<int32_t> &nums, int32_t expect);
};

void TEST_LC0128::SetUp()
{
    m_testList.push_back(new LC0128_LongestConsecutiveSequence());
}

void TEST_LC0128::TearDown()
{
    for (LC0128_LongestConsecutiveSequence *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0128::RunTest(vector<int32_t> &nums, int32_t expect)
{
    for (LC0128_LongestConsecutiveSequence *inst : m_testList) {
        EXPECT_EQ(expect, inst->longestConsecutive(nums));
    }
}

TEST_F(TEST_LC0128, case1)
{
    vector<int32_t> nums = {100, 4, 200, 1, 3, 2};
    int32_t expect = 4;
    RunTest(nums, expect);
}

TEST_F(TEST_LC0128, case2)
{
    vector<int32_t> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    int32_t expect = 9;
    RunTest(nums, expect);
}

TEST_F(TEST_LC0128, case3)
{
    vector<int32_t> nums = {1, 0, 1, 2};
    int32_t expect = 3;
    RunTest(nums, expect);
}
