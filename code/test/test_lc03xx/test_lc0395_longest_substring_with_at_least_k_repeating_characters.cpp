/*
 * Time : 2025-06-28 15:40:11
 * URL  : https://leetcode.cn/problems/longest-substring-with-at-least-k-repeating-characters/
 */
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc03xx/lc0395_longest_substring_with_at_least_k_repeating_characters.h"

using namespace std;

class TEST_LC0395 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0395_LongestSubstringWithAtLeastKRepeatingCharacters *> m_testList;
    void RunTest(std::string s, int k, const int &expect);
};

void TEST_LC0395::SetUp()
{
    m_testList.push_back(new LC0395_LongestSubstringWithAtLeastKRepeatingCharacters());
}

void TEST_LC0395::TearDown()
{
    for (LC0395_LongestSubstringWithAtLeastKRepeatingCharacters *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0395::RunTest(std::string s, int k, const int &expect)
{
    for (LC0395_LongestSubstringWithAtLeastKRepeatingCharacters *inst : m_testList) {
        int result = inst->longestSubstring(s, k);
        EXPECT_EQ(expect, result) << "s = " << s << ", k = " << k;
    }
}

TEST_F(TEST_LC0395, case1)
{
    std::string s = "aaabb";
    int k = 3;
    const int expect = 3;
    RunTest(s, k, expect);
}

TEST_F(TEST_LC0395, case2)
{
    std::string s = "ababbc";
    int k = 2;
    const int expect = 5;
    RunTest(s, k, expect);
}

TEST_F(TEST_LC0395, case3)
{
    std::string s = "aaabbb";
    int k = 3;
    const int expect = 6;
    RunTest(s, k, expect);
}

TEST_F(TEST_LC0395, case4)
{
    std::string s = "bbaaacbd";
    int k = 3;
    const int expect = 3;
    RunTest(s, k, expect);
}

TEST_F(TEST_LC0395, case5)
{
    std::string s = "baaabcb";
    int k = 3;
    const int expect = 3;
    RunTest(s, k, expect);
}
