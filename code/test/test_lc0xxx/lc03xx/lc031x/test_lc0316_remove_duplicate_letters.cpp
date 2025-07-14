/*
 * Time : 2025-07-13 21:48:24
 * URL  : https://leetcode.cn/problems/remove-duplicate-letters/?envType=problem-list-v2&envId=monotonic-stack
 */

#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc0xxx/lc03xx/lc031x/lc0316_remove_duplicate_letters.h"

using namespace std;

class TEST_LC0316 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0316_RemoveDuplicateLetters *> m_testList;
    void RunTest(std::string &s, std::string &expect);
};

void TEST_LC0316::SetUp()
{
    m_testList.push_back(new LC0316_RemoveDuplicateLetters());
}

void TEST_LC0316::TearDown()
{
    for (LC0316_RemoveDuplicateLetters *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0316::RunTest(std::string &s, std::string &expect)
{
    for (LC0316_RemoveDuplicateLetters *inst : m_testList) {
        std::string result = inst->removeDuplicateLetters(s);
        EXPECT_EQ(expect, result) << s;
    }
}

TEST_F(TEST_LC0316, case1)
{
    std::string s = "bcabc";
    std::string expect = "abc";
    RunTest(s, expect);
}

TEST_F(TEST_LC0316, case2)
{
    std::string s = "cbacdcbc";
    std::string expect = "acdb";
    RunTest(s, expect);
}
