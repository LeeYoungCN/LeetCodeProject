/*
 * Time : 2025-06-27 18:01:21
 * URL  :
 * https://leetcode.cn/problems/longest-subsequence-repeated-k-times/solutions/1006067/mei-ju-pai-lie-zi-xu-lie-pi-pei-by-endle-oi2h/?envType=daily-question&envId=2025-06-27
 */

#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc2xxx/lc20xx/lc201x/lc2014_longest_subsequence_repeated_k_times.h"

using namespace std;

class TEST_LC2014 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC2014_LongestSubsequenceRepeatedKTimes *> m_testList;
    void RunTest(std::string s, int k, const std::string &expect);
};

void TEST_LC2014::SetUp()
{
    m_testList.push_back(new LC2014_LongestSubsequenceRepeatedKTimes());
}

void TEST_LC2014::TearDown()
{
    for (LC2014_LongestSubsequenceRepeatedKTimes *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC2014::RunTest(std::string s, int k, const std::string &expect)
{
    for (LC2014_LongestSubsequenceRepeatedKTimes *inst : m_testList) {
        std::string result = inst->longestSubsequenceRepeatedK(s, k);
        EXPECT_EQ(expect, result) << "s = " << s;
    }
}

TEST_F(TEST_LC2014, case1)
{
    std::string s = "letsleetcode";
    int k = 2;
    const std::string expect = "let";
    RunTest(s, k, expect);
}

TEST_F(TEST_LC2014, case2)
{
    std::string s = "bb";
    int k = 2;
    const std::string expect = "b";
    RunTest(s, k, expect);
}

TEST_F(TEST_LC2014, case3)
{
    std::string s = "ab";
    int k = 2;
    const std::string expect;
    RunTest(s, k, expect);
}
