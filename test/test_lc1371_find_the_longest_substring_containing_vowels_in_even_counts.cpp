/*
 * Time : 2025-06-11 13:21:38
 * URL  : https://leetcode.cn/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc1371_find_the_longest_substring_containing_vowels_in_even_counts.h"

using namespace std;

class TEST_LC1371 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC1371_FindTheLongestSubstringContainingVowelsInEvenCounts *> m_testList;
    void RunTest(string s, int expect);
};

void TEST_LC1371::SetUp()
{
    m_testList.push_back(new LC1371_FindTheLongestSubstringContainingVowelsInEvenCounts());
}

void TEST_LC1371::TearDown()
{
    for (LC1371_FindTheLongestSubstringContainingVowelsInEvenCounts *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC1371::RunTest(string s, int expect)
{
    for (LC1371_FindTheLongestSubstringContainingVowelsInEvenCounts *inst : m_testList) {
        int result = inst->findTheLongestSubstring(s);
        EXPECT_EQ(expect, result);
    }
}

TEST_F(TEST_LC1371, case1)
{
    string s = "eleetminicoworoep";
    int expect = 13;
    RunTest(s, expect);
}

TEST_F(TEST_LC1371, case2)
{
    string s = "leetcodeisgreat";
    int expect = 5;
    RunTest(s, expect);
}

TEST_F(TEST_LC1371, case3)
{
    string s = "bcbcbc";
    int expect = 6;
    RunTest(s, expect);
}

TEST_F(TEST_LC1371, case4)
{
    string s = "lll";
    int expect = 3;
    RunTest(s, expect);
}
