/*
 * Time : 2025-06-21 00:09:29
 * URL  :
 * https://leetcode.cn/problems/minimum-deletions-to-make-string-k-special/description/?envType=daily-question&envId=2025-06-21
 */

#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc3xxx/lc30xx/lc308x/lc3085_minimum_deletions_to_make_string_k_special.h"

using namespace std;

class TEST_LC3085 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC3085_MinimumDeletionsToMakeStringKSpecial *> m_testList;
    void RunTest(string word, int k, const int &expect);
};

void TEST_LC3085::SetUp()
{
    m_testList.push_back(new LC3085_MinimumDeletionsToMakeStringKSpecial());
}

void TEST_LC3085::TearDown()
{
    for (LC3085_MinimumDeletionsToMakeStringKSpecial *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC3085::RunTest(string word, int k, const int &expect)
{
    for (LC3085_MinimumDeletionsToMakeStringKSpecial *inst : m_testList) {
        int result = inst->minimumDeletions(word, k);
        EXPECT_EQ(expect, result);
    }
}

TEST_F(TEST_LC3085, case1)
{
    string word = "aabcaba";
    int k = 0;
    const int expect = 3;
    RunTest(word, k, expect);
}

TEST_F(TEST_LC3085, case2)
{
    string word = "dabdcbdcdcd";
    int k = 2;
    const int expect = 2;
    RunTest(word, k, expect);
}

TEST_F(TEST_LC3085, case3)
{
    string word = "aaabaaa";
    int k = 2;
    const int expect = 1;
    RunTest(word, k, expect);
}
