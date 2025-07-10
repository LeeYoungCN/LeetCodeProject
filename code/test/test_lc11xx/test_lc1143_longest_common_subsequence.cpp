/*
 * Time : 2025-06-21 19:36:30
 * URL  : https://leetcode.cn/problems/longest-common-subsequence/description/
 */
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc11xx/lc1143_longest_common_subsequence.h"

using namespace std;

class TEST_LC1143 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC1143_LongestCommonSubsequence *> m_testList;
    void RunTest(std::string text1, std::string text2, const int &expect);
};

void TEST_LC1143::SetUp()
{
    m_testList.push_back(new LC1143_LongestCommonSubsequence());
}

void TEST_LC1143::TearDown()
{
    for (LC1143_LongestCommonSubsequence *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC1143::RunTest(std::string text1, std::string text2, const int &expect)
{
    for (LC1143_LongestCommonSubsequence *inst : m_testList) {
        int result = inst->longestCommonSubsequence(text1, text2);
        EXPECT_EQ(expect, result) << "text1 = " << text1 << ", text2 = " << text2;
    }
}

TEST_F(TEST_LC1143, case1)
{
    std::string text1 = "abcde";
    std::string text2 = "ace";
    const int expect = 3;
    RunTest(text1, text2, expect);
}

TEST_F(TEST_LC1143, case2)
{
    std::string text1 = "abc";
    std::string text2 = "abc";
    const int expect = 3;
    RunTest(text1, text2, expect);
}

TEST_F(TEST_LC1143, case3)
{
    std::string text1 = "abc";
    std::string text2 = "def";
    const int expect = 0;
    RunTest(text1, text2, expect);
}

TEST_F(TEST_LC1143, case4)
{
    std::string text1 = "ezupkr";
    std::string text2 = "ubmrapg";
    const int expect = 2;
    RunTest(text1, text2, expect);
}

TEST_F(TEST_LC1143, case5)
{
    std::string text1 = "oxcpqrsvwf";
    std::string text2 = "shmtulqrypy";
    const int expect = 2;
    RunTest(text1, text2, expect);
}

TEST_F(TEST_LC1143, case6)
{
    std::string text1 = "pmjghexybyrgzczy";
    std::string text2 = "hafcdqbgncrcbihkd";
    const int expect = 4;
    RunTest(text1, text2, expect);
}
