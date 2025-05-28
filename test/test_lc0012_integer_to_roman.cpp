// https://leetcode.cn/problems/integer-to-roman/description/

#include "gtest/gtest.h"
#include "lc0012_integer_to_roman.h"

using namespace std;

class TEST_LC0012 : public testing::Test {
protected:
    LC0012_IntegerToRoman m_test;
    void RunTest(int num, const char *expect);
};

void TEST_LC0012::RunTest(int num, const char *expect)
{
    EXPECT_STREQ(expect, m_test.intToRoman(num).c_str());
}

TEST_F(TEST_LC0012, case1)
{
    RunTest(3749, "MMMDCCXLIX");
}

TEST_F(TEST_LC0012, case2)
{
    RunTest(58, "LVIII");
}

TEST_F(TEST_LC0012, case3)
{
    RunTest(1994, "MCMXCIV");
}
