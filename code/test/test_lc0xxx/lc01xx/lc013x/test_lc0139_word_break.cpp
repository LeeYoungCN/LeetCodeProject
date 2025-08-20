/*
 * Time : 2025-06-24 16:21:12
 * URL  : https://leetcode.cn/problems/word-break/?envType=problem-list-v2&envId=dynamic-programming
 */

#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc0xxx/lc01xx/lc013x/lc0139_word_break.h"
#include "leetcode_utils/leetcode_utils_vector.hpp"

using namespace std;

class TEST_LC0139 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0139_WordBreak*> m_testList;
    void RunTest(std::string s, std::vector<std::string>& wordDict, const bool& expect);
};

void TEST_LC0139::SetUp()
{
    m_testList.push_back(new LC0139_WordBreak());
}

void TEST_LC0139::TearDown()
{
    for (LC0139_WordBreak* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0139::RunTest(std::string s, std::vector<std::string>& wordDict, const bool& expect)
{
    for (LC0139_WordBreak* inst : m_testList) {
        bool result = inst->wordBreak(s, wordDict);
        EXPECT_EQ(expect, result) << "s = " << s << "\ndict = " << Vector2String(wordDict);
    }
}

TEST_F(TEST_LC0139, case1)
{
    std::string s = "leetcode";
    std::vector<std::string> wordDict = {"leet", "code"};
    const bool expect = true;
    RunTest(s, wordDict, expect);
}

TEST_F(TEST_LC0139, case2)
{
    std::string s = "applepenapple";
    std::vector<std::string> wordDict = {"apple", "pen"};
    const bool expect = true;
    RunTest(s, wordDict, expect);
}

TEST_F(TEST_LC0139, case3)
{
    std::string s = "catsandog";
    std::vector<std::string> wordDict = {"cats", "dog", "sand", "and", "cat"};
    const bool expect = false;
    RunTest(s, wordDict, expect);
}

TEST_F(TEST_LC0139, case4)
{
    std::string s = "aaaaaaa";
    std::vector<std::string> wordDict = {"aaaa", "aaa"};
    const bool expect = true;
    RunTest(s, wordDict, expect);
}

TEST_F(TEST_LC0139, case5)
{
    std::string s =
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    std::vector<std::string> wordDict = {
        "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};

    const bool expect = false;
    RunTest(s, wordDict, expect);
}
