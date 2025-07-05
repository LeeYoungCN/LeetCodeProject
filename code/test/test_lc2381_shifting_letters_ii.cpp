/*
 * Time : 2025-07-05 14:53:48
 * URL  : https://leetcode.cn/problems/shifting-letters-ii/description/
 */

#include <cstdint>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc2381_shifting_letters_ii.h"

using namespace std;

class TEST_LC2381 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC2381_ShiftingLettersII*> m_testList;
    void RunTest(std::string s, std::vector<std::vector<int32_t>>& shifts, const std::string& expect);
};

void TEST_LC2381::SetUp()
{
    m_testList.push_back(new LC2381_ShiftingLettersII());
}

void TEST_LC2381::TearDown()
{
    for (LC2381_ShiftingLettersII* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC2381::RunTest(std::string s, std::vector<std::vector<int32_t>>& shifts, const std::string& expect)
{
    for (LC2381_ShiftingLettersII* inst : m_testList) {
        std::string result = inst->shiftingLetters(s, shifts);
        EXPECT_EQ(expect, result);
    }
}

TEST_F(TEST_LC2381, case1)
{
    std::string s = "abc";
    std::vector<std::vector<int32_t>> shifts = {{0, 1, 0}, {1, 2, 1}, {0, 2, 1}};
    const std::string expect = "ace";
    RunTest(s, shifts, expect);
}

TEST_F(TEST_LC2381, case2)
{
    std::string s = "dztz";
    std::vector<std::vector<int32_t>> shifts = {{0, 0, 0}, {1, 1, 1}};
    const std::string expect = "catz";
    RunTest(s, shifts, expect);
}
