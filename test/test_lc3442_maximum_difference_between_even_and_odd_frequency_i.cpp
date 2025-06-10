/*
 * Time : 2025-06-10 09:25:33
 * URL  :
 * https://leetcode.cn/problems/maximum-difference-between-even-and-odd-frequency-i/description/?envType=daily-questionURL_STRenvId=2025-06-10
 */
#include "gtest/gtest.h"
#include "lc3442_maximum_difference_between_even_and_odd_frequency_i.h"

using namespace std;

class TEST_LC3442 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC3442_MaximumDifferenceBetweenEvenAndOddFrequencyI *> m_testList;
    void RunTest(string s, int expect);
};

void TEST_LC3442::SetUp()
{
    m_testList.push_back(new LC3442_MaximumDifferenceBetweenEvenAndOddFrequencyI());
}

void TEST_LC3442::TearDown()
{
    for (LC3442_MaximumDifferenceBetweenEvenAndOddFrequencyI *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC3442::RunTest(string s, int expect)
{
    for (LC3442_MaximumDifferenceBetweenEvenAndOddFrequencyI *inst : m_testList) {
        int result = inst->maxDifference(s);
        EXPECT_EQ(expect, result) << "string : " << s;
    }
}

TEST_F(TEST_LC3442, case1)
{
    string s = "aaaaabbc";
    int expect = 3;
    RunTest(s, expect);
}

TEST_F(TEST_LC3442, case2)
{
    string s = "abcabcab";
    int expect = 1;
    RunTest(s, expect);
}

TEST_F(TEST_LC3442, case3)
{
    string s = "yzyyys";
    int expect = -3;
    RunTest(s, expect);
}
