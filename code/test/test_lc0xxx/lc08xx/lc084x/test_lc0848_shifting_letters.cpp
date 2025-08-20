/*
 * Time : 2025-07-05 14:04:07
 * URL  : https://leetcode.cn/problems/shifting-letters/description/
 */

#include <cstdint>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc0xxx/lc08xx/lc084x/lc0848_shifting_letters.h"
#include "leetcode_utils/leetcode_utils_vector.hpp"

using namespace std;

class TEST_LC0848 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0848_ShiftingLetters*> m_testList;
    void RunTest(std::string s, std::vector<int32_t>& shifts, const std::string& expect);
};

void TEST_LC0848::SetUp()
{
    m_testList.push_back(new LC0848_ShiftingLetters());
}

void TEST_LC0848::TearDown()
{
    for (LC0848_ShiftingLetters* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0848::RunTest(std::string s, std::vector<int32_t>& shifts, const std::string& expect)
{
    for (LC0848_ShiftingLetters* inst : m_testList) {
        std::string result = inst->shiftingLetters(s, shifts);
        EXPECT_EQ(expect, result);
    }
}

TEST_F(TEST_LC0848, case1)
{
    std::string s = "abc";
    std::vector<int32_t> shifts = CreateIntVector("[3,5,9]");
    const std::string expect = "rpl";
    RunTest(s, shifts, expect);
}

TEST_F(TEST_LC0848, case2)
{
    std::string s = "aaa";
    std::vector<int32_t> shifts = CreateIntVector("[1,2,3]");
    const std::string expect = "gfd";
    RunTest(s, shifts, expect);
}
