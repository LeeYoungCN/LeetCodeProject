/*
 * Time : 2025-06-23 21:08:36
 * URL  :
 * https://leetcode.cn/problems/interleaving-string/description/?envType=problem-list-v2&envId=dynamic-programming
 */
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc0xxx/lc00xx/lc009x/lc0097_interleaving_string.h"

using namespace std;

class TEST_LC0097 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0097_InterleavingString *> m_testList;
    void RunTest(std::string s1, std::string s2, std::string s3, const bool &expect);
};

void TEST_LC0097::SetUp()
{
    m_testList.push_back(new LC0097_InterleavingString());
}

void TEST_LC0097::TearDown()
{
    for (LC0097_InterleavingString *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0097::RunTest(std::string s1, std::string s2, std::string s3, const bool &expect)
{
    for (LC0097_InterleavingString *inst : m_testList) {
        bool result = inst->isInterleave(s1, s2, s3);
        EXPECT_EQ(expect, result);
    }
}

TEST_F(TEST_LC0097, case1)
{
    std::string s1 = "aabcc";
    std::string s2 = "dbbca";
    std::string s3 = "aadbbcbcac";
    const bool expect = true;
    RunTest(s1, s2, s3, expect);
}

TEST_F(TEST_LC0097, case2)
{
    std::string s1 = "aabcc";
    std::string s2 = "dbbca";
    std::string s3 = "aadbbbaccc";
    const bool expect = false;
    RunTest(s1, s2, s3, expect);
}

TEST_F(TEST_LC0097, case3)
{
    std::string s1;
    std::string s2;
    std::string s3;
    const bool expect = true;
    RunTest(s1, s2, s3, expect);
}

TEST_F(TEST_LC0097, case4)
{
    std::string s1;
    std::string s2 = "a";
    std::string s3 = "a";
    const bool expect = true;
    RunTest(s1, s2, s3, expect);
}
