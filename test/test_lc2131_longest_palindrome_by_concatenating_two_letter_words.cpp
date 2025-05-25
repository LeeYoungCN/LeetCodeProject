/*
 * Time : 2025-05-25 08:55:42
 * URL  :
 * https://leetcode.cn/problems/longest-palindrome-by-concatenating-two-letter-words/?envType=daily-questionURL_STRenvId=2025-05-25
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc2131_longest_palindrome_by_concatenating_two_letter_words.h"

using namespace std;

class TEST_LC2131 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC2131_LongestPalindromeByConcatenatingTwoLetterWords *> m_testList;
    void RunTest(std::vector<std::string> &words, int expect)const;
};

void TEST_LC2131::SetUp()
{
    m_testList.push_back(new LC2131_LongestPalindromeByConcatenatingTwoLetterWords());
}

void TEST_LC2131::TearDown()
{
    for (LC2131_LongestPalindromeByConcatenatingTwoLetterWords *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC2131::RunTest(std::vector<std::string> &words, int expect)const
{
    string caseStr;
    for (const string &word : words) {
        caseStr += word + ", ";
    }
    for (LC2131_LongestPalindromeByConcatenatingTwoLetterWords *inst : m_testList) {
        EXPECT_EQ(expect, inst->longestPalindrome(words)) << caseStr;
    }
}

TEST_F(TEST_LC2131, case1)
{
    std::vector<std::string> words = {"lc", "cl", "gg"};
    RunTest(words, 6);
}

TEST_F(TEST_LC2131, case2)
{
    std::vector<std::string> words = {"ab", "ty", "yt", "lc", "cl", "ab"};
    RunTest(words, 8);
}

TEST_F(TEST_LC2131, case3)
{
    std::vector<std::string> words = {"cc", "ll", "xx"};
    RunTest(words, 2);
}

TEST_F(TEST_LC2131, case4)
{
    std::vector<std::string> words = {"ab", "cd"};
    RunTest(words, 0);
}

TEST_F(TEST_LC2131, case5)
{
    std::vector<std::string> words = {"ll", "cc", "cc"};
    RunTest(words, 6);
}

TEST_F(TEST_LC2131, case6)
{
    std::vector<std::string> words = {"oo", "vv", "uu", "gg", "pp", "ff", "ss", "yy", "vv", "cc", "rr", "ig", "jj",
                                      "uu", "ig", "gb", "zz", "xx", "ff", "bb", "ii", "dd", "ii", "ee", "mm", "qq",
                                      "ig", "ww", "ss", "tt", "vv", "oo", "ww", "ss", "bi", "ff", "gg", "bi", "jj",
                                      "ee", "gb", "qq", "bg", "nn", "vv", "oo", "bb", "pp", "ww", "qq", "mm", "ee",
                                      "tt", "hh", "ss", "tt", "ee", "gi", "ig", "uu", "ff", "zz", "ii", "ff", "ss",
                                      "gi", "yy", "gb", "mm", "pp", "uu", "kk", "jj", "ee"};
    RunTest(words, 102);
}
