/*
 * Time : 2025-06-22 18:18:39
 * URL  : https://leetcode.cn/problems/decode-ways/description/?envType=problem-list-v2&envId=dynamic-programming
 */
#include <cmath>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc0091_decode_ways.h"

using namespace std;

class TEST_LC0091 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0091_DecodeWays *> m_testList;
    void RunTest(std::string s, const int &expect);
};

void TEST_LC0091::SetUp()
{
    m_testList.push_back(new LC0091_DecodeWays_V1());
    m_testList.push_back(new LC0091_DecodeWays_V2());
}

void TEST_LC0091::TearDown()
{
    for (LC0091_DecodeWays *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0091::RunTest(std::string s, const int &expect)
{
    for (LC0091_DecodeWays *inst : m_testList) {
        int result = inst->numDecodings(s);
        EXPECT_EQ(expect, result);
    }
}

TEST_F(TEST_LC0091, case1)
{
    std::string s = "12";
    const int expect = 2;
    RunTest(s, expect);
}

TEST_F(TEST_LC0091, case2)
{
    std::string s = "226";
    const int expect = 3;
    RunTest(s, expect);
}

TEST_F(TEST_LC0091, case3)
{
    std::string s = "06";
    const int expect = 0;
    RunTest(s, expect);
}

TEST_F(TEST_LC0091, case4)
{
    std::string s = "125481022512";
    const int expect = 18;
    RunTest(s, expect);
}

TEST_F(TEST_LC0091, case5)
{
    std::string s = "2101";
    const int expect = 1;
    RunTest(s, expect);
}
