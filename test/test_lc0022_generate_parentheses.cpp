/*
 * Time : 2025-05-19 16:35:29
 * URL  : https://leetcode.cn/problems/generate-parentheses/description/?envType=daily-questionURL_STRenvId=2025-05-18
 */

#include <set>
#include <vector>
#include <string>
#include <set>
#include "gtest/gtest.h"
#include "lc0022_generate_parentheses.h"

using namespace std;

class Test_Lc0022 : public testing::Test
{
protected:
    method2::Lc0022_GenerateParentheses m_test;
    void RunTest(int n, const set<string> &expect);
};

void Test_Lc0022::RunTest(int n, const set<string> &expect)
{
    vector<string> result = m_test.generateParenthesis(n);
    ASSERT_EQ(expect.size(), result.size());

    for (const string &str : result)
    {
        std::set<string>::iterator it = expect.find(str);
        ASSERT_TRUE(expect.end() != it);
        EXPECT_STREQ(it->c_str(), str.c_str());
    }
}

TEST_F(Test_Lc0022, case1)
{
    const set<string> expect = {"()"};
    RunTest(1, expect);
}

TEST_F(Test_Lc0022, case2)
{
    const set<string> expect = {"()()", "(())"};
    RunTest(2, expect);
}

TEST_F(Test_Lc0022, case3)
{
    const set<string> expect = {"(()())", "((()))", "()()()", "()(())", "(())()"};
    RunTest(3, expect);
}

TEST_F(Test_Lc0022, case4)
{
    const set<string> expect = {
        "(((())))", "((()()))", "((())())", "((()))()",
        "(()(()))", "(()()())", "(()())()", "(())(())",
        "(())()()", "()((()))", "()(()())", "()(())()",
        "()()(())", "()()()()"
    };
    RunTest(4, expect);
}
