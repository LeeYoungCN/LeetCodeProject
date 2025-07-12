/*
 * Time : 2025-06-05 19:17:03
 * URL  :
 * https://leetcode.cn/problems/lexicographically-smallest-equivalent-string/?envType=daily-questionURL_STRenvId=2025-06-05
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc1xxx/lc10xx/lc106x/lc1061_lexicographically_smallest_equivalent_string.h"

using namespace std;

class TEST_LC1061 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC1061_LexicographicallySmallestEquivalentString *> m_testList;
    void RunTest(string s1, string s2, string baseStr, string expect);
};

void TEST_LC1061::SetUp()
{
    m_testList.push_back(new LC1061_LexicographicallySmallestEquivalentString());
}

void TEST_LC1061::TearDown()
{
    for (LC1061_LexicographicallySmallestEquivalentString *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC1061::RunTest(string s1, string s2, string baseStr, string expect)
{
    for (LC1061_LexicographicallySmallestEquivalentString *inst : m_testList) {
        EXPECT_EQ(expect, inst->smallestEquivalentString(s1, s2, baseStr));
    }
}

TEST_F(TEST_LC1061, case1)
{
    string s1 = "parker";
    string s2 = "morris";
    string baseStr = "parser";
    string expect = "makkek";
    RunTest(s1, s2, baseStr, expect);
}

TEST_F(TEST_LC1061, case2)
{
    string s1 = "hello";
    string s2 = "world";
    string baseStr = "hold";
    string expect = "hdld";
    RunTest(s1, s2, baseStr, expect);
}

TEST_F(TEST_LC1061, case3)
{
    string s1 = "leetcode";
    string s2 = "programs";
    string baseStr = "sourcecode";
    string expect = "aauaaaaada";
    RunTest(s1, s2, baseStr, expect);
}
