/*
 * Time : 2025-06-20 22:43:05
 * URL  : https://leetcode.cn/problems/edit-distance/description/?envType=problem-list-v2&envId=dynamic-programming
 */

#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc0xxx/lc00xx/lc007x/lc0072_edit_distance.h"

using namespace std;

class TEST_LC0072 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0072_EditDistance *> m_testList;
    void RunTest(string word1, string word2, const int &expect);
};

void TEST_LC0072::SetUp()
{
    m_testList.push_back(new LC0072_EditDistance());
}

void TEST_LC0072::TearDown()
{
    for (LC0072_EditDistance *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0072::RunTest(string word1, string word2, const int &expect)
{
    for (LC0072_EditDistance *inst : m_testList) {
        int result = inst->minDistance(word1, word2);
        EXPECT_EQ(expect, result);
    }
}

TEST_F(TEST_LC0072, case1)
{
    string word1 = "horse";
    string word2 = "ros";
    const int expect = 3;
    RunTest(word1, word2, expect);
}

TEST_F(TEST_LC0072, case2)
{
    string word1 = "intention";
    string word2 = "execution";
    const int expect = 5;
    RunTest(word1, word2, expect);
}
