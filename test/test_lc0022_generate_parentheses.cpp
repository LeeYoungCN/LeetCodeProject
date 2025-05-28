/*
 * Time : 2025-05-19 16:35:29
 * URL  : https://leetcode.cn/problems/generate-parentheses/description/?envType=daily-questionURL_STRenvId=2025-05-18
 */

#include <set>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc0022_generate_parentheses.h"

using namespace std;

class TEST_LC0022 : public testing::Test {
protected:
    vector<LC0022_GenerateParentheses *> m_testArray;
    void RunTest(int n, const set<string> &expect);
    void SetUp() override;
    void TearDown() override;
};

void TEST_LC0022::SetUp()
{
    m_testArray.push_back(new LC0022_GenerateParentheses_Num());
    m_testArray.push_back(new LC0022_GenerateParentheses_Itr1());
    m_testArray.push_back(new LC0022_GenerateParentheses_Itr2());
}

void TEST_LC0022::TearDown()
{
    for (LC0022_GenerateParentheses *inst : m_testArray) {
        delete inst;
    }
}

void TEST_LC0022::RunTest(int n, const set<string> &expect)
{
    for (LC0022_GenerateParentheses *inst : m_testArray) {
        ASSERT_NE(inst, nullptr);
        vector<string> result = inst->generateParenthesis(n);
        ASSERT_EQ(expect.size(), result.size());

        for (const string &str : result) {
            std::set<string>::iterator it = expect.find(str);
            ASSERT_TRUE(expect.end() != it);
            EXPECT_STREQ(it->c_str(), str.c_str());
        }
    }
}

TEST_F(TEST_LC0022, case1)
{
    const set<string> expect = {"()"};
    RunTest(1, expect);
}

TEST_F(TEST_LC0022, case2)
{
    const set<string> expect = {"()()", "(())"};
    RunTest(2, expect);
}

TEST_F(TEST_LC0022, case3)
{
    const set<string> expect = {"(()())", "((()))", "()()()", "()(())", "(())()"};
    RunTest(3, expect);
}

TEST_F(TEST_LC0022, case4)
{
    const set<string> expect = {"(((())))",
                                "((()()))",
                                "((())())",
                                "((()))()",
                                "(()(()))",
                                "(()()())",
                                "(()())()",
                                "(())(())",
                                "(())()()",
                                "()((()))",
                                "()(()())",
                                "()(())()",
                                "()()(())",
                                "()()()()"};
    RunTest(4, expect);
}
