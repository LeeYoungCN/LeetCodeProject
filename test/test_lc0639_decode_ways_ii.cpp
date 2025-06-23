/*
 * Time : 2025-06-22 23:57:26
 * URL  : https://leetcode.cn/problems/decode-ways-ii/
 */
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc0639_decode_ways_ii.h"

using namespace std;

class TEST_LC0639 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0639_DecodeWaysII *> m_testList;
    void RunTest(std::string s, const int &expect);
};

void TEST_LC0639::SetUp()
{
    m_testList.push_back(new LC0639_DecodeWaysII());
}

void TEST_LC0639::TearDown()
{
    for (LC0639_DecodeWaysII *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0639::RunTest(std::string s, const int &expect)
{
    for (LC0639_DecodeWaysII *inst : m_testList) {
        int result = inst->numDecodings(s);
        EXPECT_EQ(expect, result) << "s = " << s;
    }
}

TEST_F(TEST_LC0639, case1)
{
    std::string s = "*";
    const int expect = 9;
    RunTest(s, expect);
}

TEST_F(TEST_LC0639, case2)
{
    std::string s = "1*";
    const int expect = 18;
    RunTest(s, expect);
}

TEST_F(TEST_LC0639, case3)
{
    std::string s = "2*";
    const int expect = 15;
    RunTest(s, expect);
}

TEST_F(TEST_LC0639, case4)
{
    std::string s = "0*";
    const int expect = 0;
    RunTest(s, expect);
}

TEST_F(TEST_LC0639, case5)
{
    std::string s = "**";
    const int expect = 96;
    RunTest(s, expect);
}

TEST_F(TEST_LC0639, case6)
{
    std::string s = "*********";
    const int expect = 291868912;
    RunTest(s, expect);
}

TEST_F(TEST_LC0639, case7)
{
    std::string s = "7*9*3*6*3*0*5*4*9*7*3*7*1*8*3*2*0*0*6*";
    const int expect = 196465252;
    RunTest(s, expect);
}

