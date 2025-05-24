/*
 * Time : 2025-05-19 21:27:40
 * URL  : https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
 */
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc0017_letter_combinations_of_a_phone_number.h"

using namespace std;

class TEST_LC0017 : public testing::Test {
    protected:
        LC0017_LetterCombinationsOfAPhoneNumber m_test;
        void RunTest(string &digits, const set<string> &expect);
};

void TEST_LC0017::RunTest(string &digits, const set<string> &expect)
{
    vector<string> result = m_test.letterCombinations(digits);
    ASSERT_EQ(expect.size(), result.size());
    if (expect.size() == 0) {
        return;
    }
    for (const string &str : result) {
        std::set<string>::iterator it = expect.find(str);
        ASSERT_TRUE(expect.end() != it);
        EXPECT_STREQ(it->c_str(), str.c_str());
    }
}

TEST_F(TEST_LC0017, case1)
{
    string digits = "23";
    set<string> expect = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    RunTest(digits, expect);
}

TEST_F(TEST_LC0017, case2)
{
    string digits = "";
    set<string> expect = {};
    RunTest(digits, expect);
}

TEST_F(TEST_LC0017, case3)
{
    string digits = "2";
    set<string> expect = {"a", "b", "c"};
    RunTest(digits, expect);
}
