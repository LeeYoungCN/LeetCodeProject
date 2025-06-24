/*
 * Time : 2025-06-21 18:03:05
 * URL  : https://leetcode.cn/problems/delete-operation-for-two-strings/
 */
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc0583_delete_operation_for_two_strings.h"

using namespace std;

class TEST_LC0583 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0583_DeleteOperationForTwoStrings *> m_testList;
    void RunTest(std::string word1, std::string word2, const int &expect);
};

void TEST_LC0583::SetUp()
{
    m_testList.push_back(new LC0583_DeleteOperationForTwoStrings_MinDelete());
    m_testList.push_back(new LC0583_DeleteOperationForTwoStrings_MaxCommon());
}

void TEST_LC0583::TearDown()
{
    for (LC0583_DeleteOperationForTwoStrings *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0583::RunTest(std::string word1, std::string word2, const int &expect)
{
    for (LC0583_DeleteOperationForTwoStrings *inst : m_testList) {
        int result = inst->minDistance(word1, word2);
        EXPECT_EQ(expect, result) << "word1 = " << word1 << ", word2 = " << word2;
    }
}

TEST_F(TEST_LC0583, case1)
{
    std::string word1 = "sea";
    std::string word2 = "eat";
    const int expect = 2;
    RunTest(word1, word2, expect);
}

TEST_F(TEST_LC0583, case2)
{
    std::string word1 = "leetcode";
    std::string word2 = "etco";
    const int expect = 4;
    RunTest(word1, word2, expect);
}
