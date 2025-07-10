/*
 * Time : 2025-07-01 09:00:08
 * URL  : https://leetcode.cn/problems/find-the-original-typed-string-i/?envType=daily-question&envId=2025-07-01
 */

#include <cstdint>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc33xx/lc3330_find_the_original_typed_string_i.h"

using namespace std;

class TEST_LC3330 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC3330_FindTheOriginalTypedStringI *> m_testList;
    void RunTest(std::string word, const int32_t &expect);
};

void TEST_LC3330::SetUp()
{
    m_testList.push_back(new LC3330_FindTheOriginalTypedStringI());
}

void TEST_LC3330::TearDown()
{
    for (LC3330_FindTheOriginalTypedStringI *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC3330::RunTest(std::string word, const int32_t &expect)
{
    for (LC3330_FindTheOriginalTypedStringI *inst : m_testList) {
        int32_t result = inst->possibleStringCount(word);
        EXPECT_EQ(expect, result);
    }
}

TEST_F(TEST_LC3330, case1)
{
    std::string word = "abbcccc";
    const int32_t expect = 5;
    RunTest(word, expect);
}

TEST_F(TEST_LC3330, case2)
{
    std::string word = "abcd";
    const int32_t expect = 1;
    RunTest(word, expect);
}

TEST_F(TEST_LC3330, case3)
{
    std::string word = "aaaa";
    const int32_t expect = 4;
    RunTest(word, expect);
}
