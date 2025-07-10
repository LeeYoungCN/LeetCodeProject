/*
 * Time : 2025-06-06 01:21:03
 * URL  :
 * https://leetcode.cn/problems/using-a-robot-to-print-the-lexicographically-smallest-string/description/?envType=daily-questionURL_STRenvId=2025-06-06
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc24xx/lc2434_using_a_robot_to_print_the_lexicographically_smallest_string.h"

using namespace std;

class TEST_LC2434 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC2434_UsingARobotToPrintTheLexicographicallySmallestString *> m_testList;
    void RunTest(string s, string expect);
};

void TEST_LC2434::SetUp()
{
    m_testList.push_back(new LC2434_UsingARobotToPrintTheLexicographicallySmallestString());
}

void TEST_LC2434::TearDown()
{
    for (LC2434_UsingARobotToPrintTheLexicographicallySmallestString *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC2434::RunTest(string s, string expect)
{
    for (LC2434_UsingARobotToPrintTheLexicographicallySmallestString *inst : m_testList) {
        EXPECT_EQ(expect, inst->robotWithString(s)) << "s = " << s;
    }
}

TEST_F(TEST_LC2434, case1)
{
    string s = "zza";
    string expect = "azz";
    RunTest(s, expect);
}

TEST_F(TEST_LC2434, case2)
{
    string s = "bac";
    string expect = "abc";
    RunTest(s, expect);
}

TEST_F(TEST_LC2434, case3)
{
    string s = "bdda";
    string expect = "addb";
    RunTest(s, expect);
}

TEST_F(TEST_LC2434, case4)
{
    string s = "bydizfve";
    string expect = "bdevfziy";
    RunTest(s, expect);
}
