/*
 * Time : 2025-06-07 00:42:01
 * URL  :
 * https://leetcode.cn/problems/lexicographically-minimum-string-after-removing-stars/description/?envType=daily-questionURL_STRenvId=2025-06-07
 */
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc3xxx/lc31xx/lc317x/lc3170_lexicographically_minimum_string_after_removing_stars.h"

using namespace std;

class TEST_LC3170 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC3170_LexicographicallyMinimumStringAfterRemovingStars *> m_testList;
    void RunTest(string s, string expect);
};

void TEST_LC3170::SetUp()
{
    m_testList.push_back(new LC3170_LexicographicallyMinimumStringAfterRemovingStars_Heap());
    m_testList.push_back(new LC3170_LexicographicallyMinimumStringAfterRemovingStars_Stack());
}

void TEST_LC3170::TearDown()
{
    for (LC3170_LexicographicallyMinimumStringAfterRemovingStars *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC3170::RunTest(string s, string expect)
{
    for (LC3170_LexicographicallyMinimumStringAfterRemovingStars *inst : m_testList) {
        string result = inst->clearStars(s);
        EXPECT_EQ(expect, result);
    }
}

TEST_F(TEST_LC3170, case1)
{
    string s = "aaba*";
    string expect = "aab";
    RunTest(s, expect);
}

TEST_F(TEST_LC3170, case2)
{
    string s = "abc";
    string expect = "abc";
    RunTest(s, expect);
}

TEST_F(TEST_LC3170, case3)
{
    string s = "ab*c";
    string expect = "bc";
    RunTest(s, expect);
}

TEST_F(TEST_LC3170, case4)
{
    string s = "b*babab**c";
    string expect = "bbbc";
    RunTest(s, expect);
}

TEST_F(TEST_LC3170, case5)
{
    string s = "b*acb**c";
    string expect = "cc";
    RunTest(s, expect);
}

TEST_F(TEST_LC3170, case6)
{
    string s = "abacb*c";
    string expect = "abcbc";
    RunTest(s, expect);
}
