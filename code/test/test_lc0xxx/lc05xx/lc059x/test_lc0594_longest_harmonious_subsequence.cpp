/*
 * Time : 2025-06-30 00:24:59
 * URL  : https://leetcode.cn/problems/longest-harmonious-subsequence/?envType=daily-question&envId=2025-06-30
 */
#include <cstdint>
#include <vector>

#include "gtest/gtest.h"
#include "lc0xxx/lc05xx/lc059x/lc0594_longest_harmonious_subsequence.h"
#include "leetcode_utils_vector.hpp"

using namespace std;

class TEST_LC0594 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0594_LongestHarmoniousSubsequence*> m_testList;
    void RunTest(std::vector<int32_t>& nums, const int32_t& expect);
};

void TEST_LC0594::SetUp()
{
    m_testList.push_back(new LC0594_LongestHarmoniousSubsequence());
}

void TEST_LC0594::TearDown()
{
    for (LC0594_LongestHarmoniousSubsequence* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0594::RunTest(std::vector<int32_t>& nums, const int32_t& expect)
{
    for (LC0594_LongestHarmoniousSubsequence* inst : m_testList) {
        int32_t result = inst->findLHS(nums);
        EXPECT_EQ(expect, result) << Vector2String(nums);
    }
}

TEST_F(TEST_LC0594, case1)
{
    std::vector<int32_t> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    const int32_t expect = 5;
    RunTest(nums, expect);
}

TEST_F(TEST_LC0594, case2)
{
    std::vector<int32_t> nums = {1, 2, 3, 4};
    const int32_t expect = 2;
    RunTest(nums, expect);
}

TEST_F(TEST_LC0594, case3)
{
    std::vector<int32_t> nums = {1, 1, 1, 1};
    const int32_t expect = 0;
    RunTest(nums, expect);
}
