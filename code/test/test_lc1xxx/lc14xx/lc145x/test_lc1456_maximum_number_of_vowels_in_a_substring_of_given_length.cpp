/*
 * Time : 2025-05-31 22:04:33
 * URL  : https://leetcode.cn/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/
 */
#include <cstdint>
#include <vector>

#include "gtest/gtest.h"
#include "lc1xxx/lc14xx/lc145x/lc1456_maximum_number_of_vowels_in_a_substring_of_given_length.h"

using namespace std;

class TEST_LC1456 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC1456_MaximumNumberOfVowelsInASubstringOfGivenLength *> m_testList;
    void RunTest(string s, int k, int expect);
};

void TEST_LC1456::SetUp()
{
    m_testList.push_back(new LC1456_MaximumNumberOfVowelsInASubstringOfGivenLength());
}

void TEST_LC1456::TearDown()
{
    for (LC1456_MaximumNumberOfVowelsInASubstringOfGivenLength *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC1456::RunTest(string s, int k, int expect)
{
    for (LC1456_MaximumNumberOfVowelsInASubstringOfGivenLength *inst : m_testList) {
        EXPECT_EQ(expect, inst->maxVowels(s, k));
    }
}

TEST_F(TEST_LC1456, case1)
{
    string s = "abciiidef";
    int32_t k = 3;
    int32_t expect = 3;
    RunTest(s, k, expect);
}

TEST_F(TEST_LC1456, case2)
{
    string s = "aeiou";
    int32_t k = 2;
    int32_t expect = 2;
    RunTest(s, k, expect);
}
TEST_F(TEST_LC1456, case3)
{
    string s = "leetcode";
    int32_t k = 3;
    int32_t expect = 2;
    RunTest(s, k, expect);
}

TEST_F(TEST_LC1456, case4)
{
    string s = "rhythms";
    int32_t k = 4;
    int32_t expect = 0;
    RunTest(s, k, expect);
}

TEST_F(TEST_LC1456, case5)
{
    string s = "tryhard";
    int32_t k = 4;
    int32_t expect = 1;
    RunTest(s, k, expect);
}
