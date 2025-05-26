/*
 * Time : 2025-05-27 00:20:24
 * URL  :
 * https://leetcode.cn/problems/divisible-and-non-divisible-sums-difference/description/?envType=daily-questionURL_STRenvId=2025-05-27
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc2894_divisible_and_non_divisible_sums_difference.h"

using namespace std;

class TEST_LC2894 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC2894_DivisibleAndNonDivisibleSumsDifference *> m_testList;
    void RunTest(int n, int m, int expect);
};

void TEST_LC2894::SetUp()
{
    m_testList.push_back(new LC2894_DivisibleAndNonDivisibleSumsDifference());
}

void TEST_LC2894::TearDown()
{
    for (LC2894_DivisibleAndNonDivisibleSumsDifference *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC2894::RunTest(int n, int m, int expect)
{
    for (LC2894_DivisibleAndNonDivisibleSumsDifference *inst : m_testList) {
        EXPECT_EQ(expect, inst->differenceOfSums(n, m));
    }
}

TEST_F(TEST_LC2894, case1)
{
    int32_t n = 10;
    int32_t m = 3;
    RunTest(n, m, 19);
}

TEST_F(TEST_LC2894, case2)
{
    int32_t n = 5;
    int32_t m = 6;
    RunTest(n, m, 15);
}

TEST_F(TEST_LC2894, case3)
{
    int32_t n = 5;
    int32_t m = 1;
    RunTest(n, m, -15);
}
