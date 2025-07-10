/*
 * Time : 2025-06-11 09:53:03
 * URL  :
 * https://leetcode.cn/problems/maximum-difference-between-even-and-odd-frequency-ii/?envType=daily-questionURL_STRenvId=2025-06-11
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc34xx/lc3445_maximum_difference_between_even_and_odd_frequency_ii.h"

using namespace std;

class TEST_LC3445 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC3445_MaximumDifferenceBetweenEvenAndOddFrequencyII *> m_testList;
    void RunTest(string s, int k, int expect);
};

void TEST_LC3445::SetUp()
{
    m_testList.push_back(new LC3445_MaximumDifferenceBetweenEvenAndOddFrequencyII());
}

void TEST_LC3445::TearDown()
{
    for (LC3445_MaximumDifferenceBetweenEvenAndOddFrequencyII *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC3445::RunTest(string s, int k, int expect)
{
    for (LC3445_MaximumDifferenceBetweenEvenAndOddFrequencyII *inst : m_testList) {
        int result = inst->maxDifference(s, k);
        EXPECT_EQ(expect, result);
    }
}

TEST_F(TEST_LC3445, case1)
{
    string s = "12233";
    int k = 4;
    int expect = -1;
    RunTest(s, k, expect);
}

TEST_F(TEST_LC3445, case2)
{
    string s = "1122211";
    int k = 3;
    int expect = 1;
    RunTest(s, k, expect);
}

TEST_F(TEST_LC3445, case3)
{
    string s = "110";
    int k = 3;
    int expect = -1;
    RunTest(s, k, expect);
}
