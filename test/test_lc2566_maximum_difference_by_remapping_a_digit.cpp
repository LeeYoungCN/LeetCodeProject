/*
 * Time : 2025-06-14 02:00:32
 * URL  :
 * https://leetcode.cn/problems/maximum-difference-by-remapping-a-digit/description/?envType=daily-questionURL_STRenvId=2025-06-14
 */
#include "gtest/gtest.h"
#include "lc2566_maximum_difference_by_remapping_a_digit.h"

using namespace std;

class TEST_LC2566 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC2566_MaximumDifferenceByRemappingADigit *> m_testList;
    void RunTest(int num, int expect);
};

void TEST_LC2566::SetUp()
{
    m_testList.push_back(new LC2566_MaximumDifferenceByRemappingADigit_Math());
    m_testList.push_back(new LC2566_MaximumDifferenceByRemappingADigit_String());
}

void TEST_LC2566::TearDown()
{
    for (LC2566_MaximumDifferenceByRemappingADigit *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC2566::RunTest(int num, int expect)
{
    for (LC2566_MaximumDifferenceByRemappingADigit *inst : m_testList) {
        int result = inst->minMaxDifference(num);
        EXPECT_EQ(expect, result);
    }
}

TEST_F(TEST_LC2566, case1)
{
    int num = 11891;
    int expect = 99009;
    RunTest(num, expect);
}

TEST_F(TEST_LC2566, case2)
{
    int num = 90;
    int expect = 99;
    RunTest(num, expect);
}
