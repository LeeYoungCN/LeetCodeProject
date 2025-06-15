/*
 * Time : 2025-06-15 19:50:29
 * URL  :
 * https://leetcode.cn/problems/max-difference-you-can-get-from-changing-an-integer/description/?envType=daily-questionURL_STRenvId=2025-06-15
 */
#include "gtest/gtest.h"
#include "lc1432_max_difference_you_can_get_from_changing_an_integer.h"

using namespace std;

class TEST_LC1432 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC1432_MaxDifferenceYouCanGetFromChangingAnInteger *> m_testList;
    void RunTest(int num, int expect);
};

void TEST_LC1432::SetUp()
{
    m_testList.push_back(new LC1432_MaxDifferenceYouCanGetFromChangingAnInteger());
}

void TEST_LC1432::TearDown()
{
    for (LC1432_MaxDifferenceYouCanGetFromChangingAnInteger *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC1432::RunTest(int num, int expect)
{
    for (LC1432_MaxDifferenceYouCanGetFromChangingAnInteger *inst : m_testList) {
        int result = inst->maxDiff(num);
        EXPECT_EQ(expect, result) << "num = " << num;
    }
}

TEST_F(TEST_LC1432, case1)
{
    int num = 555;
    int expect = 888;
    RunTest(num, expect);
}

TEST_F(TEST_LC1432, case2)
{
    int num = 9;
    int expect = 8;
    RunTest(num, expect);
}

TEST_F(TEST_LC1432, case3)
{
    int num = 123456;
    int expect = 820000;
    RunTest(num, expect);
}

TEST_F(TEST_LC1432, case4)
{
    int num = 10000;
    int expect = 80000;
    RunTest(num, expect);
}

TEST_F(TEST_LC1432, case5)
{
    int num = 9288;
    int expect = 8700;
    RunTest(num, expect);
}

TEST_F(TEST_LC1432, case6)
{
    int num = 111;
    int expect = 888;
    RunTest(num, expect);
}

TEST_F(TEST_LC1432, case7)
{
    int num = 90270580; // 99279589 10270580
    int expect = 89009009;
    RunTest(num, expect);
}


